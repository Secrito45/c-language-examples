#include <stdio.h>

static inline void test(void)
{
    int i = 0;
    i++;
    i++;
    i++;
}

static void test_2(void)
{
    int j = 0;
    j++;
    j++;
    j++;
}

struct test_values
{
    int age;
    char name[32];
};

void print_test_values(struct test_values val)
{
    printf("User name is: %s, %d years old.\n", val.name, val.age);
}

int main(void)
{ 
    struct test_values test_val = {45, "Jane"};
    
    print_test_values(test_val);

    print_test_values((struct test_values){106, "Adolf"});

    return 0;
}