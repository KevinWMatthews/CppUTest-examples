extern "C"
{
}

#include "CppUTest/TestHarness.h"
#include "CppUTestExt/MockSupport.h"
#include "SomeStructComparator.h"

// Test the actual comparator

TEST_GROUP(SomeStructComparator)
{
    SomeStructComparator local_comparator;
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

// Should/how should we test output?

TEST(SomeStructComparator, structs_can_be_equal)
{
    some_struct.thing1 = 0;
    some_struct.thing2 = 0;
    some_struct2.thing1 = 0;
    some_struct2.thing2 = 0;

    result = local_comparator.isEqual(&some_struct, &some_struct2);
    CHECK_TRUE(result);
}

TEST(SomeStructComparator, thing1_causes_inequality)
{
    some_struct.thing1 = 0;
    some_struct.thing2 = 0;

    some_struct2.thing1 = 16;
    some_struct2.thing2 = 0;

    result = local_comparator.isEqual(&some_struct, &some_struct2);
    CHECK_FALSE(result);
}

TEST(SomeStructComparator, thing2_causes_inequality)
{
    some_struct.thing1 = 0;
    some_struct.thing2 = 42;

    some_struct2.thing1 = 0;
    some_struct2.thing2 = 0;

    result = local_comparator.isEqual(&some_struct, &some_struct2);
    CHECK_FALSE(result);
}

TEST(SomeStructComparator, null_first_object_does_not_segfault)
{
    result = local_comparator.isEqual(NULL, &some_struct2);
    CHECK_FALSE(result);
}

TEST(SomeStructComparator, null_second_object_does_not_segfault)
{
    result = local_comparator.isEqual(&some_struct, NULL);
    CHECK_FALSE(result);
}

TEST(SomeStructComparator, null_objects_are_equal)
{
    result = local_comparator.isEqual(NULL, NULL);
    CHECK_TRUE(result);
}
