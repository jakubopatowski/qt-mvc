cmake_minimum_required(VERSION 3.20)

project(helloworld VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
#set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

if(CMAKE_VERSION VERSION_LESS "3.7.0")
    set(CMAKE_INCLUDE_CURRENT_DIR ON)
endif()

set(CMAKE_PREFIX_PATH "d:\\Qt5\\5.14.2\\msvc2017_64")
find_package(Qt5 COMPONENTS Widgets Gui REQUIRED)

add_executable(helloworld
    src/main.cpp
    src/MainWindow.cpp
    src/MainWindow.hpp
    src/MainWindow.ui
    src/PersonalInfo.cpp
    src/PersonalInfo.hpp
    src/PersonalModel.cpp
    src/PersonalModel.hpp
    src/PersonalWidget.cpp
    src/PersonalWidget.hpp
    src/PersonalWidget.ui
)

target_link_libraries(helloworld Qt5::Widgets Qt5::Gui)