set(SRC
    cli_example.cpp)

add_executable(test_cli ${SRC})

target_link_libraries(test_cli liblockcli gtest gtest_main)

add_test(NAME test_cli COMMAND test_cli)
