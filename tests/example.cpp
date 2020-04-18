#include <iostream>

#include "gtest/gtest.h"
#include "lock/safe.hpp"

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
    ASSERT_TRUE(lock::example());
}
