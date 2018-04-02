#include "HiddenStructComparator.h"

bool HiddenStructComparator::isEqual(const void* object1, const void* object2)
{
    if (object1 == NULL && object2 == NULL)
        return true;

    return false;
}

SimpleString HiddenStructComparator::valueToString(const void* object)
{
    return StringFrom(object);
}
