add_subdirectory(liblock)
add_subdirectory(lockcli)

add_test(NAME test_lib COMMAND test_lib)
add_test(NAME test_cli COMMAND test_cli)
