#ifndef CARD_H
#define	CARD_H

#include <array>
#include <string>

class Card
{

public:
    // constructor
    Card();
    // destructor
    virtual ~Card(){};

    // I am using cons to avoid accidential modification
    // I am using pass by reference to avoid copying value repeately(pass by value)
    // I am not using template because I assume the data type is clear Integer and then I convert it to card format

    // fill the array variable
    void fillCard() ;

    //shuffle deck
    virtual void shuffleCard();

    //get one Card
    int getCard(const int & arr ) const;

    //print deck --> only for debuging and testing
    void printCard();

    // get the current card
    int getCurrentCard() const;

    // reset the current card becomes 0, it is used when the game is restarting
    void resetCurrentCard();

    //to set the value of current number/ navigate the dect
    void setCurrentCard(int &x);

    // add 1 current card when user draws a card
    void addCurrentCard();

    // get the current card
    int getOneCard() const;

    // int checkNextCard();

private:

    //int deck[52];

    std::array<int, 52> card; // array deck of cards

    int current_card = 0;

};

#endif	/* BOARD_H */
