#include "User.h"
#include <vector>
#include <string>
#include <iostream>
User::User()
{
  dropuserHand();
  user_hand.reserve(5); // reserve 5 blocks of array memory

}


void User::dropuserHand()
{

  user_hand.clear();

}

// convert to human card
void User::convert(int & x)
{
  std::string suit[4] = { "Diamonds", "Hearts", "Spade", "Clubs" };
  std::string number[13] ={"Ace","Two","Three","Four","Five","Six","Seven","Eight","Nine","Ten","Jack","Queen","King"};

  //  cout<<
  std::cout<<number[(x%13)]<<" "<<suit[(x/13)]<<std::endl;

}

//
void User::showUserHand()
{

  for (std::vector<int>::iterator it = user_hand.begin(); it != user_hand.end(); ++it)
  {
    convert(*it);
  }
  // std::cout<<"value = "<<countPoint()<<std::endl<<std::endl;

  if(countPoint() <= 21 )
  {

    std::cout<<"value = "<< countPoint()<<std::endl<<std::endl;

  }else{

    std::cout<<"BUST!!!"<<std::endl<<std::endl;

  }

}

//
int User::getTotalCardInHand()
{

  return user_hand.size();

}

void User::pickACard(const int & x ){

  user_hand.emplace_back(x);

}

// count value of user card
int User::countPoint()
{

  int total = 0;

  for (std::vector<int>::iterator itt = user_hand.begin(); itt != user_hand.end(); ++itt)
  // this logic to convert jack, queen and king to be equal 10
    //()?  :  ;
    if(*itt%13 >=9){

      total += 9; //--> maximum value is 9 because it will be added by the size(1), so will become 10

    }else{
      total += (*itt%13);
    }

  return total + user_hand.size();

}

void User::status() const
{



}
