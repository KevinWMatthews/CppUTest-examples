#include "CppUTest/CommandLineTestRunner.h"
#include "CppUTest/TestPlugin.h"
#include "CppUTest/TestRegistry.h"
#include "CppUTestExt/MockSupportPlugin.h"

extern "C"
{
#include "SomeLibrary.h"
}

class SomeStructComparator : public MockNamedValueComparator
{
public:
    virtual bool isEqual(const void* object1, const void* object2)
    {
        return true;
    }

    virtual SimpleString valueToString(const void* object)
    {
        return StringFrom(object);
    }
};

int main(int ac, char **av)
{
    SomeStructComparator some_struct_comparator;
    MockSupportPlugin mockPlugin;

    mockPlugin.installComparator("SOME_STRUCT", some_struct_comparator);
    TestRegistry::getCurrentRegistry()->installPlugin(&mockPlugin);
    return CommandLineTestRunner::RunAllTests(ac, av);
}
