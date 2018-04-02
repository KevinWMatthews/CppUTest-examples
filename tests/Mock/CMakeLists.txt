enable_language(CXX)

add_executable(Test_Mock
    RunAllTests.cpp
    Test_Mock.cpp
)
target_link_libraries(Test_Mock
    PRIVATE
        CppUTest
)
add_test(
    NAME CTest_Mock
    COMMAND Test_Mock
)
