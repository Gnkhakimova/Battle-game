#include "Enemy.h"
using namespace std;

//For the Enemy class, this function will randomly generate a choice 
//for the enemy (1 for offensive, 2 for defensive).
void Enemy::SelectAction()
{
    //PRE: None
    //POST: Attack type
    //Returns: None
    int answer = 0;
    answer = GetRandom(1, 2);
    m_attackType = (AttackType)answer;
}