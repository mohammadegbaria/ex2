#include "Mtmchkin.h"
#include "Card.h"
#define FIRST_CARD 0








Mtmchkin::Mtmchkin(const char* playerName, const Card* cardsArray, int numOfCards)
{
     gamer=Player(playerName);
    numberOfCards=numOfCards;
    index=FIRST_CARD;
    for(int i=0;i<numberOfCards;i++)
    {
    arrayOfCards[i]=cardsArray[i];
    }
    game=GameStatus::MidGame;
}

GameStatus Mtmchkin:: getGameStatus() const
{
  return game;
}

void Mtmchkin:: playNextCard()
{
    if(index==numberOfCards-1)
    {
        index=FIRST_CARD;
    }
    else
    {
        index++;
    }
    arrayOfCards[index].printInfo();
    arrayOfCards[index].applyEncounter(gamer);
    gamer.printInfo();
}
bool Mtmchkin::isOver()const
{
    if(game == GameStatus::MidGame)
    {
        return false;
    }
        return true;
}
Mtmchkin::Mtmchkin(Mtmchkin& other)
    {
        int size = other.numberOfCards;
        arrayOfCards = new Card[size];

        game = other.game;
        index = other.index;
        gamer = Player(other.gamer);
        numberOfCards = other.numberOfCards;

        for(int card = 0; card < numberOfCards; card++){
            arrayOfCards[card] = other.arrayOfCards[card];
        }

    }

    Mtmchkin& Mtmchkin::operator=(const Mtmchkin& other)
    {
        if(this == &other){
            return *this;
        }
        delete [] arrayOfCards;
        int size = other.numberOfCards;
        arrayOfCards = new Card[size];
        game = other.game;
        index = other.index;
        gamer = other.gamer; 
        numberOfCards = other.numberOfCards;

        for(int card = 0; card < numberOfCards; card++){
            arrayOfCards[card] = other.arrayOfCards[card];
        }

        return *this;
    }
    Mtmchkin::~Mtmchkin()
    {
        delete [] arrayOfCards;
    }


