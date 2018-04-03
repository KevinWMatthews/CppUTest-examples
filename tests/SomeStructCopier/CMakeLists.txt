enable_language(CXX)

add_executable(Test_SomeStructCopier
    RunAllTests.cpp
    Test_SomeStructCopier.cpp
)
target_link_libraries(Test_SomeStructCopier
    PRIVATE
        CppUTest
        CppUTestExt
        MockSomeLibrary::MockSomeLibrary
        SomeLibrary::SomeLibrary
)
add_test(
    NAME CTest_SomeStructCopier
    COMMAND Test_SomeStructCopier
)
