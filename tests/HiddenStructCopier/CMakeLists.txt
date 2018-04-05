enable_language(CXX)

add_executable(Test_HiddenStructCopier
    AllTests.cpp
    Test_HiddenStructCopier.cpp
)
target_link_libraries(Test_HiddenStructCopier
    PRIVATE
        CppUTest
        MockSomeLibrary::MockSomeLibrary
        SomeLibrary::SomeLibrary
)
add_test(
    NAME Test_HiddenStructCopier
    COMMAND Test_HiddenStructCopier
)
