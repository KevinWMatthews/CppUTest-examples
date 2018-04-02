extern "C"
{
}

#include "CppUTest/TestHarness.h"


TEST_GROUP(BasicUnitTest)
{
    void setup()
    {
    }

    void teardown()
    {
    }
};

TEST(BasicUnitTest, can_fail)
{
    // FAIL("This test always fails");
}

TEST(BasicUnitTest, check_true)
{
    CHECK_TRUE(1);
}

TEST(BasicUnitTest, check_false)
{
    CHECK_FALSE(0);
}
