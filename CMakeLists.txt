cmake_minimum_required(VERSION 3.30)

set(CMAKE_CXX_STANDARD 23)

# Build the shared library
add_subdirectory(Source)

# Build the Injector tool
add_subdirectory(Injector)