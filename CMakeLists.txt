cmake_minimum_required(VERSION 3.6)
project(ft_printf)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Werror -Wextra -std=c99")

set(SOURCE_FILES ft_printf.c)
add_executable(ft_printf ${SOURCE_FILES})