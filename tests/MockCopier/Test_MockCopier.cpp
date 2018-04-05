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

    mock("SomeLibrary").expectOneCall("SomeLibrary_FillStructParameter")
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

    mock("SomeLibrary").expectOneCall("SomeLibrary_FillStructParameter")
        .withOutputParameterOfTypeReturning("SOME_STRUCT", "self", &output);

    SomeLibrary_FillStructParameter(&some_struct);

    LONGS_EQUAL(41, some_struct.thing1);
    LONGS_EQUAL(42, some_struct.thing2);
}

TEST(TestWithMockCopier, fill_struct_from_parameters_without_copier)
{
    int thing1 = 41;
    int thing2 = 42;

    mock("SomeLibrary").expectOneCall("SomeLibrary_FillStructFromValues")
        .withParameter("thing1", thing1)
        .withParameter("thing2", thing2);
    // Fill struct manually in mock actual call.
    // We could fill the struct using a copier, but
    // in this case it is straightforward to do it manually in the mock.

    SomeLibrary_FillStructFromValues(thing1, thing2, &some_struct);

    LONGS_EQUAL(thing1, some_struct.thing1);
    LONGS_EQUAL(thing2, some_struct.thing2);
}

TEST(TestWithMockCopier, fill_struct_from_parameters_using_copier)
{
    int thing1 = 41;
    int thing2 = 42;
    SOME_STRUCT output = {};
    output.thing1 = thing1;
    output.thing2 = thing2;

    mock("SomeLibrary").expectOneCall("SomeLibrary_FillStructFromValues")
        .withParameter("thing1", thing1)
        .withParameter("thing2", thing2)
        // Fill struct using a copier.
        // In more complex cases this could be simpler.
        // This isn't a complex case, but demonstrate this method using a simple case.
        .withOutputParameterOfTypeReturning("SOME_STRUCT", "self", &output);

    SomeLibrary_FillStructFromValuesWithCopier(thing1, thing2, &some_struct);

    LONGS_EQUAL(thing1, some_struct.thing1);
    LONGS_EQUAL(thing2, some_struct.thing2);
}

TEST(TestWithMockCopier, fill_struct_from_struct_without_copier)
{
    SOME_STRUCT_INIT_PARAMS init_params = {};
    int val1 = 41;
    int val2 = 42;

    init_params.init_value1 = val1;
    init_params.init_value2 = val2;

    mock("SomeLibrary").expectOneCall("SomeLibrary_FillStructFromStruct")
        // Use a comparator to verify that the input parameters are valid.
        .withParameterOfType("SOME_STRUCT_INIT_PARAMS", "params", &init_params);
        // Not using copier - manually copy these values into the output parameter in the mock actual call.

    SomeLibrary_FillStructFromStruct(&init_params, &some_struct);

    LONGS_EQUAL( val1, some_struct.thing1 );
    LONGS_EQUAL( val2, some_struct.thing2 );
}

TEST(TestWithMockCopier, fill_struct_from_struct_using_copier)
{
    SOME_STRUCT_INIT_PARAMS init_params = {};
    int val1 = 41;
    int val2 = 42;

    init_params.init_value1 = val1;
    init_params.init_value2 = val2;
    output.thing1 = val1;
    output.thing2 = val2;

    mock("SomeLibrary").expectOneCall("SomeLibrary_FillStructFromStructWithCopier")
        // Use a comparator to verify that the input parameters are valid.
        .withParameterOfType("SOME_STRUCT_INIT_PARAMS", "params", &init_params)
        // Use a copier to fill the struct.
        .withOutputParameterOfTypeReturning("SOME_STRUCT", "self", &output);

    SomeLibrary_FillStructFromStructWithCopier(&init_params, &some_struct);

    LONGS_EQUAL( val1, some_struct.thing1 );
    LONGS_EQUAL( val2, some_struct.thing2 );
}
