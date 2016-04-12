#include "led.h"
#include "gpio.h"
#include <config.h>

#include <cstdint>

static auto state = false;
static auto num = 8;

void toggle_led() {
    state = !state;
    num++;

    /*
    if(state) led_gpio::set( led_pins );
    else      led_gpio::reset( led_pins );
    */

    led_gpio::reset( led_pins );
    num = (num > 15) ? 8 : num;
    led_gpio::set( PinSet{num} );
}
