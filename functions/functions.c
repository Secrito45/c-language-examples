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