#include <stdio.h>

int main(void)
{
    char *str_lit = "SOME STRING LITERAL";
    const char *const another_lit = "ANOTHER STRING LITERAL";

    char char_array[] = "this is a string in array";

    printf("%s\n", str_lit);
    str_lit = another_lit;
    printf("%s\n", str_lit);
    
    //str_lit[0] = ' '; //<< Not possible to do, points to area in ROM.
    //printf("%s\n", str_lit);
 
    str_lit = char_array;
    printf("%s\n", str_lit);

    str_lit[0] = ' '; // < Now this is legal to do, points to area in RAM
    printf("%s\n", str_lit);

    return 0;
}