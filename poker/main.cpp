#include <iostream>
#include <string>
#include <limits>

#include "Player.h"
#include "PokerGame.h"
using namespace std;


int main() {
    string playerName;
    cout << endl;
    cout << "--------------------Poker--------------------";
    cout << endl << endl ;
    cout<< "Enter your name: ";
    cin>> playerName;

    Player player(playerName);
    PokerGame game(playerName);

    int credit = game.getCredit();
    int option=0;
    int option1=0;

    while (credit > 0) {
        system("cls");
        cout << endl;
        player.printStats("player_stats.txt");
        cout << "--------------------Poker--------------------";
        cout << endl << endl ;
        cout << "Current Credit:" << " " << credit << endl;
        cout << "Wins: " << player.getWin() <<" Losses: " <<player.getLoss()<< " Ties: "<<player.getTie()<<endl<<endl;
        cout << "1)Play round. (entry bet: 10 credits)." << endl;
        cout << "2)Skip round." << endl;
        cout << "Choose option:";

        if (!(cin >> option)) {
            cout << "Invalid input! Please enter a valid option." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }



        switch (option) {

            case 1:

                system("cls");
                cout << endl;
                cout << "--------------------Poker--------------------";
                cout << endl << endl ;
                game.computeCredit();
                credit = game.getCredit();
                cout << game << endl;
                game.dealCards(2);
                game.displayHands();
                game.display3Cards();
                option1 = 0;
                while (option1 != -1) {
                    cout<< endl;
                    cout << "1)Raise"<< endl;
                    cout << "2)Check"<< endl;
                    cout << "Choose option:";

                    if (!(cin >> option1)) {
                        cout << "Invalid input! Please enter a valid option." << endl;
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        continue;
                    }

                    switch(option1){

                        case 1:
                            game.placeBet();
                            std::cout <<" Common Cards:" << std::endl;
                            game.display2Cards();
                            game.dealerHands();
                            game.determineWinner();
                            game.addWins();
                            game.resetBet();
                            credit = game.getCredit();
                            cout << "You have:" << " " << credit << " " << "credits." << endl;
                            if(game.getWinner()==1)
                                player.setWin();
                            else if (game.getWinner()==0)
                                player.setTie();
                            else if (game.getWinner()==-1)
                                player.setLoss();

                            cout << "Wins: " << player.getWin() <<" Losses: " <<player.getLoss()<< " Ties: "<<player.getTie()<<endl;
                            option1 = -1;
                            player.printStats("player_stats.txt");
                            cout << "Press Enter to continue.";
                            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                            cin.get();
                            system("cls");
                            player.printStats("player_stats.txt");
                            break;

                        case 2:
                            game.check();
                            std::cout << std::endl<<" Common Cards:" << std::endl;
                            game.display2Cards();
                            game.dealerHands();
                            game.determineWinner();
                            game.addWins();
                            game.resetBet();
                            credit = game.getCredit();
                            cout << "You have:" << " " << credit << " " << "credits." << endl << endl;

                            if(game.getWinner()==1)
                                player.setWin();
                            else if (game.getWinner()==0)
                                player.setTie();
                            else if (game.getWinner()==-1)
                                player.setLoss();

                            cout << "Wins: " << player.getWin() <<" Losses: " <<player.getLoss()<< " Ties: "<<player.getTie()<<endl;
                            option1 = -1;
                            player.printStats("player_stats.txt");
                            cout << "Press Enter to continue.";
                            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                            cin.get();
                            system("cls");
                            player.printStats("player_stats.txt");
                            break;

                        default:
                            cout <<"Invalid choice! Try again."<<endl;
                            break;
                    }
                }
                break;

            case 2:
                system("cls");
                cout << endl;
                cout << "--------------------Poker--------------------";
                cout << endl << endl ;
                cout << "Skipped this round." << endl;
                game.dealCards(2);
                game.displayHands();
                game.display3Cards();
                game.display2Cards();
                game.dealerHands();
                game.determineWinner();
                cout << "Press Enter to continue.";
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                cin.get();
                system("cls");
                break;

            default:
                cout <<"Invalid choice! Try again."<<endl;
                break;
        }
    }
    cout << endl;
    cout << "--------------------Poker--------------------";
    cout << endl << endl ;
    cout << "You Lost!"<< endl;
    cout << "Press Enter to exit.";
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    cin.get();
    return 0;
}