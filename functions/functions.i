# 1 "functions.c"
# 1 "<built-in>"
# 1 "<command-line>"
# 31 "<command-line>"
# 1 "/usr/include/stdc-predef.h" 1 3 4
# 32 "<command-line>" 2
# 1 "functions.c"
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

int main(void)
{
    test();

    test_2();

    return 0;
}
