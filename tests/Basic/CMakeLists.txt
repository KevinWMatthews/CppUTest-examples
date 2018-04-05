enable_language(CXX)

add_executable(Test_Basic
    AllTests.cpp
    Test_Basic.cpp
)
target_link_libraries(Test_Basic
    PRIVATE
        CppUTest
)
add_test(
    NAME Test_Basic
    COMMAND Test_Basic
)
