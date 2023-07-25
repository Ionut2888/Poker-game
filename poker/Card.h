#ifndef POKER_CARD_H
#define POKER_CARD_H

#include <string>

class Card {
private:
     std::string rank;
     std::string suit;
public:
    Card(std::string cardRank, std::string cardSuit);
    [[nodiscard]] std::string getRank() const;
    [[nodiscard]] std::string getSuit() const;
};

#endif //POKER_CARD_H
