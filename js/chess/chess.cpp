#include "chess.hpp"
#include "functions.hpp"

bool Chess::play() {
    std::string select;
    show_board();
    return true;
}

void Chess::reset_board() {
    white_board.fill(' ');
    black_board.fill(' ');
    for (int i = 0; i < 8; i++) {
        white_board[48 + i] = 'P';
        white_board[56 + i] = white_row[i];
        black_board[8 + i] = 'p';
        black_board[i] = black_row[i];
    }
}

void Chess::show_board() {
    system("clear"); // clears stdout, system call
    bool col = true; // true for white
    for (int i = 0; i < 8; i++) {
        for (int b = 0; b < size / 2; b++) {
            for (int j = 0; j < 8; j++) {
                for (int a = 0; a < size; a++) {
                    if (b == size / 4 && a == size / 2) { // middle of tile
                        if (white_board[i*8 + j] != ' ') std::cout << white_board[i*8 + j];
                        else if (black_board[i*8 + j] != ' ') std::cout << black_board[i*8 + j];
                        else std::cout << (col ? "█" : " ");
                    }
                    else std::cout << (col ? "█" : " ");
                }
                col ^= 1;
            }
            std::cout << '\n';
        }
        col ^= 1;
    }
    std::cout << '\n';
}
