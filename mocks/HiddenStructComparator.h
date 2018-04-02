#ifndef HIDDEN_STRUCT_COMPARATOR_INCLUDED
#define HIDDEN_STRUCT_COMPARATOR_INCLUDED

extern "C"
{
#include "SomeLibrary.h"
}

#include "CppUTestExt/MockSupport.h"

class HiddenStructComparator : public MockNamedValueComparator
{
public:
    virtual bool isEqual(const void* object1, const void* object2);
    virtual SimpleString valueToString(const void* object);
};

#endif
