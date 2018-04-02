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
    HIDDEN_STRUCT_HANDLE hidden_struct_handle;
    HIDDEN_STRUCT_HANDLE hidden_struct_handle2;
    bool result;

    void setup()
    {
    }

    void teardown()
    {
    }
};

TEST(HiddenStructComparator, null_first_object_does_not_segfault)
{
    result = local_comparator.isEqual(NULL, &hidden_struct_handle2);
    CHECK_FALSE(result);
}

TEST(HiddenStructComparator, null_second_object_does_not_segfault)
{
    result = local_comparator.isEqual(&hidden_struct_handle, NULL);
    CHECK_FALSE(result);
}

TEST(HiddenStructComparator, null_objects_are_equal)
{
    result = local_comparator.isEqual(NULL, NULL);
    CHECK_TRUE(result);
}
