#include "CppUTest/CommandLineTestRunner.h"
#include "CppUTest/TestPlugin.h"
#include "CppUTest/TestRegistry.h"
#include "CppUTestExt/MockSupportPlugin.h"
#include "SomeStructCopier.h"
#include "SomeStructInitParamsComparator.h"
#include "HiddenStructCopier.h"

int main(int ac, char **av)
{
    SomeStructCopier some_struct_copier;
    SomeStructInitParamsComparator some_struct_init_params_comparator;
    HiddenStructCopier hidden_struct_copier;
    MockSupportPlugin mockPlugin;

    mockPlugin.installCopier("SOME_STRUCT", some_struct_copier);
    mockPlugin.installComparator("SOME_STRUCT_INIT_PARAMS", some_struct_init_params_comparator);
    mockPlugin.installCopier("HIDDEN_STRUCT", hidden_struct_copier);
    TestRegistry::getCurrentRegistry()->installPlugin(&mockPlugin);
    return CommandLineTestRunner::RunAllTests(ac, av);
}
