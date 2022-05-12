#include <iostream>
#include <string>
#include "Player.h"
#include "utilities.h"
#define FIRSTLEVEL 1
#define STARTCOINS 0
#define DEAD 0

Player::Player(const char* name,int maxHp,int force)
{
    namePlayer =name;
    levelPlayer=FIRSTLEVEL;
    coinsPlayer=STARTCOINS;
    forceplayer=force;
    maxHealth=maxHp;
    hpPlayer=maxHp;
}
void Player::printInfo()
{   
    printPlayerInfo(namePlayer, levelPlayer, forceplayer, hpPlayer, coinsPlayer);
}
void Player::levelUp()
{
    if (levelPlayer<10)
    {
        levelPlayer++;
    }
}
int Player::getLevel()
{
  return levelPlayer;
}
void Player::buff(unsigned int value)
{
    forceplayer=forceplayer+value;
}
void Player::heal(unsigned int hp)
{
    if( hpPlayer+hp > maxHealth )
       hpPlayer=maxHealth;
    else
     hpPlayer+=hp;       
}
void Player::damage(unsigned int dam)
{
    if(hpPlayer-dam<0)
       hpPlayer=DEAD;
    else 
       hpPlayer-=dam;   
}
bool Player::isKnockedOut()
{
    if(hpPlayer==0)
       return true;
    return false;       
}
void Player::addCoins(unsigned int money)
{
    coinsPlayer+=money;
}
bool Player::pay(unsigned int cost)
{
    if(cost > coinsPlayer)
      return false;
    coinsPlayer-=cost;
    return true;  
}
int Player::getAttackStrength()
{
    return (levelPlayer+forceplayer);
}