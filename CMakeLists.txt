cmake_minimum_required(VERSION 3.20)

project(abyss)

set_property(GLOBAL PROPERTY USE_FOLDERS ON)


set(${PROJECT_NAME}_VERSION_MAJOR 0)
set(${PROJECT_NAME}_VERSION_MINOR 1)

#set(CMAKE_OSX_ARCHITECTURES "arm64;x86_64")

add_subdirectory(libabyss)
add_subdirectory(abyssengine)
add_subdirectory(abysstoolset)
