extern "C"
{
#include "SomeLibrary.h"
}

#include "CppUTest/TestHarness.h"
#include "CppUTestExt/MockSupport.h"
#include "SomeStructInitParamsComparator.h"

// Test the actual comparator

TEST_GROUP(SomeStructInitParamsComparator)
{
    SomeStructInitParamsComparator local_comparator;
    SOME_STRUCT_INIT_PARAMS params;
    SOME_STRUCT_INIT_PARAMS params2;
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

// Should/how should we test output of valueToString()?

TEST(SomeStructInitParamsComparator, structs_can_be_equal)
{
    params.init_value1 = 0;
    params.init_value2 = 0;
    params2.init_value1 = 0;
    params2.init_value2 = 0;

    result = local_comparator.isEqual(&params, &params2);
    CHECK_TRUE(result);
}

TEST(SomeStructInitParamsComparator, thing1_causes_inequality)
{
    params.init_value1 = 16;
    params.init_value2 = 0;

    params2.init_value1 = 0;
    params2.init_value2 = 0;

    result = local_comparator.isEqual(&params, &params2);
    CHECK_FALSE(result);
}

TEST(SomeStructInitParamsComparator, thing2_causes_inequality)
{
    params.init_value1 = 0;
    params.init_value2 = 42;

    params2.init_value1 = 0;
    params2.init_value2 = 0;

    result = local_comparator.isEqual(&params, &params2);
    CHECK_FALSE(result);
}

TEST(SomeStructInitParamsComparator, null_first_object_does_not_segfault)
{
    result = local_comparator.isEqual(NULL, &params2);
    CHECK_FALSE(result);
}

TEST(SomeStructInitParamsComparator, null_second_object_does_not_segfault)
{
    result = local_comparator.isEqual(&params, NULL);
    CHECK_FALSE(result);
}

TEST(SomeStructInitParamsComparator, null_objects_are_equal)
{
    result = local_comparator.isEqual(NULL, NULL);
    CHECK_TRUE(result);
}
