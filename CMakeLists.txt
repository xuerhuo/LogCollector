cmake_minimum_required(VERSION 3.7)
project(LogCollector)

set(CMAKE_CXX_STANDARD 11)
set(SOURCE_FILES LogCollector.cpp LogCollector.h Tools.cpp Tools.h FileTools.cpp FileTools.h OutPut.cpp OutPut.h ./lib/hiredis/hiredis.h base64.cpp base64.h)
add_executable(LogCollector ${SOURCE_FILES})
TARGET_LINK_LIBRARIES(LogCollector /home/erhuo/CLionProjects/LogCollector/lib/hiredis/libhiredis.a)