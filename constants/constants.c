#include <stdio.h>

//> Functions with constant parameter
int takes_const_int_as_arg(const int arg)
{
    //> Causes error: increment of read-only parameter ‘arg’
    //return arg++;

    int temp = arg;
    return temp++;
}

int takes_const_int_pointer_as_arg(const int * arg)
{
    //> Causes error: assignment of read-only location ‘*arg’
    //*arg = (*arg) * (*arg);

    return 0;
}

int main(void)
{

    return 0;
}