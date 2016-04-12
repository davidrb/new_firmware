#include <rcc.h>
#include <rcc_registers.h>

void enable_pll() {
    /*
    *rcc::cr |= 0b1<<18;      // HSE Bypass
    *rcc::cr |= 0b1<<16;     // HSE On

    while(!( *rcc::cr & (0b1<<17) ));     // Wait until HSERDY
    */

    *rcc::cfgr &= ~(0b1111<<18);
    *rcc::cfgr |= (0b1110<<18);     // 64Mhz with HSI/2 as PLLSRC

    *rcc::cr |= (0b1<<24);          // Turn PLL On
    while(! (*rcc::cr & (0b1<<25) )); // Wait until PLLRDY

    //*rcc::cfgr &= ~(0b11);
    //*rcc::cfgr |= (0b10);           // select PLL as SYSCLK

    //while((*rcc::cfgr & (0b11<<2)) != (0b10<<2) );
}
