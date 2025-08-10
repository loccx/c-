#include <iostream>
#include <fstream>
#include <thread>
#include <chrono>
#include "Deck.hpp"
#include "Player.hpp"

/*
shuffle deck
select buy in

gameplay :
    hit, stay
    burn cards
    dealer goes last

deck
shuffle
deal
reset (shuffles, takes cards back)
*/
int main() {
    std::ifstream balance_file("balance.txt");

    Deck deck;
    // std::cout << "How much money do you want to start with?\n";
    std::string start;
    if (balance_file) {
        balance_file >> start;
        balance_file.close();
    }
    else {
        std::cout << "Error opening balance\n";
        balance_file.close();
        return 1;
    }

    double start_balance = stoi(start);
    if (start_balance < 0) {
        std::cout << "You are in debt! Get out of my casino.\n";
        return 1;
    }
    Player key(start_balance);

    while (true) {
        deck.reset();
        key.reset();
        deck.shuffle();

        std::cout << "balance: " << key.balance << '\n';
        std::string wager;
        int wager_num;
        while (true) {
            std::cout << "how much do you want to WAGER!\n";
            std::cin >> wager;
            wager_num = stoi(wager);
            if (wager_num > key.balance || wager_num <= 0) {
                std::cout << "invalid! you broke boy\n";
            }
            else {
                std::cout << "dealing:\n\n";
                break;
            }
        }
        key.balance -= wager_num;

        while (key.score < 21) {
            std::cout << "do you want to HIT or STAY?\n";
            std::string inp;
            std::cin >> inp;
            if (inp == "HIT") {
                deck.deal(key, false);
            }
            else if (inp == "STAY") {
                break;
            }
        }
        key.show_score();

        if (key.score > 21) {
            std::cout << "You busted! Try again next time...\n";
            continue;
        }

        Player dealer;
        std::cout << "\nMy turn...\n\n";

        // add some probability threshold later
        std::this_thread::sleep_for(std::chrono::seconds(1));
        while (dealer.score < key.score) { // split pot if get the same, dealer is more protective
            deck.deal(dealer, true);
            std::this_thread::sleep_for(std::chrono::seconds(1));
        }
        std::this_thread::sleep_for(std::chrono::seconds(1));

        if (dealer.score > 21) {
            std::cout << "Dealer bust! Congrats, you win: " << 2 * wager_num << "!\n\n";
            key.balance += 2 * wager_num;
        }
        else if (key.score == dealer.score) { // tie
            std::cout << "Split! Congrats! You get your money back.\n";
            key.balance += wager_num;
        }
        else { // loss
            std::cout << "Dealer: " << dealer.score << '\n';
            std::cout << "Damn... You lost.\n";
        }
        std::cout << "\n\n";
    }

    return 0;
}
