#include "gtest/gtest.h"

#include <iostream>

class LockTest : public ::testing::Test
{
    protected:
    LockTest() {}
    ~LockTest() override {}

    void SetUp() override {}
    void TearDown() override {}
};

TEST_F(LockTest, GTestSetUpSuccess)
{
    std::cout << "TESTING!!!\n";
}
