#include <iostream>
#include "vec.h"

int main() {
    vec<int> test = {1, 2, 3, 4, 5, 6};

    std::cout << test << std::endl;
    for (int i = 0; i < 20; i++) test.push_back(i);
    std::cout << test << std::endl;

    return 0;
}
