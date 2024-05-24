#include "lib/printf/printf.h"
#include <stddef.h>
#include "gd32f3x0.h"
#include "gd32f3x0_fmc.h"
#include "gd32f3x0_spi.h"
#include "st7735s.h"
#include "stdbool.h"
//#include "display.h"
#include "delay.h"

void write_to_flash(uint32_t address, uint32_t data) {
    // NOTE: Did not work for me - Tunas1337
    
    // Unlock the Flash Program Erase controller
    fmc_unlock();

    // Clear all pending flags
    fmc_flag_clear(FMC_FLAG_END | FMC_FLAG_WPERR | FMC_FLAG_PGERR );

    // Erase the page
    fmc_page_erase(address);

    // Write the data
    fmc_word_program(address, data);

    // Lock the Flash Program Erase controller
    fmc_lock();
}

/*
 * Device Flash Size Register, KB as unit
 */
#define DEV_FLASH_SIZE (REG32(0x1FFFF7E0U))
/*
 * Device Type Register
 * 2-403,4-413,5-415,7-403A,
 * 8-407,9-421,D-435,E-437
 */
#define DEV_DEV_TYPE (REG32(0x1FFFF7F3U) & 0xFF)

#define FLASH_READ_BUF_SIZE 256
volatile uint32_t FLASH_READ_BUF[FLASH_READ_BUF_SIZE] = {0};

void dumpflash(uint32_t addr, uint32_t len);
void flash_read_words(uint32_t addr, uint32_t *data, uint32_t len);
void hex_dump(void *data, int len, int startAddress);
void com_usart_init(void);

void dumpflash(uint32_t addr, uint32_t len) {
  // /* Address out of range. */
  // if (addr > (DEV_FLASH_SIZE * 1024) ||
  //     (addr + len) > (DEV_FLASH_SIZE * 1024)) {
  //   return;
  // }

  /* Address is not 4 bytes aligned, will start from (addr - addr % 4) */
  if (addr % 4 != 0) {
    addr = addr - addr % 4;
    len = len + addr % 4;
  }

  /* Length is not 4 bytes aligned, will read (4 * ((len / 4) + 1))) bytes. */
  if (len % 4 != 0) {
    len = 4 * ((len / 4) + 1);
  }

  uint32_t *readBuf = (uint32_t *)FLASH_READ_BUF;

  /* First Page Read */
  uint32_t pageEnd = (addr & 0xFFFFFF00) + FLASH_READ_BUF_SIZE;
  uint32_t pageLen = pageEnd - addr;
  if (pageLen > len) {
    pageLen = len;
  }
  flash_read_words(addr, readBuf, pageLen / 4);
  hex_dump(readBuf, pageLen, addr);

  uint32_t leftLen = (len - pageLen);

  /* Batch Read left pages if needed */
  while (leftLen > 0) {
    addr += pageLen;
    if (leftLen > FLASH_READ_BUF_SIZE) {
      pageLen = FLASH_READ_BUF_SIZE;
    } else {
      pageLen = leftLen;
    }
    flash_read_words(addr, readBuf, pageLen / 4);
    hex_dump(readBuf, pageLen, addr);

    leftLen -= pageLen;
  }
}

void flash_read_words(uint32_t addr, uint32_t *data, uint32_t len) {
  uint8_t i;
  for (i = 0; i < len; i++) {
    data[i] = *(__IO int32_t *)addr;
    addr += 4;
  }
}

static char *itohexa_helper(char *dest, unsigned x, int padding) {
  if (--padding)
    dest = itohexa_helper(dest, x >> 4, padding); // recursion
  *dest++ = "0123456789ABCDEF"[x & 0xF];          // mask and offset
  return dest;
}


/*!
    \brief      main function
    \param[in]  none
    \param[out] none
    \retval     none
*/
int main(void)
{
    //84MHz internal RC
    SystemInit();

    // /* enable the systick */
    SysTick_Config(SystemCoreClock / 10000);
    // NVIC_SetPriority(SysTick_IRQn, 0x00);

    //printf("Hello, World!\r\n");
    gpio_config();
    
    ST7735S_Init();
    ST7735S_SetColor(0, 0, 0);
    ST7735S_SetPixelFormat(COLOR_FORMAT_RGB666);
    ST7735S_Fill_Rect(0, 0, 160, 128);

    while (true) {
    }
}

char *itohexa(char *dest, unsigned x, int padding) {
  *itohexa_helper(dest, x, padding) = '\0';
  return dest;
}

/* Print memory data as hex aligned by 16 byte with line address */
void hex_dump(void *data, int len, int startAddress) {
  char array[8];
  int startAddressAlign = startAddress & 0xFFFFFFF0;
  int currentAddress = startAddressAlign;
  bool firstLine = true;

  for (size_t i = 0; i < len; i++) {
    if (currentAddress % 16 == 0) {
      printf("0x");
      printf(itohexa(array, currentAddress, 8));

      if (firstLine) {
        firstLine = false;
        for (size_t j = 0; j < (startAddress & 0x0F); j++) {
          printf("   ");
          currentAddress++;
        }
      }
    }
    printf(" ");
    printf(itohexa(array, ((uint8_t *)data)[i], 2));

    currentAddress++;
    if (currentAddress % 16 == 0) {
      printf("\r\n");
    }
  }
}


/*!
    \brief      initialize the USART configuration of the com
    \param[in]  none
    \param[out] none
    \retval     none
*/
void com_usart_init(void)
{
    /* enable GPIO clock */
    rcu_periph_clock_enable(RCU_GPIOA);
    /* enable USART clock */
    rcu_periph_clock_enable(RCU_USART0);

    /* connect port to USART TX */
    gpio_af_set(GPIOA, GPIO_AF_1, GPIO_PIN_9);

    /* connect port to USART RX */
    gpio_af_set(GPIOA, GPIO_AF_1, GPIO_PIN_10);

    /* configure USART TX as alternate function push-pull */
    gpio_mode_set(GPIOA, GPIO_MODE_AF, GPIO_PUPD_PULLUP, GPIO_PIN_9);
    gpio_output_options_set(GPIOA, GPIO_OTYPE_PP, GPIO_OSPEED_10MHZ, GPIO_PIN_9);

    /* configure USART RX as alternate function push-pull */
    gpio_mode_set(GPIOA, GPIO_MODE_AF, GPIO_PUPD_PULLUP, GPIO_PIN_10);
    gpio_output_options_set(GPIOA, GPIO_OTYPE_PP, GPIO_OSPEED_10MHZ, GPIO_PIN_10);

    /* configure USART */
    usart_deinit(USART0);
    usart_word_length_set(USART0, USART_WL_8BIT);
    usart_stop_bit_set(USART0, USART_STB_1BIT);
    usart_parity_config(USART0, USART_PM_NONE);
    usart_baudrate_set(USART0, 115200U);
    usart_receive_config(USART0, USART_RECEIVE_ENABLE);
    usart_transmit_config(USART0, USART_TRANSMIT_ENABLE);
    usart_enable(USART0);
}

/* retarget the C library printf function to the USART */
int fputc(int ch, uint8_t *f)
{
    usart_data_transmit(USART0, (uint8_t) ch);
    while(RESET == usart_flag_get(USART0, USART_FLAG_TBE));
    return ch;
}

uint8_t uart_getchar(void) {return 0;}

// This function is called by printf to output data
void _putchar(char character)
{
	usart_data_transmit(USART0, character);
	while(usart_flag_get(USART0, USART_FLAG_TBE)==RESET);
}

