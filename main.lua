Class = require 'class'
push = require 'push'

require 'Animation'
require 'Map'
require 'Player'
gameState = 'Mode1'
VIRTUAL_WIDTH = 432
VIRTUAL_HEIGHT = 243

WINDOW_WIDTH = 1280
WINDOW_HEIGHT = 720

math.randomseed(os.time())

love.graphics.setDefaultFilter('nearest', 'nearest')

map = Map()
VictoryFont = love.graphics.getFont("font.ttf")

function love.load()

    love.graphics.setFont(love.graphics.newFont('fonts/font.ttf', 8))

    push:setupScreen(VIRTUAL_WIDTH, VIRTUAL_HEIGHT, WINDOW_WIDTH, WINDOW_HEIGHT, {
        fullscreen = false,
        resizable = true
    })

    love.window.setTitle('BlockGlitchUp')

    love.keyboard.keysPressed = {}
    love.keyboard.keysReleased = {}
end


function love.resize(w, h)
    push:resize(w, h)
end

function love.keyboard.wasPressed(key)
    if (love.keyboard.keysPressed[key]) then
        return true
    else
        return false
    end
end

function love.keyboard.wasReleased(key)
    if (love.keyboard.keysReleased[key]) then
        return true
    else
        return false
    end
end

function love.keypressed(key)
    if key == 'escape' then
        love.event.quit()
    elseif key == 'enter' or key == 'return' then
        gameState = 'Mode2'
    end

    love.keyboard.keysPressed[key] = true
end

function love.keyreleased(key)
    love.keyboard.keysReleased[key] = true
end

function love.update(dt)
    map:update(dt)
    love.keyboard.keysPressed = {}
    love.keyboard.keysReleased = {}
    if love.keyboard.wasPressed('j') then
        gameState = 'Mode2'
    end
end

function love.draw()
    push:apply('start')
    if gameState == 'Mode1' then
        love.graphics.print('GAME OF GLITCHES!!!', VIRTUAL_HEIGHT/2 - 50, VIRTUAL_WIDTH/2 - 90)
        love.graphics.print('PLAY INSTRUCTIONS:', VIRTUAL_WIDTH/2 - 50, VIRTUAL_HEIGHT/2 - 50)
        love.graphics.print('SPACE to fly', VIRTUAL_WIDTH/2 - 50, VIRTUAL_HEIGHT/2 - 50 + 15)
        love.graphics.print('R to restart', VIRTUAL_WIDTH/2 - 50, VIRTUAL_HEIGHT/2 - 40 + 15)
        love.graphics.print('ORANGE blocks kill you', VIRTUAL_WIDTH/2 - 50, VIRTUAL_HEIGHT/2 - 30 + 15)
        love.graphics.print('GREEN blocks reverse your movement', VIRTUAL_WIDTH/2 - 50, VIRTUAL_HEIGHT/2 - 20 + 15)
        love.graphics.print('RED blocks stop you', VIRTUAL_WIDTH/2 - 50, VIRTUAL_HEIGHT/2 - 10 + 15)
        love.graphics.print('Jump into the purple portal to win!', VIRTUAL_WIDTH/2 - 50, VIRTUAL_HEIGHT/2 + 20)
        love.graphics.print('ENTER TO BEGIN', VIRTUAL_WIDTH/2 - 50, VIRTUAL_HEIGHT/2 + 70)
    end
    if gameState == 'Mode2' then
        love.graphics.clear(108/255, 140/255, 255/255, 255/255)
        love.graphics.translate(math.floor(-map.camX + 0.5), math.floor(-map.camY + 0.5))
    end
    map:render()
    push:apply('end')
end
