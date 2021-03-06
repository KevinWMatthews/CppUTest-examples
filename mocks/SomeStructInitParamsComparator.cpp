#include "SomeStructInitParamsComparator.h"

bool SomeStructInitParamsComparator::isEqual(const void* object1, const void* object2)
{
    const SOME_STRUCT_INIT_PARAMS* params1 = (const SOME_STRUCT_INIT_PARAMS*)object1;
    const SOME_STRUCT_INIT_PARAMS* params2 = (const SOME_STRUCT_INIT_PARAMS*)object2;

    if (object1 == NULL && object2 == NULL)
        return true;

    if (object1 == NULL)
        return false;
    if (object2 == NULL)
        return false;

    if (params1->init_value1 != params2->init_value1)
        return false;
    if (params1->init_value2 != params2->init_value2)
        return false;

    return true;
}

SimpleString SomeStructInitParamsComparator::valueToString(const void* object)
{
    const SOME_STRUCT_INIT_PARAMS * params = (SOME_STRUCT_INIT_PARAMS *)object;

    SimpleString output;

    output += StringFrom("SOME_STRUCT_INIT_PARAMS");
    output += StringFrom(" - ") + StringFrom("init_value1: ") + StringFrom(params->init_value1);
    output += StringFrom("; ") + StringFrom("init_value2: ") + StringFrom(params->init_value2);
    return output;
}
