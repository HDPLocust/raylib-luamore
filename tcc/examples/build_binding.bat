tcc -o luaray.exe luaray.c -std=c99 -Wall -lmsvcrt -lraylib -lopengl32 -lgdi32 -lkernel32 -lshell32 -luser32 -lwinmm -Wl,-subsystem=gui
luaray