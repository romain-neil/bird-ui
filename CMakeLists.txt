cmake_minimum_required(VERSION 3.29)
project(bird_ui)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(CMAKE_PREFIX_PATH "/Users/romain/Qt/6.7.2/macos/lib/cmake")

find_package(Qt6 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

add_executable(bird_ui main.cpp)
target_link_libraries(bird_ui
        Qt::Core
        Qt::Gui
        Qt::Widgets
)

