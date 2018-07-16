#ifndef BANK_H
#define	BANK_H

#include <array>
#include <string>
#include <vector>
#include "User.h"
#include "Card.h"


class Bank : public User, public Card
{

public:
  // constructor of user
  Bank();

  // destructor of user class
  virtual ~Bank(){};

  // cheating function to see next card. but this function is only for bank
  int checkNextCard();

  // virtual void opening()  override;
  virtual void opening() const override ;

  // virtual void opening()  override; // to see who is the turn
  virtual void status() const override;

private:


};

#endif	/* BOARD_H */
