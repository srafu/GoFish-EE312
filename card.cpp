//Juan Paez and Arul Saraf
// implementation for class "card"
//Implements constructors and functions as defined in header file, card.h

#include <iostream>
#include <string>
#include <sstream>
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
        myRank = -1;
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
        suitPrint = "h";
    else if (s==spades)
        suitPrint = "s";
    else if (s==clubs)
        suitPrint = "c";
    else if (s==diamonds)
        suitPrint = "d";

    return suitPrint;
}

string Card::rankString(int r) const {
    string rankPrint;

    if (r > 1 && r < 11){
        ostringstream s;
        s << r;
        rankPrint = string(s.str());
    }
    else if (r == 1)
        rankPrint = "A";
    else if (r == 11)
        rankPrint = "J";
    else if (r==12)
        rankPrint = "Q";
    else if (r==13)
        rankPrint = "K";

    return rankPrint;
}


string Card::toString() const {
    string cardPrint;

    cardPrint = Card::rankString(myRank);
    cardPrint.append(Card::suitString(mySuit));

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
    out<<c.toString();
    return out;
}