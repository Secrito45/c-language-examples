#include <stdio.h>


#define ARRAY_LEN(array)    (sizeof(array) / sizeof(array[0]))

void array_of_strings_size(void)
{
    const char *const string_array[] = {"str1", "str2", "str3", "str4"};
    size_t str_array_size = sizeof(string_array);
    size_t str_array_size2 = ARRAY_LEN(string_array);

    printf("Size of string array: %ld\n", str_array_size);
    printf("Size2 of string array: %ld\n", str_array_size2);
    
    //string_array[0][3] = 'r'; // ILLEGAL
    //string_array[0] = "prr";    // ILLEGAL if defined char *const string_array[]

    for (int i = 0; i < ARRAY_LEN(string_array); i++)
    {
        printf("String at idx %d: %s\n", i, string_array[i]);
    }
}

int main(void)
{

    array_of_strings_size();
    return 0;
}