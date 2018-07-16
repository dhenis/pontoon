#include <iostream>
#include <string>
#include <iomanip>

#include "Card.h"
#include "User.h"
#include "Player.h"
#include "Bank.h"
#include "Game.h"
#include "File.h"


int main() {
 // instance fo game object --> main manipulator of game
Game gm;
Game * game = &gm;

// instance for Player
Player ply ;
Player * player = &ply;

// instance for bank
Bank bk ;
Bank * bank = &bk;

std::string answer; // for deriving input choice to twist or stick
std::string play_again; // for deriving input to restart game or quit
std::string finish_time = ""; //

int play_on = 1; // in system
int new_game = 1; // in system


while(new_game)
{
  // starting / restarting game

// ------reset-----
  player->dropuserHand();
  bank->dropuserHand();
  bank->resetCurrentCard();
  bank->shuffleCard();

// -------------

//  bank->printCard(); // for debuging show the card

  player->pickACard(bank->getOneCard());  // pick 1 card for player
  bank->addCurrentCard(); // for pointing card 1

  bank->pickACard(bank->getOneCard()); // pick 1 card for bank
  bank->addCurrentCard(); // for pointing card 2

  player->pickACard(bank->getOneCard());  // pick 1 card for player
  bank->addCurrentCard(); // for pointing card 3

  bank->pickACard(bank->getOneCard()); // pick 1 card for bank
  bank->addCurrentCard(); // for pointing card 4

  // initial game
  player->status();
  // std::cout<<std::endl << "your hand is : " << std::endl<<std::endl;

  player->showUserHand();

  while (play_on)
  {

    // for input validation
    do
    {

      if(player->getTotalCardInHand()<= 4) //
      {

        if(player->countPoint() == 21){

          play_on=0; // go to result state
          answer = "s"; // sistem assumses player stick if the point ==21

        }else if(bank->countPoint() == 21){

          play_on=0;  // go to result state
          answer = "t"; // only for exit this loop
        }else{

          std::cout <<std::endl<< "[s]tick or [t]wist? ";
          std::cin >> answer; // ordinary user input

        }

      } else // user only can input until 5 cards on hand. after that, system should not ask anymore
      {
        answer = "s";
      }

    }while (game->ask_twist_stick(answer)); // always result 1 if no found

    // logic for twist

    if (game->goTwist(answer) and play_on == 1 ) // player choose twist
    {


      player->pickACard(bank->getOneCard()); // pick 1 card for player

      bank->addCurrentCard(); // for pointing card 5

      player->status();

      player->showUserHand();

      if(player->countPoint() >20 ) // evaluate later
      {

        play_on = 0;

      }

    }

    else if (game->goStick(answer) and play_on == 1) // player choose stick
    {

      // dealer logic
       bank->status();

       bank->showUserHand();

       if(bank->countPoint() >20 ) // evaluate later
       {

         play_on = 0;

       }

       // running bot (auto draw a card for )

       if(bank->countPoint()  <  player->countPoint())
       {

         do // auto genereate dealer (bot)
         {

           if(bank->getTotalCardInHand() <= 5)
           {


               bank->pickACard(bank->getOneCard()); // pick 1 card for bank
               bank->addCurrentCard(); // for pointing card 4

               bank->opening(); // for pointing card 4
               bank->status();

               bank->showUserHand();

               if(bank->countPoint() >20 ) // evaluate later
               {

                  play_on = 0;

               }

            }


       }while ((bank->checkNextCard()) <= 21 and bank->getTotalCardInHand() <= 5);

      }

       play_on = 0;

     }

  }

// decide the winner

// bust if lose
if((bank->countPoint() > player->countPoint() and bank->countPoint() <= 21) or player->countPoint() > 21)
{
    if((bank->countPoint() < player->countPoint()  and bank->countPoint()< 21) and player->countPoint()  < 21) // as requirement if bank lost, it should be bust
    {

      bank->pickACard(bank->getOneCard()); // pick 1 card for bank
      bank->addCurrentCard(); // for pointing card 4

      bank->opening(); // for pointing card 4
      bank->status();

      // potentially bug because the resuld should busts
      bank->showUserHand();

      // std::cout<<std::endl<<"BUST!!!"<<std::endl<<std::endl;

    }

    game->insertHistory("lost");

    std::cout<<"Bad luck, the bank won"<<std::endl<<std::endl;


  }else if(bank->countPoint() == player->countPoint() and bank->countPoint()< 21) //  draw condtion
  {

    if(bank->getTotalCardInHand() > player->getTotalCardInHand())
    {
      game->insertHistory("lost");

      std::cout<<"Bad luck, the bank won"<<std::endl<<std::endl;

    }else if(bank->getTotalCardInHand() == player->getTotalCardInHand())
    {

      game->insertHistory("draw");

      std::cout<<"The game is draw"<<std::endl<<std::endl;

    }else
    {
      game->insertHistory("draw");

      std::cout<<"Well done, you won !!!"<<std::endl<<std::endl;

    }

//11.	If both the player and the bank have the same value,
// the one has more cards in hand (maximum 5 cards) wins.
// If they have the same value and same number of cards, it is draw.
  }
  else
  {

    game->insertHistory("won");

    std::cout<<"Well done, you won !!!"<<std::endl<<std::endl;

  }

  do // validation
  {
    std::cout<<"do you want to play again ([y]es/[n]o) ";

  } while ((std::cin >> play_again) && game->ask_play(play_again));


  if (game->goPlay(play_again)) // dealer turn
  {

    play_on = 1; // start game again

  }
  if(game->endGame(play_again))
  {

    std::cout<<std::endl<< "Thanks, bye!"<<std::endl<<std::endl;

    game->setEndTimeReadable();

    game->createFile();

    new_game = 0; // end game

  }

}

// uncomment for debuging
// std::cout<<std::endl<<"hand player "<<player->getTotalCardInHand()<<std::endl;
// std::cout<<"hand bank "<<bank->getTotalCardInHand()<<std::endl;
// std::cout<<std::endl<<"history rounds "<<game->getSizeHistory()<<std::endl;
// std::cout<<std::endl<<"time start"<<game->getStartTimeReadable()<<std::endl;
// std::cout<<std::endl<<"time end"<<game->getEndTimeReadable()<<std::endl<<std::endl;


return 0;
}
