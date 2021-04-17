cmake_minimum_required(VERSION 3.17)
project(arithmetic_coding)

set(CMAKE_CXX_STANDARD 17)

include_directories("/usr/local/include/")
link_directories("/usr/local/lib/")

add_executable(arithmetic_coding
        main.cpp
        src/Fraction/Fraction.cpp
        src/Arithmetic/arithmetic.cpp
        src/Utils/utils.cpp)

target_link_libraries(arithmetic_coding gmp gmpxx)
