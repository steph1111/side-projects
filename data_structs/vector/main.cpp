#include <iostream>
#include "vec.h"

int main() {
    vec<int> test = {3, 1, 2, 3, 5, 3, 3, 3, 3};

    std::cout << "List" << test << std::endl;
    std::cout << "SIZE: " << test.size() << std::endl;
    test.remove(3);
   std::cout << "List" << test << std::endl;
    std::cout << "SIZE: " << test.size() << std::endl;

    return 0;
}
