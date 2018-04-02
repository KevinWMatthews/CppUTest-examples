enable_language(CXX)

add_library(MockSomeLibrary
    SomeStructComparator.h
    SomeStructComparator.cpp
    HiddenStructComparator.h
    HiddenStructComparator.cpp
    MockSomeLibrary.cpp
)
target_include_directories(MockSomeLibrary
    PUBLIC
        "${CMAKE_CURRENT_LIST_DIR}"
)
target_link_libraries(MockSomeLibrary
    PRIVATE
        CppUTest
        CppUTestExt
        SomeLibrary::SomeLibrary
)
add_library(MockSomeLibrary::MockSomeLibrary ALIAS MockSomeLibrary)
