cmake_minimum_required(VERSION 3.24.2)
project(BeatFlipper)

set(CMAKE_CXX_STANDARD 23)

# Removed -ld_classic to prevent linking issues
set(CMAKE_EXE_LINKER_FLAGS "")

add_executable(BeatFlipper
        Main.cpp
        Download.cpp
        OutputColors.cpp
        GlobalVariables.cpp
        UtilityTool.cpp
        ../include/Download.h
        ../include/OutputColors.h
        ../include/GlobalVariables.h
        ../include/UtilityTool.h)

# Explicitly link against libstdc++
target_link_libraries(BeatFlipper stdc++)