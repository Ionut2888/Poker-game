#ifndef POKER_POKERGAME_H
#define POKER_POKERGAME_H

#include <iostream>
#include <algorithm>
#include <vector>
#include <limits>


#include "Player.h"
#include "Deck.h"
#include "Card.h"


class PokerGame {
private:
    int bet;
    int credit;
    int winner;
    Deck deck;
    Player player;
    Player dealer;
    std::vector<Card> commonCards;

public:

    explicit PokerGame(std::string playerName);

    friend std::ostream& operator<<(std::ostream& os, const PokerGame& game);

    void computeCredit();
    void placeBet();
    void resetBet();
    [[nodiscard]] int getCredit() const;
    void dealCards(int numCards);
    void display3Cards();
    void display2Cards();
    void displayHands();
    void dealerHands();
    void addWins();
    void check();
    static int getHighCard(const std::vector<Card>& hand);
    void determineWinner();
    static int evaluateHand(const std::vector<Card>& hand);
    static bool isRoyalFlush(const std::vector<Card>& hand);
    static bool isStraightFlush(const std::vector<Card>& hand);
    static bool isFourOfAKind(const std::vector<Card>& hand);
    static bool isFullHouse(const std::vector<Card>& hand);
    static bool isFlush(const std::vector<Card>& hand);
    static bool isStraight(const std::vector<Card>& hand);
    static bool isThreeOfAKind(const std::vector<Card>& hand);
    static bool isTwoPair(const std::vector<Card>& hand);
    static bool isOnePair(const std::vector<Card>& hand);
    static int getRankValue(const std::string& rank);
    static std::string getHandName(int rank);
    [[nodiscard]] int getWinner() const;
};

#endif //POKER_POKERGAME_H
