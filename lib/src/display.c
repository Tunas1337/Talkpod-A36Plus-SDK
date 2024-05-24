#include "gd32f3x0_spi.h"
#include "gd32f3x0_gpio.h"
#include "delay.h"
#include "display.h"
#include "../printf/printf.h"

typedef uint8_t byte;

void DISPLAY_Initialize(void)
{
  gpio_bit_set(GPIOB,GPIO_PIN_12);
  delay_1ms(1);
  gpio_bit_reset(GPIOB,GPIO_PIN_12);
  delay_1ms(1);
  gpio_bit_set(GPIOB,GPIO_PIN_12);
  delay_1ms(120);
  SPI_SendCommand(ST7735S_CMD_SLPOUT);
  delay_1ms(0x78);
  SPI_SendCommand(ST7735S_CMD_FRMCTR1);
  SPI_SendByte(5);
  SPI_SendByte(0x3a);
  SPI_SendByte(0x3a);
  SPI_SendCommand(ST7735S_CMD_FRMCTR2);
  SPI_SendByte(5);
  SPI_SendByte(0x3a);
  SPI_SendByte(0x3a);
  SPI_SendCommand(ST7735S_CMD_FRMCTR3);
  SPI_SendByte(5);
  SPI_SendByte(0x3a);
  SPI_SendByte(0x3a);
  SPI_SendByte(5);
  SPI_SendByte(0x3a);
  SPI_SendByte(0x3a);
  SPI_SendCommand(ST7735S_CMD_INVCTR);
  SPI_SendByte(3);
  SPI_SendCommand(ST7735S_CMD_PWCTR1);
  SPI_SendByte(0x62);
  SPI_SendByte(2);
  SPI_SendByte(4);
  SPI_SendCommand(ST7735S_CMD_PWCTR2);
  SPI_SendByte(0xc0);
  SPI_SendCommand(ST7735S_CMD_PWCTR3);
  SPI_SendByte(0xd);
  SPI_SendByte(0);
  SPI_SendCommand(ST7735S_CMD_PWCTR4);
  SPI_SendByte(0x8d);
  SPI_SendByte(0x6a);
  SPI_SendCommand(ST7735S_CMD_PWCTR5);
  SPI_SendByte(0x8d);
  SPI_SendByte(0xee);
  SPI_SendCommand(ST7735S_CMD_VMCTR1);
  SPI_SendByte(0x12);
  SPI_SendCommand(ST7735S_CMD_GMCTRP1);
  SPI_SendByte(3);
  SPI_SendByte(0x1b);
  SPI_SendByte(0x12);
  SPI_SendByte(0x11);
  SPI_SendByte(0x3f);
  SPI_SendByte(0x3a);
  SPI_SendByte(0x32);
  SPI_SendByte(0x34);
  SPI_SendByte(0x2f);
  SPI_SendByte(0x2b);
  SPI_SendByte(0x30);
  SPI_SendByte(0x3a);
  SPI_SendByte(0);
  SPI_SendByte(1);
  SPI_SendByte(2);
  SPI_SendByte(5);
  SPI_SendCommand(ST7735S_CMD_GMCTRN1);
  SPI_SendByte(3);
  SPI_SendByte(0x1b);
  SPI_SendByte(0x12);
  SPI_SendByte(0x11);
  SPI_SendByte(0x32);
  SPI_SendByte(0x2f);
  SPI_SendByte(0x2a);
  SPI_SendByte(0x2f);
  SPI_SendByte(0x2e);
  SPI_SendByte(0x2c);
  SPI_SendByte(0x35);
  SPI_SendByte(0x3f);
  SPI_SendByte(0);
  SPI_SendByte(0);
  SPI_SendByte(1);
  SPI_SendByte(5);
  SPI_SendCommand(ST7735S_CMD_GCV);
  SPI_SendByte(0x8c);
  SPI_SendCommand(ST7735S_CMD_MADCTL);
  SPI_SendByte(0xa8);
  SPI_SendCommand(ST7735S_CMD_COLMOD);
  SPI_SendByte(5);
  //DISPLAY_FillColor(0);
  SPI_SendCommand(ST7735S_CMD_DISPON);
  return;
}

uint32_t check_spi_status_reg(uint32_t *param_1,uint32_t param_2)

{
  uint32_t uVar1;
  
  uVar1 = param_1[2] & param_2;
  if (uVar1 != 0) {
    uVar1 = 1;
  }
  return uVar1;
}

void set_spi_data_register(uint32_t *param_1,uint32_t param_2)

{
  param_1[3] = param_2;
  return;
}


void SPI_SendCommand(ST7735S_Command_t param_1)
{
  uint32_t uVar1;
  printf("SPI_SendCommand %x\r\ncheese\r\n", param_1);
  gpio_bit_reset(GPIOB,0b00000100);
  gpio_bit_reset(GPIOB,0b0000010000000000);
  do {
                    /* check if transmit buffer empty */
	uVar1 = check_spi_status_reg(SPI1, 0x2);
  } while (uVar1 == 0);
  // Set SPI data register
  set_spi_data_register(SPI1, param_1);
  do {
	// Check if SPI status register is empty
	uVar1 = check_spi_status_reg(SPI1, 0x2);
  } while (uVar1 == 0);
  gpio_bit_set(GPIOB,4);
  return;
}

void SPI_SendByte(uint8_t data)
{
	uint32_t uVar1;
  printf("SPI_SendByte %x\r\ncheese\r\n", data);
  gpio_bit_reset(GPIOB,0b00000100);
  gpio_bit_set(GPIOB,0b0000010000000000);
  do {
                    /* check if transmit buffer empty */
	uVar1 = check_spi_status_reg(SPI1, 0x2);
  } while (uVar1 == 0);
  // Set SPI data register
  set_spi_data_register(SPI1, data);
  do {
	// Check if SPI status register is empty
	uVar1 = check_spi_status_reg(SPI1, 0x2);
  } while (uVar1 == 0);
  gpio_bit_set(GPIOB,4);
  return;
}


void DISPLAY_WritePixel(uint16_t param_1,uint32_t param_2,uint32_t param_3)

{
  uint8_t bVar1;
  uint8_t bVar2;
  
  SPI_SendCommand(ST7735S_CMD_CASET);
  bVar1 = (uint8_t)((uint16_t)(param_1 + 0x20) >> 8);
  SPI_SendByte(bVar1);
  bVar2 = (uint8_t)(param_1 + 0x20);
  SPI_SendByte(bVar2);
  SPI_SendByte(bVar1);
  SPI_SendByte(bVar2);
  SPI_SendCommand(ST7735S_CMD_RASET);
  bVar2 = (uint8_t)(param_2 >> 8);
  SPI_SendByte(bVar2);
  SPI_SendByte((uint8_t)param_2);
  SPI_SendByte(bVar2);
  SPI_SendByte((uint8_t)param_2);
  SPI_SendCommand(ST7735S_CMD_RAMWR);
  SPI_SendByte((uint8_t)(param_3 >> 8));
  SPI_SendByte((uint8_t)param_3);
  return;
}


void DISPLAY_FillColor(uint16_t param_1)

{
  DISPLAY_DrawRectangle(0,0,0x80,0x80,param_1);
  return;
}


void DISPLAY_DrawRectangle(int start_x,uint32_t start_y,int end_x,int end_y,uint16_t color)

{
  uint32_t width;
  uint32_t height;
  uint32_t uVar1;
  
  width = end_x - start_x & 0xffff;
  height = end_y - start_y & 0xffff;
  uVar1 = 0;
  if (end_x != 0) {
    ST7735_SetAddrWindow(start_x,start_y,width,height);
    ST7735S_SetAddress(start_x,start_y);
                    /* RAM Write */
    SPI_SendCommand(ST7735S_CMD_RAMWR);
    for (; uVar1 < (width * height & 0xffff); uVar1 = uVar1 + 1 & 0xffff) {
      SPI_SendByte((uint8_t)(color >> 8));
      SPI_SendByte((uint8_t)color);
    }
  }
  return;
}


void ST7735_SetAddrWindow(uint32_t start_x,uint32_t start_y,int width,int height)

{
  int iVar1;
  int iVar2;
  uint32_t uVar3;
  
  uVar3 = start_x + 32 & 0xffff;
  iVar1 = uVar3 + width + -1;
  iVar2 = start_y + height + -1;
                    /* Column addr set */
  SPI_SendCommand(ST7735S_CMD_CASET);
  SPI_SendByte((byte)(uVar3 >> 8));
  SPI_SendByte((byte)(start_x + 32));
  SPI_SendByte((byte)((uint32_t)iVar1 >> 8));
  SPI_SendByte((byte)iVar1);
                    /* Row addr set */
  SPI_SendCommand(ST7735S_CMD_RASET);
  SPI_SendByte((byte)(start_y >> 8));
  SPI_SendByte((byte)start_y);
  SPI_SendByte((byte)((uint32_t)iVar2 >> 8));
  SPI_SendByte((byte)iVar2);
  return;
}

void ST7735S_SetAddress(uint32_t start_x,uint32_t start_y)

{
                    /* Column address */
  SPI_SendCommand(ST7735S_CMD_CASET);
  SPI_SendByte((byte)(start_x + 0x20 >> 8));
  SPI_SendByte((byte)(start_x + 0x20));
                    /* Row address */
  SPI_SendCommand(ST7735S_CMD_RASET);
  SPI_SendByte((byte)(start_y >> 8));
  SPI_SendByte((byte)start_y);
  return;
}



