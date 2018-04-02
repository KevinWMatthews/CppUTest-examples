#include "SomeLibrary.h"
#include <stdio.h>

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
