#include <stdbool.h>
#include <stdint.h>

#include "sys_tick.h"
#include "led.h"

#include <bitset>

#include <cstdio>

int main() {
    set_sys_tick_value(8'000'000 - 1);
    enable_sys_tick();
}

int h = 42;

extern "C"
void sys_tick_handler() {
    printf("Hello, World! %i\n", h++);
    toggle_led();
}


#include <cstdio>
#include <cstdlib>

#include <vector>
#include <new>
#include <map>

auto foo() -> int {
    return 42;
}

int i = foo();

void test() {
    auto k = new int{3};

    auto v = std::vector<int>{};
    v.emplace_back(3);

    auto q = v[0];

    auto m = std::map<int, char>{ {3, 'c'}, {4, 'd'} };
    auto c = m[4];

    auto i = (unsigned *)malloc(4);
    *i = 42;
}
