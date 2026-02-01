
cmake_minimum_required(VERSION 3.10)
project(car_db C)

find_package(SQLite3 REQUIRED)

add_executable(car_db src/main.c)
target_link_libraries(car_db SQLite::SQLite3)
