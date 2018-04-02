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

    mock("SomeMock").expectOneCall("SomeLibrary_DoesNothingWithStructParameter")
        .withParameterOfType("SOME_STRUCT", "param", &some_struct);

    SomeLibrary_DoesNothingWithStructParameter(&some_struct);
}
