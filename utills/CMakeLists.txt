cmake_minimum_required(VERSION 3.10) # Or higher

# Project name for your executable
project(main_project)

# Add executable
add_executable(main main.cpp)

# Link to the utils-lib.  You need to tell CMake where to find the library.
#   There are several ways to do this.  The modern way is using find_dependency
#   or IMPORTED targets.  Here's a basic approach, assuming utils-lib is built
#   in a subdirectory.

# Add the subdirectory where utils-lib's CMakeLists.txt is located.
add_subdirectory(utills-lib) #  Relative path to utils-lib

# Link the executable to the utils-lib target.
target_link_libraries(main utils-lib)

# Include directories.  If main.cpp uses headers from utils-lib,
#  you need to specify where to find them.  If you used the
#  INTERFACE_INCLUDE_DIRECTORIES property in utils-lib's CMakeLists.txt,
#  you do NOT need this, but I'm including it for clarity.
include_directories(utils-lib/include) #  Relative path to utils-lib's include

# If you have other source files in your main project, add them here, *before* add_executable
# set(MAIN_SOURCE_FILES
#     main.cpp
#     other_source.cpp
# )
# add_executable(main ${MAIN_SOURCE_FILES})
