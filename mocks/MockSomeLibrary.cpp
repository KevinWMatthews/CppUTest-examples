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

void SomeLibrary_FillStructParameter(SOME_STRUCT *self)
{
    mock("SomeMock").actualCall("SomeLibrary_FillStructParameter")
        .withOutputParameterOfType("SOME_STRUCT", "self", self);
}

void SomeLibrary_FillStructFromValues(int thing1, int thing2, SOME_STRUCT *param)
{
    mock("SomeMock").actualCall("SomeLibrary_FillStructFromValues")
       .withParameter("thing1", thing1)
       .withParameter("thing2", thing2);
    param->thing1 = thing1;
    param->thing2 = thing2;
}

void SomeLibrary_FillStructFromValuesWithCopier(int thing1, int thing2, SOME_STRUCT *param)
{
    mock("SomeMock").actualCall("SomeLibrary_FillStructFromValues")
       .withParameter("thing1", thing1)
       .withParameter("thing2", thing2)
       .withOutputParameterOfType("SOME_STRUCT", "param", param);
}

void SomeLibrary_FillHiddenStruct(int value, HIDDEN_STRUCT_HANDLE handle)
{
}

HIDDEN_STRUCT_HANDLE SomeLibrary_HiddenStructInitialize(HIDDEN_STRUCT_INIT_PARAMS *params)
{
    return NULL;
}
