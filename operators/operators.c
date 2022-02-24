#include <stdio.h>

int main(void)
{
    int array[8], i, array_val;

    for (i = 0; i < sizeof(array) / sizeof(int); i++)
    {
        array[i] = i;
        printf("Array[%d] => %d \n", i, i);
    }
    i = 0;
    array_val = array[i+4];
    printf("Array[%d] => %d; i => %d \n", i, array_val, i);

    return 0;
}