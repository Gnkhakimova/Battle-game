#pragma once
#include <iostream>
#include <string>
#include "Utils.h"

using namespace std;

class Character
{
    // create protective variables
protected:
    enum AttackType { OFFENSIVE = 1, DEFENSIVE = 2 };
    int m_hp;
    int m_atk;
    int m_def;
    AttackType m_attackType;
    string m_name;

public:
    // create public functions
    void Setup(const string &name, int hp, int atk, int def);
    void DisplayStats();
    void SelectAction();
    int GetAttack();
    void GetHit(int attack);
    int GetHp();
};

