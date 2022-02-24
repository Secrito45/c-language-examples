#include <stdio.h>

typedef int * P_INT;

int glob_value = 5555;
int *glob_value_p = &glob_value;

void foo(P_INT *value_pointer_pointer)
{
    printf("[foo] Pointer to pointer:\t%p \n", value_pointer_pointer);
    printf("[foo] Pointer to value:\t\t%p \n", *value_pointer_pointer);
    printf("[foo] Value:\t\t\t%u \n", **value_pointer_pointer);
    printf("\n");
}

void assing_pointer(int *copy_pointer_int /* Copy of pointer_int */)
{   
    //> Copy pointer_to_pointer -> 1234
    //> glob_value_p -> 5555
    copy_pointer_int = glob_value_p;
    //> Copy pointer_to_pointer -> 5555
}
// Copy pointer_to_pointer is deleted

void assing_pointer_v2(int **pointer_to_pointer /* Pointer to pointer_int */)
{   
    //> Copy pointer_to_pointer -> pointer_int -> 1234
    //> glob_value_p -> 5555
    *pointer_to_pointer = glob_value_p;
    //> Copy pointer_to_pointer -> glob_value_p -> 5555
    //> glob_value_p -> 5555
}

void pointer_test(void)
{
    printf("Hello Pointers \n");

    int value = 1234;
    int *pointer_int;
    pointer_int = &value;

    foo(&pointer_int);

    printf("Value pointed by pointer_int: %u \n", *pointer_int);
    //> pointer_int -> 1234
    assing_pointer(pointer_int);
    //> Still pointer_int -> 1234
    printf("After assign, value pointed by pointer_int: %u \n", *pointer_int);
    //> pointer_int -> 1234
    assing_pointer_v2(&pointer_int);
    //> pointer_int -> 5555
    printf("After assign 2, value pointed by pointer_int: %u \n", *pointer_int);

    foo(&pointer_int);
}

void pointer_value_assign(void)
{
    int val = 2;
    int *val_p = &val;

    *val_p = *val_p + *val_p;
    printf("After assign, val_p equals: %u \n", *val_p);
}

typedef struct
{
    unsigned int value_a;
    unsigned int value_b;
}data_ts;

typedef struct 
{
    data_ts data_buf_a;
    data_ts data_buf_b;
}data_buf_ts;

void print_func(data_ts *data)
{
    printf("Values in data %d and %d \n", data->value_a, data->value_b);
}

void print_func_2(data_buf_ts *data)
{
    printf("Values in data %d and %d \n", data->data_buf_a.value_a, data->data_buf_a.value_b);
}

void making_pointer_of_structure_element(void)
{
    data_buf_ts data_bufs;
    data_buf_ts *shm_area;
    shm_area = &data_bufs;

    shm_area->data_buf_a.value_a = 12;
    shm_area->data_buf_a.value_b = 45;

    print_func(&shm_area->data_buf_a);
    print_func_2(shm_area);
}

void multiply_values(int *array, int a_len)
{
    for (int i=0; i < a_len; i++)
    {
        array[i] = array[i] * array[i];
    }
}

void print_array_of_values(int *array, int a_len)
{
    printf("Values: ");
    for (int i=0; i < a_len-1; i++)
    {
        printf("%d,\t", array[i]);
    }
    printf("%d\n", array[a_len-1]);
}

void change_array_data_in_func(void)
{
    int values[] = {1, 2, 3, 4, 5};
    int len = sizeof(values) / sizeof(int);

    print_array_of_values(values, len);

    multiply_values(values, len);

    print_array_of_values(values, len);
}

int main ()
{
    change_array_data_in_func();
    return 0;
}