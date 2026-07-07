//Portfolio 2!!
#include <iostream>
#include <string>
#include <cctype>
using namespace std;

// LEVEL 1 : A New Enemy, Basic Beginner level!
void loadLevel1() 
{
    //map loaded
    cout << "Level 1 loaded" << endl;
    cout << "Reach the $ without being seen by the guard." << endl;
    cout << "----------------------------------------------" << endl;

    string map[5] =
    {
        "########",
        "#      #",
        "#   #  #",
        "#     $#",
        "########"
    };
    //variables for guards and players
    int playerX = 1;
    int playerY = 1;

    int guardX = 2;
    int guardY = 6;

    int guardDirection = -1;
    char guardSymbol = '<';

    char input;

    while (true)
    {
        // Print map
        for (int i = 0; i < 5; i++)
        {
            for (int j = 0; j < 8; j++)
            {
                if (i == playerX && j == playerY)
                    cout << '@';
                else if (i == guardX && j == guardY)
                    cout << guardSymbol;
                else
                    cout << map[i][j];
            }
            cout << endl;
        }

        // Get input
        cout << "Move (WASD): ";
        cin >> input;
        input = tolower(input);

        int newX = playerX;
        int newY = playerY;
//WASD MOVEMENT
if (input != 'w' && input != 'a' && input != 's' && input != 'd')
{
    cout << "Invalid input. Use W, A, S, or D\n";
    continue;
}
        if (input == 'w') newX--;
        if (input == 's') newX++;
        if (input == 'a') newY--;
        if (input == 'd') newY++;

        // Win condition
        if (map[newX][newY] == '$')
        {
            cout << "YOU WIN LEVEL 1!" << endl;
            return;
        }

        // Lose condition (walk into guard)
        if (newX == guardX && newY == guardY)
        {
            cout << "YOU WERE CAUGHT!" << endl;
            return;
        }

        // Move player & oops you ran into wall message.
        if (map[newX][newY] != '#')
        {
            playerX = newX;
            playerY = newY;
        }
        else
        {
            cout << "Oops! You crashed into a wall. Use W, A, S, or D to move around obstacles.\n";
            continue;
        }

        // Guard movement
        if (guardY + guardDirection < 0 ||
            guardY + guardDirection >= 8 ||
            map[guardX][guardY + guardDirection] == '#')
        {
            guardDirection = -guardDirection;
        }

        guardY += guardDirection;

        // Update guard symbol
        if (guardDirection == 1)
            guardSymbol = '>';
        else
            guardSymbol = '<';

        // Guard vision
        if (playerX == guardX)
        {
            // LEFT
            for (int y = guardY - 1; y >= 0; y--)
            {
                if (map[guardX][y] == '#') break;

                if (y == playerY)
                {
                    cout << "YOU WERE CAUGHT!" << endl;
                    return;
                }
            }

            // RIGHT
            for (int y = guardY + 1; y < 8; y++)
            {
                if (map[guardX][y] == '#') break;

                if (y == playerY)
                {
                    cout << "YOU WERE CAUGHT!" << endl;
                    return;
                }
            } // end of the (player X == guardX)
        } // end for the load level 1 void
    }// while loop ends here
}// function ends here
//FIXED GUARD!

// LEVEL 2: The Truth of the Weapon, DIFFERENT MAP!
void loadLevel2() 
{
    //map loaded
    cout << "Level 2 loaded" << endl;
    cout << "Reach the $ without being seen by the guard." << endl;
    cout << "----------------------------------------------" << endl;

    string map[5] =
    {
        "########",
        "#   #  #",
        "#   #  #",
        "#     $#",
        "########"
    };

    int playerX = 1;
    int playerY = 1;

    int guardX = 1;
    int guardY = 6;

    int guardDirection = -1;
    char guardSymbol = '<';

    char input;

    while (true)
    {
        //prints map and the user's symbol
        for (int i = 0; i < 5; i++)
        {
            for (int j = 0; j < 8; j++)
            {
                if (i == playerX && j == playerY)
                    cout << '@';
                else if (i == guardX && j == guardY)
                    cout << guardSymbol;
                else
                    cout << map[i][j];
            }
            cout << endl;
        }

        // User input
        cout << "Move (WASD): ";
        cin >> input;
        input = tolower(input);

        int newX = playerX;
        int newY = playerY;
        //MOVEMENT
    if (input != 'w' && input != 'a' && input != 's' && input != 'd')
    {
    cout << "Invalid input. Use W, A, S, or D\n";
    continue;
    }
        if (input == 'w') newX--;
        if (input == 's') newX++;
        if (input == 'a') newY--;
        if (input == 'd') newY++;
        
        //win condition
        if (map[newX][newY] == '$')
        {
            cout << "YOU WIN LEVEL 2!" << endl;
            return;
        }
        //lose condition (walking into guard)
        if (newX == guardX && newY == guardY)
        {
            cout << "YOU WERE CAUGHT!" << endl;
            return;
        }

        //Move player & oops you ran into wall message.
        if (map[newX][newY] != '#')
        {
            playerX = newX;
            playerY = newY;
        }
        else
        {
            cout << "Oops! You crashed into a wall. Use W, A, S, or D to move around obstacles.\n";
            continue;
        }
        //guard movement
        if (guardY + guardDirection < 0 ||
            guardY + guardDirection >= 8 ||
            map[guardX][guardY + guardDirection] == '#')
        {
            guardDirection = -guardDirection;
        }

        guardY += guardDirection;
        //update guard symbol
        if (guardDirection == 1)
            guardSymbol = '>';
        else
            guardSymbol = '<';
        if (playerX == guardX)
        {
            // LEFT
            for (int y = guardY - 1; y >= 0; y--)
            {
                if (map[guardX][y] == '#') break;

                if (y == playerY)
                {
                    cout << "YOU WERE CAUGHT!" << endl;
                    return;
                }
            }

            // RIGHT
            for (int y = guardY + 1; y < 8; y++)
            {
                if (map[guardX][y] == '#') break;

                if (y == playerY)
                {
                    cout << "YOU WERE CAUGHT!" << endl;
                    return;
                }
            } // end of the (player X == guardX)
        } // end for the load level 1 void
    }// while loop ends here
}// function ends here

// LEVEL 3: Revenge of the General, DIFFERENT MAP!
void loadLevel3() 
{
    cout << "Level 3 loaded" << endl;
    cout << "Reach the $ without being seen by the guard." << endl;
    cout << "----------------------------------------------" << endl;
    //different map loaded
    string map[5] =
{
    "########",
    "#     ##",
    "# ##   #",
    "#    #$#",
    "########"
    }; // map string ends here
    //variables for guard and player
    int playerX = 1;
    int playerY = 1;

    int guardX = 3;
    int guardY = 1;
    int guardDirection = -1;

    char guardSymbol = '<';
    char input;

    while (true)
    {
        // Print map
        for (int i = 0; i < 5; i++)
        {
            for (int j = 0; j < 8; j++)
            {
                if (i == playerX && j == playerY)
                    cout << '@';
                else if (i == guardX && j == guardY)
                    cout << guardSymbol;
                else
                    cout << map[i][j];
            }
            cout << endl;
        }
        // user input and directions
        cout << "Move (WASD): ";
        cin >> input;
        input = tolower(input);
        //x y coords
        int newX = playerX;
        int newY = playerY;
       //MOVEMENT, new
    if (input != 'w' && input != 'a' && input != 's' && input != 'd')
    {
    cout << "Invalid input. Use W, A, S, or D\n";
    continue;
    }
        if (input == 'w') newX--;
        if (input == 's') newX++;
        if (input == 'a') newY--;
        if (input == 'd') newY++;

        //win condition
        if (map[newX][newY] == '$')
        {
            cout << "YOU WIN LEVEL 3!" << endl;
            return;
        }
        // Lose condition (walking into guard)
        if (newX == guardX && newY == guardY)
        {
            cout << "YOU WERE CAUGHT!" << endl;
            return;
        }
         // Move player & oops you ran into wall message.
        if (map[newX][newY] != '#')
        {
            playerX = newX;
            playerY = newY;
        }
        else
        {
            cout << "Oops! You crashed into a wall. Use W, A, S, or D to move around obstacles.\n";
            continue;

        }
        //guard movement
        if (guardY + guardDirection < 0 ||
            guardY + guardDirection >= 8 ||
            map[guardX][guardY + guardDirection] == '#')
        {
            guardDirection = -guardDirection;
        }
        guardY += guardDirection;
        //update's guard symbol when it moves left and right
        if (guardDirection == 1)
            guardSymbol = '>';
        else
            guardSymbol = '<';
        if (playerX == guardX)
        {
            // LEFT
            for (int y = guardY - 1; y >= 0; y--)
            {
                if (map[guardX][y] == '#') break;

                if (y == playerY)
                {
                    cout << "YOU WERE CAUGHT!" << endl;
                    return;
                }
            }

            // RIGHT
            for (int y = guardY + 1; y < 8; y++)
            {
                if (map[guardX][y] == '#') break;

                if (y == playerY)
                {
                    cout << "YOU WERE CAUGHT!" << endl;
                    return;
                }
            } // end of the (player X == guardX)
        } // end for the load level 1 void
    }// while loop ends here
}// function ends here

//Main menu with user input & loading the levels, play again added!
int main()
{
 // user input
 // play again button (NEW ADDITION/PEER)
string choice;
char playAgain = 'y';
//main menu
while (playAgain == 'y' || playAgain == 'Y')
{
    cout << "Welcome to Ultra-Spy" << endl;
    cout << "Select a level: " << endl; 
    cout << "1) A New Enemy" << endl;
    cout << "2) The Truth of the Weapon" << endl;
    cout << "3) Revenge of the General" << endl;  


getline(cin, choice);
 for (int i = 0; i < choice.length(); i++)
 {
    choice[i] = tolower(choice[i]);
 }
 


//case insensitive, if statements for user's input
if (choice == "1" || choice == "A New Enemy" || choice == "a new enemy")
{
    loadLevel1(); // function level 1
}
else if (choice == "2" || choice == "The Truth of the Weapon" || choice == "the truth of the weapon")
{
    loadLevel2(); // function level 2
} 
else if (choice == "3" || choice == "revenge of the general" || choice == "Revenge of the General")
{
    loadLevel3(); //function level 3
}
else 
{
    cout << "Invalid choice." << endl;
}
 cout << "Would you like to play again? (y/n): ";
 cin >> playAgain;
 cin.ignore(); //getline for next loop   

}
cout << "Thanks for playing!" << endl;
return 0;
}  