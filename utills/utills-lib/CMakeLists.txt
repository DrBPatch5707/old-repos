cmake_minimum_required(VERSION 3.10) # Or higher

# Project name for the library
project(utils-lib)

# Set the library type.  STATIC or SHARED.  A static library is usually preferred for simpler distribution.
set(LIBRARY_TYPE STATIC) # Or SHARED

# Include directories.  Crucially, you need to include the 'include'
# directory so that other projects can find your header files.
include_directories(include)

# Source files for the library.  Do NOT include header files here.
set(LIB_SOURCE_FILES
    source/errorReport.cpp
    source/loading.cpp
    # source/fileManager.cpp  (If you have a .cpp for this)
    # source/utils.cpp        (If you have a .cpp for this)
)

# Create the library.
add_library(${PROJECT_NAME} ${LIBRARY_TYPE} ${LIB_SOURCE_FILES})

#  Install the library and header files (Optional, but recommended for wider use)
install(TARGETS ${PROJECT_NAME}
    ARCHIVE DESTINATION lib # Where the .a or .lib file goes
    # For shared libraries, you might also need to install RUNTIME
)
install(DIRECTORY include/ # Install the whole include directory
    DESTINATION include
    FILES_MATCHING PATTERN "*.hpp" # Only install header files
)

# Set include directories property for dependent projects.
# This makes it easier for other projects to use this library.
set_target_properties(${PROJECT_NAME} PROPERTIES
    INTERFACE_INCLUDE_DIRECTORIES "${CMAKE_INSTALL_PREFIX}/include"
)
