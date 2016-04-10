#include "led.h"
#include "gpio.h"
#include <config.h>

#include <cstdint>

static auto state = false;

void toggle_led() {
    state = !state;

    if(state) led_gpio::set( led_pins );
    else      led_gpio::reset( led_pins );
}
