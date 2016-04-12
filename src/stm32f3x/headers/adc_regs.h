#ifndef ADC_REGS_H
#define ADC_REGS_H

#include <cstdint>

template< std::uint32_t base >
struct ADCRegisters {
    static volatile constexpr auto base_ptr = (std::uint32_t *)base;

    static volatile constexpr auto 
        isr = base_ptr + 0x00/4,
        ier = base_ptr + 0x04/4,
        cr = base_ptr + 0x08/4,
        cfgr = base_ptr + 0x0C/4,

        smpr1 = base_ptr + 0x14/4,
        smpr2 = base_ptr + 0x18/4,

        tr1 = base_ptr + 0x20/4,
        tr2 = base_ptr + 0x24/4,
        tr3 = base_ptr + 0x28/4,

        sqr1 = base_ptr + 0x30/4,
        sqr2 = base_ptr + 0x34/4,
        sqr3 = base_ptr + 0x38/4,
        sqr4 = base_ptr + 0x3C/4,

        dr = base_ptr + 0x40/4,
        jsqr = base_ptr + 0x4C/4,

        ofr1 = base_ptr + 0x60/4,
        ofr2 = base_ptr + 0x64/4,
        ofr3 = base_ptr + 0x68/4,
        ofr4 = base_ptr + 0x6C/4,

        jdr1 = base_ptr + 0x80/4,
        jdr2 = base_ptr + 0x84/4,
        jdr3 = base_ptr + 0x88/4,
        jdr4 = base_ptr + 0x8C/4,

        awd2cr = base_ptr + 0xA0/4,
        awd3cr = base_ptr + 0xA4/4,

        difsel = base_ptr + 0xB0/4,
        calfact = base_ptr + 0xB4/4,

        csr = base_ptr + 0x300/4,
        ccr = base_ptr + 0x308/4,
        cdr = base_ptr + 0x30C/4;
};

#endif
