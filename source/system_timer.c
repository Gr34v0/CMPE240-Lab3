#include "system_timer.h"

#define checkTimerMatch(bit) ((sys_timer[SYS_TIMER_CS] & (1 << bit)) == 0 ) //Returns True when bit at "bit"
                                                                            // is 1
void timer_delay_us(uint32_t delayUs)
{
    //Page 172 of manual
    // First, get the current count of the timer.
    uint32_t x = sys_timer[SYS_TIMER_CLO];
    // Next, add the delay to the current count.
    // and, put that into the C0 timer register;
    x = x + delayUs;
    sys_timer[SYS_TIMER_C0] = x;
    // Clear the M0 timer register.
    sys_timer[SYS_TIMER_CS] &= (0 << 0);
    // Now we spin until the CS register
    // has a 1 in the 0 position, then we know
    // our timer has expired.
    while(checkTimerMatch(0)){ //0th bit for the macro defined above
        //NOOP
    }
}

void timer_delay_ms(uint32_t delayMs)
{
    // scale the microsecond delay appropriately
    timer_delay_us(1000 * delayMs);
}

void timer_delay_sec(uint32_t delaySec)
{
    // scale the microsecond delay appropriately
    timer_delay_us(1000000 * delaySec); 
}
