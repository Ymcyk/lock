set(SRC
    lib_example.cpp)

add_executable(test_lib ${SRC})

target_link_libraries(test_lib liblock gtest gtest_main)

add_test(NAME test_lib COMMAND test_lib)
