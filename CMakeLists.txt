cmake_minimum_required(VERSION 3.17)

project(opengl_tutorial)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(CMAKE_BUILD_TYPE Release)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(CMAKE_CXX_FLAGS "-Wall -Wextra")
set(CMAKE_VERBOSE_MAKEFILE true)

include(FetchContent)

# Fetch glad2
FetchContent_Declare(
  glad2
  GIT_REPOSITORY https://github.com/Dav1dde/glad.git
  GIT_TAG 7a3c14c31df49b2f7f62e91d0ed4eb82379d7d6d)
FetchContent_MakeAvailable(glad2)

add_subdirectory("${glad2_SOURCE_DIR}/cmake")
glad_add_library(glad_gl_core_46 API gl:core=4.6)

#
set(PROJECT_NAME "01_HelloWindow")
add_executable(${PROJECT_NAME} src/${PROJECT_NAME}/${PROJECT_NAME}.cpp)
target_link_libraries(${PROJECT_NAME} PRIVATE glfw glad_gl_core_46)

set(PROJECT_NAME "02_HelloTriangle")
add_executable(${PROJECT_NAME} src/${PROJECT_NAME}/${PROJECT_NAME}.cpp)
target_link_libraries(${PROJECT_NAME} PRIVATE glfw glad_gl_core_46)
