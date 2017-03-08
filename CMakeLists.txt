cmake_minimum_required(VERSION 3.6)
project(ft_printf)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=c99")

set(SOURCE_FILES ft_printf.c ft_printf.h libft.h)
add_executable(ft_printf ${SOURCE_FILES})
target_link_libraries(ft_printf ${CMAKE_SOURCE_DIR}/libft.a)