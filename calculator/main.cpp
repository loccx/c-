#include <exception>
#include <iostream>
#include <string>
#include "calculator.hpp"

int main() {
    Calculator c;
    while (true) {
        std::string inp;
        std::cout << "input equation: (leave empty to close)\n";
        std::getline(std::cin, inp);

        if (inp.empty()) return 0;
        try {
            double res = c.solve(inp);
            std::cout << res << '\n';
        }
        catch (std::exception e) {
            std::cout << e.what() << '\n';
            std::cout << "exception!\n";
        }

        c.reset();
    }
    return 0;
}
