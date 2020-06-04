cmake_minimum_required(VERSION 3.16)
project(base_datastruct)

set(CMAKE_CXX_STANDARD 14)

file (GLOB files wangdao/*/*.cpp jianzhioffer/*/*.cpp)
foreach (file ${files})
string(REGEX REPLACE ".+/(.+)\\..*" "\\1" exe ${file})
add_executable (${exe} ${file}
        wangdao/chapter04/SString.cpp wangdao/chapter04/SString.h)
message (\ \ \ \ --\ wangdao/*/${exe}.cpp\  will\ be\ compiled\ to\ bin/${exe})
endforeach ()