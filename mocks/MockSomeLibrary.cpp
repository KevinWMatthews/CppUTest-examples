extern "C"
{
#include "SomeLibrary.h"
}

#include "CppUTestExt/MockSupport.h"

// Be sure to completely define the library interface here.
// If you fail to do this, the linker can throw cryptic 'multiple definition' errors.
// This is because the functions defined here will be linked but
// the missing function will be linked from production code.
// When this occurs, the linker now sees duplicate definitions for all the functions
// that were mocked.
// You will see errors for all the functions that are mocked properly but not
// the one that is missing.

void SomeLibrary_DoesNothing(void)
{
    mock("SomeMock").actualCall("SomeLibrary_DoesNothing");
}

void SomeLibrary_DoesNothingWithParameter(int param)
{
    mock("SomeMock").actualCall("SomeLibrary_DoesNothingWithParameter")
        .withParameter("param", param);
}

void SomeLibrary_DoesNothingWithStructParameter(SOME_STRUCT *param)
{
    mock("SomeMock").actualCall("SomeLibrary_DoesNothingWithStructParameter")
        .withParameterOfType("SOME_STRUCT", "param", param);
}

void SomeLibrary_ClearStructParameter(SOME_STRUCT *self)
{
    mock("LocalMock").actualCall("SomeLibrary_ClearStructParameter")
        .withOutputParameterOfType("SOME_STRUCT", "self", self);
}

HIDDEN_STRUCT_HANDLE SomeLibrary_HiddenStructInitialize(HIDDEN_STRUCT_INIT_PARAMS *params)
{
    return NULL;
}
