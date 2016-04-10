#ifndef CONFIG_H
#define CONFIG_H

#include <cstdint>

#include <gpio.h>
#include "uart_registers.h"

using led_gpio = gpioe;
constexpr auto led_pins = PinSet{ 9, 10, 12 };

using io_uart = uart1;

#endif
