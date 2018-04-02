enable_language(CXX)

add_executable(Test_Mock
    RunAllTests.cpp
    Test_Mock.cpp
    "${CMAKE_HOME_DIRECTORY}/mocks/MockSomeLibrary.cpp"
)
target_link_libraries(Test_Mock
    PRIVATE
        CppUTest
        CppUTestExt
        SomeLibrary::SomeLibrary
)
add_test(
    NAME CTest_Mock
    COMMAND Test_Mock
)
