#include <iostream>
#include "../src/rect.hpp"
#include <cstring>
#include <cassert>

int main() {
    Rect r1(1, 1, 3, 3);
    Rect r2(2, 2, 3, 3);
    Rect r3 = bounding_rect(r1, r2);
    
    Rect r4(1, 1, 3, 3);
    Rect r5(2, 2, 3, 3);
    Rect r6 = bounding_rect(r4, r5);

    assert(r3.get_left() == 1);
    assert(r3.get_right() == 5);
    assert(r3.get_top() == 5);
    assert(r3.get_bottom() == 1);
   

    assert(r6.get_left() == 1);
    assert(r6.get_right() == 5);
    assert(r6.get_top() == 5);
    assert(r6.get_bottom() == 1);
 
    std::cout << "All tests passed successfully!" << std::endl;
    return 0;
}
