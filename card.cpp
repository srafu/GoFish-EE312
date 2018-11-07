//Juan Paez and Arul Saraf
// implementation for class "card"
//Implements constructors and functions as defined in header file, card.h

#include <iostream>
#include <string>
#include "card.h"

using namespace std;

Card::Card(){
    myRank = 1;
    mySuit = spades;
}

Card::Card(int rank, Suit suit){
    if (rank>0 && rank<14)
        myRank = rank;
    else
        myRank = 1;
    mySuit = suit;
}


int Card::getRank() const {
    return myRank;
}

Card::Suit Card::getSuit() const {
    return mySuit;
}

bool Card::sameSuitAs(const Card &c) const {
    if (mySuit == c.getSuit()){
        return true;
    }
    return false;
}

string Card::suitString(Card::Suit s) const {
    string suitPrint;

    if (s==hearts)
        suitPrint.append("h");
    else if (s==spades)
        suitPrint.append("s");
    else if (s==clubs)
        suitPrint.append("c");
    else if (s==diamonds)
        suitPrint.append("d");

    return suitPrint;
}

string Card::rankString(int r) const {
    string rankPrint;

    if (r > 1 && r < 11){
        string num = to_string(r);
        rankPrint.append(num);
    }
    else if (r == 1)
        rankPrint.append("A");
    else if (r == 11)
        rankPrint.append("J");
    else if (r==12)
        rankPrint.append("Q");
    else if (r==13)
        rankPrint.append("K");

    return rankPrint;
}


string Card::toString() const {
    string cardPrint;

    cardPrint.append(Card::rankString(myRank));
    cardPrint.append(Card::suitString(mySuit));
    cardPrint.append("\0");

    return cardPrint;
}

bool Card::operator!=(const Card &rhs) const {
    if (myRank == rhs.getRank())
        return false;
    if (mySuit == rhs.getSuit())
        return false;
    return true;
}

bool Card::operator==(const Card &rhs) const {
    if (myRank != rhs.getRank())
        return false;
    if (mySuit != rhs.getSuit())
        return false;
    return true;
}


ostream& operator << (ostream& out, const Card& c){
    cout<<c.toString();
}