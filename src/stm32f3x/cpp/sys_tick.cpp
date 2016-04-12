#include "sys_tick.h"
#include "sys_tick_registers.h"

void set_sys_tick_value( std::uint32_t value ) {
   *stk_load = value;
}

void enable_sys_tick() {
   *stk_ctrl |= 0b111;
}
