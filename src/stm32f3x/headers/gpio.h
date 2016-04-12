#ifndef GPIO_H
#define GPIO_H

#include <gpio_enums.h>
#include <gpio_regs.h>
#include <pin_set.h>

#include <rcc_registers.h>

#include <cstdint>

template< typename regs, unsigned ahbenr_bit >
struct GPIO {
    static void enable_clock() {
        *rcc::ahbenr |= (0b1<<ahbenr_bit); 
    }

    static void set( PinSet ps ) {
        *regs::bsrr = ps.mask1;
    }

    static void reset( PinSet ps ) {
        *regs::brr = ps.mask1;
    }

    static void configure( PinSet ps, GPIOMode mode ) { 
        *regs::moder &= ~ps.mask2;
        *regs::moder |= (std::uint32_t)mode & ps.mask2;
    }

    static void configure( PinSet ps, GPIOType type ) { 
        *regs::otyper &= ~ps.mask2;
        *regs::otyper |= (std::uint32_t)type & ps.mask2;
    }

    static void configure( PinSet ps, GPIOSpeed speed ) { 
        *regs::ospeedr &= ~ps.mask2;
        *regs::ospeedr |= (std::uint32_t)speed & ps.mask2;
    }

    static void configure( PinSet ps, GPIOAlternate af ) { 
        if( ps.mask4l != 0 ) {
            *regs::afrl &= ~ps.mask4l;
            *regs::afrl |= (std::uint32_t)af & ps.mask4l;
        }
        if( ps.mask4h != 0 ) {
            *regs::afrh &= ~ps.mask4h;
            *regs::afrh |= (std::uint32_t)af & ps.mask4h;
        }
    }

    template< typename Param, typename... Params >
    static void configure( PinSet ps, Param param, Params... params ) {
        configure(ps, param);
        configure(ps, params...);
    }
 };

using gpioa = GPIO<GPIORegisters<0x4800'0000>, 17>;
using gpioe = GPIO<GPIORegisters<0x4800'1000>, 21>;

#endif
