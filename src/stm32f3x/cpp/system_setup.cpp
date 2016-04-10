#include <gpio.h>
#include <rcc_registers.h>
#include <sys_tick.h>

#include "config.h"

extern "C"
void setup_gpio() {
    led_gpio::enable_clock();
    led_gpio::configure( led_pins, GPIOMode::Output, GPIOType::PushPull, GPIOSpeed::High );
}

extern "C"
void setup_uart() {
    auto constexpr pins = PinSet{ 9, 10 };

    gpioa::enable_clock();
    gpioa::configure( pins, GPIOMode::Alternate, GPIOSpeed::High, GPIOType::PushPull, GPIOAlternate::AF7 );

    uart1::enable_clock();
    uart1::enable_tx();
    uart1::enable_rx();
    uart1::enable();
}

extern "C"
void system_setup() {
    setup_gpio();
    setup_uart();
}
