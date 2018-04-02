enable_language(C)

add_library(SomeLibrary
    "${CMAKE_HOME_DIRECTORY}/include/SomeLibrary.h"
    SomeLibrary.c
)
target_include_directories(SomeLibrary
    PUBLIC
        "${CMAKE_HOME_DIRECTORY}/include"
)
set_target_properties(SomeLibrary PROPERTIES
    LINKER_LANGUAGE C
)
add_library(SomeLibrary::SomeLibrary ALIAS SomeLibrary)
