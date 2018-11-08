// FILE: card_demo.cpp
// This is a small demonstration program showing how the Card and Deck classes are used.
#include <iostream>    // Provides cout and cin
#include <cstdlib>     // Provides EXIT_SUCCESS
#include <fstream>
#include "card.h"
#include "player.h"
#include "deck.h"

using namespace std;


void dealHand(Deck &d, Player &p, int numCards) {
    if(d.size() > 0) {
        Card temp;
        for (int i = 0; i < numCards; i++) {
            temp = d.dealCard();
            p.addCard(temp);
        }
        if (numCards==1)
            cout << p.getName() << " picks up " << temp << endl;
    }

}




int main(){

    ofstream myfile;
    myfile.open("gofish_results.txt");
    if (myfile.is_open()){
        cout<<"File open";
    }
    else {
        cout << "Failed to open";
        return 0;
    }


    //create and shuffle deck
    Deck d;
    d.shuffle();
    myfile<<"Deck shuffled!"<<endl;

    //create two players and deal hands, and then show cards
    Player p1("Arul");
    Player p2("Juan");
    dealHand(d, p1, 7);
    dealHand(d, p2, 7);
    myfile << "Dealing cards: \n";
    myfile <<  p1.showHand() << endl;
    myfile << p2.showHand() << endl;

    //dummy cards for comparison
    Card c1;
    Card c2;
    Card choice;

    //first get rid of initial books
    while(p1.checkHandForBook(c1,c2)){
        p1.bookCards(c1,c2);
    }
    while(p2.checkHandForBook(c1,c2)){
        p2.bookCards(c1,c2);
    }

    //show updated hands before first turn
    myfile << "\nBefore first turn: \n";
    myfile <<  p1.showHand() << endl;
    myfile << p2.showHand() << endl << endl;

    bool goFishFlag;

    while(d.size() > 0 || p1.getHandSize()>0 || p2.getHandSize()>0) {

        //PLAYER 1 GO
        goFishFlag = true;
        //repeat until Go Fish
        while (goFishFlag){
            if (p1.getHandSize() > 0) {
                //ask for card
                choice = p1.chooseCardFromHand();
                myfile << p1.getName() << " asks: Do you have a " << choice.rankString(choice.getRank()) << "" << endl;
                //hand over card or go fish
                if (p2.rankInHand(choice)) {
                    myfile << p2.getName() << " responds: yes, I do" << endl;
                    p1.addCard(p2.removeCardFromHand(p2.getCardOfSameRank(choice)));
                } else {
                    myfile << p2.getName() << " responds: no, Go Fish." << endl;
                    dealHand(d, p1, 1);
                    goFishFlag = false;
                }
            }
            //if no cards in hand, pick up
            else{
                dealHand(d, p1, 1);
                goFishFlag = false;
            }

            //book pairs
            while(p1.checkHandForBook(c1,c2)){
                p1.bookCards(c1,c2);
            }

            //show hands and deck size after turn
            myfile << p1.showHand() << endl;
            myfile << p2.showHand() << endl;
            myfile << d.size() << " cards left in the deck" << endl << endl << endl;
        }

        //PLAYER 2 GO
        goFishFlag = true;
        //repeat until Go Fish
        while (goFishFlag){
            if (p2.getHandSize() > 0) {
                //ask for card
                choice = p2.chooseCardFromHand();
                myfile << p2.getName() << " asks: Do you have a " << choice.rankString(choice.getRank()) << "" << endl;
                //hand over card or go fish
                if (p1.rankInHand(choice)) {
                    myfile << p1.getName() << " responds: yes, I do" << endl;
                    p2.addCard(p1.removeCardFromHand(p1.getCardOfSameRank(choice)));
                } else {
                    myfile << p1.getName() << " responds: no, Go Fish." << endl;
                    dealHand(d, p2, 1);
                    goFishFlag = false;
                }
            }
            //if no cards in hand, pick up
            else{
                dealHand(d, p2, 1);
                goFishFlag = false;
            }

            //book pairs
            while(p2.checkHandForBook(c1,c2)){
                p2.bookCards(c1,c2);
            }

            //show hands and deck size after turn
            myfile << p1.showHand() << endl;
            myfile << p2.showHand() << endl;
            myfile << d.size() << " cards left in the deck" << endl << endl << endl;
        }
    }


    myfile << endl << p1.getName() << "'s Score is: " << p1.getBookSize() << " books!\n";
    myfile << p2.getName() << "'s Score is: " << p2.getBookSize() << " books!\n";

    if (p1.getBookSize() > p2.getBookSize()){
        myfile << p1.getName() << " wins!";
    }
    else if (p2.getBookSize() > p1.getBookSize()){
        myfile << p2.getName() << " wins!";
    }
    else{
        myfile <<"TIE GAME";
    }



}







/**
// PROTOTYPES for functions used by this demonstration program:
void dealHand(Deck &d, Player &p, int numCards);



int main( )
{
    int numCards = 5;
    
    Player p1("Joe");
    Player p2("Jane");
    
    Deck d;  //create a deck of cards
    d.shuffle();
    
    dealHand(d, p1, numCards);
    dealHand(d, p2, numCards);
       
    cout << p1.getName() <<" has : " << p1.showHand() << endl;
    cout << p2.getName() <<" has : " << p2.showHand() << endl;
    
    return EXIT_SUCCESS;  
}




   
*/




