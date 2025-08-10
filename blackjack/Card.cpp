#include "Card.hpp"

Card CardClass::create_card(uint8_t suit, uint8_t rank) {
    return (suit << 4) | rank;
}

int CardClass::get_suit(Card& c) {
    return (c >> 4) & 0x03;
}

int CardClass::get_rank(Card& c) {
    return c & 0x0F;
}
