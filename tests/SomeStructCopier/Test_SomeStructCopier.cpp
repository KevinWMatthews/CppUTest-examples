extern "C"
{
#include "SomeLibrary.h"
}

#include "CppUTest/TestHarness.h"
#include "CppUTestExt/MockSupport.h"
#include "SomeStructCopier.h"

// Test the actual comparator

TEST_GROUP(SomeStructCopier)
{
    SomeStructCopier local_copier;
    SOME_STRUCT some_struct;
    SOME_STRUCT some_struct2;

    void setup()
    {
    }

    void teardown()
    {
    }
};

TEST(SomeStructCopier, can_copy_object)
{
    some_struct.thing1 = 41;
    some_struct.thing2 = 42;
    some_struct2.thing1 = 0;
    some_struct2.thing2 = 0;

    local_copier.copy(&some_struct2, &some_struct);
    LONGS_EQUAL( some_struct2.thing1, 41 );
    LONGS_EQUAL( some_struct2.thing2, 42 );
}

TEST(SomeStructCopier, null_first_object_does_not_segfault)
{
    local_copier.copy(NULL, &some_struct2);
}

TEST(SomeStructCopier, null_second_object_does_not_segfault)
{
    local_copier.copy(NULL, &some_struct2);
}
