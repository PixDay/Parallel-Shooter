CMAKE_MINIMUM_REQUIRED(VERSION 3.10)

PROJECT(APP)

SET(CMAKE_CXX_STANDARD 20)
SET(CMAKE_CXX_STANDARD_REQUIRED True)

ADD_SUBDIRECTORY(GFX)
ADD_SUBDIRECTORY(lib)

SET(APP_EXE application)

INCLUDE_DIRECTORIES (
    ${CMAKE_SOURCE_DIR}/include
    ${CMAKE_SOURCE_DIR}/lib/cpp-core/include
    ${CMAKE_SOURCE_DIR}/GFX/SFML-2.5.1/include
)

ADD_EXECUTABLE(${APP_EXE}
    source/main.cpp
    source/game.cpp
    source/menu.cpp
    source/scene.cpp
)

TARGET_LINK_LIBRARIES(${APP_EXE}
    cpp-core
)