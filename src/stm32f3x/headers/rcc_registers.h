#ifndef RCC_REGISTERS_H
#define RCC_REGISTERS_H

#include <cstdint>

struct RCC {
    static volatile constexpr auto base_ptr = (std::uint32_t *)0x4002'1000;

    static volatile constexpr auto 
        cr = base_ptr,
        cfgr = base_ptr + 0x04/4,
        cir = base_ptr + 0x08/4,
        apb2rstr = base_ptr + 0x0C/4,
        apb1rstr = base_ptr + 0x10/4,
        ahbenr = base_ptr + 0x14/4,
        apb2enr = base_ptr + 0x18/4,
        apb1enr = base_ptr + 0x1C/4,
        bdcr = base_ptr + 0x20/4,
        csr = base_ptr + 0x24/4,
        ahbrstr = base_ptr + 0x28/4,
        cfgr2 = base_ptr + 0x2C/4,
        cfgr3 = base_ptr + 0x30/4;
};

using rcc = RCC;

#endif
