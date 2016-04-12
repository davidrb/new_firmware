#ifndef UART_H
#define UART_H

#include <uart_regs.h>
#include <rcc_registers.h>

#include <cstdint>

template< typename regs, unsigned cfgr3_lsb, unsigned apb_num, unsigned apb_bit >
struct UART {
    static void enable_clock() {
        *rcc::cfgr3 &= ~(0b11<<cfgr3_lsb);
        *rcc::cfgr3 |= (0b1<<cfgr3_lsb);

        if(apb_num == 1)  *rcc::apb1enr |= (0b1<<apb_bit);
        else              *rcc::apb2enr |= (0b1<<apb_bit);
    }

    static void enable() {
        //*regs::brr = 0x0681;      // use 9600 baud with fck = 8MHz
        *regs::brr = 0x0341;      // use 9600 baud with fck = 8MHz
        //*regs::brr = 0x1A0A;      // use 9600 baud with fck = 8MHz
        *regs::cr1 |= (0b1<<3);  // enable tx
        *regs::cr1 |= (0b1<<2);  // enable rx
        *regs::cr1 |= (0b1<<0);   
    }

    static auto tx_empty() -> bool {
        return *regs::isr & (0b1<<7);
   }

    static void transmit( std::uint8_t byte ) { 
        *regs::tdr = byte;
    }
};

using uart1 = UART<UARTRegisters<0x4001'3800>, 0, 2, 14>;
using uart2 = UART<UARTRegisters<0x4001'4400>, 16, 1, 17>;

#endif
