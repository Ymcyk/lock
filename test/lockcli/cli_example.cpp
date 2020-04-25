#include "gtest/gtest.h"

class LockCliTest : public ::testing::Test
{
    protected:
    LockCliTest() {}
    ~LockCliTest() override {}

    void SetUp() override {}
    void TearDown() override {}
};

TEST_F(LockCliTest, Example)
{
    ASSERT_TRUE(true);
}
