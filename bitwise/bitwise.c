#include <stdio.h>

#define STX         0x02
#define COMMAND     0x4f5a

#define HEADER(code)    ((STX << 24) | (code << 8) | (0xff << 0))

/*enum Numbers {
    ONE = 1,
    TWO,
    THREE
};*/

void foo()
{
    //unsigned char word = 'S';
    //unsigned int testData = (word & 0x000000ff) | 0x10000000;
    //unsigned int testData = ((STX << 24) | (COMMAND << 8)) & 0xffffffff;
    unsigned int data = HEADER(COMMAND);
    printf("Testa data: 0x%x \n", data);
    data = ((STX << 24) | (COMMAND << 8) | (0xff << 0));
    printf("Testa data: 0x%08x \n", data);
    //printf("Hello Data");
}

void bar()
{
    __uint8_t array[] = {0xa5, 0xff};
    __uint16_t data = (array[0] << 8) | (array[1]);
    
    printf("Testa data: 0x%08x \n", data);  
}

void multiply_or_devide_value_with_power_of_two(void)
{
    unsigned long val = 10;

    val <<= 15; // Multiply value with the 2^15 (32 768)
    printf("val is %ld\n", val);

    printf("val equals %ld\n", val * 32768);
    
    val >>= 15; // Divide value with the 2^15
    printf("val is %ld\n", val);
}

int main(void) 
{
    unsigned char reg = 0b01001000;
    unsigned char flag= 0b00001000;
    printf("0x%02x \n", reg);
    printf("0x%02x \n", flag);
    printf("0x%02x \n", (reg & flag));
    return 0;
}