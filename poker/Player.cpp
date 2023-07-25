#include "Player.h"
#include <iostream>

Player::Player(std::string playerName) {
    name = std::move(playerName);
}

void Player::addCard(Card const& card) {
    hand.push_back(card);
}

void Player::displayHand() {
    std::cout << name << "'s Hand:" << std::endl;
    for (const auto& card : hand) {
        std::cout << "Card: " << card.getRank() << " of " << card.getSuit() << std::endl;
    }
}

std::string Player::getName() {
    return name;
}

std::vector<Card> Player::getHand() {
    return hand;
}

void Player::clearHand() {
    hand.clear();
}

void Player::setWin() {
    win=win+1;
}

void Player::setLoss() {
    loss=loss+1;
}

void Player::setTie() {
    tie=tie+1;
}

int Player::getWin() const {
    return win;
}

int Player::getLoss() const {
    return loss;
}

int Player::getTie() const {
    return tie;
}

void Player::printStats(const std::string& filename) const {
    std::ofstream file(filename);

    if (file.is_open()) {
        file << "Player: " << name << std::endl;
        file << "Wins: " << win << std::endl;
        file << "Losses: " << loss << std::endl;
        file << "Ties: " << tie << std::endl;

        file.close();
    }
    else {
        std::cout << "Unable to open the file: " << filename << std::endl;
    }
}