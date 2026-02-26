#include <iostream>
#include "../src/rect.hpp"
#include <cstring>
#include <cassert>

int main() {
    Rect r1(1, 1, 3, 3);

    assert(r1.get_width() == 3);
    assert(r1.get_height() == 3);
    assert(r1.get_square() == 9);
    
    r1.set_width(4);
    r1.set_height(5);

    assert(r1.get_width() == 4);
    assert(r1.get_height() == 5);

    std::cout << "All tests passed successfully!" << std::endl;
    return 0;
}
