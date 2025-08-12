#include <iostream>
#include "median.hpp"

int main() {
    MedianFinder m;

    m.add_number(-1);
    std::cout << m.get_median() << '\n';
    m.add_number(-2);
    std::cout << m.get_median() << '\n';
    m.add_number(-3);
    std::cout << m.get_median() << '\n';

    return 0;
}
