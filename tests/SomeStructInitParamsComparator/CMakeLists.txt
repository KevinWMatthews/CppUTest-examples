enable_language(CXX)

add_executable(Test_SomeStructInitParamsComparator
    AllTests.cpp
    Test_SomeStructInitParamsComparator.cpp
)
target_link_libraries(Test_SomeStructInitParamsComparator
    PRIVATE
        CppUTest
        MockSomeLibrary::MockSomeLibrary
        SomeLibrary::SomeLibrary
)
add_test(
    NAME CTest_SomeStructInitParamsComparator
    COMMAND Test_SomeStructInitParamsComparator
)
