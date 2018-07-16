#ifndef GAME_H
#define	GAME_H

#include <array>
#include <string>
#include <set>
#include "File.h"

class Game : public File {
public:
  // constructor
  Game();

  // destructor
  virtual ~Game(){};

  // asking variable
  int ask_twist_stick(std::string & x);
  int ask_play(std::string & x);

  // player choice to continue or not
  int goPlay(std::string & x);
  int endGame(std::string & x);

  // player choice to switch or stick
  int goTwist(const std::string & x);
  int goStick(const std::string & x);

  // round reset
  void resetRound();

  // get round
  int getRounds();

  // add 1
  void addRounds();

private:
  // in case of user unconciously activated caps lock #done
  // in my opinion it is the better validation input for user, instead of directly using if/else


  // this is for user dialoge to sticck or to twist
  std::set<std::string> sticks = {"s", "S"};
  std::set<std::string> twist = {"t", "T"};
  std::set<std::string> answers;


  // this is for user dialoge to play again or quit game
  std::set<std::string> ask_play_yes = {"y", "Y","yes","YES"}; // in case of user unconciously activated caps lock
  std::set<std::string> ask_play_no = {"n", "N","no","NO"};
  std::set<std::string> plays;

  int rounds =1;

};

#endif	/* BOARD_H */
