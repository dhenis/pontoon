#include "Game.h"
#include <set>
#include <string>
#include <iostream>


Game::Game(){

      // prepare to recieve user dialoge
      answers.insert(sticks.begin(), sticks.end());
      answers.insert(twist.begin(), twist.end());

      // prepare to recieve user dialoge
      plays.insert(ask_play_yes.begin(), ask_play_yes.end());
      plays.insert(ask_play_no.begin(), ask_play_no.end());


}

int Game::ask_twist_stick(std::string & x)
{

  return (answers.find(x) == answers.end());


}

int Game::ask_play(std::string & x)
{

  return (plays.find(x) == plays.end());


}


int Game::goPlay(std::string & x)
{

  return (ask_play_yes.find(x) != ask_play_yes.end());

}

int Game::endGame(std::string & x)
{

  return (ask_play_no.find(x) != ask_play_no.end());

}

int Game::goTwist(const std::string & x)
{

  return (twist.find(x) != twist.end()) ;

}

int Game::goStick(const std::string & x)
{

  return (sticks.find(x) != sticks.end());

}

void Game::resetRound()
{

  rounds =1;

}

int Game::getRounds()
{

  return rounds;

}

void Game::addRounds()
{

  rounds += 1;

}
