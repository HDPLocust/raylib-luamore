local ray = require'raylib_luamore'
local Color = ray.Color

ray.core.InitWindow(400, 300, "Hello")

while not ray.core.WindowShouldClose() do
	ray.core.BeginDrawing()
		ray.core.ClearBackground(Color"raywhite")
		ray.text.DrawText("lu",     30, 20, 40, Color"darkblue")
		ray.text.DrawText("a",      66, 20, 40, Color"maroon")
		ray.text.DrawText("more",   42, 44, 40, Color"maroon")
		ray.text.DrawText("raylib", 66, 68, 40, Color"darkblue")
	ray.core.EndDrawing()
end

ray.core.CloseWindow()