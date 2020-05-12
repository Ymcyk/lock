project(liblock)
set(SRC
    src/exception.cpp)

set(HDRS
    include/lock/exception.hpp)

add_library(liblock STATIC ${SRC} ${HDRS})

set_target_properties(liblock 
    PROPERTIES
        PREFIX "")

target_include_directories(liblock
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    PRIVATE
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/src>)
