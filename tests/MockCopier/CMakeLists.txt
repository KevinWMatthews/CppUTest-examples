enable_language(CXX)

add_executable(Test_MockCopier
    RunAllTests.cpp
    Test_MockCopier.cpp
)
target_link_libraries(Test_MockCopier
    PRIVATE
        CppUTest
        CppUTestExt
        MockSomeLibrary::MockSomeLibrary
        SomeLibrary::SomeLibrary
)
add_test(
    NAME CTest_MockCopier
    COMMAND Test_MockCopier
)
