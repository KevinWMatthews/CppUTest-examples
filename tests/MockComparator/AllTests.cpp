#include "CppUTest/CommandLineTestRunner.h"
#include "CppUTest/TestPlugin.h"
#include "CppUTest/TestRegistry.h"
#include "CppUTestExt/MockSupportPlugin.h"
#include "SomeStructComparator.h"
#include "HiddenStructComparator.h"

int main(int ac, char **av)
{
    SomeStructComparator some_struct_comparator;
    HiddenStructComparator hidden_struct_comparator;
    MockSupportPlugin mockPlugin;

    mockPlugin.installComparator("SOME_STRUCT", some_struct_comparator);
    mockPlugin.installComparator("HIDDEN_STRUCT", hidden_struct_comparator);
    TestRegistry::getCurrentRegistry()->installPlugin(&mockPlugin);
    return CommandLineTestRunner::RunAllTests(ac, av);
}
