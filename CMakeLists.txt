cmake_minimum_required(VERSION 3.5)
project(mik8)

if (NOT CMAKE_BUILD_TYPE)
    message(STATUS "No build type selected, default to Release")
    set(CMAKE_BUILD_TYPE "Release")
endif ()

set(CMAKE_CXX_STANDARD 11)



set(SOURCE_FILES src/parsedexal.c src/parsedexal.h src/mik.c src/mik.h src/mikexecute.c src/mikexecute.h src/mikparse.c src/mikparse.h src/main.c)
add_executable(mik8 ${SOURCE_FILES})