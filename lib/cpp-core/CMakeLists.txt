PROJECT(cpp-ui VERSION 1.0.0.0 LANGUAGES CXX)

SET(LIB_NAME cpp-core)

INCLUDE_DIRECTORIES (
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

ADD_LIBRARY(${LIB_NAME} STATIC 
    src/core.cpp
    src/gameObject.cpp
    src/displayableObject.cpp
    src/scene.cpp
    src/sceneManager.cpp
    src/input.cpp
    src/inputManager.cpp
    src/pair.cpp
    src/textObject.cpp
    src/camera.cpp
)

TARGET_INCLUDE_DIRECTORIES(${LIB_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

TARGET_LINK_LIBRARIES(${LIB_NAME} PUBLIC sfml-system sfml-graphics sfml-window)