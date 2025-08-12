#include <array>
#include <vector>

class Chess {
public:
    bool play();

private:
    std::array<std::vector<int>, 64> white_moves;
    std::array<std::vector<int>, 64> black_moves;
    std::array<char, 64> board;

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
