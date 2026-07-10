//Portfolio, Spy Game
#include <iostream>
#include <string>
#include <cctype>
using namespace std;

// LEVEL 1 : A New Enemy, Basic Beginner level!
void loadLevel1() 
{
    //HOW TO...
    cout << "   Level 1 loaded     " << endl;
    cout << "----- Directions -----" << endl;
    cout << "Reach the $ without being seen by the guard." << endl;
    cout << "Type 'inspect' to check what is on a tile." << endl;
    cout << "Inspecting does not use your turn." << endl;
    cout << "Walk onto switches (S) to open doors (D)." << endl;
    cout << "----------------------------------------------" << endl;


    string map[5] =
    {
    "########",
    "#      #",
    "#  #   #",
    "#  S D$#",
    "########"
    };
    int playerX = 1;
    int playerY = 1;
    // Guard starts here
    int guardX = 2;
    int guardY = 6;
    // Guard moving left
    int guardDX = 0;
    int guardDY = -1;

    char guardSymbol = '<';
//~ DOOR FEATURE
    bool doorOpen = false;

    string input;
    while (true)
    {
// PRINT MAP
for (int i = 0; i < 5; i++)
    {
    for (int j = 0; j < 8; j++)
    {
        if (i == playerX && j == playerY)
        {
            cout << '@';
        }
        else if (i == guardX && j == guardY)
        {
            cout << guardSymbol;
        }
        else if (map[i][j] == 'D' && doorOpen)
        {
            cout << ' ';
        }
        else
        {
            cout << map[i][j];
        }
    }
    cout << endl;
}

        cout << "Move (WASD) or type 'inspect': ";
        cin >> input;

        // INSPECT FEATURE
        if (input == "inspect")
        {
            int row;
            int col;


            cout << "Enter row: ";
            cin >> row;

            cout << "Enter column: ";
            cin >> col;


            if(row < 0 || row >= 5 || col < 0 || col >= 8)
            {
                cout << "Invalid location.\n";
                continue;
            }


            if(row == guardX && col == guardY)
{
    cout << "Guard facing " << guardSymbol << endl;
}
else if(map[row][col] == '#')
{
    cout << "Wall." << endl;
}
else if(map[row][col] == 'D')
{
    cout << "Closed door." << endl;
}
else if(map[row][col] == 'S')
{
    cout << "Switch." << endl;
}
else if(map[row][col] == '$')
{
    cout << "Goal." << endl;
}
else
{
    cout << "Empty tile." << endl;
}
    continue;
        }
        int newX = playerX;
        int newY = playerY;

        if(input != "w" && input != "a" &&
           input != "s" && input != "d")
        {
            cout << "Invalid input.\n";
            continue;
        }

        if(input == "w") newX--;
        if(input == "s") newX++;
        if(input == "a") newY--;
        if(input == "d") newY++;

        //PLAYER WALKS INTO GUARD
        if(newX == guardX && newY == guardY)
        {
            cout << "YOU WERE CAUGHT!" << endl;
            return;
        }

        //WIN
        if(map[newX][newY] == '$')
        {
            cout << "YOU WIN LEVEL 1!" << endl;
            return;
        }
   //MOVE PLAYER
if (map[newX][newY] != '#' &&
    (map[newX][newY] != 'D' || doorOpen))
{
    playerX = newX;
    playerY = newY;

    //Switch
    if (map[playerX][playerY] == 'S')
    {
        if (!doorOpen)
        {
            doorOpen = true;
            cout << "Door opened!" << endl;
        }
    }
}
else
{
    cout << "You hit a wall or a closed door." << endl;
    continue;
}

        //GUARD PATROL

        int nextX = guardX + guardDX;
        int nextY = guardY + guardDY;


        // Hit wall = turn clockwise
        if(map[nextX][nextY] == '#' || (map[nextX][nextY] == 'D' && !doorOpen))
        {

            // Left -> Up
            if(guardDX == 0 && guardDY == -1)
            {
                guardDX = -1;
                guardDY = 0;
                guardSymbol = '^';
            }

            // Up -> Right
            else if(guardDX == -1 && guardDY == 0)
            {
                guardDX = 0;
                guardDY = 1;
                guardSymbol = '>';
            }

            // Right -> Down
            else if(guardDX == 0 && guardDY == 1)
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

        guardX += guardDX;
        guardY += guardDY;

        // GUARD WALKS INTO PLAYER
        if(playerX == guardX && playerY == guardY)
        {
            cout << "YOU WERE CAUGHT!" << endl;
            return;
        }

        // Guard vision
if (guardSymbol == '<')
{
    // Look left
    for (int y = guardY - 1; y >= 0; y--)
    {
        if (map[guardX][y] == '#' || (map[guardX][y] == 'D' && !doorOpen))
            break;

        if (guardX == playerX && y == playerY)
        {
            cout << "YOU WERE CAUGHT!" << endl;
            return;
        }
    }
}
else if (guardSymbol == '>')
{
    // Look right
    for (int y = guardY + 1; y < 8; y++)
    {
        if (map[guardX][y] == '#' || (map[guardX][y] == 'D' && !doorOpen))
        {

        break;     
        }
        
        if (guardX == playerX && y == playerY)
        {
            cout << "YOU WERE CAUGHT!" << endl;
            return;
        }
    }
}
else if (guardSymbol == '^')
{
    // Look up
    for (int x = guardX - 1; x >= 0; x--)
    {
        if (map[x][guardY] == '#' ||
    (map[x][guardY] == 'D' && !doorOpen))
{
    break;
}
        if (x == playerX && guardY == playerY)
        {
            cout << "YOU WERE CAUGHT!" << endl;
            return;
        }
    }
}
else if (guardSymbol == 'V')    
    {
    // Look down
    for (int x = guardX + 1; x < 5; x++)
    {
        if (map[x][guardY] == '#' ||
    (map[x][guardY] == 'D' && !doorOpen))
    {
    break;
    }
        if (x == playerX && guardY == playerY)
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
    cout << "   Level 2 loaded  " << endl;
    cout << "----- Directions -----" << endl;
    cout << "Reach the $ without being seen by the guard." << endl;
    cout << "Type 'inspect' to check what is on a tile." << endl;
    cout << "Inspecting does not use your turn." << endl;
    cout << "Walk onto switches (S) to open doors (D)." << endl;
    cout << "----------------------------------------------" << endl;

string map[5] =
{
    "########",
    "# D    #",
    "# ## # #",
    "# S  D$#",
    "########"
};
    int playerX = 1;
    int playerY = 1;
    // Guard starts here
    int guardX = 1;
    int guardY = 5;
    // Guard moving left
    int guardDX = 0;
    int guardDY = -1;
    char guardSymbol = '<';
//DOOR FEATURE
    bool doorOpen = false;

    string input;

    while (true)
    {
// PRINT MAP
for (int i = 0; i < 5; i++)
    {
    for (int j = 0; j < 8; j++)
    {
        if (i == playerX && j == playerY)
        {
            cout << '@';
        }
        else if (i == guardX && j == guardY)
        {
            cout << guardSymbol;
        }
        else if (map[i][j] == 'D' && doorOpen)
        {
            cout << ' ';
        }
        else
        {
            cout << map[i][j];
        }
    }
    cout << endl;
}

        cout << "Move (WASD) or type'inspect': ";
        cin >> input;

        //INSPECT FEATURE
        if (input == "inspect")
        {
            int row;
            int col;

            cout << "Enter row: ";
            cin >> row;

            cout << "Enter column: ";
            cin >> col;

            if(row < 0 || row >= 5 || col < 0 || col >= 8)
            {
                cout << "Invalid location.\n";
                continue;
            }


if(row == guardX && col == guardY)
{
    cout << "Guard facing " << guardSymbol << endl;
}
else if(map[row][col] == '#')
{
    cout << "Wall." << endl;
}
else if(map[row][col] == 'D')
{
    if (doorOpen)
    {
        cout << "Open door." << endl;
    }
    else
    {
        cout << "Closed door." << endl;
    }
}
else if(map[row][col] == 'S')
{
    cout << "Switch." << endl;
}
else if(map[row][col] == '$')
{
    cout << "Goal." << endl;
}
else
{
    cout << "Empty tile." << endl;
}
continue;
        }
        int newX = playerX;
        int newY = playerY;


        if(input != "w" && input != "a" &&
           input != "s" && input != "d")
        {
            cout << "Invalid input.\n";
            continue;
        }
        if(input == "w") newX--;
        if(input == "s") newX++;
        if(input == "a") newY--;
        if(input == "d") newY++;
        //PLAYER WALKS INTO GUARD
        if(newX == guardX && newY == guardY)
        {
            cout << "YOU WERE CAUGHT!" << endl;
            return;
        }
        //WIN
        if(map[newX][newY] == '$')
        {
            cout << "YOU WIN LEVEL 2!" << endl;
            return;
        }
        //MOVE PLAYER
      if (map[newX][newY] != '#' && (map[newX][newY] != 'D' || doorOpen))
        {
        playerX = newX;
        playerY = newY;

    if (map[playerX][playerY] == 'S')
{
    if (!doorOpen)
    {
        doorOpen = true;
        cout << "Door opened!" << endl;
        }
    }
}
else 
{
    cout << "You hit a wall or a closed door!" << endl;
    continue;
}
        // GUARD PATROL
        int nextX = guardX + guardDX;
        int nextY = guardY + guardDY;
        // Hit wall = turn clockwise
        if(map[nextX][nextY] == '#' || (map[nextX][nextY] == 'D' && !doorOpen))
        {
            // Left -> Up
            if(guardDX == 0 && guardDY == -1)
            {
                guardDX = -1;
                guardDY = 0;
                guardSymbol = '^';
            }
            // Up -> Right
            else if(guardDX == -1 && guardDY == 0)
            {
                guardDX = 0;
                guardDY = 1;
                guardSymbol = '>';
            }
            // Right -> Down
            else if(guardDX == 0 && guardDY == 1)
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
        guardX += guardDX;
        guardY += guardDY;
        //GUARD WALKS INTO PLAYER
        if(playerX == guardX && playerY == guardY)
        {
            cout << "YOU WERE CAUGHT!" << endl;
            return;
        }
        //Guard vision
if (guardSymbol == '<')
{
    //look left
    for (int y = guardY - 1; y >= 0; y--)
    {
        if (map[guardX][y] == '#' || (map[guardX][y] == 'D' && !doorOpen))
            break;
        if (guardX == playerX && y == playerY)
        {
            cout << "YOU WERE CAUGHT!" << endl;
            return;
        }
    }
}
else if (guardSymbol == '>')
{
    //look right
    for (int y = guardY + 1; y < 8; y++)
    {
        if (map[guardX][y] == '#' || (map[guardX][y] == 'D' && !doorOpen))
        {
        break;     
        }
        if (guardX == playerX && y == playerY)
        {
            cout << "YOU WERE CAUGHT!" << endl;
            return;
        }
    }
}
else if (guardSymbol == '^')
{
    //look up
    for (int x = guardX - 1; x >= 0; x--)
    {
        if (map[x][guardY] == '#' ||
    (map[x][guardY] == 'D' && !doorOpen))
{
    break;
}
        if (x == playerX && guardY == playerY)
        {
            cout << "YOU WERE CAUGHT!" << endl;
            return;
        }
    }
}
else if (guardSymbol == 'V')    
    {
    //look down
    for (int x = guardX + 1; x < 5; x++)
    {
        if (map[x][guardY] == '#' ||
    (map[x][guardY] == 'D' && !doorOpen))
    {
    break;
    }
        if (x == playerX && guardY == playerY)
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
    cout << "   Level 3 loaded  " << endl;
    cout << "----- Directions -----" << endl;
    cout << "Reach the $ without being seen by the guard." << endl;
    cout << "Type 'inspect' to check what is on a tile." << endl;
    cout << "Inspecting does not use your turn." << endl;
    cout << "Walk onto switches (S) to open doors (D)." << endl;
    cout << "----------------------------------------------" << endl;

    string map[5] =
    {
        "########",
        "#   D  #",
        "# ## # #",
        "#S   D$#",
        "########"
    };

    // Variables for guard and player
    int playerX = 1;
    int playerY = 1;
    
    // Guard starts here
    int guardX = 2;
    int guardY = 6;
    
    // Guard moving left initially
    int guardDX = 0;
    int guardDY = -1;
    char guardSymbol = '<';

    // DOOR FEATURE
    bool doorOpen = false;
    string input;

    while (true)
    {
        // PRINT MAP
        for (int i = 0; i < 5; i++)
        {
            for (int j = 0; j < 8; j++)
            {
                if (i == playerX && j == playerY)
                {
                    cout << '@';
                }
                else if (i == guardX && j == guardY)
                {
                    cout << guardSymbol;
                }
                else if (map[i][j] == 'D' && doorOpen)
                {
                    cout << ' ';
                }
                else
                {
                    cout << map[i][j];
                }
            }
            cout << endl;
        }

        cout << "Move (WASD) or type 'inspect': ";
        cin >> input;

        // INSPECT FEATURE
        if (input == "inspect")
        {
            int row;
            int col;

            cout << "Enter row: ";
            cin >> row;

            cout << "Enter column: ";
            cin >> col;

            if (row < 0 || row >= 5 || col < 0 || col >= 8)
            {
                cout << "Invalid location.\n";
                continue;
            }
            
            if (row == guardX && col == guardY)
            {
                cout << "Guard facing " << guardSymbol << endl;
            }
            else if (map[row][col] == '#')
            {
                cout << "Wall." << endl;
            }
            else if (map[row][col] == 'D')
            {
                if (doorOpen)
                {
                    cout << "Open door." << endl;
                }
                else
                {
                    cout << "Closed door." << endl;
                }
            }
            else if (map[row][col] == 'S')
            {
                cout << "Switch." << endl;
            }
            else if (map[row][col] == '$')
            {
                cout << "Goal." << endl;
            }
            else
            {
                cout << "Empty tile." << endl;
            }
            continue;
        }

        int newX = playerX;
        int newY = playerY;

        if (input != "w" && input != "a" && input != "s" && input != "d")
        {
            cout << "Invalid input.\n";
            continue;
        }

        if (input == "w") newX--;
        if (input == "s") newX++;
        if (input == "a") newY--;
        if (input == "d") newY++;

        // PLAYER WALKS INTO GUARD
        if (newX == guardX && newY == guardY)
        {
            cout << "YOU WERE CAUGHT!" << endl;
            return;
        }

        // WIN
        if (map[newX][newY] == '$')
        {
            cout << "YOU WIN LEVEL 3!" << endl;
            return;
        }

        // MOVE PLAYER
        if (map[newX][newY] != '#' && (map[newX][newY] != 'D' || doorOpen))
        {
            playerX = newX;
            playerY = newY;

            if (map[playerX][playerY] == 'S')
            {
                if (!doorOpen)
                {
                    doorOpen = true;
                    cout << "Door opened!" << endl;
                }
            }
        }
        else
        {
            cout << "You hit a wall or a closed door!" << endl;
            continue;
        }

        // GUARD PATROL
        int nextX = guardX + guardDX;
        int nextY = guardY + guardDY;

        // Check if next step would leave map bounds
        bool outOfBounds = (nextX < 0 || nextX >= 5 || nextY < 0 || nextY >= 8);

        // Hit wall, closed door, or out-of-bounds = turn clockwise
        if (outOfBounds || map[nextX][nextY] == '#' || (map[nextX][nextY] == 'D' && !doorOpen))
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
        else 
        {
            // Only step forward if the path was clear and the guard didn't turn
            guardX = nextX;
            guardY = nextY;
        }

        // GUARD WALKS INTO PLAYER
        if (playerX == guardX && playerY == guardY)
        {
            cout << "YOU WERE CAUGHT!" << endl;
            return;
        }
        // GUARD VISION
        if (guardSymbol == '<')
        {
            // Look left
            for (int y = guardY - 1; y >= 0; y--)
            {
                if (map[guardX][y] == '#' || (map[guardX][y] == 'D' && !doorOpen))
                    break;
                if (guardX == playerX && y == playerY)
                {
                    cout << "YOU WERE CAUGHT!" << endl;
                    return;
                }
            }
        }
        else if (guardSymbol == '>')
        {
            // Look right
            for (int y = guardY + 1; y < 8; y++)
            {
                if (map[guardX][y] == '#' || (map[guardX][y] == 'D' && !doorOpen))
                    break; 
                if (guardX == playerX && y == playerY)
                {
                    cout << "YOU WERE CAUGHT!" << endl;
                    return;
                }
            }
        }
        else if (guardSymbol == '^')
        {
            // Look up
            for (int x = guardX - 1; x >= 0; x--)
            {
                if (map[x][guardY] == '#' || (map[x][guardY] == 'D' && !doorOpen))
                    break;
                if (x == playerX && guardY == playerY)
                {
                    cout << "YOU WERE CAUGHT!" << endl;
                    return;
                }
            }
        }
        else if (guardSymbol == 'V')    
        {
            // Look down
            for (int x = guardX + 1; x < 5; x++)
            {
                if (map[x][guardY] == '#' || (map[x][guardY] == 'D' && !doorOpen))
                    break;
                if (x == playerX && guardY == playerY)
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