#pragma once
#include <iostream>
#include <cstdlib>
#include <array>
#include <vector>
#include <string>

class Chess {
public:
    Chess() {
        reset_board();
    }
    Chess(int n) : size(n) {
        Chess();
    }

    bool play();

    /*
     * removes everything
     * default positions
     */
    void reset_board();

    void show_board();

private:
    std::array<std::vector<int>, 64> white_moves;
    std::array<std::vector<int>, 64> black_moves;

    std::array<char, 64> white_board;
    std::array<char, 64> black_board;
    bool turn = true; // true = white turn

    std::array<char, 8> black_row = {'r', 'k', 'b', 'q', 'w', 'b', 'k', 'r'};
    std::array<char, 8> white_row = {'R', 'K', 'B', 'Q', 'W', 'B', 'K', 'R'};
    
    const int size = 10;
/*
board setup
    black side
8 1      -      8
7 9      -     16
6 17     -     24
5 25     -     32
4 33     -     40
3 41     -     48
2 49     -     56
1 57     -     64
  A B C D E F G H
  white side
*/

};
