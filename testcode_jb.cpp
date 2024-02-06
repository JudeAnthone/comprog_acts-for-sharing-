#include <iostream>
#include <ctime>
using namespace std;

char getUserChoice();
char getComputerChoice(int difficulty, char player);
void showChoice(char choice);
void chooseWinner(char player, char computer, int &userScore, int &computerScore);
void clear()
{
  cout << "\nPress Enter to Continue...";
  cin.ignore();
  cin.get();

  system("clear");
}

int main()
{
  char player;
  char computer;
  char playAgain;
  int difficulty;
  int userScore = 0;
  int computerScore = 0;
  char choice;

  do
  {
    cout << "============================\n";
    cout << "Choose difficulty level:\n";
    cout << "1) Easy\n";
    cout << "2) Medium\n";
    cout << "3) Hard\n";
    cout << "============================\n";

    do
    {
      cout << "Enter your choice: ";
      cin >> difficulty;

      if (difficulty < 1 || difficulty > 3)
      {
        cout << "Invalid choice. Please enter 1, 2, or 3.\n";
      }

    } while (difficulty < 1 || difficulty > 3);

    cout << "You chose difficulty level " << difficulty << ".\n";
    clear();
    do
    {

      player = getUserChoice();
      cout << "\nYour choice: ";

      showChoice(player);

      computer = getComputerChoice(difficulty, player);
      cout << "Computer's choice: ";
      showChoice(computer);

      chooseWinner(player, computer, userScore, computerScore);

      cout << "\nScore - You: " << userScore << " | Computer: " << computerScore << endl;

      cout << "\nDo you want to play again? (y/n): ";
      cin >> playAgain;

    } while (playAgain == 'y' || playAgain == 'Y');

    cout << "\nDo you want to change the difficulty level? (y/n): ";
    cin >> playAgain;

  } while (playAgain == 'y' || playAgain == 'Y');

  cout << "Thanks for playing!\n";
  clear();
  return 0;
}

char getUserChoice()
{
  char player;
  cout << "\nRock-Paper-Scissors Game\n";

  do
  {
    cout << "\nPick your choice\n";
    cout << "-------------------------\n";
    cout << "r) Rock\n";
    cout << "p) Paper\n";
    cout << "s) Scissors\n";
    cout << "-------------------------\n";
    cout << "Enter your choice: ";
    cin >> player;
  } while (player != 'r' && player != 'p' && player != 's');
  return player;
}

char getComputerChoice(int difficulty, char player)
{
  srand(time(0));
  int num;

  switch (difficulty)
  {
  case 1: // Easy
    num = rand() % 2 + 1;
    break;
  case 2: // Medium
    num = rand() % 3 + 1;
    break;
  case 3: // Hard
    if (player == 'r')
    {
      num = 2; // Choose Paper
    }
    else if (player == 'p')
    {
      num = 3; // Choose Scissors
    }
    else
    {
      num = 1; // Choose Rock
    }
    break;
  default:
    num = rand() % 3 + 1;
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
    cout << "Rock✊\n";
    break;
  case 'p':
    cout << "Paper✋\n";
    break;
  case 's':
    cout << "Scissors✌️\n";
    break;
  }
}

void chooseWinner(char player, char computer, int &userScore, int &computerScore)
{
  switch (player)
  {
  case 'r':
    if (computer == 'r')
    {
      cout << "Tie\n";
    }
    else if (computer == 'p')
    {
      cout << "You lose\n";
      computerScore++;
    }
    else
    {
      cout << "You win\n";
      userScore++;
    }
    break;
  case 'p':
    if (computer == 'r')
    {
      cout << "You Win\n";
      userScore++;
    }
    else if (computer == 'p')
    {
      cout << "Tie\n";
    }
    else
    {
      cout << "You lose\n";
      computerScore++;
    }
    break;
  case 's':
    if (computer == 'r')
    {
      cout << "You lose\n";
      computerScore++;
    }
    else if (computer == 'p')
    {
      cout << "You win\n";
      userScore++;
    }
    else
    {
      cout << "Tie\n";
    }
    break;
  }
}