enable_language(CXX)

add_executable(Test_MockCopier
    AllTests.cpp
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
    NAME Test_MockCopier
    COMMAND Test_MockCopier
)
