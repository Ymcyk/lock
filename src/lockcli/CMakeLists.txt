project(lockcli)
set(SRC
    src/app.cpp
    src/exception.cpp
    src/commands/parser.cpp
    src/commands/add_command.cpp
    src/commands/ls_command.cpp
    src/commands/rm_command.cpp
    src/commands/cp_command.cpp)

add_library(liblockcli ${SRC})

set_target_properties(liblockcli 
    PROPERTIES
        PREFIX "")

target_include_directories(liblockcli
    PRIVATE
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/src>
        $<BUILD_INTERFACE:${liblock_SOURCE_DIR}/include>
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/3rdparty>)

add_executable(lock src/main.cpp)
target_link_libraries(liblockcli liblock)
target_link_libraries(lock liblockcli)
