#ifndef GPIO_ENUM_H
#define GPIO_ENUM_H

#include <cstdint>

enum class GPIOMode : std::uint32_t {
    Input = 0x00000000,
    Output = 0x55555555,
    Alternate = 0xAAAAAAAA,
    Analog = 0xFFFFFFFF
};

enum class GPIOType : std::uint32_t {
    PushPull = 0x00000000,
    OpenDrain = 0x55555555,
};

enum class GPIOSpeed : std::uint32_t {
    Low = 0x00000000,
    Med = 0x55555555,
    High = 0xAAAAAAAA,
};

enum class GPIOAlternate : std::uint32_t {
    AF0 = 0x00000000,
    AF1 = 0x11111111,
    AF2 = 0x22222222,
    AF3 = 0x33333333,
    AF4 = 0x44444444,
    AF5 = 0x55555555,
    AF7 = 0x77777777
};

#endif
