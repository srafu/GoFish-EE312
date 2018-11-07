#include <cstdlib>
#include <ctime>

#include "card.h"
#include "deck.h"

static const int SIZE = 52;
Card myCards[SIZE];
int myIndex; 

Deck::Deck(){
	//make a fresh deck, spades first then hearts then diamonds, last clubs
	Card::Suit suits[] = {Card::spades, Card::hearts, Card::diamonds, Card::clubs};
	for(int i = 0; i < 4; i++){
		for(int j = 1; j < 13 + 1; j++){
			//j*i + j returns current card in deck
			myCards[j*i + j] = Card(j, suits[i]);
		}
	}
	//seed the random number
	srand((unsigned) time(0));
	//set index to zero
	myIndex = 0;
}

void Deck::shuffle(){
	//loop through the deck and swap each card with a random index
	for(int i = 0; i < SIZE; i++){
		this->swap(i, rand() % SIZE);
	}
}

Card Deck::dealCard(){
	if(myIndex < SIZE){
		Card currentCard = myCards[myIndex];
		myIndex++;

		return currentCard;
	} else {
		return Card();
	}
}

int Deck::size() const{
	return SIZE - myIndex;
}

void Deck::swap(int card1, int card2){
	Card temp = myCards[card1];
	myCards[card1] = myCards[card2];
	myCards[card2] = temp;
}
