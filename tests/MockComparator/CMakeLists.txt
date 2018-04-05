enable_language(CXX)

add_executable(Test_MockComparator
    AllTests.cpp
    Test_MockComparator.cpp
)
target_link_libraries(Test_MockComparator
    PRIVATE
        CppUTest
        CppUTestExt
        MockSomeLibrary::MockSomeLibrary
        SomeLibrary::SomeLibrary
)
add_test(
    NAME CTest_MockComparator
    COMMAND Test_MockComparator
)
