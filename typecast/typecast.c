#include <stdio.h>
#include <string.h>

void foo(void)
{
    unsigned int     u_val_32 = 0xABABEFEF;
    unsigned short   u_val_16 = 0;

    u_val_16 = (unsigned short)u_val_32;

    printf("u_val_32 after cast: %x \n", u_val_16);

    u_val_32 = 1 << 3;
    u_val_16 = 1 << 3;

    printf("AND result between values: %x \n", (u_val_16 & u_val_32));
}

void float_cast_to_integer(int float_as_int, float original_float)
{
    int retval = memcmp(&float_as_int, &original_float, sizeof(float));
    if (retval)
    {
        printf("Value's bit order differs\n");
    }
    else
    {
        printf("Value's bit order differs\n");
    }
}

void division_of_integers(void)
{
    int value = 289348;
    const int constant = 32768;

    printf("Not like this!: %.2f\n", (value / constant));
    printf("Little bit better: %.2f\n", (float)(value / constant));
    printf("This is the correct solution: %.2f\n", ((float) value / constant));
}

int main(void)
{
    //float some_float_value = 0.1234;
    //float_cast_to_integer(some_float_value, some_float_value);

    division_of_integers();

    return 0;
}