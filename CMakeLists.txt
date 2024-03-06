cmake_minimum_required(VERSION 3.18)
project(matmult LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)

include_directories(include)

add_executable(matmult
        src/matmult.cpp)

####################
## Vectorization
####################
#
#add_executable(matmult_vec
#        src/matmult.cpp)
#
#target_compile_options(matmult_vec PRIVATE -O2 -ftree-vectorize -fopt-info-vec-optimized)
#
####################
## Parallel version
####################
#
#find_package(OpenMP REQUIRED)
#
#add_executable(matmult_par
#            src/matmult_par.cpp)
#
#target_link_libraries(matmult_par PUBLIC OpenMP::OpenMP_CXX)
#
#
####################
## Vectorized Parallel version
####################
#
#add_executable(matmult_par_vec
#            src/matmult_par.cpp)
#
#target_link_libraries(matmult_par_vec PUBLIC OpenMP::OpenMP_CXX)
#target_compile_options(matmult_par_vec PRIVATE -O2 -ftree-vectorize -fopt-info-vec-optimized)
