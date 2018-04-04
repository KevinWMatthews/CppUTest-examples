#ifndef MOCK_SOME_LIBRARY_INCLUDED
#define MOCK_SOME_LIBRARY_INCLUDED

// Define the hidden structure for testing.
// The real version is hidden in production code.
typedef struct HIDDEN_STRUCT_DEFINITION
{
    int test_value;
} HIDDEN_STRUCT_DEFINITION;

#endif
