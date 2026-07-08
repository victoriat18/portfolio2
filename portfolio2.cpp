//Portfolio, Spy Game
#include <iostream>
#include <string>
#include <cctype>
using namespace std;

// LEVEL 1 : A New Enemy, Basic Beginner level!
void loadLevel1() 
{
    //map loaded, User instructions
    cout << "Level 1 loaded" << endl;
    cout << "Directions:" << endl;
    cout << "Reach the $ without being seen by the guard." << endl;
    cout << "Type 'inspect' to check what is on a tile." << endl;
    cout << "Inspecting does not use your turn!" << endl;
    cout << "----------------------------------------------" << endl;
    
    // 'D' = closed door, 'S' = switched

    string map[5] =
    {
        "########",
        "#      #",
        "#   D  #",
        "#  S  $#",
        "########"
    };
    //variables for guards and players
    int playerX = 1;
    int playerY = 1;

    int guardX = 2;
    int guardY = 6;
// ~PORTFOLIO 2 ADDITION
int guardDX = 0;
int guardDY = -1;

char guardSymbol = '<';

string input;

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

//~INSPECT FEATURE
if (input == "inspect")
{
    int inspectRow;
    int inspectCol;

    cout << "Enter row: ";
    cin >> inspectRow;

    cout << "Enter column: ";
    cin >> inspectCol;


    //Check if coordinates are valid
    if (inspectRow < 0 || inspectRow >= 5 ||
        inspectCol < 0 || inspectCol >= 8)
    {
        cout << "Invalid location.\n";
        continue;
    }


    //Inspect tile
    if (inspectRow == guardX && inspectCol == guardY)
    {
        cout << "This is a guard facing " << guardSymbol << endl;
    }
    else if (map[inspectRow][inspectCol] == '#')
    {
        cout << "This is a wall." << endl;
    }
    else if (map[inspectRow][inspectCol] == '$')
    {
        cout << "This is the goal." << endl;
    }
    else
    {
        cout << "This tile is empty." << endl;
    }

    continue; // does NOT use player's turn
}


    int newX = playerX;
    int newY = playerY;

    // WASD MOVEMENT ~ FEATURE UPDATED
    if (input != "w" && input != "a" && input != "s" && input != "d")
    {
        cout << "Invalid input. Use W, A, S, or D\n";
        continue;
    }

    if (input == "w") newX--;
    if (input == "s") newX++;
    if (input == "a") newY--;
    if (input == "d") newY++;

    // Win condition
    if (map[newX][newY] == '$')
    {
        cout << "YOU WIN LEVEL 1!" << endl;
        return;
    }

    // Lose condition (player walks into guard)
    if (newX == guardX && newY == guardY)
    {
        cout << "YOU WERE CAUGHT!" << endl;
        return;
    }

    // Move player
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

    // Calculate the guard's next position
    int nextX = guardX + guardDX;
    int nextY = guardY + guardDY;

    // If guard hits a wall, turn clockwise
    if (map[nextX][nextY] == '#')
    {
        // Left -> Up
        if (guardDX == 0 && guardDY == -1)
        {
            guardDX = -1;
            guardDY = 0;
            guardSymbol = '^';
        }
        // Up -> Right
        else if (guardDX == -1 && guardDY == 0)
        {
            guardDX = 0;
            guardDY = 1;
            guardSymbol = '>';
        }
        // Right -> Down
        else if (guardDX == 0 && guardDY == 1)
        {
            guardDX = 1;
            guardDY = 0;
            guardSymbol = 'V';
        }
        // Down -> Left
        else
        {
            guardDX = 0;
            guardDY = -1;
            guardSymbol = '<';
        }
    }

    // Move guard
    guardX += guardDX;
    guardY += guardDY;

    // Bug fix: if guard walks onto player
    if (playerX == guardX && playerY == guardY)
    {
        cout << "YOU WERE CAUGHT!" << endl;
        return;
    }

    // Guard vision (temporary)
    if (playerX == guardX)
    {
        // Look left
        for (int y = guardY - 1; y >= 0; y--)
        {
            if (map[guardX][y] == '#')
                break;

            if (y == playerY)
            {
                cout << "YOU WERE CAUGHT!" << endl;
                return;
            }
        }

        // Look right
        for (int y = guardY + 1; y < 8; y++)
        {
            if (map[guardX][y] == '#')
                break;

            if (y == playerY)
            {
                cout << "YOU WERE CAUGHT!" << endl;
                return;
                }
            }
        }
    }
}

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

        //user input
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

//lose condition (player walks into guard)
if (newX == guardX && newY == guardY)
{
    cout << "YOU WERE CAUGHT!" << endl;
    return;
}

//move player
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

//move guard
guardY += guardDirection;

//Update guard symbol
if (guardDirection == 1)
    guardSymbol = '>';
else
    guardSymbol = '<';

// If the guard moved onto the player, the player loses
if (playerX == guardX && playerY == guardY)
{
    cout << "YOU WERE CAUGHT!" << endl;
    return;
}

// Guard vision
if (playerX == guardX)
{
    //left
    for (int y = guardY - 1; y >= 0; y--)
    {
        if (map[guardX][y] == '#')
            break;

        if (y == playerY)
        {
            cout << "YOU WERE CAUGHT!" << endl;
            return;
        }
    }

    // right
    for (int y = guardY + 1; y < 8; y++)
    {
        if (map[guardX][y] == '#')
            break;

        if (y == playerY)
        {
            cout << "YOU WERE CAUGHT!" << endl;
            return;
                }
            }
        }
    }
}

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
        //Print map
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

       //Win condition
if (map[newX][newY] == '$')
{
    cout << "YOU WIN LEVEL 2!" << endl;
    return;
}

//Lose condition, player walks into guard
if (newX == guardX && newY == guardY)
{
    cout << "YOU WERE CAUGHT!" << endl;
    return;
}

//Move player
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

//Guard movement
if (guardY + guardDirection < 0 ||
    guardY + guardDirection >= 8 ||
    map[guardX][guardY + guardDirection] == '#')
{
    guardDirection = -guardDirection;
}

//Move guard
guardY += guardDirection;

//Update guard symbol
if (guardDirection == 1)
    guardSymbol = '>';
else
    guardSymbol = '<';

// If the guard moved onto the player, the player loses!
if (playerX == guardX && playerY == guardY)
{
    cout << "YOU WERE CAUGHT!" << endl;
    return;
}

// Guard vision
if (playerX == guardX)
{
    //LEFT MOVEMENT
    for (int y = guardY - 1; y >= 0; y--)
    {
        if (map[guardX][y] == '#')
            break;

        if (y == playerY)
        {
            cout << "YOU WERE CAUGHT!" << endl;
            return;
        }
    }

    //RIGHT movement for guard
    for (int y = guardY + 1; y < 8; y++)
    {
        if (map[guardX][y] == '#')
            break;

        if (y == playerY)
        {
            cout << "YOU WERE CAUGHT!" << endl;
            return;
                }
            }
        }
    }
}

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