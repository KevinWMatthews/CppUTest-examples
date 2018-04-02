enable_language(CXX)

add_executable(Test_SomeStructComparator
    RunAllTests.cpp
    Test_SomeStructComparator.cpp
)
target_link_libraries(Test_SomeStructComparator
    PRIVATE
        CppUTest
        MockSomeLibrary::MockSomeLibrary
        SomeLibrary::SomeLibrary
)
add_test(
    NAME CTest_SomeStructComparator
    COMMAND Test_SomeStructComparator
)
