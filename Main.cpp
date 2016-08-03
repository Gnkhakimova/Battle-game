/*

Name:	Gulnoza Khakimova
Course: CS 201R
Program: Battle Game.
Due Date:	02/28/2016
Description:  Two characters battle, choosing what kind of attack to do each round,
and taking damage each round. When one of the characters hits 0 HP, the game is over.
Inputs: Player name, Stat options, attack types.
Outputs: Display stats, Attack types, Number of HPs, Game result.
Algorithm:
1. In the main program, create a Player and Enemy object.
2. First Loop: Character Creation
  1. Call the SetupCharacters(...) function to set up the player and enemy's beginning
  stats.
  2. Afterwards, display both the player and enemy's stats (via DisplayStats() function),
  and ask them if this is OK. (Use a number menu, so you can use GetUserInput(...)).
  3. Keep looping through the stat creation until the player chooses the “ready” option.
3. Second Loop: Gameplay – Continue looping until one character's life is less than or equal to 0.
  1. Display the round # and both the character's stats at the beginning of each round.
  2. Display the action menu:
    1. Offensive Attack
    2. Defensive Attack
  3. Call each character's SelectAction() function.
  4. Afterwards, call both character's GetHit(...) functions, passing in the attack value
  (from GetAttack()) from the opposite character.
4. Outside of the loop – game over
  1. Check to see whose HP is <= 0. Display “You Win” if the player is still alive, and “You
  Lose” if the player has died.


*/

#include "Character.h"
#include "Utils.h"
#include "Enemy.h"
#include "Player.h"

using namespace std;

void SetupCharacter(Character &Player, Character &Enemy); //prototype

int main()
{
    //PRE: Create an objects
    //POST: Output stats and game result
    //Returns: 0
    
    Player Player;
    Enemy Enemy;

    int answer = 0;
    while (answer != 1)
    {
        // Call the SetupCharacters(...) function to set up the player 
        //and enemy's beginning stats.
        SetupCharacter(Player, Enemy);
        // Display both the player and enemy's stats
        Player.DisplayStats();
        Enemy.DisplayStats();
        //Ask them if this is OK
        cout << "Is this correct? 1 = Yes, 0 = No" << endl;
        answer = GetUserInput(0, 1);
    }

    // Display the round # and both the character's stats at the beginning of each round.
    int round = 1;

    while (Player.GetHp() > 0 && Enemy.GetHp() > 0)
    {
        cout << "Round # " << round << endl;
        round++;
        //Display the action menu:
        
        Player.DisplayStats();
        Enemy.DisplayStats();
        int playerAttack = Player.GetAttack();
        int enemyAttack = Enemy.GetAttack();
        ////Call each character's SelectAction() function.
        Player.SelectAction();
        Enemy.SelectAction();
        //call both character's GetHit(...) functions, passing in the attack value
        //(from GetAttack()) from the opposite character.
        Player.GetHit(enemyAttack);
        Enemy.GetHit(playerAttack);

    }
    //Check to see whose HP is <= 0. Display “You Win” if the player 
    //is still alive, and “You Lose” if the player has died.
    if (Player.GetHp() > Enemy.GetHp())
    {
        cout << "You win" << endl;
    }
    else
    {
        cout << "You lose" << endl;
    }
    system("pause");
    return 0;

}

//For this function, it will first ask the user to enter their name. 
//Secondly, it will display a set of three stats to choose from :
void SetupCharacter(Character &Player, Character &Enemy)
{
    //PRE:  Character reference of player,  Character reference of enemy
    //POST: Stat options
    //Returns: None
    string playerName = "";
    int atk = 0;
    int def = 0;
    int hp = 100;
    int answer = 0;
    cout << "Enter your name: " << endl;
    cin >> playerName;

    bool correctAnswer = false;
    while (correctAnswer == false)
    {
        cout << "Choose your stats: " << endl;
        cout << "Option " << "\t" << "Attack" << "\t" << "Defense" << endl;
        cout << "---------------------------------------------" << endl;
        cout << "1   " << "\t" << "5" << "\t" << "15" << endl;
        cout << "2   " << "\t" << "15" << "\t" << "5" << endl;
        cout << "3   " << "\t" << "10" << "\t" << "10" << endl;
        cin >> answer;
        if (answer == 1 || answer == 2 || answer == 3)
        {
            correctAnswer = true;
        }
    }

    // The user selects the stats for the player, and the enemy's 
    //stats are randomly selected. Use the Setup(...) function from 
    //the Character class to initialize both characters.
    switch (answer)
    {
    case 1:
        atk = 5;
        def = 15;
        break;
    case 2:
        atk = 15;
        def = 5;
        break;
    case 3:
        atk = 10;
        def = 10;
        break;
    }
    Player.Setup(playerName, hp, atk, def);


    int answer2 = 0;
    answer2 = GetRandom(1, 3);
    switch (answer2)
    {
    case 1:
        atk = 5;
        def = 15;
        break;
    case 2:
        atk = 15;
        def = 5;
        break;
    case 3:
        atk = 10;
        def = 10;
        break;
    }
    Enemy.Setup("Enemy", hp, atk, def);
}
