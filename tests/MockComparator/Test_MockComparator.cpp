extern "C"
{
#include "SomeLibrary.h"
}

#include "CppUTest/TestHarness.h"
#include "CppUTestExt/MockSupport.h"

// The comparator is defined at the global scope.

TEST_GROUP(TestWithMockComparator)
{
    void setup()
    {
    }

    void teardown()
    {
        // Rather than checking and clearing the mock here,
        // use the MockSupport plugin to do so at global scope.
    }
};

TEST(TestWithMockComparator, call_function_with_comparator)
{
    SOME_STRUCT some_struct = {};
    some_struct.thing1 = 41;
    some_struct.thing2 = 42;

    mock("SomeLibrary").expectOneCall("SomeLibrary_DoesNothingWithStructParameter")
        .withParameterOfType("SOME_STRUCT", "self", &some_struct);

    SomeLibrary_DoesNothingWithStructParameter(&some_struct);
}

#if 0
// This test is configured to fail
TEST(TestWithMockComparator, comparator_can_fail)
{
    SOME_STRUCT some_struct = {};
    some_struct.thing1 = 41;
    some_struct.thing2 = 42;

    mock("SomeLibrary").expectOneCall("SomeLibrary_DoesNothingWithStructParameter")
        .withParameterOfType("SOME_STRUCT", "self", &some_struct);

    SOME_STRUCT other_struct = {};
    other_struct.thing1 = 66;
    other_struct.thing2 = 67;
    SomeLibrary_DoesNothingWithStructParameter(&other_struct);
}
#endif
