cmake_minimum_required(VERSION 3.16)
project(base_datastruct)

set(CMAKE_CXX_STANDARD 14)

file (GLOB files wangdao/*/*.cpp jianzhioffer/*/*.cpp)
foreach (file ${files})
string(REGEX REPLACE ".+/(.+)\\..*" "\\1" exe ${file})
add_executable (${exe} ${file}
        wangdao/chapter02/DLinkList.cpp
        wangdao/chapter02/SLinkList.cpp
        wangdao/chapter02/Exercises2_2.cpp
        wangdao/chapter08/Sort.cpp)
message (\ \ \ \ --\ wangdao/*/${exe}.cpp\  will\ be\ compiled\ to\ bin/${exe})
endforeach ()