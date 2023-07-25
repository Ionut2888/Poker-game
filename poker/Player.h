#ifndef POKER_PLAYER_H
#define POKER_PLAYER_H

#include <vector>
#include <fstream>
#include "Card.h"


class Player {
private:
    std::string name;
    std::vector<Card> hand;
    int win=0, loss=0, tie=0;
public:
    explicit Player(std::string playerName);
    void addCard(Card const &card);
    void displayHand();
    std::string getName();
    std::vector<Card> getHand();
    void clearHand();
    void setWin();
    void setLoss();
    void setTie();
    [[nodiscard]] int getWin() const;
    [[nodiscard]] int getLoss() const;
    [[nodiscard]] int getTie() const;
    void printStats(const std::string& filename) const;
};


#endif //POKER_PLAYER_H
