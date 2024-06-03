#include "main.h"
#include "dma.h"
#include "spi.h"

// Written by Jamiexu

uint8_t usart_tx[10];
uint8_t flash_data[W25Q16JV_SECTOR_SIZE] = {0};
uint8_t flash_data_text[16] = {0};
uint32_t current_addr = 0;

void bk4819_test(void)
{
    bk4819_write_reg(BK4819_REG_10, 0x8085);
    printf("BK4819 REG_10: 0x%x\n", bk4819_read_reg(BK4819_REG_10));
    printf("BK4819 REG_11: 0x%x\n", bk4819_read_reg(BK4819_REG_11));
    printf("BK4819 REG_12: 0x%x\n", bk4819_read_reg(BK4819_REG_12));
    printf("BK4819 REG_13: 0x%x\n", bk4819_read_reg(BK4819_REG_13));
    printf("BK4819 REG_14: 0x%x\n", bk4819_read_reg(BK4819_REG_14));
    printf("BK4819 REG_18: 0x%x\n", bk4819_read_reg(BK4819_REG_18));
    printf("BK4819 REG_19: 0x%x\n", bk4819_read_reg(BK4819_REG_19));
}

void bk1080_test(void)
{

    printf("Bk1080 REG0: 0x%x\n", bk1080_read_reg(BK1080_REG0)); // default 0x0006
    printf("Bk1080 REG1: 0x%x\n", bk1080_read_reg(BK1080_REG0)); // default 0x1080
    printf("Bk1080 REG2: 0x%x\n", bk1080_read_reg(BK1080_REG0)); // default 0x0000
    printf("Bk1080 REG3: 0x%x\n", bk1080_read_reg(BK1080_REG0)); // default 0x0000
    delay_1ms(1000);
}

int main(void)
{
    gpio_config();
    //  dma_config();
    spi_config();
    usart_config();
    //systick_config();
    //st7735s_init();
    // bk4819_init();


    uint8_t i;

    printf("Running...\n");
    while (1)
    {
        printf("Testing...\n");
        // bk1080_test();
        // bk4819_test();
        // // flash_dump();
        // for (uint32_t i = 0; i < 16; i++)
        // {
        //     /* code */
        //     w25q16jv_read_sector(i * 0xFF, flash_data);
        //     for (uint32_t i = 0; i < W25Q16JV_SECTOR_SIZE; i++)
        //     {

        //         printf("%x ", flash_data[i]);
        //         delay_1ms(100);
        //     }
        //     delay_1ms(500);
        // }

        //st7735s_test();
        delay_1ms(1000);
    }
}

uint8_t uart_getchar(void) {return 0;}

// This function is called by printf to output data
void _putchar(char character)
{
	usart_data_transmit(USART0, character);
	while(usart_flag_get(USART0, USART_FLAG_TBE)==RESET);
}