#pragma once

#include <iostream>
#include <array>
#include <string>
#include <algorithm>
#include <cstdint>
#include <random>

#include "Card.hpp"
#include "Player.hpp"

class Deck {
public:
    Deck() {
        values = "23457890JQKA";
        suits = "CSDH";
        it = deck.begin();
        auto curr = it;
        for (uint8_t i = 0; i < 13; i++) {
            for (uint8_t j = 0; j < 4; j++) {
                *curr++ = cc.create_card(j, i);
            }
        }
    }

    /*
    * outputs first n cards of deck
    */
    void view(int n);

    /*
    * shuffles the deck
    */
    void shuffle();

    /*
    * deals one card, "removes" from deck
    */
    void deal(Player& p, bool dealer);

    /*
    * return cards left in deck
    */
    int size();

    void reset();

private:
    std::string values;
    std::string suits;
    std::array<Card, 52>::iterator it;
    std::array<Card, 52> deck;
    CardClass cc;
};
