# ADVANCED ORIENTED OBJECT PROGRAMMING :computer:

## LESSON TRACKING :memo:

### :pill: LEVEL 1 :pill:

#### 1. Install a compiler :heavy_check_mark:
#### 2. Use an IDE :heavy_check_mark:

- <kbd>F2</kbd>     =   Rename Symbol
- <kbd>F12</kbd>    =   Go to définition
- <kbd>CTRL</kbd> + <kbd>SHIFT</kbd> + <kbd>O</kbd>    =   Look for fonction/method in a file
- <kbd>CTRL</kbd> + <kbd>P</kbd>    =   Look for a specific file
- <kbd>ALT</kbd> + <kbd>O</kbd>     =    Switch between .hpp and .cpp
- <kbd>CTRL</kbd> + <kbd>F</kbd>   =   Global research in file
- <kbd>CTRL</kbd> + <kbd>SHIFT</kbd> + <kbd>F</kbd>   =   Global research in project

#### 3. Use Git :heavy_check_mark:
#### 4. Use a debugger :heavy_check_mark:
#### 5. Use a formating tool :heavy_check_mark:
#### 6. Use a static analysers :heavy_check_mark:
#### 7. Naming :heavy_check_mark:
#### 8. Stack vs Heap :heavy_check_mark:
#### 9. Consistency in style :heavy_check_mark:

### :pill: LEVEL 2 :pill:

#### 1. Make it work, then make it good :heavy_check_mark:
#### 2. Prefer free functions :heavy_check_mark:
#### 3. Design cohesive classes :heavy_check_mark:

- Class = everything is private with getters and setters
- Struct = everithnig is public

#### 4. Use struct to group data :heavy_check_mark:
Clean instanciation of a struct:
```cpp
// DECLARATION
struct WindowConfig
{
    const char* title;
    int         initial_width               = 1280;
    int         initial_height              = 720;
    bool        cap_framerate_on_startup_if = true;
    bool        maximize_on_startup_if      = is_building_as(BuildMode::Release);
    bool        hide_on_startup_if          = false;
};
```
```cpp
// INSTANCIATION
const auto window_config = WindowConfig {
    .title                  = "Hello C++",
    .initial_width          = 500,
    .initial_height         = 500,
    .maximize_on_startup_if = true,
};
```

#### 5. Write small functions :heavy_check_mark:
#### 6. DRY : don't repeat yourself :heavy_check_mark:
#### 7. Enums :heavy_check_mark:
#### 8. Split problems in small pieces :heavy_check_mark:
**!! THINK SMALL !!** 
#### 9. Composition over Inheritance :heavy_check_mark:

### :pill: LEVEL 3 :pill:
