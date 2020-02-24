local ray = require'raylib_luamore'
ray.core.InitWindow(300, 300, "Hello")

local c1 = ray.Color(120, 200, 200)
local c2 = ray.Color("darkpurple")
local c3 = ray.Color({0xb, 0xbb, 0x21})

local r = ray.Rectangle(20, 20, 20, 20);
local v = ray.Vector2(10, 10)
function Main()
	ray.core.BeginDrawing()
		ray.core.ClearBackground(c1)
		local s = (math.sin(os.clock())/2 + 0.5) * 255
		local t = os.clock() * 360
		
		c1:set(255 - s, _, s)
		r:setPosition(20, s):draw(c3):setPosition(s, 20):draw(v, t, c2)
		ray.text.DrawText("luamore\nRaylib", 20, 20, 20, c3)
	ray.core.EndDrawing()
end

while not ray.core.WindowShouldClose() do
	Main()
end

ray.core.CloseWindow()
os.exit()
