# Poker-game
Welcome to the Poker Game project! This is a simple command-line-based poker game implemented in C++. The game allows you to play a simplified version of poker against a dealer.

Table of Contents

1.Introduction
2.Requirements
3.How to Build
4.How to Play
5.Game Rules
6.Implementation Details
Contributing
7.License

1. Introduction
This project is a C++ implementation of a Poker Game. It provides a command-line interface for playing poker against a dealer. The game uses a simplified set of rules, and players can place bets and try their luck against the dealer.

2. Requirements
To build and run the Poker Game, you'll need the following:
C++ compiler supporting C++11 or later
Standard C++ library
Command-line terminal or console

3. How to Build
Follow these steps to build the Poker Game project:
Download the source files from https://github.com/Ionut2888/Poker-game.
Open a terminal or command prompt in the project directory.
Compile the source files using a C++ compiler with C++11 support.
g++ -std=c++11 main.cpp Card.cpp Deck.cpp Player.cpp PokerGame.cpp -o poker_game
After successful compilation, an executable named poker_game (or poker_game.exe on Windows) will be created in the project directory.

4. How to Play
Run the compiled poker_game executable in your terminal or command prompt.
The game will prompt you to enter your name.
Follow the on-screen instructions to place bets, view cards, and make decisions during the game.
The dealer will deal cards, and the winner will be determined based on the hand rankings.

5. Game Rules
This implementation of Poker Game follows simplified rules:
The game is played with a standard deck of 52 cards.
Each player (you and the dealer) is dealt two private cards.
Three common cards are dealt face-up on the table (the "flop").
Two additional common cards are dealt (the "turn" and the "river").
The player with the best hand at the end wins the game.

6. Implementation Details
The project consists of the following classes:
Card: Represents a playing card with a rank and a suit.
Deck: Represents a deck of cards, which can be shuffled and dealt.
Player: Represents a player with a name and a hand of cards.
PokerGame: Manages the game flow, dealing cards, evaluating hands, and determining the winner.

7.License
This Poker Game project is protected by a custom license. All rights are reserved by Ionuț Gârdu, the author and owner of this code. This software is provided "as is" without any warranty. Unauthorized distribution, modification, or use of this code is strictly prohibited without the express written permission of Ionuț Gârdu.
Redistribution and use in source and binary forms, with or without modification, are strictly prohibited without express written permission from Ionuț Gârdu.

This software is provided "as is" and any express or implied warranties, including, but not limited to, the implied warranties of merchantability and fitness for a particular purpose are disclaimed. In no event shall Ionuț Gârdu be liable for any direct, indirect, incidental, special, exemplary, or consequential damages (including, but not limited to, procurement of substitute goods or services; loss of use, data, or profits; or business interruption) however caused and on any theory of liability, whether in contract, strict liability, or tort (including negligence or otherwise) arising in any way out of the use of this software, even if advised of the possibility of such damage.

For any inquiries or permission requests, please contact: ionutgardu28@gmail.com

Disclaimer:
This project is provided "as is" without any warranty. Ionuț Gârdu shall not be liable for any direct or indirect damages arising from the use of this software.

For any questions or concerns about the project, please contact: ionutgardu28@gmail.com
