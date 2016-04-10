#include <cstdint>

extern std::uint32_t __heap_start;
static std::uint32_t *__heap;

extern "C"
void *_sbrk(unsigned i) {
    auto tmp = __heap;
    __heap += i;  // TODO: check for collision
    return tmp;
}

extern "C"
void __init_heap() {
    __heap = &__heap_start;
}
