cmake_minimum_required(VERSION 3.13)
project(embedded_systems)

set(CMAKE_CXX_STANDARD 14)

add_subdirectory(01-einfuehrung)
add_subdirectory(02-digio)
add_subdirectory(03-interrupts)
add_subdirectory(04-timer)
add_subdirectory(05-pwm)
add_subdirectory(06-analog-io)