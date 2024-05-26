project(MyApp C CXX)
cmake_minimum_required(VERSION 3.3.2)

include(cmake/App.cmake)

set(SOURCES "src/MyApp.h"
            "src/TempCleaner.h"
            "src/TempFolder.cpp"
            "src/MyApp.cpp"
            "src/TempCleaner.cpp"
            "src/main.cpp")

add_app("${SOURCES}")