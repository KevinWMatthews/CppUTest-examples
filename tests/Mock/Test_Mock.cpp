extern "C"
{
}

#include "CppUTest/TestHarness.h"


TEST_GROUP(TestWithMock)
{
    void setup()
    {
    }

    void teardown()
    {
    }
};

TEST(TestWithMock, wiring_check)
{
    FAIL("HI");
}
