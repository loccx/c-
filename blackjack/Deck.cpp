#include "Deck.hpp"
#include "Card.hpp"
#include "Player.hpp"

void Deck::view(int n) {
    for (int i = 0; i < n; i++) {
        auto& card = deck[i];
        std::cout << cc.get_rank(card) << ' ' << cc.get_suit(card) << '\n'; }
    std::cout << '\n';
}

void Deck::shuffle() {
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(it, deck.end(), g);
}

void Deck::deal(Player& p, bool dealer) {
    p.hit(*it++, dealer);
}

int Deck::size() {
    return std::distance(it, deck.end());
}

void Deck::reset() {
    it = deck.begin();
}
