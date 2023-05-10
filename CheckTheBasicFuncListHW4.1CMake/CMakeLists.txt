cmake_minimum_required (VERSION 3.22)

add_subdirectory(../Catch2 Catch2-build)

# Файлы взятые из туториала
add_executable(MyTest1 main-test.cpp)
target_link_libraries(MyTest1 PRIVATE Catch2::Catch2)
