#include "tetris.hpp"

#define bug(x) std::cout << #x << ": " << x << '\n';

void output_grid(std::vector<std::vector<bool>>& grid) {
    for (auto& gr : grid) {
        for (auto tile : gr) {
            if (tile) std::cout << "❑";
            else std::cout << " ";
        }
        std::cout << '\n';
    }
    std::cout << '\n';
}

std::vector<std::vector<bool>> tetris_process(std::vector<std::vector<bool>>& grid, std::vector<std::pair<tetris_piece, int>>& drops) {
    for (int i = 0; i < (int)drops.size(); i++) {
        auto& drop = drops[i];
        std::cout << i << '\n';
        if (!fall(drop, grid)) break;
        output_grid(grid);
    }
    return grid;
}

bool fall(std::pair<tetris_piece, int>& piece, std::vector<std::vector<bool>>& grid) {
    auto& [curr_piece, curr_col] = piece;

    int piece_height = (int)curr_piece.shape.size();
    int piece_width = (int)curr_piece.shape[0].size();
    int grid_height = (int)grid.size();

    bug(piece_height)
    bug(piece_width)
    bug(grid_height)

    // int grid_width = (int)grid[0].size();
    if (piece_width + curr_col > (int)grid[0].size()) return false;
    // find row to start drawing entire piece
    int possible_row = INT_MAX;
    std::cout << '\n';
    for (int j = 0; j < piece_width; j++) { // go across col of piece
        bug(j)
        int lowest_row = 0;
        for (int i = 0; i < piece_height; i++) { // go across height of piece
            if (curr_piece.shape[i][j]) lowest_row = i;
        }
        lowest_row++;
        bug(lowest_row)

        int highest_block = grid_height;
        for (int i = 0; i < grid_height; i++) {
            if (grid[i][j]) {
                highest_block = i;
                break;
            }
        }
        bug(highest_block)

        int curr_possible = highest_block - piece_height + lowest_row;
        bug(curr_possible)
        if (curr_possible < 0) return false;
        possible_row = fmin(possible_row, curr_possible);
        std::cout << '\n';
    }

    bug(possible_row)
    if (possible_row == INT_MAX) return false;
    for (int i = 0; i < piece_height; i++) {
        for (int j = 0; j < piece_width; j++) {
            if (curr_piece.shape[i][j]) {
                grid[possible_row + i][curr_col + j] = true;
            }
        }
    }

    return true;
}
