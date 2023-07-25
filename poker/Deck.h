#ifndef POKER_DECK_H
#define POKER_DECK_H

#include <vector>
#include "Card.h"

class Deck {
private:
    std::vector<Card> cards;

public:

    Deck();
    void resetDeck();
    void shuffle();
    Card dealCard();

};

#endif //POKER_DECK_H