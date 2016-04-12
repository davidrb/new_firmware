#include <gpio.h>
#include <rcc.h>
#include <sys_tick.h>

#include "config.h"

extern "C"
void setup_gpio() {
    led_gpio::enable_clock();
    led_gpio::configure( led_pins, GPIOMode::Output, GPIOType::PushPull, GPIOSpeed::High );
}

extern "C"
void setup_uart() {
    gpioa::enable_clock();
    gpioa::configure( uart_pins, GPIOMode::Alternate, GPIOSpeed::High, GPIOType::PushPull, GPIOAlternate::AF7 );

    io_uart::enable_clock();
    io_uart::enable();
}

extern "C"
void system_setup() {
    enable_pll();

    setup_gpio();
    setup_uart();
}
