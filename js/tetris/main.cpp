#include "tetris.hpp"
#include <vector>

int main() {
    std::vector<std::vector<bool>> grid = {
        {false, false, false, false, false},
        {false, false, false, false, false},
        {false, false, false, false, false},
        {false, false, false, false, false},
        {false, false, false, false, false},
        {false, true, false, false, false},
        {true, true, true, false, false}
    };

    output_grid(grid);


    std::vector<std::vector<bool>> p1 = {{true, true, true},
                                        {true, false, false}};
    tetris_piece piece1(p1);
    std::vector<std::vector<bool>> p2 = {{true, true, true},
                                        {false, false, true}};
    tetris_piece piece2(p2);

    std::vector<std::pair<tetris_piece, int>> drops = {{p1, 0}, {p2, 1}};

    auto res = tetris_process(grid, drops);

    output_grid(res);

    return 0;
}
