#include <stdio.h>    

//> WARNING! Bad way of using macros
#define ARRAY(i)            (array[i]&0xff)

int main()
{
    //> In this system int is 32 bit
    int value   = 0xAABBCCDD;
    //              ^~MSB  ^~LSB
    //> cast 4 Byte (32 / 8) long value to a array of 1 Byte long values.
    char *array = (char*)&value; 

    printf("value: 0x%X\n", value);
    printf("array: 0x%X%X%X%X\n", ARRAY(0), ARRAY(1), ARRAY(2), ARRAY(3));
    // PRINTS >> 0xDDCCBBAA, the value is stored as little-endian (LSB first).
    // big-endianness means that the value is stored in same order it's written.

    return 0;
}