cmake_minimum_required(VERSION 3.22.1)

project(opengl-app)

include(FetchContent)
set(BUILD_SHARED_LIBS OFF)

# glfw
FetchContent_Declare(
    glfw3
    GIT_REPOSITORY https://github.com/glfw/glfw.git
)
FetchContent_MakeAvailable(glfw3)

# glad
add_library(glad deps/glad/glad.h deps/glad/glad.c)

# build
add_executable(
    opengl-app
    src/main.cpp
    src/Shader.cpp
    src/ShaderProgram.cpp
)
target_include_directories(
    opengl-app
    PRIVATE
    include
    deps
    deps/glm
)

target_link_libraries(
    opengl-app
    PRIVATE
    GL
    glad
    glfw
)

