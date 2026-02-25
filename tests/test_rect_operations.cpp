#include <iostream>
#include "../src/rect.hpp"
#include <cstring>
#include <cassert>

int main() {
    Rect r1(1, 4, 4, 1);

    r1.inflate(1);
    
    assert(r1.get_left() == 0);
    assert(r1.get_right() == 5);
    assert(r1.get_top() == 5);
    assert(r1.get_bottom() == 0);

    r1.inflate(1, 2);

    assert(r1.get_left() == -1);
    assert(r1.get_right() == 6);
    assert(r1.get_top() == 7);
    assert(r1.get_bottom() == -2);

    r1.inflate(1, 2, 3, 4);

    assert(r1.get_left() == -2);
    assert(r1.get_right() == 8);
    assert(r1.get_top() == 10);
    assert(r1.get_bottom() == -6);

    r1.move(1);
    r1.move(1, 2);

    assert(r1.get_left() == 0);
    assert(r1.get_right() == 10);
    assert(r1.get_top() == 12);
    assert(r1.get_bottom() == -4);

    std::cout << "All tests passed successfully!" << std::endl;
    return 0;
}
