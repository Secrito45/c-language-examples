#include <stdio.h>

#define START_CODE(a, b)        ((a << 16) | (b << 8) | (0xff))
#define SELECT_BYTE(a, b)       ((char)((a >> b) & 0xff))

int main(void)
{
    int val  = START_CODE('M', 'P');
    printf("0x%08x\n", val);
    printf("Start code contains: %c%c\n", SELECT_BYTE(val, 16), SELECT_BYTE(val, 8));
    return 0;
}