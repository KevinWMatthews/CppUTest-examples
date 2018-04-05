enable_language(CXX)

add_executable(Test_SomeStructComparator
    AllTests.cpp
    Test_SomeStructComparator.cpp
)
target_link_libraries(Test_SomeStructComparator
    PRIVATE
        CppUTest
        MockSomeLibrary::MockSomeLibrary
        SomeLibrary::SomeLibrary
)
add_test(
    NAME Test_SomeStructComparator
    COMMAND Test_SomeStructComparator
)
