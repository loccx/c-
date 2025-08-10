#pragma once

#include <iostream>
#include <array>
#include "Card.hpp"

class Player {
public:
    Player() : it(0), score(0), bust(false) {}
    Player(int balance) : it(0), balance(balance), score(0), bust(false) {}

    CardClass cc;
    std::array<Card, 10> hand;
    int it;
    int balance;
    int score;
    int cardcount;
    bool bust;

    void hit(Card& c, bool dealer);
    void show_hand();
    void show_score();
    void reset();
};
