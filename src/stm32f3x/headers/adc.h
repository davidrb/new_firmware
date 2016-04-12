#ifndef ADC_H
#define ADC_H

#include <adc_regs.h>
#include <rcc_registers.h>
#include <cstdint>

template< typename regs, unsigned ahbenr_bit, unsigned cfgr2_lsb >
struct ADC {
    static void enable_clock() {
        *rcc::ahbenr |= (0b1<<ahbenr_bit);

        *rcc::cfgr2 &= ~(0b11111<<cfgr2_lsb);    // PLL/1
        *rcc::cfgr2 |= (0b10000<<cfgr2_lsb);    // PLL/1
    }

    static void enable() {
        *regs::cr &= ~(0b11<<28);          // ADVREGEN
        *regs::cr |= 0b01<<28;          // ADVREGEN

        for( auto i = 0u; i < 100000u; i++ );

        *regs::cr &= ~(0b1<<31);
        *regs::cr |= (0b1<<31);
        while((*regs::cr) & (0b1<<31));   // Calibration

        *regs::sqr1 &= ~(0b1111<<6);
        *regs::sqr1 |= (0b0010<<6);     // Channel 2 is first

        //*regs::smpr1 &= ~(0b111<<3);
        //*regs::smpr1 |= (0b111<<3);

        *regs::cr |= 0b1;                       // ADEN
        while(!( *regs::isr & 0b1 ));           // wait for ADRDY
    }

    static auto convert() -> std::uint32_t {
        while(!( *regs::isr & 0b1 ));           // wait for ADRDY
        *regs::cr |= (0b1<<2);                  // Start conversion

        while(!( *regs::isr & (0b1<<1) ));  // End of Sample
        *regs::isr = (0b1<<1); 
    
        while(!( *regs::isr & (0b1<<2) ));  // End of Conversion
        *regs::isr = (0b1<<2); 

        while(!( *regs::isr & (0b1<<3) ));  // End of Sequence
        *regs::isr = (0b1<<3); 

        return *regs::dr;
    }
};

using adc1 = ADC<ADCRegisters<0x5000'0000>, 28, 4>;
using adc3 = ADC<ADCRegisters<0x5000'0400>, 29, 9>;

#endif
