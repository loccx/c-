#pragma once
#include <iostream>
#include <vector>

struct tetris_piece {
    tetris_piece(std::vector<std::vector<bool>> vec) : shape(vec) {}
    std::vector<std::vector<bool>> shape;
};

bool fall(std::pair<tetris_piece, int>& piece, std::vector<std::vector<bool>>& grid);

void output_grid(std::vector<std::vector<bool>>& grid);

std::vector<std::vector<bool>> tetris_process(std::vector<std::vector<bool>>& grid, std::vector<std::pair<tetris_piece, int>>& drops);

bool fall(std::pair<tetris_piece, int>& piece, std::vector<std::vector<bool>>& grid);
