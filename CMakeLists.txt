cmake_minimum_required(VERSION 3.6)
project(ft_printf)

set(CMAKE_C_STANDARD 11)

set(SOURCE_FILES ft_printf.c)
add_executable(ft_printf ${SOURCE_FILES})