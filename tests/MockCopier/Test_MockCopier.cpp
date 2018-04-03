extern "C"
{
#include "SomeLibrary.h"
}

#include "CppUTest/TestHarness.h"
#include "CppUTestExt/MockSupport.h"
#include "SomeStructCopier.h"

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

TEST(TestWithMockCopier, call_function_with_copier)
{
    SOME_STRUCT some_struct = {};
    some_struct.thing1 = 41;
    some_struct.thing2 = 42;

    SOME_STRUCT output = {};

    mock("LocalMock").expectOneCall("SomeLibrary_ClearStructParameter")
        .withOutputParameterOfTypeReturning("SOME_STRUCT", "self", &output);

    SomeLibrary_ClearStructParameter(&some_struct);

    LONGS_EQUAL(0, some_struct.thing1);
    LONGS_EQUAL(0, some_struct.thing2);
}
