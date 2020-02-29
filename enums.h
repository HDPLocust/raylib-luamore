/*!MD
## Enums
### eKeyboard.
Any keyboard function accepts string or integer key representation.
Representation layout:

| integer                  | string     | description
| :------                  | :--------- | :-----------
| **Character keys**       |            |
| -1                       | unknown    | The pressed key is unknown (used if user tries to use unknown string as key)
| 32                       | space      | Space key
| 39                       | '          | Single quote key
| 44                       | ,          | Comma key
| 45                       | -          | Hyphen-minus key
| 46                       | .          | Full stop key
| 47                       | /          | Slash key
| 48                       | 0          | The zero key
| 49                       | 1          | The one key
| 50                       | 2          | The two key
| 51                       | 3          | The three key
| 52                       | 4          | The four key
| 53                       | 5          | The five key
| 54                       | 6          | The six key
| 55                       | 7          | The seven key
| 56                       | 8          | The eight key
| 57                       | 9          | The nine key
| 59                       | ;          | Semicolon key
| 61                       | =          | Equal key
| 65                       | a          | The A key
| 66                       | b          | The B key
| 67                       | c          | The C key
| 68                       | d          | The D key
| 69                       | e          | The E key
| 70                       | f          | The F key
| 71                       | g          | The G key
| 72                       | h          | The H key
| 73                       | i          | The I key
| 74                       | j          | The J key
| 75                       | k          | The K key
| 76                       | l          | The L key
| 77                       | m          | The M key
| 78                       | n          | The N key
| 79                       | o          | The O key
| 80                       | p          | The P key
| 81                       | q          | The Q key
| 82                       | r          | The R key
| 83                       | s          | The S key
| 84                       | t          | The T key
| 85                       | u          | The U key
| 86                       | v          | The V key
| 87                       | w          | The W key
| 88                       | x          | The X key
| 89                       | y          | The Y key
| 90                       | z          | The Z key
| 91                       | \[         | Left square bracket key
| 92                       | \\         | Backslash key
| 93                       | \]         | Right square bracket key
| 96                       | \`         | Grave accent key, also known as the "Back tick" key
| **Editing keys**         |            | 
| 258                      | tab        | Tab key
| 259                      | backspace  | Backspace key
| 260                      | insert     | Insert key
| 261                      | delete     | Delete key
| **Navigation keys**      |            |
| 256                      | escape     | Escape key
| 257                      | enter      | Enter key, also known as the Return key
| 257                      | return     | Return key, also known as the Enter key
| 262                      | right      | Right arrow key
| 263                      | left       | Left arrow key
| 264                      | down       | Down arrow key
| 265                      | up         | Up arrow key
| 266                      | pageup     | Page up key
| 267                      | pagedown   | Page down key
| 268                      | home       | Home key
| 269                      | end        | End key
| **Miscellaneous keys**   |            |
| 280                      | capslock   | Caps-lock key, caps-on is a key press. Caps-off is a key release.
| 281                      | scrolllock | Scroll-lock key
| 282                      | numlock    | Num-lock key, clear on Mac keyboards.
| 283                      | prtscr     | Printscreen key
| 284                      | pause      | Pause key
| 348                      | menu       | Menu key
| **Function keys**        |            |
| 290                      | f1         | 
| 291                      | f2         | 
| 292                      | f3         | 
| 293                      | f4         | 
| 294                      | f5         | 
| 295                      | f6         | 
| 296                      | f7         | 
| 297                      | f8         | 
| 298                      | f9         | 
| 299                      | f10        | 
| 300                      | f11        | 
| 301                      | f12        | 
| **Modifier keys**        |            |
| 340                      | lshift     | Left shift key
| 341                      | lctrl      | Left control key
| 342                      | lalt       | Left alt key
| 343                      | lsuper     | Left command key in OS X, Windows key in Windows.
| 344                      | rshift     | Right shift key
| 345                      | rctrl      | Right control key
| 346                      | ralt       | Right alt key
| 347                      | rsuper     | Right command key in OS X, Windows key in Windows.
| **Numpad keys**          |            |
| 320                      | kp0        | The numpad zero key
| 321                      | kp1        | The numpad one key
| 322                      | kp2        | The numpad two key
| 323                      | kp3        | The numpad three key
| 324                      | kp4        | The numpad four key
| 325                      | kp5        | The numpad five key
| 326                      | kp6        | The numpad six key
| 327                      | kp7        | The numpad seven key
| 328                      | kp8        | The numpad eight key
| 329                      | kp9        | The numpad nine key
| 330                      | kp.        | The numpad decimal point key	
| 331                      | kp/        | The numpad division key
| 332                      | kp*        | The numpad multiplication key	
| 333                      | kp-        | The numpad substraction key	
| 334                      | kp+        | The numpad addition key
| 335                      | kpenter    | The numpad enter key
| 336                      | kp=        | The numpad equals key	

Translating of representations provides by `rl.ekey` table:
```lua
key = "space"
ikey = rl.ekey[key]  --> 32
skey = rl.ekey[ikey] --> "space"
```
This table is used internally in the library, so do not modify it if you don't know what is happens.
*/

int ray_lua_enum_key;
void luaray_exportKeyboardKeys(lua_State * L){
  lua_newtable(L);
  ray_lua_enum_key = lua_ref(L, -1);
  lua_rawgeti(L, LUA_REGISTRYINDEX, ray_lua_enum_key);
  luax_tsnumber(L, "unknown",  -1);                   luax_tnstring(L, -1,                "unknown");
  luax_tsnumber(L, "'",  KEY_APOSTROPHE);             luax_tnstring(L, KEY_APOSTROPHE,    "'");
  luax_tsnumber(L, ",",  KEY_COMMA);                  luax_tnstring(L, KEY_COMMA,         ",");
  luax_tsnumber(L, "-",  KEY_MINUS);                  luax_tnstring(L, KEY_MINUS,         "-");
  luax_tsnumber(L, ".",  KEY_PERIOD);                 luax_tnstring(L, KEY_PERIOD,        ".");
  luax_tsnumber(L, "/",  KEY_SLASH);                  luax_tnstring(L, KEY_SLASH,         "/");
  luax_tsnumber(L, "0",  KEY_ZERO);                   luax_tnstring(L, KEY_ZERO,          "0");
  luax_tsnumber(L, "1",  KEY_ONE);                    luax_tnstring(L, KEY_ONE,           "1");
  luax_tsnumber(L, "2",  KEY_TWO);                    luax_tnstring(L, KEY_TWO,           "2");
  luax_tsnumber(L, "3",  KEY_THREE);                  luax_tnstring(L, KEY_THREE,         "3");
  luax_tsnumber(L, "4",  KEY_FOUR);                   luax_tnstring(L, KEY_FOUR,          "4");
  luax_tsnumber(L, "5",  KEY_FIVE);                   luax_tnstring(L, KEY_FIVE,          "5");
  luax_tsnumber(L, "6",  KEY_SIX);                    luax_tnstring(L, KEY_SIX,           "6");
  luax_tsnumber(L, "7",  KEY_SEVEN);                  luax_tnstring(L, KEY_SEVEN,         "7");
  luax_tsnumber(L, "8",  KEY_EIGHT);                  luax_tnstring(L, KEY_EIGHT,         "8");
  luax_tsnumber(L, "9",  KEY_NINE);                   luax_tnstring(L, KEY_NINE,          "9");
  luax_tsnumber(L, ";",  KEY_SEMICOLON);              luax_tnstring(L, KEY_SEMICOLON,     ";");
  luax_tsnumber(L, "=",  KEY_EQUAL);                  luax_tnstring(L, KEY_EQUAL,         "=");
  luax_tsnumber(L, "a",  KEY_A);                      luax_tnstring(L, KEY_A,             "a");
  luax_tsnumber(L, "b",  KEY_B);                      luax_tnstring(L, KEY_B,             "b");
  luax_tsnumber(L, "c",  KEY_C);                      luax_tnstring(L, KEY_C,             "c");
  luax_tsnumber(L, "d",  KEY_D);                      luax_tnstring(L, KEY_D,             "d");
  luax_tsnumber(L, "e",  KEY_E);                      luax_tnstring(L, KEY_E,             "e");
  luax_tsnumber(L, "f",  KEY_F);                      luax_tnstring(L, KEY_F,             "f");
  luax_tsnumber(L, "g",  KEY_G);                      luax_tnstring(L, KEY_G,             "g");
  luax_tsnumber(L, "h",  KEY_H);                      luax_tnstring(L, KEY_H,             "h");
  luax_tsnumber(L, "i",  KEY_I);                      luax_tnstring(L, KEY_I,             "i");
  luax_tsnumber(L, "j",  KEY_J);                      luax_tnstring(L, KEY_J,             "j");
  luax_tsnumber(L, "k",  KEY_K);                      luax_tnstring(L, KEY_K,             "k");
  luax_tsnumber(L, "l",  KEY_L);                      luax_tnstring(L, KEY_L,             "l");
  luax_tsnumber(L, "m",  KEY_M);                      luax_tnstring(L, KEY_M,             "m");
  luax_tsnumber(L, "n",  KEY_N);                      luax_tnstring(L, KEY_N,             "n");
  luax_tsnumber(L, "o",  KEY_O);                      luax_tnstring(L, KEY_O,             "o");
  luax_tsnumber(L, "p",  KEY_P);                      luax_tnstring(L, KEY_P,             "p");
  luax_tsnumber(L, "q",  KEY_Q);                      luax_tnstring(L, KEY_Q,             "q");
  luax_tsnumber(L, "r",  KEY_R);                      luax_tnstring(L, KEY_R,             "r");
  luax_tsnumber(L, "s",  KEY_S);                      luax_tnstring(L, KEY_S,             "s");
  luax_tsnumber(L, "t",  KEY_T);                      luax_tnstring(L, KEY_T,             "t");
  luax_tsnumber(L, "u",  KEY_U);                      luax_tnstring(L, KEY_U,             "u");
  luax_tsnumber(L, "v",  KEY_V);                      luax_tnstring(L, KEY_V,             "v");
  luax_tsnumber(L, "w",  KEY_W);                      luax_tnstring(L, KEY_W,             "w");
  luax_tsnumber(L, "x",  KEY_X);                      luax_tnstring(L, KEY_X,             "x");
  luax_tsnumber(L, "y",  KEY_Y);                      luax_tnstring(L, KEY_Y,             "y");
  luax_tsnumber(L, "z",  KEY_Z);                      luax_tnstring(L, KEY_Z,             "z");
  luax_tsnumber(L, "[",  KEY_LEFT_BRACKET);           luax_tnstring(L, KEY_LEFT_BRACKET,  "[");
  luax_tsnumber(L, "\\", KEY_BACKSLASH);              luax_tnstring(L, KEY_BACKSLASH,     "\\");
  luax_tsnumber(L, "]",  KEY_RIGHT_BRACKET);          luax_tnstring(L, KEY_RIGHT_BRACKET, "]");
  luax_tsnumber(L, "`",  KEY_GRAVE);                  luax_tnstring(L, KEY_GRAVE,         "`");

  // Function keys
  luax_tsnumber(L, "space",      KEY_SPACE);          luax_tnstring(L, KEY_SPACE,         "space");
  luax_tsnumber(L, "escape",     KEY_ESCAPE);         luax_tnstring(L, KEY_ESCAPE,        "escape");
  luax_tsnumber(L, "enter",      KEY_ENTER);          luax_tnstring(L, KEY_ENTER,         "enter");
  luax_tsnumber(L, "return",     KEY_ENTER);          // same as enter
  luax_tsnumber(L, "tab",        KEY_TAB);            luax_tnstring(L, KEY_TAB,           "tab");
  luax_tsnumber(L, "backspace",  KEY_BACKSPACE);      luax_tnstring(L, KEY_BACKSPACE,     "backspace");
  luax_tsnumber(L, "insert",     KEY_INSERT);         luax_tnstring(L, KEY_INSERT,        "insert");
  luax_tsnumber(L, "delete",     KEY_DELETE);         luax_tnstring(L, KEY_DELETE,        "delete");
  luax_tsnumber(L, "right",      KEY_RIGHT);          luax_tnstring(L, KEY_RIGHT,         "right");
  luax_tsnumber(L, "left",       KEY_LEFT);           luax_tnstring(L, KEY_LEFT,          "left");
  luax_tsnumber(L, "down",       KEY_DOWN);           luax_tnstring(L, KEY_DOWN,          "down");
  luax_tsnumber(L, "up",         KEY_UP);             luax_tnstring(L, KEY_UP,            "up");
  luax_tsnumber(L, "pageup",     KEY_PAGE_UP);        luax_tnstring(L, KEY_PAGE_UP,       "pageup");
  luax_tsnumber(L, "pagedown",   KEY_PAGE_DOWN);      luax_tnstring(L, KEY_PAGE_DOWN,     "pagedown");
  luax_tsnumber(L, "home",       KEY_HOME);           luax_tnstring(L, KEY_HOME,          "home");
  luax_tsnumber(L, "end",        KEY_END);            luax_tnstring(L, KEY_END,           "end");
  luax_tsnumber(L, "capslock",   KEY_CAPS_LOCK);      luax_tnstring(L, KEY_CAPS_LOCK,     "capslock");
  luax_tsnumber(L, "scrolllock", KEY_SCROLL_LOCK);    luax_tnstring(L, KEY_SCROLL_LOCK,   "scrolllock");
  luax_tsnumber(L, "numlock",    KEY_NUM_LOCK);       luax_tnstring(L, KEY_NUM_LOCK,      "numlock");
  luax_tsnumber(L, "prtscr",     KEY_PRINT_SCREEN);   luax_tnstring(L, KEY_PRINT_SCREEN,  "prtscr");
  luax_tsnumber(L, "pause",      KEY_PAUSE);          luax_tnstring(L, KEY_PAUSE,         "pause");
  luax_tsnumber(L, "f1",         KEY_F1);             luax_tnstring(L, KEY_F1,            "f1");
  luax_tsnumber(L, "f2",         KEY_F2);             luax_tnstring(L, KEY_F2,            "f2");
  luax_tsnumber(L, "f3",         KEY_F3);             luax_tnstring(L, KEY_F3,            "f3");
  luax_tsnumber(L, "f4",         KEY_F4);             luax_tnstring(L, KEY_F4,            "f4");
  luax_tsnumber(L, "f5",         KEY_F5);             luax_tnstring(L, KEY_F5,            "f5");
  luax_tsnumber(L, "f6",         KEY_F6);             luax_tnstring(L, KEY_F6,            "f6");
  luax_tsnumber(L, "f7",         KEY_F7);             luax_tnstring(L, KEY_F7,            "f7");
  luax_tsnumber(L, "f8",         KEY_F8);             luax_tnstring(L, KEY_F8,            "f8");
  luax_tsnumber(L, "f9",         KEY_F9);             luax_tnstring(L, KEY_F9,            "f9");
  luax_tsnumber(L, "f10",        KEY_F10);            luax_tnstring(L, KEY_F10,           "f10");
  luax_tsnumber(L, "f11",        KEY_F11);            luax_tnstring(L, KEY_F11,           "f11");
  luax_tsnumber(L, "f12",        KEY_F12);            luax_tnstring(L, KEY_F12,           "f12");
  luax_tsnumber(L, "lshift",     KEY_LEFT_SHIFT);     luax_tnstring(L, KEY_LEFT_SHIFT,    "lshift");
  luax_tsnumber(L, "lctrl",      KEY_LEFT_CONTROL);   luax_tnstring(L, KEY_LEFT_CONTROL,  "lctrl");
  luax_tsnumber(L, "lalt",       KEY_LEFT_ALT);       luax_tnstring(L, KEY_LEFT_ALT,      "lalt");
  luax_tsnumber(L, "lsuper",     KEY_LEFT_SUPER);     luax_tnstring(L, KEY_LEFT_SUPER,    "lsuper");
  luax_tsnumber(L, "rshift",     KEY_RIGHT_SHIFT);    luax_tnstring(L, KEY_RIGHT_SHIFT,   "rshift");
  luax_tsnumber(L, "rctrl",      KEY_RIGHT_CONTROL);  luax_tnstring(L, KEY_RIGHT_CONTROL, "rctrl");
  luax_tsnumber(L, "ralt",       KEY_RIGHT_ALT);      luax_tnstring(L, KEY_RIGHT_ALT,     "ralt");
  luax_tsnumber(L, "rsuper",     KEY_RIGHT_SUPER);    luax_tnstring(L, KEY_RIGHT_SUPER,   "rsuper");
  luax_tsnumber(L, "menu",       KEY_KB_MENU);        luax_tnstring(L, KEY_KB_MENU,       "menu");
  // Keypad keys
  luax_tsnumber(L, "kp0",        KEY_KP_0);           luax_tnstring(L, KEY_KP_0,          "kp0");
  luax_tsnumber(L, "kp1",        KEY_KP_1);           luax_tnstring(L, KEY_KP_1,          "kp1");
  luax_tsnumber(L, "kp2",        KEY_KP_2);           luax_tnstring(L, KEY_KP_2,          "kp2");
  luax_tsnumber(L, "kp3",        KEY_KP_3);           luax_tnstring(L, KEY_KP_3,          "kp3");
  luax_tsnumber(L, "kp4",        KEY_KP_4);           luax_tnstring(L, KEY_KP_4,          "kp4");
  luax_tsnumber(L, "kp5",        KEY_KP_5);           luax_tnstring(L, KEY_KP_5,          "kp5");
  luax_tsnumber(L, "kp6",        KEY_KP_6);           luax_tnstring(L, KEY_KP_6,          "kp6");
  luax_tsnumber(L, "kp7",        KEY_KP_7);           luax_tnstring(L, KEY_KP_7,          "kp7");
  luax_tsnumber(L, "kp8",        KEY_KP_8);           luax_tnstring(L, KEY_KP_8,          "kp8");
  luax_tsnumber(L, "kp9",        KEY_KP_9);           luax_tnstring(L, KEY_KP_9,          "kp9");
  luax_tsnumber(L, "kp.",        KEY_KP_DECIMAL);     luax_tnstring(L, KEY_KP_DECIMAL,    "kp.");
  luax_tsnumber(L, "kp/",        KEY_KP_DIVIDE);      luax_tnstring(L, KEY_KP_DIVIDE,     "kp/");
  luax_tsnumber(L, "kp*",        KEY_KP_MULTIPLY);    luax_tnstring(L, KEY_KP_MULTIPLY,   "kp*");
  luax_tsnumber(L, "kp-",        KEY_KP_SUBTRACT);    luax_tnstring(L, KEY_KP_SUBTRACT,   "kp-");
  luax_tsnumber(L, "kp+",        KEY_KP_ADD);         luax_tnstring(L, KEY_KP_ADD,        "kp+");
  luax_tsnumber(L, "kpenter",    KEY_KP_ENTER);       luax_tnstring(L, KEY_KP_ENTER,      "kpenter");
  luax_tsnumber(L, "kp=",        KEY_KP_EQUAL);       luax_tnstring(L, KEY_KP_EQUAL,      "kp=");
}

const char * ray_keyboard_getKeyEnumString(lua_State * L, int key){
  const char * value = "unknown";
  lua_rawgeti(L, LUA_REGISTRYINDEX, ray_lua_enum_key);
  lua_pushnumber(L, key);
  lua_gettable(L, -1);
  if (lua_isstring(L, -1)) value = luaL_checkstring(L, -1);
  lua_pop(L, 3);
  return value;
}

int ray_keyboard_getKeyEnumInteger(lua_State * L, const char * key){
  int value = -1;
  lua_rawgeti(L, LUA_REGISTRYINDEX, ray_lua_enum_key);
  lua_pushstring(L, key);
  lua_getfield(L, -1, key);
  if (lua_isnumber(L, -1)) value = luaL_checkinteger(L, -1);
  lua_pop(L, 3);
  return value;
}

int ray_keyboard_getKeyEnumFromStack(lua_State * L, int idx){
  int value = -1;
  lua_rawgeti(L, LUA_REGISTRYINDEX, ray_lua_enum_key);
  if (lua_type(L, idx) == LUA_TSTRING){
    const char * key = luaL_checkstring(L, idx);
    lua_getfield(L, -1, key);
    value = (lua_isnumber(L, -1)) ? luaL_checknumber(L, -1) : value;
    lua_pop(L, 1);
  }
  else if (lua_type(L, idx) == LUA_TNUMBER) {
    int key = luaL_checkinteger(L, idx);
    lua_rawgeti(L, -1, key);
    printf("RAWGET: %d %s\n", key, luaL_typename(L, -1));
    value = (lua_isstring(L, -1)) ? key : value;
    lua_pop(L, 1);
  }
  lua_pop(L, 1);
  return value;
}
