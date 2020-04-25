#include "gtest/gtest.h"

class LibLockTest : public ::testing::Test
{
    protected:
    LibLockTest() {}
    ~LibLockTest() override {}

    void SetUp() override {}
    void TearDown() override {}
};

TEST_F(LibLockTest, Example)
{
    ASSERT_TRUE(true);
}
