enable_language(CXX)

add_executable(Test_Basic
    RunAllTests.cpp
    Test_Basic.cpp
)
target_link_libraries(Test_Basic
    PRIVATE
        CppUTest
)
add_test(
    NAME CTest_Basic
    COMMAND Test_Basic
)
