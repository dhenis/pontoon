#ifndef PLAYER_H
#define	PLAYER_H

#include <array>
#include <string>
#include <vector>
#include "User.h"

class Player : public User{
public:
  // constructor of user
  Player();

  // destructor
  virtual ~Player(){};


  // overiding function
  virtual void opening() const override ;
  virtual void status() const override;

private:


};

#endif	/* BOARD_H */
