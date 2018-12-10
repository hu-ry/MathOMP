cmake_minimum_required(VERSION 3.10)
project(MathOMP VERSION 0.1.0)
include(GNUInstallDirs)
set(CMAKE_CXX_STANDARD 14)
set(SOURCE_FILES mathomp.cpp)

add_library(MathOMP STATIC ${SOURCE_FILES})

install(TARGETS MathOMP DESTINATION lib)
install(FILES mathomp.h DESTINATION include)