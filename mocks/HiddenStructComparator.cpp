#include "HiddenStructComparator.h"

extern "C"
{
#include "MockSomeLibrary.h"
}

bool HiddenStructComparator::isEqual(const void* object1, const void* object2)
{
    const HIDDEN_STRUCT_DEFINITION * hidden_struct = (const HIDDEN_STRUCT_DEFINITION *)object1;
    const HIDDEN_STRUCT_DEFINITION * hidden_struct2 = (const HIDDEN_STRUCT_DEFINITION *)object2;

    if (object1 == NULL && object2 == NULL)
        return true;

    if (object1 == NULL)
        return false;
    if (object2 == NULL)
        return false;

    if (hidden_struct->test_value != hidden_struct2->test_value)
        return false;

    return true;
}

SimpleString HiddenStructComparator::valueToString(const void* object)
{
    return StringFrom(object);
}
