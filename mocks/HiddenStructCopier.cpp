#include "HiddenStructCopier.h"

extern "C"
{
#include "MockSomeLibrary.h"
}

// The HiddenStruct is defined in the library mock.

void HiddenStructCopier::copy(void* out, const void* in)
{
    HIDDEN_STRUCT_DEFINITION * hidden_struct_out = (HIDDEN_STRUCT_DEFINITION *)out;
    const HIDDEN_STRUCT_DEFINITION * hidden_struct_in = (const HIDDEN_STRUCT_DEFINITION *)in;

    if (hidden_struct_out == NULL)
        return;
    if (hidden_struct_in == NULL)
        return;

    hidden_struct_out->test_value = hidden_struct_in->test_value;
}
