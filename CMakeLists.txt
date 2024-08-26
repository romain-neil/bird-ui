cmake_minimum_required(VERSION 3.29)
project(bird_ui)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(CMAKE_PREFIX_PATH "/Users/romain/Qt/6.7.2/macos/lib/cmake")
set(QT_VERSION 6)
set(REQUIRED_LIBS Core Gui Widgets)
set(REQUIRED_LIBS_QUALIFIED Qt6::Core Qt6::Gui Qt6::Widgets ssh)

find_package(Qt${QT_VERSION} COMPONENTS ${REQUIRED_LIBS} REQUIRED)

find_package(libssh CONFIG REQUIRED)

set(UIS src/ui/bgpPeerUI.ui)

qt6_wrap_ui(UI_HEADERS ${UIS})

add_executable(bird_ui main.cpp
        ${UI_HEADERS}

        src/window/MainWindow.cpp
        src/window/MainWindow.h
        src/service/BirdConfigService.cpp
        src/service/BirdConfigService.h
        src/Object/BirdConfigObject.cpp
        src/Object/BirdConfigObject.h
        src/Object/PeerObject.cpp
        src/Object/PeerObject.h
        src/Object/AbstractBirdObject.h
        src/window/RouteWindow.cpp
        src/window/RouteWindow.h
        src/models/RouteTableModel.cpp
        src/models/RouteTableModel.h
        src/models/InterfaceTableModel.cpp
        src/models/InterfaceTableModel.h
        src/window/BgpPeersWindow.cpp
        src/window/BgpPeersWindow.h
        src/window/BgpPeerWindow.cpp
        src/window/BgpPeerWindow.h
        src/window/InterfacesWindow.cpp
        src/window/InterfacesWindow.h
        src/service/CommandService.cpp
        src/service/CommandService.h
        src/service/SshService.cpp
        src/service/SshService.h
        src/models/Interface.h
        src/thread/LoadInterfacesThread.cpp
        src/thread/LoadInterfacesThread.h
)

target_link_libraries(${PROJECT_NAME} ${REQUIRED_LIBS_QUALIFIED})

if (WIN32)
    set(DEBUG_SUFFIX)
    if (CMAKE_BUILD_TYPE MATCHES "Debug")
        set(DEBUG_SUFFIX "d")
    endif ()
    if (EXISTS "${QT_DIR_PATH}/../../plugins/platforms/qwindows${DEBUG_SUFFIX}.dll")
        add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E make_directory
                "$<TARGET_FILE_DIR:${PROJECT_NAME}>/plugins/platforms/")
        add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E copy
                "${QT_DIR_PATH}/../../plugins/platforms/qwindows${DEBUG_SUFFIX}.dll"
                "$<TARGET_FILE_DIR:${PROJECT_NAME}>/plugins/platforms/")
    endif ()
    foreach (QT_LIB ${REQUIRED_LIBS})
        add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E copy
                "${QT_DIR_PATH}/../../bin/Qt${QT_VERSION}${QT_LIB}${DEBUG_SUFFIX}.dll"
                "$<TARGET_FILE_DIR:${PROJECT_NAME}>")
    endforeach (QT_LIB)
endif ()