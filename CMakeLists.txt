set(CMAKE_CXX_STANDARD 17)
#set(CMAKE_CXX_STANDARD_Required ON)
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++2a")


cmake_minimum_required(VERSION 3.20)
project(Khayon_Arknights)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOUIC_SEARCH_PATHS src/Khayon_Gui)
#set(CMAKE_PREFIX_PATH "E:/toolchains/Cygwin/bin/cmake")
#set(Qt6_DIR "E:/Env/Qt/6.2.1/mingw81_64/lib/cmake")
set(CMAKE_PREFIX_PATH "E:/Env/Qt/6.2.1/mingw81_64/lib/cmake")
find_package(Qt6 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

add_executable(Khayon_Arknights main.cpp src/Khayon_Gui/khayon.cpp src/Khayon_Gui/khayon.h src/Khayon_Gui/khayon.ui src/Khayon_Assistant/Recruitment.cpp src/Khayon_Assistant/Recruitment.h src/Khayon_Assistant/OperatorInfo.cpp src/Khayon_Assistant/OperatorInfo.h src/Khayon_Assistant/debug.hpp src/Khayon_Assistant/util.h)
target_link_libraries(Khayon_Arknights
        Qt::Core
        Qt::Gui
        Qt::Widgets
        )


if (WIN32)
    set(DEBUG_SUFFIX)
    if (CMAKE_BUILD_TYPE MATCHES "Debug" AND QT_VERSION LESS_EQUAL 5 AND QT_MINOR_VERSION LESS 14)
        set(DEBUG_SUFFIX "d")
    endif ()
    set(QT_INSTALL_PATH "${CMAKE_PREFIX_PATH}")
    if (NOT EXISTS "${QT_INSTALL_PATH}/bin")
        set(QT_INSTALL_PATH "${QT_INSTALL_PATH}/..")
        if (NOT EXISTS "${QT_INSTALL_PATH}/bin")
            set(QT_INSTALL_PATH "${QT_INSTALL_PATH}/..")
        endif ()
    endif ()
    if (EXISTS "${QT_INSTALL_PATH}/plugins/platforms/qwindows${DEBUG_SUFFIX}.dll")
        add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E make_directory
                "$<TARGET_FILE_DIR:${PROJECT_NAME}>/plugins/platforms/")
        add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E copy
                "${QT_INSTALL_PATH}/plugins/platforms/qwindows${DEBUG_SUFFIX}.dll"
                "$<TARGET_FILE_DIR:${PROJECT_NAME}>/plugins/platforms/")
    endif ()
    foreach (QT_LIB Core Gui Widgets)
        add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E copy
                "${QT_INSTALL_PATH}/bin/Qt6${QT_LIB}${DEBUG_SUFFIX}.dll"
                "$<TARGET_FILE_DIR:${PROJECT_NAME}>")
    endforeach (QT_LIB)
endif ()
