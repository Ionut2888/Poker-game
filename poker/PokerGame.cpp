#include "PokerGame.h"


PokerGame::PokerGame(std::string playerName) : player(std::move(playerName)), dealer("Dealer") {
    deck.shuffle();
    winner = -1;
    bet = 10;
    credit = 100;
}

std::ostream& operator<<(std::ostream& os, const PokerGame& game) {

    os << "Bet: " << game.bet << std::endl;
    os << "Credit: " << game.credit << std::endl;
    return os;
}

void PokerGame::computeCredit() {
    credit = credit - bet;
}

void PokerGame::placeBet() {
    int credit_copy;
    int bet_copy;
    bet = 10;

    while (true) {
        std::cout << "Place your bet: ";

        if (!(std::cin >> bet_copy)) {
            std::cout << "Invalid input! Please enter a number." << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }

        if (bet_copy <= credit) {
            credit_copy = credit - bet_copy;
            bet = bet + bet_copy;
            if(bet_copy == credit)
                std::cout << "Total bet: " << bet <<" "<<"(All In)"<< std::endl << std::endl;
            else
                std::cout << "Total bet: " << bet << std::endl << std::endl;
            break;
        }
        else {
            std::cout << "Insufficient Credit. (credit: " << credit << ")" << std::endl;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        }
    }

    credit = credit_copy;
}

void PokerGame::resetBet() {
    bet = 10;
}

int PokerGame::getCredit() const {
    return credit;
}

void PokerGame::dealCards(int numCards) {
    player.clearHand();
    dealer.clearHand();
    for (int i = 0; i < numCards; i++) {
        Card playerCard = deck.dealCard();
        player.addCard(playerCard);

        Card dealerCard = deck.dealCard();
        dealer.addCard(dealerCard);
    }

}

void PokerGame::display3Cards() {
    commonCards.clear();
    std::cout <<" Common Cards:" << std::endl;
    for (int i = 0; i < 3; i++) {
        Card card = deck.dealCard();
        commonCards.push_back(card);
        std::cout << "Card " << (i + 1) << ": " << card.getRank() << " of " << card.getSuit() << std::endl;
    }
}

void PokerGame::display2Cards() {

    for (int i = 3; i < 5; i++) {
        Card card = deck.dealCard();
        commonCards.push_back(card);
        std::cout << "Card " << (i + 1) << ": " << card.getRank() << " of " << card.getSuit() << std::endl;
    }
    std::cout << std::endl;
    deck.resetDeck();
}

void PokerGame::displayHands() {

    player.displayHand();
    std::cout << std::endl;
}

void PokerGame::dealerHands() {

    dealer.displayHand();
    std::cout << std::endl;
}

void PokerGame::addWins() {

    if (winner ==1){
        credit = credit + 2*bet;
    }
    else if (winner == 0) {
        credit = credit + bet;
    }

}

void PokerGame::check() {
    bet=10;
}

int PokerGame::getHighCard(const std::vector<Card>& hand) {
    int highCard = 0;

    for (const Card& card : hand) {
        int cardValue = getRankValue(card.getRank());

        if (cardValue > highCard) {
            highCard = cardValue;
        }
    }

    return highCard;
}

void PokerGame::determineWinner() {



    std::vector<Card> mergedPlayerHand = player.getHand();
    mergedPlayerHand.insert(mergedPlayerHand.end(), commonCards.begin(), commonCards.end());


    std::vector<Card> mergedDealerHand = dealer.getHand();
    mergedDealerHand.insert(mergedDealerHand.end(), commonCards.begin(), commonCards.end());



    int playerRank = evaluateHand(mergedPlayerHand);


    int dealerRank = evaluateHand(mergedDealerHand);


    std::string playerHandName = getHandName(playerRank);
    std::string dealerHandName = getHandName(dealerRank);


    std::cout << player.getName() << "'s hand: " << playerHandName << std::endl;
    std::cout << dealer.getName() << "'s hand: " << dealerHandName << std::endl;


    if (playerRank > dealerRank) {
        std::cout << player.getName() << " wins!" << std::endl;
        winner = 1;

    } else if (playerRank < dealerRank) {
        std::cout << dealer.getName() << " wins!" << std::endl;
        winner = -1;

    } else {

        int playerHighCard = getHighCard(player.getHand());
        int dealerHighCard = getHighCard(dealer.getHand());

        if (playerHighCard > dealerHighCard) {
            std::cout << player.getName() << " wins with a High card!" << std::endl;
            winner = 1;

        } else if (playerHighCard < dealerHighCard) {
            std::cout << dealer.getName() << " wins with a High card!" << std::endl;
            winner = -1;

        } else {
            std::cout << "It's a tie! Split the pot!" << std::endl;
            winner = 0;

        }
    }
    std::cout << std::endl;
}

int PokerGame::evaluateHand(const std::vector<Card>& hand) {

    if (isRoyalFlush(hand)) {
        return 9;
    } else if (isStraightFlush(hand)) {
        return 8;
    } else if (isFourOfAKind(hand)) {
        return 7;
    } else if (isFullHouse(hand)) {
        return 6;
    } else if (isFlush(hand)) {
        return 5;
    } else if (isStraight(hand)) {
        return 4;
    } else if (isThreeOfAKind(hand)) {
        return 3;
    } else if (isTwoPair(hand)) {
        return 2;
    } else if (isOnePair(hand)) {
        return 1;
    } else {
        return 0;
    }
}

bool PokerGame::isRoyalFlush(const std::vector<Card>& hand) {
    bool hasAce = false;
    bool hasKing = false;
    bool hasQueen = false;
    bool hasJack = false;
    bool hasTen = false;
    std::string suit;

    for (const Card& card : hand) {
        if (card.getRank() == "A") {
            hasAce = true;
            suit = card.getSuit();
        } else if (card.getRank() == "K") {
            hasKing = true;
        } else if (card.getRank() == "Q") {
            hasQueen = true;
        } else if (card.getRank() == "J") {
            hasJack = true;
        } else if (card.getRank() == "10") {
            hasTen = true;
        }
    }

    bool sameSuit = true;
    for (const Card& card : hand) {
        if (card.getRank() != "A" && card.getRank() != "K" && card.getRank() != "Q" && card.getRank() != "J" && card.getRank() != "10") {
            continue;
        }

        if (card.getSuit() != suit) {
            sameSuit = false;
            break;
        }
    }

    return hasAce && hasKing && hasQueen && hasJack && hasTen && sameSuit;
}

bool PokerGame::isStraightFlush(const std::vector<Card>& hand) {
    std::string suits[] = { "Spades", "Hearts", "Diamonds", "Clubs" };

    for (const std::string& suit : suits) {
        int count = 0;
        for (const Card& card : hand) {
            if (card.getSuit() == suit) {
                count++;
            }
        }

        if (count < 5) {
            continue;
        }

        std::vector<int> ranks;
        for (const Card& card : hand) {
            if (card.getSuit() == suit) {
                ranks.push_back(getRankValue(card.getRank()));
            }
        }

        std::sort(ranks.begin(), ranks.end());

        for (size_t i = 0; i <= ranks.size() - 5; ++i) {
            if (ranks[i + 4] - ranks[i] == 4) {
                return true;
            }
        }
    }

    return false;
}

bool PokerGame::isFourOfAKind(const std::vector<Card>& hand) {
    for (int i = 0; i < hand.size(); i++) {
        int count = 0;
        for (int j = 0; j < hand.size(); j++) {
            if (hand[i].getRank() == hand[j].getRank()) {
                count++;
            }
        }
        if (count == 4) {
            return true;
        }
    }
    return false;
}

bool PokerGame::isFullHouse(const std::vector<Card>& hand) {
    int threeOfAKindRank = -1;
    int pairRank = -1;

    for (int i = 0; i < hand.size(); i++) {
        int count = 0;
        for (int j = 0; j < hand.size(); j++) {
            if (hand[i].getRank() == hand[j].getRank() && i!=j) {
                count++;
            }
        }
        if (count == 3) {
            threeOfAKindRank = getRankValue(hand[i].getRank());
        } else if (count == 2) {
            pairRank = getRankValue(hand[i].getRank());
        }
    }

    return threeOfAKindRank != -1 && pairRank != -1 && threeOfAKindRank != pairRank;
}

bool PokerGame::isFlush(const std::vector<Card>& hand) {
    int suitCount[4] = {0};

    for (const auto& card : hand) {
        if (card.getSuit() == "Clubs") {
            suitCount[0]++;
        } else if (card.getSuit() == "Diamonds") {
            suitCount[1]++;
        } else if (card.getSuit() == "Hearts") {
            suitCount[2]++;
        } else if (card.getSuit() == "Spades") {
            suitCount[3]++;
        }
    }
    int n =4;
    for (int i = 0; i < n; i++) {
        if (suitCount[i] == 5) {
            return true;
        }
    }

    return false;
}

bool PokerGame::isStraight(const std::vector<Card>& hand) {
    std::vector<int> ranks;
    for (const auto& card : hand) {
        int rankValue = getRankValue(card.getRank());
        ranks.push_back(rankValue);
    }

    sort(ranks.begin(), ranks.end());


    std::vector<int> sequence = {2, 3, 4, 5, 14};
    if(includes(ranks.begin(), ranks.end(), sequence.begin(), sequence.end()))
        return true;

    int count = 1;
    for (int i = 1; i < ranks.size(); i++) {
        if (ranks[i] == ranks[i - 1] + 1) {
            count++;
            if (count == 5)
                return true;
        } else if (ranks[i] != ranks[i - 1]) {
            count = 1;
        }
    }

    return false;
}

bool PokerGame::isThreeOfAKind(const std::vector<Card>& hand) {
    for (int i = 0; i < hand.size(); i++) {
        int count = 0;
        for (int j = 0; j < hand.size(); j++) {
            if (hand[i].getRank() == hand[j].getRank()) {
                count++;
            }
        }
        if (count == 3) {
            return true;
        }
    }
    return false;
}

bool PokerGame::isTwoPair(const std::vector<Card>& hand) {
    int pairCount = 0;
    for (int i = 0; i < hand.size() - 1; i++) {
        for (int j = i + 1; j < hand.size(); j++) {
            if (hand[i].getRank() == hand[j].getRank()) {
                pairCount++;
                if (pairCount == 2) {
                    return true;
                }
            }
        }
    }
    return false;
}

bool PokerGame::isOnePair(const std::vector<Card>& hand) {
    for (int i = 0; i < hand.size() - 1; i++) {
        for (int j = i + 1; j < hand.size(); j++) {
            if (hand[i].getRank() == hand[j].getRank()) {
                return true;
            }
        }
    }
    return false;
}

int PokerGame::getRankValue(const std::string& rank) {
    if (rank == "2") {
        return 2;
    } else if (rank == "3") {
        return 3;
    } else if (rank == "4") {
        return 4;
    } else if (rank == "5") {
        return 5;
    } else if (rank == "6") {
        return 6;
    } else if (rank == "7") {
        return 7;
    } else if (rank == "8") {
        return 8;
    } else if (rank == "9") {
        return 9;
    } else if (rank == "10") {
        return 10;
    } else if (rank == "J") {
        return 11;
    } else if (rank == "Q") {
        return 12;
    } else if (rank == "K") {
        return 13;
    } else if (rank == "A") {
        return 14;
    }

    return 0;
}

std::string PokerGame::getHandName(int rank) {
    static const std::vector<std::string> handNames = {
            "High Card",
            "One Pair",
            "Two Pair",
            "Three of a Kind",
            "Straight",
            "Flush",
            "Full House",
            "Four of a Kind",
            "Straight Flush",
            "Royal Flush"
    };

    if (rank >= 0 && rank < handNames.size()) {
        return handNames[rank];
    }

    return "Unknown Hand";
}

int PokerGame::getWinner() const {
    return winner;
}

