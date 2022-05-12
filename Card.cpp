#include <string>
#include "Card.h"
#define WIN 1

Card::Card(CardType type, const CardStats& stats)
{
    m_effect= type;
    m_stats=stats;  
}

void Card::printInfo() const
{
switch (m_effect)
{
case CardType::Battle:
    printBattleCardInfo(this->m_stats);
    break;
case CardType::Buff:
    printBuffCardInfo(this->m_stats);
    break;
case CardType::Heal:
     printHealCardInfo(this->m_stats);
     break;
case CardType::Treasure:
    printTreasureCardInfo(this->m_stats);
    break;  
}
}
void Card::applyEncounter(Player& player)const
{
   switch (m_effect)
   {
   case CardType::Buff:
        if(player.pay(m_stats.cost))
            player.buff(m_stats.heal);

   case CardType::Heal:
        if(player.pay(m_stats.cost))
           player.heal(m_stats.buff);

   case CardType::Treasure:
        player.addCoins(m_stats.loot);

   case CardType::Battle:
      if (player.getAttackStrength()<m_stats.force)
      {
          player.damage(m_stats.hpLossOnDefeat);
          printBattleResult(!WIN);
      }
      else
      {        
          player.addCoins(m_stats.loot);
          player.levelUp();
          
          printBattleResult(WIN);

      }

break;
}
}
