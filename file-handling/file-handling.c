#include <stdio.h>

int main(void)
{
    FILE *fd = NULL;
    char c[] = "Hello, file!\n";
    int test_data = 1234;
    fd = fopen("./test.bin", "wb");
    fwrite(&test_data, 4, 1, fd);
    fprintf(fd, "%c", '\n');
    fwrite(c, sizeof(c)-1, 1, fd);
    fwrite(c, 1, sizeof(c)-1, fd);

    fclose(fd);
    return 0;
}