cmake_minimum_required(VERSION 3.10)
project(MyProject VERSION 1.0)

# Стандарт C++
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Флаги компиляции
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -pedantic")

# Поиск исходников
file(GLOB SOURCES "src/*.cpp")

# Создание исполняемого файла
add_executable(program ${SOURCES})

# Директории с заголовочными файлами
target_include_directories(program PRIVATE include)

# Опции для отладки
option(DEBUG_MODE "Enable debug mode" OFF)
if(DEBUG_MODE)
    set(CMAKE_BUILD_TYPE Debug)
    target_compile_definitions(program PRIVATE DEBUG)
endif()