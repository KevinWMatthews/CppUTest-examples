#include "SomeStructComparator.h"

bool SomeStructComparator::isEqual(const void* object1, const void* object2)
{
    const SOME_STRUCT * some_struct1 = (SOME_STRUCT *)object1;
    const SOME_STRUCT * some_struct2 = (SOME_STRUCT *)object2;

    if (some_struct1->thing1 != some_struct2->thing1)
        return false;

    if (some_struct1->thing2 != some_struct2->thing2)
        return false;

    return true;
}

SimpleString SomeStructComparator::valueToString(const void* object)
{
    const SOME_STRUCT * some_struct = (SOME_STRUCT *)object;

    SimpleString output;

    output += StringFrom(object);
    output += StringFrom(" - ") + StringFrom("thing1: ") + StringFrom(some_struct->thing1);
    output += StringFrom("; ") + StringFrom("thing2: ") + StringFrom(some_struct->thing2);
    return output;
}
