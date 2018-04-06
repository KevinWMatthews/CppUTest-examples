extern "C"
{
#include "SomeLibrary.h"
#include "MockSomeLibrary.h"
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

TEST(TestWithMockComparator, use_comparator_with_hidden_struct)
{
    // Hidden from production code. Defined in mock header file.
    HIDDEN_STRUCT_DEFINITION expected_hidden_struct = {};
    // Production code may not have access to the same variable but the comparison should still succeed.
    HIDDEN_STRUCT_DEFINITION actual_hidden_struct = {};
    expected_hidden_struct.test_value = 7;
    actual_hidden_struct.test_value = 7;

    mock("SomeLibrary").expectOneCall("SomeLibrary_CompareHiddenStruct")
        .withParameterOfType("HIDDEN_STRUCT", "handle", &expected_hidden_struct);

    SomeLibrary_CompareHiddenStruct(&actual_hidden_struct);
}

TEST(TestWithMockComparator, hidden_struct_comparator_accepts_a_handle)
{
    HIDDEN_STRUCT_DEFINITION expected_hidden_struct = {};
    HIDDEN_STRUCT_DEFINITION actual_hidden_struct = {};
    HIDDEN_STRUCT_HANDLE expected_handle = NULL;
    HIDDEN_STRUCT_HANDLE actual_handle = NULL;

    expected_hidden_struct.test_value = 7;
    actual_hidden_struct.test_value = 7;
    expected_handle = &expected_hidden_struct;
    actual_handle = &actual_hidden_struct;

    mock("SomeLibrary").expectOneCall("SomeLibrary_CompareHiddenStruct")
        .withParameterOfType("HIDDEN_STRUCT", "handle", expected_handle);

    SomeLibrary_CompareHiddenStruct(actual_handle);
}
