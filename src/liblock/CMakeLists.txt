project(liblock)

get_property(PROJECT_VERSION_MAJOR GLOBAL PROPERTY LOCK_MINOR)
get_property(PROJECT_VERSION_MINOR GLOBAL PROPERTY LOCK_MAJOR)
get_property(PROJECT_VERSION_PATCH GLOBAL PROPERTY LOCK_PATCH)
get_property(PROJECT_VERSION GLOBAL PROPERTY LOCK_PROJECT_VERSION)

set(SRC
    src/exception.cpp)

set(HDRS
    include/lock/exception.hpp)

add_library(liblock STATIC ${SRC} ${HDRS})

set_target_properties(liblock 
    PROPERTIES
        PREFIX "")

configure_file(version.hpp.in lock/version.hpp)

target_include_directories(liblock
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    PRIVATE
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/src>)
