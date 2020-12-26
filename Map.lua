require 'Util'

Map = Class{}

local SCROLL_SPEED = 62
local count = 0

function Map:init()

    self.spritesheet = love.graphics.newImage('graphics/spritesheet.png')
    self.sprites = generateQuads(self.spritesheet, 16, 16)
    self.music = love.audio.newSource('sounds/music.wav', 'static')

    self.tileWidth = 16
    self.tileHeight = 16
    self.mapWidth = 30
    self.mapHeight = 28
    self.tiles = {}

    self.gravity = 15

    self.player = Player(self)

    self.camX = 0
    self.camY = -3

    self.mapWidthPixels = self.mapWidth * self.tileWidth
    self.mapHeightPixels = self.mapHeight * self.tileHeight
    local x = 1
    while x <= self.mapWidth do            
        for y = self.mapHeight / 2, self.mapHeight do
            self:setTile(x, y, 4)
        end
        if math.random(10) == 1 then
            local randHeight = math.random(self.mapHeight/2 - 3)
            self:setTile(x, randHeight, 1)
        end
        if math.random(10) == 1 then
            local randHeight = math.random(self.mapHeight/2 - 3)
            self:setTile(x, randHeight, 2)
        end
        if math.random(10) == 1 then
            local randHeight = math.random(self.mapHeight/2 - 3)
            self:setTile(x, randHeight, 3)
        end
        if math.random(4) == 1 then
            local randHeight = math.random(self.mapHeight/2 - 3)
            self:setTile(x, randHeight, 6)
        end
        if count == 0 then
            local randHeight = math.random(self.mapHeight/2 - 3)
            local randWidth = math.random(self.mapWidth - 5)
            self:setTile(randWidth, randHeight, 7)
            count = count + 1
        end
        x = x + 1
    end
end

function Map:collides(tile)
    local collidables = {
        4, 5, 6
    }

    for _, v in ipairs(collidables) do
        if tile.id == v then
            return true
        end
    end

    return false
end

function Map:uniques(tile)
    local uniques = {
        1
    }
    for _, v in ipairs(uniques) do
        if tile.id == v then
            return true
        end
    end

    return false
end

function Map:uniques2(tile)
    local uniques2 = {
        2
    }
    for _, v in ipairs(uniques2) do
        if tile.id == v then
            return true
        end
    end

    return false
end

function Map:uniques3(tile)
    local uniques3 = {
        3
    }
    for _, v in ipairs(uniques3) do
        if tile.id == v then
            return true
        end
    end

    return false
end

function Map:uniques4(tile)
    local uniques4 = {
        7, 8
    }
    for _, v in ipairs(uniques4) do
        if tile.id == v then
            return true
        end
    end

    return false
end

function Map:update(dt)
    self.player:update(dt)
    self.camX = math.max(0, math.min(self.player.x - VIRTUAL_WIDTH / 2,
        math.min(self.mapWidthPixels - VIRTUAL_WIDTH, self.player.x)))
end

function Map:tileAt(x, y)
    return {
        x = math.floor(x / self.tileWidth) + 1,
        y = math.floor(y / self.tileHeight) + 1,
        id = self:getTile(math.floor(x / self.tileWidth) + 1, math.floor(y / self.tileHeight) + 1)
    }
end


function Map:getTile(x, y)
    return self.tiles[(y - 1) * self.mapWidth + x]
end


function Map:setTile(x, y, id)
    self.tiles[(y - 1) * self.mapWidth + x] = id
end

function Map:render()
    if gameState == 'Mode2' then
        for y = 1, self.mapHeight do
            for x = 1, self.mapWidth do
                local tile = self:getTile(x, y)
                if tile ~= TILE_EMPTY then
                    love.graphics.draw(self.spritesheet, self.sprites[tile],
                        (x - 1) * self.tileWidth, (y - 1) * self.tileHeight)
                end
            end
        end
        self.player:render()
    end
end


