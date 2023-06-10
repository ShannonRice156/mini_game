cmake_minimum_required(VERSION 3.15) ##only edit if you need to use a cmake feature above 3.15
project(mini_game C CXX) #project name, compilers and languages

set(CMAKE_CXX_STANDARD 17) #c++ version i wanna use
set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>") #sets proj settings to build as debug

set_property(GLOBAL PROPERTY USE_FOLDERS on) #creates folders in visual studio to organise proj

set(SRC_DIR "${CMAKE_CURRENT_LIST_DIR}") #

# stock_api -----------------------------------------

set(SOURCE_MINI_GAME
    "${SRC_DIR}/source/include/stage.h"
    "${SRC_DIR}/source/include/window.h"
    "${SRC_DIR}/source/include/ui_helper.h"
    "source/include/geometry.h"
    "${SRC_DIR}/source/include/game_item.h"
    "${SRC_DIR}/source/include/playable_game_item.h"
    "${SRC_DIR}/source/source/stage.cpp"
    "${SRC_DIR}/source/source/game_item.cpp"
    "${SRC_DIR}/source/source/playable_game_item.cpp"
    "${SRC_DIR}/source/source/window.cpp"
    "source/source/geometry.cpp"
    "${SRC_DIR}/source/source/ui_helper.cpp" ## THESE WILL BE ALL MY FILES
)

add_library(mini_game_lib STATIC "${SOURCE_MINI_GAME}" "source/source/game_ui_item.cpp" "source/include/game_ui_item.h")

target_include_directories(mini_game_lib PUBLIC ##sets include directory to include things from
    "${SRC_DIR}/source/include/"  ##changed based on structure of code
)

set(SOURCE_MINI_GAME_EXE #creating vairable for exe
    "${SRC_DIR}/source/main.cpp"  ##changed based on structure of code
)

add_executable(mini_game_lib_exe "${SOURCE_MINI_GAME_EXE}" "source/source/game_ui_item.cpp" "source/include/game_ui_item.h") ##adding executable to project

# Third party ----------------------------------------

target_include_directories(mini_game_lib PUBLIC "${SRC_DIR}/third_party")

target_link_libraries(mini_game_lib_exe mini_game_lib)

target_include_directories(mini_game_lib PUBLIC 
    "${SRC_DIR}/source/include"
)

target_include_directories(mini_game_lib PUBLIC "${SRC_DIR}/third_party/skia/")
target_include_directories(mini_game_lib PUBLIC "${SRC_DIR}/third_party/skia/skia/")

target_link_libraries(mini_game_lib
    "${SRC_DIR}/third_party/skia/lib/Debug/skia.lib"
    opengl32.lib
)

list(APPEND CMAKE_PREFIX_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake")

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIR})

target_link_libraries(mini_game_lib ${SDL2_LIBRARIES})

add_custom_command(TARGET mini_game_lib_exe POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different 
        "${CMAKE_SOURCE_DIR}/third_party/lib/SDL2/x64/SDL2.dll"
        $<TARGET_FILE_DIR:mini_game_lib_exe>)  

target_link_libraries(
    mini_game_lib
    ${Pthread}
)
