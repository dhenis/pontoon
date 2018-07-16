#include "Bank.h"
#include <vector>
#include <string>
#include <iostream>
Bank::Bank()
{


}

/*print EmployeeBase's information, virtual*/
void Bank::opening() const
{

  std::cout << std::endl<<"the bank draws a card:" << std::endl;

}


int Bank::checkNextCard()
{

  return User::countPoint() + (Card::getOneCard()%13);

}


void Bank::status() const
{
  
  std::cout << std::endl<<"bank hand is:" << std::endl<<std::endl;

}
