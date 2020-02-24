..\..\tcc\tcc.exe -c core.c -o .\build\core.o -Iexternal/glfw/include -std=c99 -Wall -DPLATFORM_DESKTOP -DSTBI_NO_SIMD -DGRAPHICS_API_OPENGL_33
..\..\tcc\tcc.exe -c rglfw.c -o .\build\rglfw.o -std=c99 -Wall -DPLATFORM_DESKTOP -DSTBI_NO_SIMD
..\..\tcc\tcc.exe -c shapes.c -o .\build\shapes.o -std=c99 -Wall -DPLATFORM_DESKTOP -DSTBI_NO_SIMD
..\..\tcc\tcc.exe -c textures.c -o .\build\textures.o -std=c99 -Wall -DPLATFORM_DESKTOP -DSTBI_NO_SIMD
..\..\tcc\tcc.exe -c text.c -o .\build\text.o -std=c99 -Wall -DPLATFORM_DESKTOP -DSTBI_NO_SIMD
..\..\tcc\tcc.exe -c models.c -o .\build\models.o -std=c99 -Wall -DPLATFORM_DESKTOP -DSTBI_NO_SIMD
..\..\tcc\tcc.exe -c raudio.c -o .\build\raudio.o -std=c99 -Wall -DPLATFORM_DESKTOP -DSTBI_NO_SIMD -DMAL_NO_WASAPI
..\..\tcc\tcc.exe -c utils.c -o .\build\utils.o -std=c99 -Wall -DPLATFORM_DESKTOP -DSTBI_NO_SIMD

..\..\tcc\tcc.exe -ar rcs ..\..\lib\libraylib.a .\build\core.o .\build\rglfw.o .\build\shapes.o .\build\textures.o .\build\text.o .\build\models.o .\build\raudio.o .\build\utils.o
..\..\tcc\tcc.exe -ar rcs ..\..\lib\build\libraylib.lib .\build\core.o .\build\rglfw.o .\build\shapes.o .\build\textures.o .\build\text.o .\build\models.o .\build\raudio.o .\build\utils.o
..\..\tcc\tcc.exe -shared .\build\libraylib.a .\build\core.o .\build\rglfw.o .\build\shapes.o .\build\textures.o .\build\text.o .\build\models.o .\build\raudio.o .\build\utils.o