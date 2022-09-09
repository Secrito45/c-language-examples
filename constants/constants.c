#include <stdio.h>

#define LEGAL_OP    1

//> Value pointed by arg cannot be changed, but value that arg points can.
int takes_const_int_pointer_as_arg(const int *arg)
{
    int temp = 123;
    
    printf("arg: %p\n", arg);
    printf("%d\n", *arg);
    
    arg = &temp;            //> OK 
    printf("arg: %p\n", arg);
    printf("%d\n", *arg);
    
    // *arg = temp          //> Not Ok
    //      or
    // arg[0] = temp        //> Not Ok

    return temp;
}

//> Value pointed by arg can be changed, but arg cannot be changed to point other value.
int takes_int_const_pointer_as_arg(int *const arg)
{
#if LEGAL_OP
    //>  These are legal operations
    *arg = (*arg) * (*arg);
    
    *arg = 321;
#else
    //> These are illegal operations
    arg = NULL           //> Not OK
    
    static int value = 1234;
    
    arg = &value;        // Also not OK
#endif

    return 0;
}

int main(void)
{
    int demon = 666;
    int *demon_prt = &demon;

    printf("demon_prt: %p\n", demon_prt);
    takes_const_int_pointer_as_arg(demon_prt);
    printf("demon_prt: %p\n", demon_prt);


    takes_int_const_pointer_as_arg(demon_prt);
    printf("demon * demon = %d \n", demon);

    return 0;
}