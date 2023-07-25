#include "Card.h"

#include <utility>

Card::Card(std::string cardRank, std::string cardSuit)
        : rank(std::move(cardRank)), suit(std::move(cardSuit)) {
}

std::string Card::getRank() const {
    return rank;
}

std::string Card::getSuit() const {
    return suit;
}
