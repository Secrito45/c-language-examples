#include <stdio.h>

#define ADC_MAX     ((1 << 16) - 1)
#define V_REF       3158

static int adc_to_mv(int adc)
{
    return (V_REF / ADC_MAX) * adc;
}

static int better_adc_to_mv(int adc)
{
    return (V_REF * adc) / ADC_MAX;
}

static int mv_to_temperature(int m_volts, float gain)
{
    return m_volts / gain;
}

int main(void)
{
    printf("ADC value as millivolts: %d\n", adc_to_mv(1639));
    printf("ADC value as millivolts: %d\n", better_adc_to_mv(1753));
    printf("ADC value as millivolts: %d\n", mv_to_temperature(better_adc_to_mv(1753), 0.32670));
    
    return 0;
}