set(SRC
    example.cpp)

add_library(liblock ${SRC})

set_target_properties(liblock 
    PROPERTIES
        PREFIX "")

target_include_directories(liblock
    INTERFACE
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>)

