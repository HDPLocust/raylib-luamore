
# Hello. 
This is Lua binding for raylib.
### All stuff provided by Snooze.

Read the [Core] 


## Core
### Core functions

#### Initialization
```lua
local ray = require("raylib_luamore")
```


### Window-related functions:
#### InitWindow
```lua
ray.core.InitWindow(integer Width, integer Height, string Title)
```
Initialize window and OpenGL context
Should be called before any widnow stuff is used.


#### WindowShouldClose
```lua
Boolean = ray.core.WindowShouldClose()
```
Check if KEY_ESCAPE pressed or Close icon pressed


#### CloseWindow
```lua
ray.core.CloseWindow()
```
Close window and unload OpenGL context


#### IsWindowReady
```lua
boolean res = ray.core.IsWindowReady()
```
Check if window has been initialized successfully


#### IsWindowMinimized
```lua
boolean res = ray.core.IsWindowMinimized()
```
Check if window has been minimized (or lost focus)


#### IsWindowResized
```lua
boolean res = ray.core.IsWindowResized()
```
Check if window has been resized


#### IsWindowHidden
```lua
boolean res = ray.core.IsWindowHidden()
```
Check if window is currently hidden


#### ToggleFullscreen
```lua
ray.core.ToggleFullscreen()
```
Toggle fullscreen mode (only PLATFORM_DESKTOP)


#### UnhideWindow
```lua
ray.core.UnhideWindow()
```
Show the window


#### HideWindow
```lua
ray.core.HideWindow()
```
Hide the window


#### SetWindowIcon
```lua
ray.core.SetWindowIcon(ray_image Icon)
```
Set icon for window (only PLATFORM_DESKTOP)
For additional info [ray_image]


#### SetWindowTitle
```lua
ray.core.SetWindowTitle(string Title)
```
Set title for window (only PLATFORM_DESKTOP)


#### SetWindowPosition
```lua
ray.core.SetWindowPosition(string Title)
```
Set window position on screen (only PLATFORM_DESKTOP)


#### SetWindowMonitor
```lua
ray.core.SetWindowMonitor(integer Monitor)
```
Set monitor for the current window (fullscreen mode)


#### SetWindowMinSize
```lua
ray.core.SetWindowMinSize(integer Width, integer Height)
```
Set window minimum dimensions (for FLAG_WINDOW_RESIZABLE)


#### SetWindowSize
```lua
ray.core.SetWindowSize(integer Width, integer Height)
```
Set window dimensions


#### GetWindowHandle
```lua
userdata Handle = ray.core.GetWindowHandle()
```
Get native window handle
Using for FFI or something


#### GetScreenWidth
```lua
integer Width = ray.core.GetScreenWidth()
```
Get current screen width


#### GetScreenHeight
```lua
integer Height = ray.core.GetScreenHeight()
```
Get current screen height


#### GetScreenDimensions
```lua
integer Width, integer Height = ray.core.GetScreenDimensions()
```
Get current screen dimensions


#### GetMonitorCount
```lua
integer Count = ray.core.GetMonitorCount()
```
Get number of connected monitors


#### GetMonitorWidth
```lua
integer Width = ray.core.GetMonitorWidth(integer Monitor)
```
Get selected monitor width


#### GetMonitorHeight
```lua
integer Height = ray.core.GetMonitorHeight(integer Monitor)
```
Get selected monitor height


#### GetMonitorDimensions
```lua
integer Width, integer Height = ray.core.GetMonitorDimensions(integer Monitor)
```
Get selected monitor dimensions


#### GetMonitorPhysicalWidth
```lua
integer Width = ray.core.GetMonitorPhysicalWidth(integer Monitor)
```
Get selected monitor physical width in millimetres


#### GetMonitorPhysicalHeight
```lua
integer Height = ray.core.GetMonitorPhysicalHeight(integer Monitor)
```
Get selected monitor physical height in millimetres


#### GetMonitorPhysicalDimensions
```lua
integer Width, integer Height = ray.core.GetMonitorPhysicalDimensions(integer Monitor)
```
Get selected monitor physical dimensions in millimetres


#### GetMonitors
```lua
table Monitors = ray.core.GetMonitors()
```
Get all monitors and it's stats using this layout:
```lua
Monitors = {
    { -- first monitor info
      string  name,    -- human-readable monitor name
      integer width,   -- monitor width in pixels
      integer height   -- monitor height in pixels
      integer pwidth,  -- monitor physical width in millimetres
      integer pheight, -- monitor physical height in millimetres
    },
    { -- second monitor
    }
  }
 ```


#### GetWindowPosition
```lua
ray_vector2 Position = ray.core.GetWindowPosition()
```
Get window position XY on monitor
See [Vector2](#Ray_vector2)


#### GetMonitorName
```lua
string Name = ray.core.GetMonitorName()
```
Get the human-readable, UTF-8 encoded name of the primary monitor


#### GetClipboardText
```lua
string Text = ray.core.GetClipboardText()
```
Get clipboard text content


#### SetClipboardText
```lua
ray.core.SetClipboardText(string Text)
```
Set clipboard text content


### Cursor-related functions
#### ShowCursor
```lua
ray.core.ShowCursor()
```
Shows cursor


#### HideCursor
```lua
ray.core.HideCursor()
```
Hides cursor


#### IsCursorHidden
```lua
boolean Status = ray.core.IsCursorHidden()
```
Check if cursor is not visible


#### EnableCursor
```lua
ray.core.EnableCursor()
```
Enables cursor (unlock cursor)


#### DisableCursor
```lua
ray.core.DisableCursor()
```
Disables cursor (lock cursor)


### Drawing-related functions
#### ClearBackground
```lua
ray.core.ClearBackground(ray_color Color)
```
Set background color (framebuffer clear color)
See [Color](#Ray_color)


#### BeginDrawing
```lua
ray.core.BeginDrawing()
```
Setup canvas (framebuffer) to start drawing


#### EndDrawing
```lua
ray.core.EndDrawing()
```
End canvas drawing and swap buffers (double buffering)


#### BeginMode2D
```lua
ray.core.BeginMode2D(ray_camera2d Camera)
```
Initialize 2D mode with custom camera (2D)
See [Camera2D](#Ray_camera2d)


#### EndMode2D
```lua
ray.core.EndMode2D()
```
Ends 2D mode with custom camera


#### BeginMode3D
```lua
ray.core.BeginMode3D(ray_camera3d Camera)
```
Initializes 3D mode with custom camera (3D)
See [Camera3D](#Ray_camera3d)


#### EndMode3D
```lua
ray.core.EndMode3D()
```
Ends 3D mode and returns to default 2D orthographic mode


#### BeginTextureMode
```lua
ray.core.BeginTextureMode(ray_rendertexture Texture)
```
Initializes render texture for drawing
See [RenderTexture](#Ray_rendertexture)


#### EndTextureMode
```lua
ray.core.EndTextureMode()
```
Ends drawing to render texture


#### BeginScissorMode
```lua
ray.core.BeginScissorMode(integer X, integer Y, integer Width, integer Height)
```
Begin scissor mode (define screen area for following drawing)


#### EndScissorMode
```lua
ray.core.EndScissorMode()
```
End scissor mode


# Classes

## Ray_vector2
### Initialization
```lua
-- variadic
ray_vector2 vec = ray.Vector2(number x, number y) --> vec2[x, y]
ray_vector2 vec = ray.Vector2(number x) --> vec2[x, x]
ray_vector2 vec = ray.Vector2(table t) vec2[t[1], t[2]]
```
Creates new Vector2 object.


### Methods

#### Clone
```lua
Vector2 = Vector2:clone()
```
Clones Vector2 object.


#### Get
```lua
-- variadic
float x, float y = Vector2:get()
table t = Vector2:get('t') --> {x, y}
```
Get Vector2 components.


#### Set variants
```lua
float x, float y = Vector2:get()
table t = Vector2:get('t') --> {x, y}
```
Set Vector2 components.
