cmake_minimum_required(VERSION 3.10)
project(lock)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Threads REQUIRED)

set(LOCK_LIB_SOURCES
    src/safe.cpp)

set(LOCK_CLI_SOURCES
    src/main.cpp)

set(TEST_SOURCES
    tests/example.cpp)

include(ExternalProject)

set(GTEST_ROOT gtest)
set(GTEST_LIB_PREFIX ${CMAKE_CURRENT_BINARY_DIR}/${GTEST_ROOT}/src/googletest-build/lib/${CMAKE_FIND_LIBRARY_PREFIXES})

set(GTEST_LIB_PATH ${GTEST_LIB_PREFIX}gtest.a)
set(GTEST_LIBMAIN_PATH ${GTEST_LIB_PREFIX}gtest_main.a)

ExternalProject_Add(
    googletest
    PREFIX ${GTEST_ROOT}
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG release-1.10.0
    CMAKE_ARGS -DCMAKE_BUILD_TYPE=${CMAKE_BUILD_TYPE}
    BUILD_BYPRODUCTS ${GTEST_LIB_PATH} ${GTEST_LIBMAIN_PATH}
    INSTALL_COMMAND ""
)

ExternalProject_Get_Property(googletest source_dir)

set(GTEST_INCLUDE_DIR ${source_dir}/googletest/include)

add_library(gtest STATIC IMPORTED)
add_library(gtest_main STATIC IMPORTED)

set_target_properties(gtest PROPERTIES
    IMPORTED_LOCATION ${GTEST_LIB_PATH}
)
set_target_properties(gtest_main PROPERTIES
    IMPORTED_LOCATION ${GTEST_LIBMAIN_PATH}
)

add_library(lock STATIC ${LOCK_LIB_SOURCES})

target_include_directories(lock 
    PUBLIC 
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    PRIVATE 
        ${CMAKE_CURRENT_SOURCE_DIR}/src)

add_executable(lock-cli ${LOCK_CLI_SOURCES})

set_target_properties(lock-cli
    PROPERTIES OUTPUT_NAME lock)

add_executable(test_lock ${TEST_SOURCES})

add_dependencies(test_lock googletest)
add_dependencies(gtest googletest)
add_dependencies(gtest_main googletest)

target_include_directories(test_lock PRIVATE ${GTEST_INCLUDE_DIR})
target_link_libraries(test_lock lock gtest gtest_main Threads::Threads)
target_link_libraries(lock-cli PRIVATE lock)

enable_testing()
add_test(NAME test_lock COMMAND test_lock)
