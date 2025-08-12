#include <iostream>
#include "chess.hpp"

int main() {
    std::cout << "chess\n";
    Chess g;
    bool white_wins = g.play();
    std::cout << "congrats to " << (white_wins ? "white!\n" : "black!\n");

    return 0;
}
