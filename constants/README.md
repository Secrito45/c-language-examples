Const keyword meaning and usage in C language
=== 

Const keyword can be used to define variables as constant values. This means that the
value cannot be changed after its initialized. Also you cannot define an uninitialized
const variable.

If possible the compiler tires to place the const variables value to a ROM area in memory.
This way they does not take space from the RAM areas variables.

Like original variables, also pointers can be defined as constants, but it's important to understand
how the position of to const keyword relation to the pointer symbol effects the definition of the variable.

For example: `const void *myPointer` defines a constant value void pointed by pointer myPointer. This is identical to this form `void const myPointer`. With this variable the value pointed by the pointer cannot be
changed but the address pointed by myPointer can be changed.

The form `void *const myPointer` is the opposite. With this arrangement the value pointed by myPointer can be changed, but the address pointed by myPointer cannot. This is useful in cases where you cant to pass pointer to memory section where the data can be change but you want to make sure that the pointer to that section is memory cannot be changed.