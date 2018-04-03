#ifndef SOME_STRUCT_COPIER_INCLUDED
#define SOME_STRUCT_COPIER_INCLUDED

#include "CppUTestExt/MockSupport.h"

extern "C"
{
#include "SomeLibrary.h"
}

class SomeStructCopier : public MockNamedValueCopier
{
public:
    virtual void copy(void* out, const void* in);
};

#endif
