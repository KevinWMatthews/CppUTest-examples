#ifndef SOME_STRUCT_INIT_PARAMS_COMPARATOR_INCLUDED
#define SOME_STRUCT_INIT_PARAMS_COMPARATOR_INCLUDED

extern "C"
{
#include "SomeLibrary.h"
}

#include "CppUTestExt/MockSupport.h"

class SomeStructInitParamsComparator : public MockNamedValueComparator
{
public:
    virtual bool isEqual(const void* object1, const void* object2);
    virtual SimpleString valueToString(const void* object);
};

#endif
