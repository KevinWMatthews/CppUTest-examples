enable_language(CXX)

add_executable(Test_HiddenStructComparator
    AllTests.cpp
    Test_HiddenStructComparator.cpp
)
target_link_libraries(Test_HiddenStructComparator
    PRIVATE
        CppUTest
        MockSomeLibrary::MockSomeLibrary
        SomeLibrary::SomeLibrary
)
add_test(
    NAME Test_HiddenStructComparator
    COMMAND Test_HiddenStructComparator
)
