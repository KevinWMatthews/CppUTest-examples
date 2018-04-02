enable_language(CXX)

add_executable(Test_MockComparator
    RunAllTests.cpp
    Test_MockComparator.cpp
    SomeStructComparator.h
    SomeStructComparator.cpp
    "${CMAKE_HOME_DIRECTORY}/mocks/MockSomeLibrary.cpp"
)
target_link_libraries(Test_MockComparator
    PRIVATE
        CppUTest
        CppUTestExt
        SomeLibrary::SomeLibrary
)
add_test(
    NAME CTest_MockComparator
    COMMAND Test_MockComparator
)
