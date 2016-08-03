#include "Player.h"
using namespace std;

//For the Player class, this function will prompt the user to enter an 
//option (1 for offensive, 2 for defensive).
void Player::SelectAction()
{
    //PRE: None
    //POST: Attack type
    //Returns: None
    int answer;
    cout << "Enter attack type, 1 - Offensive, 2- defensive: " << endl;
    cin >> answer;
    m_attackType = (AttackType)answer;
}