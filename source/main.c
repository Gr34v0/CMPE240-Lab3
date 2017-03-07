#include "gpio.h"
#include "system_timer.h"
#include "uart.h"

void blink_once()
{
    //toggle clear register for the chosen pin
    // GPIO3 bits 11-9  bit 001 = output
    // Turn LED on
    gpio[GPCLR0] |= (1 << 3);

    //apply a delay
    delay(countValue);

    //toggle set register for the chosen pin
    // Turn LED off
    gpio[GPSET0] |= (0 << 3);

    //apply a delay
    delay(countValue);
}

void blink_code(uint32_t err)
{
    for(int i = 0; i < err; ++i)
    {
        // Blink the LED

    }

    // Delay for desired time
    
}

int main()
{
    // Init GPIO select for external LED
    gpio[GPFSEL0] = 0x<SOMETHING>;

    // Init uart for debugging purposes
    init_uart();

    // Provide a buffer size for debug prints
    uint32_t buffer_size = 80

    // You might need a count for something
    uint32_t count = 1;

    // Mainline loop
    while (1)
    {
        // implement error code described in lab

        // call blink_code at some point
        blink_code(     );

    }
    
    return 0;
}
