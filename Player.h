#ifndef PLAYER_H
#define PLAYER_H
using namespace std;
#include<string.h>
#include<iostream>


class Player
{ 
 const char* namePlayer;
 int levelPlayer;
 int forceplayer;
 unsigned int maxHealth;
 unsigned int hpPlayer;
 unsigned int coinsPlayer;
public:

Player(const char* name,int Maxhealth=100 ,int force=5);
Player()=default;
~Player()=default;
Player(Player& Player)=default;
Player& operator=(const Player& other) = default;


void printInfo();
void levelUp();
int getLevel();
void buff(unsigned int value);
void heal(unsigned int hp);
void damage(unsigned int dama);
bool isKnockedOut();
void addCoins(unsigned int money);
bool pay(unsigned int price);
int getAttackStrength();

};
#endif