#ifndef USER_H
#define	USER_H

#include <array>
#include <string>
#include <vector>

class User {
public:
  // constructor of user
  User();

  // destructor of user class
  virtual ~User(){};

  // will derive to child class
  virtual void opening() const  = 0; // pure virtual

  // status shows who is the turn
  virtual void status() const ;

  // clear the vector
  void dropuserHand();

  // convert from array to face and suit
  void convert(int & x) ;

  // to show what are cards on user hand
  void showUserHand() ;

  // count  how many cards on user hand
  int getTotalCardInHand();

  // append card to vector
  void pickACard( const int & x );

  // count total point of cards
  int countPoint();


private:

  std::vector<int> user_hand;


};

#endif	/* BOARD_H */
