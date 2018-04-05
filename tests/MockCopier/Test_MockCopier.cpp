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
    SOME_STRUCT some_struct;
    SOME_STRUCT output;

    void setup()
    {
    }

    void teardown()
    {
        // Rather than checking and clearing the mock here,
        // use the MockSupport plugin to do so at global scope.
    }
};

TEST(TestWithMockCopier, copier_can_clear_struct)
{
    output.thing1 = 0;
    output.thing2 = 0;
    some_struct.thing1 = 66;
    some_struct.thing2 = 67;

    mock("SomeMock").expectOneCall("SomeLibrary_FillStructParameter")
        .withOutputParameterOfTypeReturning("SOME_STRUCT", "self", &output);

    SomeLibrary_FillStructParameter(&some_struct);

    LONGS_EQUAL(0, some_struct.thing1);
    LONGS_EQUAL(0, some_struct.thing2);
}

TEST(TestWithMockCopier, copier_can_fill_struct)
{
    output.thing1 = 41;
    output.thing2 = 42;
    some_struct.thing1 = 0;
    some_struct.thing2 = 0;

    mock("SomeMock").expectOneCall("SomeLibrary_FillStructParameter")
        .withOutputParameterOfTypeReturning("SOME_STRUCT", "self", &output);

    SomeLibrary_FillStructParameter(&some_struct);

    LONGS_EQUAL(41, some_struct.thing1);
    LONGS_EQUAL(42, some_struct.thing2);
}
