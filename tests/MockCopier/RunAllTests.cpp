#include "CppUTest/CommandLineTestRunner.h"
#include "CppUTest/TestPlugin.h"
#include "CppUTest/TestRegistry.h"
#include "CppUTestExt/MockSupportPlugin.h"
#include "SomeStructCopier.h"

int main(int ac, char **av)
{
    SomeStructCopier some_struct_copier;
    MockSupportPlugin mockPlugin;

    mockPlugin.installCopier("SOME_STRUCT", some_struct_copier);
    TestRegistry::getCurrentRegistry()->installPlugin(&mockPlugin);
    return CommandLineTestRunner::RunAllTests(ac, av);
}
