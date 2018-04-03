#include "SomeStructCopier.h"

void SomeStructCopier::copy(void* out, const void* in)
{
    SOME_STRUCT * some_struct = (SOME_STRUCT *)in;
    SOME_STRUCT * some_struct2 = (SOME_STRUCT *)out;

    if (out == NULL)
        return;
    if (in == NULL)
        return;

    some_struct2->thing1 = some_struct->thing1;
    some_struct2->thing2 = some_struct->thing2;
}
