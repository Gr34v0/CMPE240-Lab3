#include "gpio.h"
#include "system_timer.h"
#include "uart.h"

void blink_once()
{
    //toggle clear register for the chosen pin
    // GPIO3 bits 11-9  bit 001 = output
    // Turn LED on
    gpio[GPSET0] |= (1 << 3);
    timer_delay_sec(1);
    //toggle set register for the chosen pin
    // Turn LED off
    gpio[GPCLR0] |= (1 << 3);
}

//On for one second, off for 5 seconds, on for one second......
void blink_code(uint32_t err)
{
    for(int i = 0; i < err; ++i)
    {
        // Blink the LED
        blink_once();
        timer_delay_sec(1);
    }
    // Delay for desired time
    timer_delay_sec(5);
}

int main()
{
    // Init GPIO select for external LED
    //GPIO3
    gpio[GPFSEL0] = (1 << 9);
    // Init uart for debugging purposes
    init_uart();
    // Provide a buffer size for debug prints
    uint32_t buffer_size = 80;
    // You might need a count for something
    uint32_t count = 1;
    // Mainline loop
    while (1)
    {
        count = count % 10;
        // implement error code described in lab
        if(count != 0){
            //call blink_code at some point
            //error code has to match 900000 if lab 1 was right
            blink_code(count);
        } 
        ++count;
    }
    return 0;
}
