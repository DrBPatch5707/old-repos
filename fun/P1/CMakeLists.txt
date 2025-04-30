cmake_minimum_required(VERSION 3.10)
project(P1)

set(CMAKE_CXX_STANDARD 17)

add_subdirectory("/nix/store/rd1fs4rhah7msz41q867ng37xx099dx0-SDL2-2.30.6/lib")
# Directly specify include directory for SDL2
include_directories("/nix/store/rd1fs4rhah7msz41q867ng37xx099dx0-SDL2-2.30.6/lib")

# Directly specify library directory for SDL2
link_directories("/nix/store/rd1fs4rhah7msz41q867ng37xx099dx0-SDL2-2.30.6/lib")

# Define your executable target
add_executable(${PROJECT_NAME} main.cpp) # Replace main.cpp with your source file(s)

# Link against the SDL2 library
target_link_libraries(${PROJECT_NAME} SDL2)