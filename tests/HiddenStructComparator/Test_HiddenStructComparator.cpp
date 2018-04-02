extern "C"
{
}

#include "CppUTest/TestHarness.h"
#include "CppUTestExt/MockSupport.h"
#include "HiddenStructComparator.h"

// Test the actual comparator

TEST_GROUP(HiddenStructComparator)
{
    HiddenStructComparator local_comparator;
    SOME_STRUCT some_struct;
    SOME_STRUCT some_struct2;
    bool result;

    void setup()
    {
    }

    void teardown()
    {
        // Rather than checking and clearing the mock here,
        // use the MockSupport plugin to do so at global scope.
    }
};

TEST(HiddenStructComparator, wiring_check)
{
    FAIL("start here");
}
