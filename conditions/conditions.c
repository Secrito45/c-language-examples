#include <stdio.h>


struct example
{
    int value;
};


int main(void)
{   
    struct example *as_null = NULL;
    
    //if (as_null->value) //> Creates compile error
    if(as_null != NULL)
    {
        printf("The example evaluated as True\n");
    }
    else
    {
        printf("The example evaluated as False\n");
    }
    
    struct example value = { 1234 };
    struct example *with_value = &value;

    if (with_value != NULL)
    {
        printf("The example evaluated as True\n");
    }
    else
    {
        printf("The example evaluated as False\n");
    }

    if (as_null != NULL && with_value->value == 1234)
    {
        printf("The example evaluated as True\n");
    }
    else
    {
        printf("The example evaluated as False\n");
    }
}