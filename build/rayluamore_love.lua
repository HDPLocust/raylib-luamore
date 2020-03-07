local path = arg[1]



rl = require'raylib_luamore'
rl.core.InitWindow(400, 300, "untitled")
function no_game_func()
	rl.core.SetWindowSize(400, 300)
	rl.core.SetExitKey("escape")
	rl.core.SetTargetFPS(60)
	local rect    = rl.Rectangle(0, 0, 30, 30)
	local vOffset = rl.Vector2(15, 15)
	
	local bckgrColor = rl.Color("skyblue")
	local rectColor  = bckgrColor:clone()
	local HSV        = rectColor:toHSV()
	local textColor  = rl.Color("white")
	local time       = os.clock()

  while not rl.core.WindowShouldClose() do
		time = os.clock()
		rl.core.BeginDrawing()
  		rl.core.ClearBackground(bckgrColor)
			for i = 0, 8 do
				for j = 0, 6 do
					HSV.x = (time * 20 + (i + j) * 5)
					rectColor:fromHSV(HSV)
					
					local angle = math.sin(time + (i + j)*.2) * 100
					rect:setPosition(i * 50, j * 50)
					    :drawPro(rectColor, angle, vOffset)
				end
			end
	    rl.text.DrawText("NO GAME", 15, 110, 80, textColor)
		rl.core.EndDrawing()
  end
	os.exit()
end

no_game_func()

function error_func(err)
	rl.core.SetWindowSize(800, 600)
	rl.core.SetExitKey("escape")

  local trace  = debug.traceback(1):match("(stack.-)%[C%]: in function .xpcall.")
	local errmsg = tostring(err) .. '\n\n' .. tostring(trace)
	print(errmsg)
	
  while not rl.core.WindowShouldClose() or not rl.core.GetKeyPressed() do
		rl.core.BeginDrawing()
  		rl.core.ClearBackground(Clr"blue")
	    rl.text.DrawText(errmsg, 10, 10, 20, Clr("raywhite"))
		rl.core.EndDrawing()
  end
end