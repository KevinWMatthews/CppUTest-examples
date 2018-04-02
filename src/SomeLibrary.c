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

void SomeLibrary_DoesNothingWithStructParameter(SOME_STRUCT *param)
{
    printf("%s: This function should only be called by production code!\n", __func__);
    return;
}

HIDDEN_STRUCT_HANDLE SomeLibrary_HiddenStructInitialize(HIDDEN_STRUCT_INIT_PARAMS *params)
{
    printf("%s: This function should only be called by production code!\n", __func__);
    return NULL;
}
