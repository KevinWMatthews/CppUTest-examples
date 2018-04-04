#ifndef HIDDEN_STRUCT_COPIER_INCLUDED
#define HIDDEN_STRUCT_COPIER_INCLUDED

#include "CppUTestExt/MockSupport.h"

class HiddenStructCopier: public MockNamedValueCopier
{
public:
    virtual void copy(void* out, const void* in);
};

#endif
