extern "C"
{
#include "MockSomeLibrary.h"
}

#include "CppUTest/TestHarness.h"
#include "CppUTestExt/MockSupport.h"
#include "HiddenStructComparator.h"

// Test the actual comparator

TEST_GROUP(HiddenStructComparator)
{
    HiddenStructComparator local_comparator;
    HIDDEN_STRUCT_DEFINITION hidden_struct;
    HIDDEN_STRUCT_HANDLE hidden_struct_handle;
    HIDDEN_STRUCT_DEFINITION hidden_struct2;
    HIDDEN_STRUCT_HANDLE hidden_struct_handle2;
    bool result;

    void setup()
    {
        hidden_struct_handle = &hidden_struct;
        hidden_struct_handle2 = &hidden_struct2;
    }

    void teardown()
    {
    }
};

TEST(HiddenStructComparator, structs_can_be_equal)
{
    hidden_struct.test_value = 12;
    hidden_struct2.test_value = 12;

    result = local_comparator.isEqual(&hidden_struct, &hidden_struct2);
    CHECK_TRUE(result);
}

TEST(HiddenStructComparator, comparator_can_use_handles)
{
    // Better to initialize the struct's themselves?
    hidden_struct_handle->test_value = 13;
    hidden_struct_handle2->test_value = 13;

    result = local_comparator.isEqual(hidden_struct_handle, hidden_struct_handle2);
    CHECK_TRUE(result);
}
