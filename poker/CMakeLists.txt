cmake_minimum_required(VERSION 3.24)
project(poker)

set(CMAKE_CXX_STANDARD 20)

add_executable(poker main.cpp Card.cpp Card.h Deck.cpp Deck.h Player.cpp Player.h PokerGame.cpp PokerGame.h)
