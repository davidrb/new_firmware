#ifndef SYSTICK_H
#define SYSTICK_H

#include <cstdint>

void set_sys_tick_value( std::uint32_t value );
void enable_sys_tick();

#endif
