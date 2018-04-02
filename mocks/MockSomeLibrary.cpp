extern "C"
{
#include "SomeLibrary.h"
}

#include "CppUTestExt/MockSupport.h"

void SomeLibrary_DoesNothing(void)
{
    mock("SomeMock").actualCall("SomeLibrary_DoesNothing");
}

void SomeLibrary_DoesNothingWithParameter(int param)
{
    mock("SomeMock").actualCall("SomeLibrary_DoesNothingWithParameter")
        .withParameter("param", param);
}
