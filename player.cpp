#include "card.h"
#include "player.h"



using namespace std;

vector <Card> myHand;
vector <Card> myBook;

string myName;   

Player::Player(){
    //give player no name and clear the hand and book
    myName = "";
    srand((unsigned)time(0));
	idx=0;
}

void Player::addCard(Card c){
    myHand.push_back(c);
}

void Player::bookCards(Card c1, Card c2){
    //add the cards to the book
    myBook.push_back(c1);
    myBook.push_back(c2);

    //remove the cards from the deck
    this->removeCardFromHand(c1);
    this->removeCardFromHand(c2);
}

//OPTIONAL
// comment out if you decide to not use it
//this function will check a players hand for a pair. 
//If a pair is found, it returns true and populates the two variables with the cards tha make the pair.
bool Player::checkHandForBook(Card &c1, Card &c2){
    bool matchFound = false;

    //loop through the array for each card and look for a matahc
    vector<Card>::iterator it;
    for(it = myHand.begin(); it != myHand.end() && !matchFound; ++it){
        vector<Card>::iterator match;
        //search for a match in the cards beyond the card
        for(match= it; match != myHand.end() && !matchFound; ++match){
            if((*it).getRank() == (*match).getRank() && it != match){
                c1 = *it;
                c2 = *match;
                matchFound = true;
            }
        }
    }

    return matchFound;
}

//OPTIONAL
// comment out if you decide to not use it
//Does the player have a card with the same rank as c in her hand?
bool Player::rankInHand(Card c) const{
    int rank = c.getRank();
    int handSize = myHand.size();
    for (int i = 0; i<handSize; i++){
        if (myHand[i].getRank()==rank){
            return true;
        }
    }
    return false;
}

Card Player::getCardOfSameRank(Card c) const{
    int rank = c.getRank();
    int handSize = myHand.size();
    for (int i = 0; i<handSize; i++){
        if (myHand[i].getRank()==rank){
            return myHand[i];
        }
    }
}

//uses some strategy to choose one card from the player's
//hand so they can say "Do you have a 4?"
Card Player::chooseCardFromHand(){
    if(myHand.size() > 0){
        //if index is out of bounds, make zero
        if (idx>=myHand.size()){
            idx = 0;
        }
        Card temp = myHand[idx];
        idx++;
        return temp;
    }
    else {
        return Card(rand()%14, Card::spades);
    }
}

//Does the player have the card c in her hand?
bool Player::cardInHand(Card c) const{
    for (int i = 0; i<myHand.size(); i++){
        if (myHand[i] == c){
            return true;
        }
    }
}

//Remove the card c from the hand and return it to the caller
Card Player::removeCardFromHand(Card c){
    vector<Card>::iterator it;
    bool cardFound = false;
    for(it = myHand.begin(); it != myHand.end() && !cardFound; it++){
        if((*it) == c){
            cardFound = true;
        }
    }

    if(cardFound){
        it = --it;
        myHand.erase(it);
    }

    return c;
}

string Player::showHand() const{
    string hand = myName;
    hand.append("'s hand: ");

    for(int i = 0; i < myHand.size(); i++){
        hand.append(myHand[i].toString());
        hand.append(", ");
    }

    return hand;

}
string Player::showBooks() const{
    string book = myName;
    book.append("'s book: ");

    for(int i = 0; i < myBook.size(); i++){
        book.append(myBook[i].toString());
        book.append(", ");
    }

    return book;
}

int Player::getHandSize() const{
    return myHand.size();
}

int Player::getBookSize() const{
    return myBook.size() / 2;

}
   
//OPTIONAL
// comment out if you decide to not use it
//this function will check a players hand for a pair. 
//If a pair is found, it returns true and populates the two variables with the cards tha make the pair.

bool Player::checkHandForPair(Card &c1, Card &c2){

}

//OPTIONAL
// comment out if you decide to not use it    
//Does the player have a card with the same rank as c in her hand?
//e.g. will return true if the player has a 7d and the parameter is 7c

bool Player::sameRankInHand(Card c) const{

}   
   