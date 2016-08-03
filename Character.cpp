#include "Character.h"


//initializes the member variables m_hp, m_atk, m_def, and m_name, 
//with the values passed in.

void Character::Setup(const string& name, int hp, int atk, int def)
{
    //PRE:   const string reference name, int hp,int atk, int def
    //POST: None
    //Returns: None
    m_name = name;
    m_hp = hp;
    m_atk = atk;
    m_def = def;

}

// Utilize cout to display the character's name, HP, ATK, and DEF.
void Character::DisplayStats()
{
    //PRE: None
    //POST: Name, HP, Attack type.
    //Returns: None
    cout << "Name: " << m_name << endl;
    cout << "HP: " << m_hp << endl;
    cout << "Attack type: " << m_atk << endl;
    cout << "Defensive: " << m_def << endl;
}

void Character::SelectAction() // should be empty
{
    //PRE: None
    //POST: None
    //Returns: None
}

//This function will calculate how much damage the character will do, 
//based on their attack type and their ATK stat.

int Character::GetAttack()
{
    //PRE: None
    //POST: Choose attack type
    //Returns: Attack type
    int answer = 0;

    if (m_attackType == AttackType{ OFFENSIVE })
    {
        cout << m_name << " using OFFESNSIVE atack" << endl;
        return (GetRandom(1, 3) + m_atk);
    }
    else
    {
        cout << m_name << " using DEFENSIVE atack" << endl;
        return m_atk;
    }

}

//This function will take the input of attack damage, which was generated 
//by the opposing character's GetAttack() function.

void Character::GetHit(int attack)
{
    //PRE: int attack
    //POST: calculate attack damage
    //Returns: None
    int answer = 0;
    int damage = 0;

    if (attack == AttackType{ OFFENSIVE })
    {
        damage = attack - m_def;
    }
    else
    {
        damage = attack - m_def - GetRandom(1, 3);
    }
    if (damage > 0)
    {
        m_hp -= damage;
    }
    else
    {
        m_hp += damage; 
    }
}

// Return the value of m_hp.
int Character::GetHp()
{
    //PRE: None
    //POST: None
    //Returns: HP
    return m_hp;
}


