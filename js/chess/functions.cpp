#include "functions.hpp"

std::string format(char& w, char& b, bool col) {
    std::string  test = "ooo\nooo\nooo";
    std::string  test2 = "...\n...\n...";
    return col ? test : test2;
}
