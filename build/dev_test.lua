local rl = require'raylib_luamore'
rl.core.SetConfigFlags("WINDOW_RESIZABLE")
rl.core.InitWindow(300, 300, "Hello")
rl.core.SetWindowPosition(800, 200)
rl.core.SetTargetFPS(30)

local Clr = rl.Color

local BgColor = rl.Color(120, 200, 200)
BgColor.a = 80


local c2 = rl.Color("darkpurple")
local c3 = rl.Color({0xb, 0xbb, 0x21})
local rect  = rl.Rectangle(20, 20, 20, 20);
local rect2 = rl.Rectangle(50, 50, 100, 100);
local v = rl.Vector2(10, 20)

function Main()
	rl.core.BeginDrawing()
		rl.core.ClearBackground(BgColor)
		local s0 = (math.sin(os.clock())/2 + 0.5)
		local s = s0 * 255
		local t = os.clock() * 360
		
		v.y = (1 - s0) * 10
		BgColor.r, BgColor.b = 255 - s, s
		
		rect:setPosition(20, s)
		    :draw('line', c3)
		    :setPosition(s, 20)
		    :drawPro(c2, t, v)
		
		rect2:setPosition(0, 100)
		     :drawGradient('h', BgColor, c3)
		     :setPosition(100, 100)
		     :drawGradient(Clr("red"), Clr("yellow"), Clr("skyblue"), Clr("magenta"))
		
		rl.text.DrawText("luamore\nRaylib", 20, 20, 20, c3)

		local mv = rl.core.GetMousePosition()
		rl.shapes.DrawPixel(mv.x - 10, mv.y - 10, c2)

	rl.core.EndDrawing()
end

function error_func(err)
  local trace  = debug.traceback(1):match("(stack.-)%[C%]: in function .xpcall.")
	local errmsg = tostring(err) .. '\n\n' .. tostring(trace)
	rl.core.SetWindowSize(800, 600)
	print(errmsg)
	
  while not rl.core.WindowShouldClose() or not rl.core.GetKeyPressed() do
		rl.core.BeginDrawing()
  		rl.core.ClearBackground(Clr"blue")
	    rl.text.DrawText(errmsg, 10, 10, 20, Clr("raywhite"))
		rl.core.EndDrawing()
  end
end

xpcall( function()
  while not rl.core.WindowShouldClose() do
  	Main()
  end
end, error_func)

rl.core.CloseWindow()
os.exit()
