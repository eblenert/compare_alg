add_library(utils print_array.c read_from_file.c swap.c)

target_include_directories(utils PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})