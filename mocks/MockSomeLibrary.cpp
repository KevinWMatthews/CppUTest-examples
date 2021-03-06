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
    mock("SomeLibrary").actualCall("SomeLibrary_DoesNothing");
}

void SomeLibrary_DoesNothingWithParameter(int param)
{
    mock("SomeLibrary").actualCall("SomeLibrary_DoesNothingWithParameter")
        .withParameter("param", param);
}

int SomeLibrary_ReturnInt(void)
{
    return mock("SomeLibrary").actualCall("SomeLibrary_ReturnInt")
        // See CppUTestExt/MockActualCall.h
        .returnIntValue();
}

int SomeLibrary_ReturnInt2(void)
{
    mock("SomeLibrary").actualCall("SomeLibrary_ReturnInt2");
    // See CppUTestExt/MockSupport.h
    return mock("SomeLibrary").intReturnValue();
}

void * SomeLibrary_ReturnVoidPointer(void)
{
    return mock("SomeLibrary").actualCall("SomeLibrary_ReturnVoidPointer")
        .returnPointerValue();
    // Or this:
    // return mock("SomeLibrary").pointerReturnValue();
}

int * SomeLibrary_ReturnIntPointer(void)
{
    mock("SomeLibrary").actualCall("SomeLibrary_ReturnIntPointer");
    return (int *)mock("SomeLibrary").pointerReturnValue();
    // Or this:
    // return (int *)mock("SomeLibrary").actualCall("SomeLibrary_ReturnIntPointer")
        // .returnPointerValue();
}

SOME_STRUCT * SomeLibrary_ReturnStructPointer(void)
{
    mock("SomeLibrary").actualCall("SomeLibrary_ReturnStructPointer");
    return (SOME_STRUCT *)mock("SomeLibrary").pointerReturnValue();
}

void SomeLibrary_DoesNothingWithStructParameter(SOME_STRUCT *self)
{
    mock("SomeLibrary").actualCall("SomeLibrary_DoesNothingWithStructParameter")
        .withParameterOfType("SOME_STRUCT", "self", self);
}

void SomeLibrary_FillStructParameter(SOME_STRUCT *self)
{
    mock("SomeLibrary").actualCall("SomeLibrary_FillStructParameter")
        .withOutputParameterOfType("SOME_STRUCT", "self", self);
}

void SomeLibrary_FillStructFromValues(int thing1, int thing2, SOME_STRUCT *self)
{
    mock("SomeLibrary").actualCall("SomeLibrary_FillStructFromValues")
       .withParameter("thing1", thing1)
       .withParameter("thing2", thing2);
    self->thing1 = thing1;
    self->thing2 = thing2;
}

void SomeLibrary_FillStructFromValuesWithCopier(int thing1, int thing2, SOME_STRUCT *self)
{
    mock("SomeLibrary").actualCall("SomeLibrary_FillStructFromValues")
       .withParameter("thing1", thing1)
       .withParameter("thing2", thing2)
       .withOutputParameterOfType("SOME_STRUCT", "self", self);
}

void SomeLibrary_FillStructFromStruct(SOME_STRUCT_INIT_PARAMS *params, SOME_STRUCT *self)
{
    mock("SomeLibrary").actualCall("SomeLibrary_FillStructFromStruct")
        .withParameterOfType("SOME_STRUCT_INIT_PARAMS", "params", params);
    self->thing1 = params->init_value1;
    self->thing2 = params->init_value2;
}

void SomeLibrary_FillStructFromStructWithCopier(SOME_STRUCT_INIT_PARAMS *params, SOME_STRUCT *self)
{
    mock("SomeLibrary").actualCall("SomeLibrary_FillStructFromStructWithCopier")
        .withParameterOfType("SOME_STRUCT_INIT_PARAMS", "params", params)
        .withOutputParameterOfType("SOME_STRUCT", "self", self);
}

void SomeLibrary_CompareHiddenStruct(HIDDEN_STRUCT_HANDLE handle)
{
    mock("SomeLibrary").actualCall("SomeLibrary_CompareHiddenStruct")
        .withParameterOfType("HIDDEN_STRUCT", "handle", handle);
}

void SomeLibrary_FillHiddenStruct(int value, HIDDEN_STRUCT_HANDLE handle)
{
    mock("SomeLibrary").actualCall("SomeLibrary_FillHiddenStruct")
        .withParameter("value", value)
        .withOutputParameterOfType("HIDDEN_STRUCT", "handle", handle);
}
