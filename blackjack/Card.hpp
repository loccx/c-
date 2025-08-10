#pragma once

#include <cstdint>

using Card = uint8_t;

class CardClass {
public:
    Card create_card(uint8_t suit, uint8_t rank);
    int get_suit(Card& c);
    int get_rank(Card& c);
};
