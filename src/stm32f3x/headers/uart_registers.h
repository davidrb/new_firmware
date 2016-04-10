#ifndef UART_REGISTERS_H
#define UART_REGISTERS_H

#include <rcc_registers.h>

#include <cstdint>

template< std::uint32_t base, unsigned cfgr3_lsb, unsigned apb_num, unsigned apb_bit >
struct UART {
    static void enable_clock() {
        *rcc::cfgr3 &= ~0b11;
        *rcc::cfgr3 |= 0b1<<(cfgr3_lsb);

        if(apb_num == 1)  *rcc::apb1enr |= (0b1<<apb_bit);
        else              *rcc::apb2enr |= (0b1<<apb_bit);
    }

    static void set_baud() {
        *brr = 0x0341;      // use 9600 baud with fck = 8MHz
    }

    static void enable_tx() {
        *cr1 |= (0b1<<3); 
    }

    static void enable_rx() {
        *cr1 |= (0b1<<2);  
    }

    static void enable() {
        *cr1 |= (0b1<<0);   
    }

    static auto tx_empty() -> bool {
        return *isr & (0b1<<7);
    }

    static void transmit( std::uint8_t byte ) { 
        *tdr = byte;
    }

    static volatile constexpr auto base_ptr = (std::uint32_t *)base;

    static volatile constexpr auto 
        cr1 = base_ptr + 0x00/4,
        cr2 = base_ptr + 0x04/4,
        cr3 = base_ptr + 0x08/4,
        brr = base_ptr + 0x0C/4,
        gtpr = base_ptr + 0x10/4,
        rtor = base_ptr + 0x14/4,
        rqr = base_ptr + 0x18/4,
        isr = base_ptr + 0x1C/4,
        icr = base_ptr + 0x20/4,
        rdr = base_ptr + 0x24/4,
        tdr = base_ptr + 0x28/4;
};

using uart1 = UART<0x4001'3800, 0, 2, 14>;
using uart2 = UART<0x4001'4400, 16, 1, 17>;

#endif
