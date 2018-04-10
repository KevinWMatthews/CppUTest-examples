#ifndef SOME_LIBRARY_INCLUDED
#define SOME_LIBRARY_INCLUDED

// These functions do pretty much nothing.
// They will actually print a message to the console when called from production code.
// This is to demonstrate that the production code is not executed during tests.


// Simplest case - no arguments, no return value.
void SomeLibrary_DoesNothing(void);

// Single parameter
void SomeLibrary_DoesNothingWithParameter(int param);

// Pass struct as parameter
typedef struct SOME_STRUCT
{
    int thing1;
    int thing2;
} SOME_STRUCT;
void SomeLibrary_DoesNothingWithStructParameter(SOME_STRUCT *self);

// Modify the struct that is passed.
// The library does some internal magic that external modules can't see.
void SomeLibrary_FillStructParameter(SOME_STRUCT *self);

// Manually fill the struct from the other parameters.
void SomeLibrary_FillStructFromValues(int thing1, int thing2, SOME_STRUCT *self);

// Use a mock copier to fill the struct from other parameters.
void SomeLibrary_FillStructFromValuesWithCopier(int thing1, int thing2, SOME_STRUCT *self);

typedef struct SOME_STRUCT_INIT_PARAMS
{
    int init_value1;
    int init_value2;
} SOME_STRUCT_INIT_PARAMS;
// Manually fill the struct from the struct of initialization parameters.
void SomeLibrary_FillStructFromStruct(SOME_STRUCT_INIT_PARAMS *params, SOME_STRUCT *self);

// Use a mock copier fill the struct from the struct of initialization parameters.
void SomeLibrary_FillStructFromStructWithCopier(SOME_STRUCT_INIT_PARAMS *params, SOME_STRUCT *self);

// Return an integer value
int SomeLibrary_ReturnInt(void);

// Return an integer value, alternate implementation of actual call
int SomeLibrary_ReturnInt2(void);

// Return a void pointer.
void * SomeLibrary_ReturnVoidPointer(void);

// Return an int pointer.
int * SomeLibrary_ReturnIntPointer(void);

// Return a pointer to a struct.
SOME_STRUCT * SomeLibrary_ReturnStructPointer(void);

/*
 * Show that copiers and comparators can work when data hiding is used.
 * The production code struct definition is not available to test code,
 * so a mock definition must provided in test code.
 * In this case a mock header file defines the struct.
 */
typedef struct HIDDEN_STRUCT_DEFINITION * HIDDEN_STRUCT_HANDLE;

// Compare a struct that is hidden behind a typedef'ed pointer.
void SomeLibrary_CompareHiddenStruct(HIDDEN_STRUCT_HANDLE handle);

// Copy a struct that is hidden behind a typedef'ed pointer.
void SomeLibrary_FillHiddenStruct(int value, HIDDEN_STRUCT_HANDLE handle);

#endif
