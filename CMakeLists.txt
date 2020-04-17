cmake_minimum_required(VERSION 3.1)
project(Pengo)

#Añadir tantos subdirectorios como se necesiten
#En cada subdirectorio debe haber un fichero CMakeLists.txt
#Habitualmente cada subdirectorio determinará una libreria 
add_library(modulos STATIC)

add_subdirectory(src)

#Opciones a pasar al compilador de C++
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++1y -Wall -Wextra")
#Se desea generar un ejecutable, se especifica donde está el main
#y ficheros que aporten código que no sean librerias o subcarpetas 
add_executable(Pengo src/main.cpp)

#Añadir todos los objetos (ficheros o) que requiera el ejecutable. 
#Habitualmente todas las librerias definidas mediante subcarpetas
#aportaran código
target_link_libraries(Pengo modulos)

set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake_modules" ${CMAKE_MODULE_PATH})
#Para usar SFML
find_package(SFML REQUIRED system window graphics network audio)
if (SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(Pengo ${SFML_LIBRARIES})
endif()

set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_BUILD_TYPE RelWithDebInfo)


set(dir ${CMAKE_CURRENT_SOURCE_DIR}/bin/)
set(EXECUTABLE_OUTPUT_PATH ${dir} CACHE PATH "Build directory" FORCE)
set(LIBRARY_OUTPUT_PATH ${dir} CACHE PATH "Build directory" FORCE)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${dir})
set(CMAKE_BUILD_FILES_DIRECTORY ${dir})
set(CMAKE_BUILD_DIRECTORY ${dir})
set(CMAKE_BINARY_DIR  ${dir})
set(EXECUTABLE_OUTPUT_PATH ${dir})
set(LIBRARY_OUTPUT_PATH ${dir}lib)
set(CMAKE_CACHEFILE_DIR ${dir})