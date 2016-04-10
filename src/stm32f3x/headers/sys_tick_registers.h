#ifndef SYS_TICK_REGISTERS_H
#define SYS_TICK_REGISTERS_H

#include <cstdint>

auto constexpr stk_ctrl = (std::uint32_t *)0xE000E010;
auto constexpr stk_load = (std::uint32_t *)0xE000E014;
auto constexpr stk_val = (std::uint32_t *)0xE000E018;
auto constexpr stk_calib = (std::uint32_t *)0xE000E01C;

#endif
