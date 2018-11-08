// FILE: card_demo.cpp
// This is a small demonstration program showing how the Card and Deck classes are used.
#include <iostream>    // Provides cout and cin
#include <cstdlib>     // Provides EXIT_SUCCESS
#include "card.h"
#include "player.h"
#include "deck.h"

using namespace std;


void dealHand(Deck &d, Player &p, int numCards)
{
   for (int i=0; i < numCards; i++)
      p.addCard(d.dealCard());
}

int main(){
    Deck d;
    d.shuffle();

    Player p1("Arul");
    Player p2("Juan");

    Player players[2];
    players[0] = p1;
    players[1] = p2;

    dealHand(d, p1, 7);
    dealHand(d, p2, 7);

    Card c1;
    Card c2;
    //first get rid of intial books
    while(p1.checkHandForBook(c1,c2)){
        p1.bookCards(c1,c2);
    }

    while(p2.checkHandForBook(c1,c2)){
        p2.bookCards(c1,c2);
    }

    while(d.size() > 0){
        Card choice = p1.chooseCardFromHand();
        if(p2.rankInHand(choice)){
            p1.addCard(p2.removeCardFromHand(p2.getCardOfSameRank(choice)));
        } else {
            dealHand(d, p1, 1);
        }

        cout << p1.showHand() << endl;

        choice = p2.chooseCardFromHand();
        if(p1.rankInHand(choice)){
            p2.addCard(p1.removeCardFromHand(p1.getCardOfSameRank(choice)));
        } else {
            dealHand(d, p2, 1);
        }    

        cout << p2.showHand() << endl;         
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




