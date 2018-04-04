#include "HiddenStructCopier.h"

extern "C"
{
#include "MockSomeLibrary.h"
}

void HiddenStructCopier::copy(void* out, const void* in)
{
    HIDDEN_STRUCT_DEFINITION * hidden_struct_out = (HIDDEN_STRUCT_DEFINITION *)out;
    const HIDDEN_STRUCT_DEFINITION * hidden_struct_in = (const HIDDEN_STRUCT_DEFINITION *)in;

    hidden_struct_out->test_value = hidden_struct_in->test_value;
}
