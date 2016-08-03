#include <iostream>
#include <ctime>


using namespace std;

//Prompt the user for input (as an integer), and validate whether it 
//is between the valid minimum and maximum values.Only return 
//the user's choice once they enter a valid option.

int GetUserInput(int minimum, int maximum)
{
    //PRE: int minimum, maximum
    //POST: None
    //Returns: User input
    int answer = 0;
    bool correctAnswer = false;
    while (correctAnswer == false)
    {
        cout << "Please enter you answer: " << endl;
        cin >> answer;

        if (answer >= minimum && answer <= maximum)
        {
            correctAnswer = true;
        }
    }
    return answer;
}

//Randomly generate a number between minimum and maximum.
int GetRandom(int minimum, int maximum)
{
    //PRE: int Minimum, maximum
    //POST: None
    //Returns: Randomly generated number
    srand(time(NULL));
    int randNumber = rand() % (maximum + 1);
    return randNumber;
}



