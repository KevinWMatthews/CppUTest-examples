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
    HiddenStructCopier local_copier;
    HIDDEN_STRUCT_DEFINITION hidden_struct;
    HIDDEN_STRUCT_DEFINITION hidden_struct2;

    void setup()
    {
    }

    void teardown()
    {
    }
};

TEST(HiddenStructCopier, can_copy_object)
{
    hidden_struct.test_value = 42;
    hidden_struct2.test_value = 0;

    local_copier.copy(&hidden_struct2, &hidden_struct);
    LONGS_EQUAL( 42, hidden_struct2.test_value );
}

TEST(HiddenStructCopier, null_output_object_does_not_segfault)
{
    local_copier.copy(NULL, &hidden_struct2);
}

TEST(HiddenStructCopier, null_input_object_does_not_segfault)
{
    local_copier.copy(NULL, &hidden_struct2);
}
