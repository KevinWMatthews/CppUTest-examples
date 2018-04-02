#include "HiddenStructComparator.h"

bool HiddenStructComparator::isEqual(const void* object1, const void* object2)
{
    return false;
}

SimpleString HiddenStructComparator::valueToString(const void* object)
{
    return StringFrom(object);
}
