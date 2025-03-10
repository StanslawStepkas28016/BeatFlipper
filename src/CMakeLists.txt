cmake_minimum_required(VERSION 3.24.2)
project(BeatFlipper)

set(CMAKE_CXX_STANDARD 23)

# Do zakomentowania, podczas kompilowania na MacOs
set(CMAKE_EXE_LINKER_FLAGS "-static")

add_executable(BeatFlipper
        Main.cpp
        Downloader.cpp
        OutputColors.cpp
        GlobalVariables.cpp
        UtilityTool.cpp
        ../include/Downloader.h
        ../include/OutputColors.h
        ../include/GlobalVariables.h
        ../include/UtilityTool.h)