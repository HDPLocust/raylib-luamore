local rl = require'raylib_luamore'
print(require'inspect'(rl))

local function Log(level, msg)
  print("LOG: ", level, msg)
end
rl.core.InitWindow(300, 300, "Hello")
rl.core.SetTargetFPS(30)

local c1 = rl.Color(120, 200, 200)
local c2 = rl.Color("darkpurple")
local c3 = rl.Color({0xb, 0xbb, 0x21})

local r = rl.Rectangle(20, 20, 20, 20);
local v = rl.Vector2(10, 20)
print("VECTOR2 KEYS: ", v.x, v.y, v[1], v[2])
v:set(10, 10)

function Main()
	local text = rl.core.GetAllKeysPressedString()
	if text then rl.core.TraceLog("DEBUG", text) end
	if text == 'g' then rl.core.SetTraceLogCallback() end
  
  if rl.core.IsKeyDown('n') then print("Key n is down") end
	
	local mv = rl.core.GetMousePosition()
	
	rl.core.BeginDrawing()
		rl.core.ClearBackground(c1)
		local s0 = (math.sin(os.clock())/2 + 0.5)
		local s = s0 * 255
		local t = os.clock() * 360
		
		v.y = (1 - s0) * 10
		c1.r, c1.b = 255 - s, s
		rl.shapes.DrawPixel(mv.x - 10, mv.y - 10, c2)
		r:setPosition(20, s):draw(c3):setPosition(s, 20):draw(v, t, c2)
		rl.text.DrawText("luamore\nRaylib", 20, 20, 20, c3)
	rl.core.EndDrawing()
end

while not rl.core.WindowShouldClose() do
	Main()
end

rl.core.CloseWindow()
os.exit()