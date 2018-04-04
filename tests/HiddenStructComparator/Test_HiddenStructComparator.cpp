extern "C"
{
}

#include "CppUTest/TestHarness.h"
#include "CppUTestExt/MockSupport.h"
#include "HiddenStructComparator.h"

// Test the actual comparator

TEST_GROUP(HiddenStructComparator)
{
    HiddenStructComparator local_comparator;
    HIDDEN_STRUCT_HANDLE hidden_struct_handle;
    HIDDEN_STRUCT_HANDLE hidden_struct_handle2;
    HIDDEN_STRUCT_INIT_PARAMS init_params;
    bool result;

    void setup()
    {
    }

    void teardown()
    {
    }
};

// A pointer to the struct is declared by production code.
// The struct definition is internal to this production code module and
// is not available to tests (or other production code modules).
//
// The tests can defined their own data structure and manipulate it as needed.
TEST(HiddenStructComparator, can_fill_copy_to_hidden_struct)
{
    HIDDEN_STRUCT_HANDLE handle;

    // mock("SomeMock").expectOneCall("SomeLibrary_FillHiddenStruct")
        // .withParameter("value", 42)
        // .withOutputParameterOfTypeReturning("HIDDEN_STRUCT_HANDLE", "handle", handle);

    SomeLibrary_FillHiddenStruct(42, hidden_struct_handle);
    // check result
}

TEST(HiddenStructComparator, can_be_equal)
{
    init_params.init_value = 42;
    hidden_struct_handle = SomeLibrary_HiddenStructInitialize(&init_params);
    hidden_struct_handle2 = SomeLibrary_HiddenStructInitialize(&init_params);

    // You can pass a handle where a struct pointer is expected.
    // This is typedef'ed properly and we'll covert in the comparator regardless.
    result = local_comparator.isEqual(hidden_struct_handle, hidden_struct_handle2);
    CHECK_TRUE(result);
}

IGNORE_TEST(HiddenStructComparator, different_when_init_params_are_different)
{
    init_params.init_value = 42;
    hidden_struct_handle = SomeLibrary_HiddenStructInitialize(&init_params);
    init_params.init_value = 43;
    hidden_struct_handle2 = SomeLibrary_HiddenStructInitialize(&init_params);

    result = local_comparator.isEqual(hidden_struct_handle, hidden_struct_handle2);
    CHECK_FALSE(result);
}

TEST(HiddenStructComparator, null_first_object_does_not_segfault)
{
    result = local_comparator.isEqual(NULL, &hidden_struct_handle2);
    CHECK_FALSE(result);
}

TEST(HiddenStructComparator, null_second_object_does_not_segfault)
{
    result = local_comparator.isEqual(&hidden_struct_handle, NULL);
    CHECK_FALSE(result);
}

TEST(HiddenStructComparator, null_objects_are_equal)
{
    result = local_comparator.isEqual(NULL, NULL);
    CHECK_TRUE(result);
}
