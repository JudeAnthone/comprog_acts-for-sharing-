#include <iostream>
#include <ctime>
#include <limits>
using namespace std;

char getUserChoice();
char getComputerChoice(int difficulty, char player);
void showChoice(char choice);
void chooseWinner(char player, char computer, int &User_Score, int &Computer_Score);

// ASCII ART
void ascii();

int main()
{
    char player;
    char computer;
    char Play_Again;
    int difficulty;
    int User_Score = 0;
    int Computer_Score = 0;

    do
    {
        ascii();
        cout << '\n';

        cout << "Rock-Paper-Scissors Game\n";
        cout << '\n';
        cout << "Choose difficulty level:\n";
        cout << '\n';
        cout << "       1) Easy\n";
        cout << "       2) Medium\n";
        cout << "       3) Hard\n";
        cout << '\n';
        cout << "Enter your choice: ";
        cout << '\n';

        // Error handling for char input and 4+ values ng user
        while (!(cin >> difficulty) || difficulty < 1 || difficulty > 3)
        {
            cout << "ERROR: Invalid input. Please enter a valid difficulty level (1, 2, or 3).\n";
            cout << '\n';
            cout << "Enter your choice: ";
            cout << '\n';

            // Clear the input buffer
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        do
        {

            player = getUserChoice();
            cout << "Your Choice: ";
            cout << '\n';
            showChoice(player);

            computer = getComputerChoice(difficulty, player);
            cout << '\n';
            cout << "Computers Choice: ";
            cout << '\n';
            showChoice(computer);

            chooseWinner(player, computer, User_Score, Computer_Score);
            cout << '\n';
            cout << "Score - You: " << User_Score << " | Computer: " << Computer_Score << endl;

            cout << '\n';
            cout << "Do you want to play again or change the diffuculty? (Y/N): ";
            cout << '\n';
            cin >> Play_Again;

            while (Play_Again != 'Y' && Play_Again != 'y' && Play_Again != 'N' && Play_Again != 'n')
            {
                cout << '\n';
                cout << "ERROR: Invalid Input. Please Enter Y or N: ";
                cout << '\n';
                cin.clear();
                cin >> Play_Again;
            }

        } while (Play_Again == 'Y' || Play_Again == 'y');
        cout << '\n';
        cout << "Do you want to change the difficulty level? (Y/N): ";
        cout << '\n';
        cin >> Play_Again;

    } while (Play_Again == 'Y' || Play_Again == 'y');
    cout << '\n';
    cout << "THANK YOU FOR PLAYING!!";
    cout << '\n';
    return 0;
}

char getUserChoice()
{

    char player;
    cout << '\n';
    cout << "Rock-Paper-Scissors Game\n";

    do
    {
        cout << "    Pick your choice\n";
        cout << "-------------------------\n";
        cout << "    R) Rock\n";
        cout << "    P) Paper\n";
        cout << "    S) Scissors\n";
        cout << '\n';
        cout << "Enter your choice: ";
        cin >> player;
        player = tolower(player);

        // error handling ng user choice
        if (player != 'r' && player != 'p' && player != 's')
        {
            cout << '\n';
            cout << "ERROR: Invalid Input. Please enter R, P, and S only. '\n ";
            cout << '\n';
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

    } while (player != 'r' && player != 'p' && player != 's');

    return player;
}

char getComputerChoice(int difficulty, char player)
{

    srand(time(0));
    int num;

    switch (difficulty)
    {

    case 1: // easy
    {
        int num_easy = rand() % 10 + 1;
        if (num_easy <= 8) // 80% of winning - user
        {
            num = 1;
        }
        else // 20% of winning -  computer
        {
            num = rand() % 2 + 2;
        }
    }
    break;

    case 2: // medium
    {
        int num_medium = rand() % 10 + 1;
        if (num_medium <= 5) // 50% of winning - user
        {
            num = 1;
        }
        else // 50% of winning - computer
        {
            num = rand() % 2 + 2;
        }
    }
    break;

    case 3: // hard
    {
        int num_hard = rand() % 10 + 1;
        if (num_hard <= 6) // 60% of winning - computer
        {
            num = 1;
        }
        else // 40% of winning - user
        {
            num = rand() % 2 + 2;
        }
    }

    break;
    default:
        int num_default = rand() % 3 + 1;
        num = num_default;
    }

    switch (num)
    {
    case 1:
        return 'r';
    case 2:
        return 'p';
    case 3:
        return 's';
    }

    return 0;
}

void showChoice(char choice)
{

    switch (choice)
    {
    case 'r':
        cout << '\n';
        cout << "   _______\n";
        cout << "  (       )\n";
        cout << " (   Rock  )\n";
        cout << "  (_______)\n";
        cout << '\n';
        break;
    case 'p':
        cout << "   _______\n";
        cout << "  (       )\n";
        cout << " (  Paper  )\n";
        cout << "  (_______)\n";
        cout << '\n';
        break;
    case 's':
        cout << "   _______\n";
        cout << "  (       )\n";
        cout << " (Scissors)\n";
        cout << "  (_______)\n";
        cout << '\n';
        break;
    }
}

void chooseWinner(char player, char computer, int &User_Score, int &Computer_Score)
{
    switch (player)
    {
    case 'r':
        if (computer == 'r')
        {
            cout << "Tie\n";
            cout << '\n';
        }
        else if (computer == 'p')
        {
            cout << "HHHH YOU LOOSE\n";
            cout << '\n';
            Computer_Score++;
        }
        else
        {
            cout << '\n';
            cout << "YOU WIN!\n";
            cout << '\n';
            User_Score++;
        }
        break;
    case 'p':
        if (computer == 'r')
        {
            cout << '\n';
            cout << "YOU WIN\n";
            cout << '\n';
            User_Score++;
        }
        else if (computer == 'p')
        {
            cout << "Tie\n";
            cout << '\n';
        }
        else
        {
            cout << '\n';
            cout << "HHHH YOU LOOSE\n";
            cout << '\n';
            Computer_Score++;
        }
        break;
    case 's':
        if (computer == 'r')
        {
            cout << '\n';
            cout << "HHHH YOU LOOSE\n";
            cout << '\n';
            Computer_Score++;
        }
        else if (computer == 'p')
        {
            cout << '\n';
            cout << "YOU WIN\n";
            cout << '\n';
            User_Score++;
        }
        else
        {
            cout << '\n';
            cout << "Tie\n";
            cout << '\n';
        }
        break;
    }
}

void ascii()
{
    cout << " ____  ____   ___  ____            __   __  \n";
    cout << "(  _ \\/ ___) / __)/ ___)   ___    /  \\ / _\\ \n";
    cout << " ) _ (\\___ \\( (__ \\___ \\  (___)  (_/ //    \\\n";
    cout << "(____/(____/ \\___)(____/          (__)_/\\_/\n";
}
