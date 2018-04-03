extern "C"
{
#include "SomeLibrary.h"
}

#include "CppUTest/TestHarness.h"
#include "CppUTestExt/MockSupport.h"

// The copier is defined at the global scope.

TEST_GROUP(TestWithMockCopier)
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

TEST(TestWithMockCopier, call_function_with_comparator)
{
    SOME_STRUCT some_struct = {};
    some_struct.thing1 = 41;
    some_struct.thing2 = 42;

    mock("SomeMock").expectOneCall("SomeLibrary_ClearStructParameter");
        // .withOutputParameterOfTypeReturning("SOME_STRUCT", "param", &some_struct);

    SomeLibrary_ClearStructParameter(&some_struct);
}

#if 0
// This test is configured to fail
TEST(TestWithMockCopier, comparator_can_fail)
{
    SOME_STRUCT some_struct = {};
    some_struct.thing1 = 41;
    some_struct.thing2 = 42;

    mock("SomeMock").expectOneCall("SomeLibrary_DoesNothingWithStructParameter")
        .withParameterOfType("SOME_STRUCT", "param", &some_struct);

    SOME_STRUCT other_struct = {};
    other_struct.thing1 = 66;
    other_struct.thing2 = 67;
    SomeLibrary_DoesNothingWithStructParameter(&other_struct);
}
#endif
