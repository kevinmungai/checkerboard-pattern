cmake_minimum_required(VERSION 3.7)

set(PROJECT_NAME
        "checkers"
        )



set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES main.cpp)

find_package(GLUT REQUIRED)

find_package(OpenGL REQUIRED)

include_directories(${OPENGL_INCLUDE_DIRS} ${GLUT_INCLUDE_DIRS})

add_executable(${PROJECT_NAME} ${SOURCE_FILES})

target_link_libraries(${PROJECT_NAME} ${OPENGL_LIBRARIES} ${GLUT_LIBRARY})