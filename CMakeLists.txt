cmake_minimum_required(VERSION 3.27)
project(sandgobrrrdown)

set(CMAKE_CXX_STANDARD 17)

include_directories("C:\\Dev\\C++Libraries\\glfw-3.4.bin.WIN64\\include")

include_directories("C:\\Dev\\C++Libraries\\glm")
include_directories("C:\\Dev\\C++Libraries\\glm\\detail")
include_directories("C:\\Dev\\C++Libraries\\glm\\ext")
include_directories("C:\\Dev\\C++Libraries\\glm\\gtc")
include_directories("C:\\Dev\\C++Libraries\\glm\\gtx")
include_directories("C:\\Dev\\C++Libraries\\glm\\simd")

find_package(Vulkan REQUIRED)

add_executable(sandgobrrrdown main.cpp
        Elements/Element.h
        Elements/Behaviours/MovementBehaviours.h
        Elements/Element.cpp
        Elements/Behaviours/MovementBehaviours.cpp
        Game.cpp
        Game.h
        Elements/Coordinates.h
        Elements/Behaviours/DisplayBehaviours.h
        Graphics/Vulkan.cpp
)