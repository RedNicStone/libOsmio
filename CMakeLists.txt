cmake_minimum_required(VERSION 3.23)
project(osmio)

file(GLOB_RECURSE LIBOSMIO_HEADERS ${CMAKE_SOURCE_DIR}/src/public/*.h)

add_library(osmio ${LIBOSMIO_HEADERS})
set_target_properties(osmio PROPERTIES LINKER_LANGUAGE C)
