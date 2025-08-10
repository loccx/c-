#include "Player.hpp"

std::array<std::string, 13> values = {"2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King", "Ace"};
std::array<std::string, 4> suits = {"Club", "Spade", "Heart", "Diamond"};

void Player::hit(Card& c, bool dealer) {
    hand[it] = c;
    it++;
    int val = cc.get_rank(c);
    int suit = cc.get_suit(c);
    std::cout << values[val] << ' ' << suits[suit] << '\n';
    if (val < 9) {
        score += val + 2;
    }
    else if (val >= 9 && val < 12) {
        score += 10;
    }
    else {
        if (!dealer) {
            while (true) {
                std::cout << "Ace! 1 or 11?\n";
                std::string inp;
                std::cin >> inp;
                if (inp == "1") {
                    score++;
                    break;
                }
                else if (inp == "11") {
                    score += 11;
                    break;
                }
            }
        }
        else { // dealer ace determine
            if (score + 11 > 21) {
                score++;
            }
            else score += 11;
        }
    }

    if (score > 21) {
        bust = true;
    }

    cardcount++;
}

void Player::show_hand() {
    std::cout << "Hand:\n";
    for (int i = 0; i < cardcount; i++) {
        auto& card = hand[i];
        std::cout << cc.get_rank(card) << ' ' << cc.get_suit(card) << '\n';
    }
    std::cout << '\n';
}

void Player::show_score() {
    std::cout << "Your Score: " << score << '\n';
}

void Player::reset() {
    it = 0;
    score = 0;
    cardcount = 0;
    bust = false;
}
