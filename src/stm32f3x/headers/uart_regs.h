#ifndef UART_REGS_H
#define UART_REGS_H

#include <cstdint>

template< std::uint32_t base >
struct UARTRegisters {
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

#endif
