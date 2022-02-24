#include <stdio.h>

/* FUNCTION POINTER */
void foo(void)
{
    printf("Hello World \n" );
}

void run_cp(void *cb)
{
   ((void (*)(void)) cb)();
}
/* END of FUNCTION POINTER */

/* ENDIANES TEST */
void value_endianes(void)
{
    unsigned long long  value64 = 0;
    unsigned int        value32 = 0;
    unsigned long       valueLong = 0;
    unsigned int        size64 = sizeof(value64);
    unsigned int        size32 = sizeof(value32);
    unsigned int        sizeLong = sizeof(valueLong);

    printf("Size of value64: %u Bytes; %u bits\n", size64, size64 * 8);
    printf("Size of value32: %u Bytes; %u bits\n", size32, size32 * 8);
    printf("Size of valueLong: %u Bytes; %u bits\n", sizeLong, sizeLong * 8);

    value64 = 0xf0f0c5c5beafbeaf;
    //unsigned int *ptr32 = (unsigned int *)(&value64);
    unsigned char *ptr = (unsigned char*)(&value64);
    // ptr32 should behave like array;

    for (int i = 0; i < 8; i++)
    {
        printf("ptr32[%d]: 0x%x;\n", i, ptr[i]);
    }
    //printf("ptr32[0]: 0x%08x; ptr32[1]: 0x%08x\n", ptr32[0], ptr32[1]);
    //> Prints : ptr32[0]: 0xc5c5beaf; ptr32[1]: 0xf0f0abab

    printf("value32: 0x%08x;\n", (unsigned int)(value64 >> 32));
    printf("value32: 0x%08x;\n", (unsigned int)(value64));
}
/* END of ENDIANES TEST */

void signed_value_assing_to_unsigned_int(void)
{
    unsigned int u_val = -8;
    signed int   s_val = -8;

    unsigned int u_sum = u_val - 8;
    unsigned int s_sum = s_val - 8;


    printf("unsigned value: 0x%08x; signed value: 0x%08x; \n", 
        u_val, s_val);
    printf("unsigned value: %d; signed value: %d; \n", 
        u_val, s_val);

    printf("unsigned value: 0x%08x; signed value: 0x%08x; \n", 
        u_sum, s_sum);
    printf("unsigned value: %d; signed value: %d; \n", 
        u_sum, s_sum);
}

float itof(int x)
{
    float result = 0;
    int mantissa = (x & 0x007FFFFF);
    int exponent = (x & 0x7F800000) >> 23;



    printf("%08x\n", mantissa);
    printf("%08x\n", exponent);
    printf("%f\n", ( 1.0 + ((float)mantissa / (0xFFFFFF)) ));

    return result;
}

int main(void)
{ 
    //float mv_scaler = 0x3aad03da / 1000000;
    //float uu_scaler = 0x3dc8e8a7 / 1000000;
    float mv_scaler = 0.00328;
    float uu_scaler = 0.0981;

    printf("%x\n", *((unsigned int *)&mv_scaler));

    //itof(0x3aad03da);

    return 0;
}