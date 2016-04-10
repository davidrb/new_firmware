#ifndef GPIO_REGS_H
#define GPIO_REGS_H

#include <cstdint>

template< std::uint32_t base >
struct GPIORegisters {
   static volatile constexpr auto base_ptr = (std::uint32_t *)base;

    static volatile constexpr auto 
        moder = base_ptr + 0x00/4,
        otyper = base_ptr + 0x04/4,
        ospeedr = base_ptr + 0x08/4,
        pupdr = base_ptr + 0x0C/4,
        idr = base_ptr + 0x10/4,
        odr = base_ptr + 0x14/4,
        bsrr = base_ptr + 0x18/4,
        lckr = base_ptr + 0x1C/4,
        afrl = base_ptr + 0x20/4,
        afrh = base_ptr + 0x24/4,
        brr = base_ptr + 0x28/4;
};

#endif
