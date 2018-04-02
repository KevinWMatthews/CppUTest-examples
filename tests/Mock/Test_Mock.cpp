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
    mock("SomeMock").expectOneCall("SomeLibrary_DoesNothing");

    SomeLibrary_DoesNothing();
}

TEST(TestWithMock, call_function_with_paramter)
{
    mock("SomeMock").expectOneCall("SomeLibrary_DoesNothingWithParameter")
        .withParameter("param", 42);

    int param = 42;
    SomeLibrary_DoesNothingWithParameter(param);
}
