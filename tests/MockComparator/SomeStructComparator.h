#ifndef SOME_STRUCT_COMPARATOR_INCLUDED
#define SOME_STRUCT_COMPARATOR_INCLUDED

extern "C"
{
#include "SomeLibrary.h"
}

#include "CppUTestExt/MockSupport.h"

class SomeStructComparator : public MockNamedValueComparator
{
public:
    virtual bool isEqual(const void* object1, const void* object2);

    virtual SimpleString valueToString(const void* object);
};

#endif
