#include <array>
#include <iostream>
#include "Card.h"

Card::Card(){

  fillCard();
  shuffleCard();

}


void Card::fillCard()
{

  // constructors
  for (int i=0; i<52; i++)
  {
      card[i] = i;  // fill the array in order
  //    convert(card[i]);
  }

}

//--- Shuffle elements by randomly exchanging each with one other.
void Card::shuffleCard()
{

  srand(time(0));  // initialize seed "randomly" // #done wiht constructor

  for (int i=0; i<52; i++)
  {
      int r = rand() % 52;  // generate a random position
      int temp = card[i]; card[i] = card[r]; card[r] = temp;
  }

}

// 
// int Card::checkNextCard()
// {
//
//   return card[(current_card)];
//
// }

//get one Card
// int Card::getCard(const int & num ) const{
//
// }


//print deck --> only for debuging and testing
void Card::printCard(){

  //--- Print first n cards as ints.
  for (int c=0; c<52; c++) {
      std::cout << card[c] << " ";  // Just print number
  }

  std::cout<<std::endl;

}


int Card::getCurrentCard() const
{

  return current_card;

}

void Card::setCurrentCard(int &x)
{

  current_card = x;

}

void Card::resetCurrentCard()
{

  current_card = 0;

}

void Card::addCurrentCard()
{

  current_card += 1 ;

}

int Card::getOneCard() const
{

  return card[current_card];

}
