cmake_minimum_required (VERSION 3.22)

add_subdirectory(../Catch2 Catch2-build)

# Файлы взятые из туториала
add_executable(MyTest2 source.cpp)
target_link_libraries(MyTest2 PRIVATE Catch2::Catch2)