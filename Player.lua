Player = Class{}

local WALKING_SPEED = 140
local JUMP_VELOCITY = 250

function Player:init(map)
    
    self.x = 0
    self.y = 0
    self.width = 16
    self.height = 20

    
    self.xOffset = 8
    self.yOffset = 10

    
    self.map = map
    self.texture = love.graphics.newImage('graphics/Character.png')

    
    self.sounds = {
        ['jump'] = love.audio.newSource('sounds/jump.wav', 'static'),
        ['hit'] = love.audio.newSource('sounds/Powerup.wav', 'static'),
        ['coin'] = love.audio.newSource('sounds/coin.wav', 'static'),
        ['VICTORY'] = love.audio.newSource('sounds/VICTORY.wav', 'static')
    }

    
    self.frames = generateQuads(self.texture, 16, 16)

    
    self.currentFrame = nil

    self.state = 'idle'

    
    self.dx = 0
    self.dy = 0

    
    self.y = map.tileHeight * ((map.mapHeight - 2) / 2) - self.height
    self.x = map.tileWidth * 10

    self.animations = {
        ['idle'] = Animation({
            texture = self.texture,
            frames = {
                self.frames[1]
            }
        }),
        ['jumping'] = Animation({
            texture = self.texture,
            frames = {
                self.frames[2]
            }
        })
    }

    self.animation = self.animations['idle']
    self.currentFrame = self.animation:getCurrentFrame()

    
    self.behaviors = {
        ['idle'] = function(dt)
            
            if love.keyboard.isDown('space') then
                self.dy = -JUMP_VELOCITY
                self.state = 'jumping'
                self.animation = self.animations['jumping']
                self.sounds['jump']:play()
            end
            if love.keyboard.wasPressed('r') then
                self.x = 0
                self.y = self.map.mapHeight + 160
            end
            self.dx = WALKING_SPEED
        end,
        ['idlebutbetter'] = function(dt)
            if love.keyboard.isDown('space') then
                self.dy = -JUMP_VELOCITY
                self.state = 'jumping'
                self.animation = self.animations['jumping']
                self.sounds['jump']:play()
            end
            if love.keyboard.wasPressed('r') then
                self.x = 0
                self.y = self.map.mapHeight + 160
            end
        end,
        ['idlebutevenbetter'] = function(dt)
            
            if love.keyboard.isDown('space') then
                self.dy = -JUMP_VELOCITY
                self.dx = WALKING_SPEED
                self.state = 'jumping'
                self.animation = self.animations['jumping']
                self.sounds['jump']:play()
            end
            if love.keyboard.wasPressed('r') then
                self.x = 0
                self.y = self.map.mapHeight + 160
            end
        end,
        ['jumping'] = function(dt)
            if love.keyboard.isDown('space') then
                return
            end
            self.dy = self.dy + self.map.gravity
            if self.map:collides(self.map:tileAt(self.x, self.y + self.height)) or
                self.map:collides(self.map:tileAt(self.x + self.width - 1, self.y + self.height)) then
                self.dy = 0
                self.state = 'idle'
                self.animation = self.animations['idle']
                self.y = (self.map:tileAt(self.x, self.y + self.height).y - 1) * self.map.tileHeight - self.height
            end

            if self.map:uniques(self.map:tileAt(self.x, self.y + self.height)) or self.map:uniques(self.map:tileAt(self.x + self.width - 1, self.y + self.height)) then
                self.dy = 0
                self.dx = 0
                self.state = 'idlebutevenbetter'
                self.animation = self.animations['idle']
                self.y = (self.map:tileAt(self.x, self.y + self.height).y - 1) * self.map.tileHeight - self.height
                self.sounds['hit']:play()
            end

            if self.map:uniques2(self.map:tileAt(self.x, self.y + self.height)) or self.map:uniques2(self.map:tileAt(self.x + self.width - 1, self.y + self.height)) then
                for x = 1, 2 do
                    self.dy = JUMP_VELOCITY
                end
                self.dx = 0
                self.state = 'idle'
                self.animation = self.animations['idle']
                self.y = (self.map:tileAt(self.x, self.y + self.height).y - 1) * self.map.tileHeight - self.height
                self.sounds['hit']:play()
            end

            if self.map:uniques3(self.map:tileAt(self.x, self.y + self.height)) or self.map:uniques3(self.map:tileAt(self.x + self.width - 1, self.y + self.height)) then
                self.dy = 0
                self.dx = -WALKING_SPEED
                self.state = 'idlebutbetter'
                self.animation = self.animations['idle']
                self.y = (self.map:tileAt(self.x, self.y + self.height).y - 1) * self.map.tileHeight - self.height
                self.sounds['hit']:play()
            end
            if self.map:uniques4(self.map:tileAt(self.x, self.y + self.height)) or self.map:uniques4(self.map:tileAt(self.x + self.width - 1, self.y + self.height)) then
                self.sounds['VICTORY']:play()
                love.event.quit('restart')
            end
            if love.keyboard.wasPressed('r') then
                self.x = 0
                self.y = self.map.mapHeight + 160
            end
            self:checkRightCollision()
            self:checkLeftCollision()
        end
    }
end

function Player:update(dt)
    self.behaviors[self.state](dt)
    self.animation:update(dt)
    self.currentFrame = self.animation:getCurrentFrame()
    self.x = self.x + self.dx * dt

    self:calculateJumps()

    
    self.y = self.y + self.dy * dt
    if self.x > 30 * 16 then
        self.x = 0
    end

end


function Player:calculateJumps()
    
    if self.dy < 0 then
        if self.map:tileAt(self.x, self.y).id ~= TILE_EMPTY or
            self.map:tileAt(self.x + self.width - 1, self.y).id ~= TILE_EMPTY then
            
            self.dy = 0

            
            local playCoin = false
            local playHit = false
            if self.map:tileAt(self.x, self.y).id == JUMP_BLOCK then
                self.map:setTile(math.floor(self.x / self.map.tileWidth) + 1,
                    math.floor(self.y / self.map.tileHeight) + 1, JUMP_BLOCK_HIT)
                playCoin = true
            else
                playHit = true
            end
            if self.map:tileAt(self.x + self.width - 1, self.y).id == JUMP_BLOCK then
                self.map:setTile(math.floor((self.x + self.width - 1) / self.map.tileWidth) + 1,
                    math.floor(self.y / self.map.tileHeight) + 1, JUMP_BLOCK_HIT)
                playCoin = true
            else
                playHit = true
            end

            if playCoin then
                self.sounds['coin']:play()
            elseif playHit then
                self.sounds['hit']:play()
            end
        end
    end
end


function Player:checkLeftCollision()
    if self.dx < 0 then
        
        if self.map:collides(self.map:tileAt(self.x - 1, self.y)) or
            self.map:collides(self.map:tileAt(self.x - 1, self.y + self.height - 1)) then
            
            
            self.dx = 0
            self.x = self.map:tileAt(self.x - 1, self.y).x * self.map.tileWidth
        end
    end
end


function Player:checkRightCollision()
    if self.dx > 0 then
        
        if self.map:collides(self.map:tileAt(self.x + self.width, self.y)) or
            self.map:collides(self.map:tileAt(self.x + self.width, self.y + self.height - 1)) then
            
            
            self.dx = 0
            self.x = (self.map:tileAt(self.x + self.width, self.y).x - 1) * self.map.tileWidth - self.width
        end
    end
end

function Player:render()
    local scaleX
    love.graphics.draw(self.texture, self.currentFrame, math.floor(self.x + self.xOffset),
        math.floor(self.y + self.yOffset), 0, scaleX, 1, self.xOffset, self.yOffset)
end
