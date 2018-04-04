#include "SomeStructCopier.h"

extern "C"
{
#include "SomeLibrary.h"
}

void SomeStructCopier::copy(void* out, const void* in)
{
    SOME_STRUCT * some_struct2 = (SOME_STRUCT *)out;
    const SOME_STRUCT * some_struct = (const SOME_STRUCT *)in;

    if (out == NULL)
        return;
    if (in == NULL)
        return;

    some_struct2->thing1 = some_struct->thing1;
    some_struct2->thing2 = some_struct->thing2;
}
