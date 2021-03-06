#include "SomeLibrary.h"
#include <stdio.h>

typedef struct HIDDEN_STRUCT_DEFINITION
{
    int production_code_only;
} HIDDEN_STRUCT_DEFINITION;

void SomeLibrary_DoesNothing(void)
{
    printf("%s: This function should only be called by production code!\n", __func__);
    return;
}

void SomeLibrary_DoesNothingWithParameter(int param)
{
    printf("%s: This function should only be called by production code!\n", __func__);
    return;
}

int SomeLibrary_ReturnInt(void)
{
    printf("%s: This function should only be called by production code!\n", __func__);
    return -1;
}

int SomeLibrary_ReturnInt2(void)
{
    printf("%s: This function should only be called by production code!\n", __func__);
    return -1;
}

void * SomeLibrary_ReturnVoidPointer(void)
{
    printf("%s: This function should only be called by production code!\n", __func__);
    return NULL;
}

int * SomeLibrary_ReturnIntPointer(void)
{
    printf("%s: This function should only be called by production code!\n", __func__);
    return NULL;
}

SOME_STRUCT * SomeLibrary_ReturnStructPointer(void)
{
    printf("%s: This function should only be called by production code!\n", __func__);
    return NULL;
}

void SomeLibrary_DoesNothingWithStructParameter(SOME_STRUCT *self)
{
    printf("%s: This function should only be called by production code!\n", __func__);
    return;
}

void SomeLibrary_FillStructParameter(SOME_STRUCT *self)
{
    printf("%s: This function should only be called by production code!\n", __func__);
    return;
}

void SomeLibrary_FillStructFromValues(int thing1, int thing2, SOME_STRUCT *self)
{
    printf("%s: This function should only be called by production code!\n", __func__);
    return;
}

void SomeLibrary_FillStructFromValuesWithCopier(int thing1, int thing2, SOME_STRUCT *self)
{
    printf("%s: This function should only be called by production code!\n", __func__);
    return;
}

void SomeLibrary_FillStructFromStruct(SOME_STRUCT_INIT_PARAMS *params, SOME_STRUCT *self)
{
    printf("%s: This function should only be called by production code!\n", __func__);
    return;
}

void SomeLibrary_FillStructFromStructWithCopier(SOME_STRUCT_INIT_PARAMS *params, SOME_STRUCT *self)
{
    printf("%s: This function should only be called by production code!\n", __func__);
    return;
}

void SomeLibrary_CompareHiddenStruct(HIDDEN_STRUCT_HANDLE handle)
{
    printf("%s: This function should only be called by production code!\n", __func__);
    return;
}

void SomeLibrary_FillHiddenStruct(int value, HIDDEN_STRUCT_HANDLE handle)
{
    printf("%s: This function should only be called by production code!\n", __func__);
    return;
}
