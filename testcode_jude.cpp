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
    cout << "1) Easy\n";
    cout << "2) Medium\n";
    cout << "3) Hard\n";
    cout << "Enter your choice: ";

    // Error handling for char input and 4+ values ng user
    while (!(cin >> difficulty) || difficulty < 1 || difficulty > 3)
    {
      cout << "ERROR: Invalid input. Please enter a valid difficulty level (1, 2, or 3).\n";
      cout << "Enter your choice: ";

      // Clear the input buffer
      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    do
    {
      player = getUserChoice();
      cout << "Your Choice; ";
      showChoice(player);

      computer = getComputerChoice(difficulty, player);
      cout << "Computers Choice: ";
      showChoice(computer);

      chooseWinner(player, computer, User_Score, Computer_Score);

      cout << "Score - You: " << User_Score << " | Computer: " << Computer_Score << endl;

      cout << "Do you want to play again? (y/n): ";
      cin >> Play_Again;

    } while (Play_Again == 'y' || Play_Again == 'Y');
    cout << "Do you want to change the difficulty level? (Y/N): ";
    cin >> Play_Again;

  } while (Play_Again == 'y' || Play_Again == 'Y');

  cout << "Thanks for Playing!!";
  return 0;
}

char getUserChoice()
{

  char player;
  std::cout << "Rock-Paper-Scissors Game\n";

  do
  {
    std::cout << "Pick your choice\n";
    std::cout << "-------------------------\n";
    std::cout << "r) Rock\n";
    std::cout << "p) Paper\n";
    std::cout << "s) Scissors\n";
    std::cout << "Enter your choice: ";
    std::cin >> player;

    // error handling ng user choice
    if (player != 'r' && player != 'p' && player != 's')
    {

      cout << "ERROR: Invalid Input. Please enter r, p, and s only. '\n ";
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
    num = rand() % 2 + 1;
    break;

  case 2: // medium
    num = rand() % 3 + 1;
    break;

  case 3: // hard
    if (player == 'r')
    {
      num = 2;
    }
    else if (player == 'p')
    {
      num = 3;
    }
    else
    {
      num = 1;
    }
    break;
  default:
    int num = rand() % 3 + 1;
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
    std::cout << "Rock\n";
    break;
  case 'p':
    std::cout << "Paper\n";
    break;
  case 's':
    std::cout << "Scissors\n";
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
      std::cout << "Tie\n";
    }
    else if (computer == 'p')
    {
      std::cout << "You lose\n";
      Computer_Score++;
    }
    else
    {
      std::cout << "You win\n";
      User_Score++;
    }
    break;
  case 'p':
    if (computer == 'r')
    {
      std::cout << "You Win\n";
      User_Score++;
    }
    else if (computer == 'p')
    {
      std::cout << "Tie\n";
    }
    else
    {
      std::cout << "You lose\n";
      Computer_Score++;
    }
    break;
  case 's':
    if (computer == 'r')
    {
      std::cout << "You lose\n";
      Computer_Score++;
    }
    else if (computer == 'p')
    {
      std::cout << "You win\n";
      User_Score++;
    }
    else
    {
      std::cout << "Tie\n";
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