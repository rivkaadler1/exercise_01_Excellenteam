
cmake_minimum_required (VERSION 3.15)

project ("ex01_project01")
set (CMAKE_CXX_STANDARD 20)
set (CMAKE_CXX_STANDARD_REQUIRED ON)
set (CMAKE_CXX_EXTENSIONS OFF)
if (MSVC)
add_compile_options (/W4 /permi"src/ex01_project01.cpp"stexpr /Zc:inline)
endif ()

add_executable (ex01_project01 )
add_subdirectory (include)
add_subdirectory (src)
