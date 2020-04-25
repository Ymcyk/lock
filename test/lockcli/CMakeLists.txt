set(SRC
    cli_example.cpp)

add_executable(test_cli ${SRC})

set_target_properties(test_cli
    PROPERTIES
        OUTPUT_NAME test)

target_link_libraries(test_cli liblockcli gtest gtest_main)
