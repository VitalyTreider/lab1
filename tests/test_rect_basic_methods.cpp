#include <iostream>
#include "../src/rect.hpp"
#include <cstring>
#include <cassert>

int main() {
    Rect r1(1, 4, 4, 1);
    Rect r2;
    Rect r3(r1);

    assert(r1.get_left() == 1);
    assert(r1.get_right() == 4);
    assert(r1.get_top() == 4);
    assert(r1.get_bottom() == 1);
    
    assert(r2.get_left() == 0);
    assert(r2.get_right() == 0);
    assert(r2.get_top() == 0);
    assert(r2.get_bottom() == 0);

    assert(r3.get_left() == 1);
    assert(r3.get_right() == 4);
    assert(r3.get_top() == 4);
    assert(r3.get_bottom() == 1);

    r1.set_all(10, 40, 40, 10);
 
    assert(r1.get_left() == 10);
    assert(r1.get_right() == 40);
    assert(r1.get_top() == 40);
    assert(r1.get_bottom() == 10);

    std::cout << "All tests passed successfully!" << std::endl;
    return 0;
}
