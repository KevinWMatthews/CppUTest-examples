extern "C"
{
#include "SomeLibrary.h"
}

#include "CppUTest/TestHarness.h"
#include "CppUTestExt/MockSupport.h"


TEST_GROUP(TestWithMock)
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

TEST(TestWithMock, call_function)
{
    mock("SomeLibrary").expectOneCall("SomeLibrary_DoesNothing");

    SomeLibrary_DoesNothing();
}

TEST(TestWithMock, call_function_with_paramter)
{
    mock("SomeLibrary").expectOneCall("SomeLibrary_DoesNothingWithParameter")
        .withParameter("param", 42);

    int param = 42;
    SomeLibrary_DoesNothingWithParameter(param);
}

TEST(TestWithMock, return_int_value)
{
    int ret;

    mock("SomeLibrary").expectOneCall("SomeLibrary_ReturnInt")
        // CppUTest overloads this. See CppUTestExt/MockExpectedCall.h
        .andReturnValue(42);

    ret = SomeLibrary_ReturnInt();
    LONGS_EQUAL( 42, ret );
}

TEST(TestWithMock, return_int_value_altername_method)
{
    // The test is the same but the implementation of the actual call is different.
    int ret;

    mock("SomeLibrary").expectOneCall("SomeLibrary_ReturnInt2")
        .andReturnValue(42);

    ret = SomeLibrary_ReturnInt2();
    LONGS_EQUAL( 42, ret );
}

TEST(TestWithMock, return_void_pointer)
{
    int val = 42;
    void * ptr = &val;
    void * actual = NULL;

    mock("SomeLibrary").expectOneCall("SomeLibrary_ReturnVoidPointer")
        .andReturnValue(ptr);   // CppUTest overloads this.

    actual = SomeLibrary_ReturnVoidPointer();
    POINTERS_EQUAL( ptr, actual );
}
