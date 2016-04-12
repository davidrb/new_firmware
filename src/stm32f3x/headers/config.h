#ifndef CONFIG_H
#define CONFIG_H

#include <cstdint>

#include <gpio.h>
#include "uart.h"

using led_gpio = gpioe;
constexpr auto led_pins = PinSet{ 8, 9, 10, 11, 12, 13, 14, 15 };

using io_uart = uart1;
auto constexpr uart_pins = PinSet{ 9, 10 };

#endif
