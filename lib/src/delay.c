#include "delay.h"
void delayms(uint32_t t)
{
    uint32_t i;
    for(i=0;i<t;i++)
    {
        uint32_t j;
        for(j=0;j<14400;j++)
        {
            __asm("nop");
        }
    }
}