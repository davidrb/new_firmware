#ifndef PIN_SET_H
#define PIN_SET_H

#include <cstdint>

struct PinSet {
public:
    constexpr PinSet() : mask1{0}, mask2{0}, mask4l{0}, mask4h{0} {}

    template< typename... Others >
    constexpr PinSet( int pin, Others... others ) : 
        mask1{ (0b1<<pin) | PinSet{others...}.mask1 },
        mask2{ (0b11<<(pin*2)) | PinSet{others...}.mask2 }, 
        mask4l{ (pin >= 8 ? 0 : (0b1111<<(pin*4))) | PinSet{others...}.mask4l }, 
        mask4h{ (pin < 8 ? 0 : (0b1111<<(pin*4-32))) | PinSet{others...}.mask4h } {
    }

    std::uint32_t mask1, mask2, mask4l, mask4h;
};

#endif
