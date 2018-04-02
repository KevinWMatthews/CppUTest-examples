#ifndef SOME_LIBRARY_INCLUDED
#define SOME_LIBRARY_INCLUDED

// These functions do pretty much nothing.
// They will actually print a message to the console when called from production code.
// This is to demonstrate that the production code is not executed during tests.


// Simplest case - no arguments, no return value.
void SomeLibrary_DoesNothing(void);

// Single parameter
void SomeLibrary_DoesNothingWithParameter(int param);

#endif
