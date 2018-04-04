extern "C"
{
#include "MockSomeLibrary.h"
}

#include "CppUTest/TestHarness.h"
#include "CppUTestExt/MockSupport.h"
#include "HiddenStructCopier.h"

// Test the actual copier

TEST_GROUP(HiddenStructCopier)
{
    // HiddenStructCopier local_copier;
    // HIDDEN_STRUCT hidden_struct;
    // HIDDEN_STRUCT hidden_struct2;

    void setup()
    {
    }

    void teardown()
    {
    }
};

TEST(HiddenStructCopier, wiring_check)
{
    FAIL("start here");
}
