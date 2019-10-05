# Terminal Absolute Control and Owning
Take the control back over your terminal.

TACO implements utilities that ease the development of terminal applications, games, and other.

# Building it manually
## Install CMake
- Debian/Ubuntu: `sudo apt-get install cmake`
- MacOS (Brew): `brew install cmake`
- Windows: https://cmake.org/download/

## Get the source
```bash
git clone https://github.com/assimp/assimp.git
```
or via `git submodule`:
```bash
git submodule add https://github.com/quantumsheep/taco.git
```

## Configure TACO inside a CMakeLists.txt file
```cmake
set(TACO_PATH taco)

add_subdirectory(${TACO_PATH})
include_directories(${TACO_PATH}/include)
```

### Link with `taco` (equivalent of `-ltaco`)
```cmake
target_link_libraries(${PROJECT_NAME} taco)
```
