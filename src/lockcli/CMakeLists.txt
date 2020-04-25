set(SRC
    app.cpp)

add_library(liblockcli ${SRC})

set_target_properties(liblockcli 
    PROPERTIES
        PREFIX "")

target_include_directories(liblockcli
    INTERFACE
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>)

add_executable(lock main.cpp)
target_link_libraries(lock liblock liblockcli)
