
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to get user input (1-3 for Rock, Paper, Scissors)
int get_user_choice() {
  int choice;
  while (1) {
    printf("Enter your choice (1 - Rock, 2 - Paper, 3 - Scissors): ");
    scanf("%d", &choice);
    if (choice >= 1 && choice <= 3) {
      return choice;
    } else {
      printf("Invalid input! Please try again.\n");
    }
  }
}

// Function to get computer's random choice
int get_computer_choice() {
  srand(time(NULL)); // Seed random number generator
  return 1 + rand() % 3;  
}

// Function to determine winner
int get_winner(int user_choice, int computer_choice) {
  if (user_choice == computer_choice) {
    return 0; // Tie
  } else if (user_choice == 1 && computer_choice == 3 ||
             user_choice == 2 && computer_choice == 1 ||
             user_choice == 3 && computer_choice == 2) {
    return 1; // User wins
  } else {
    return 2; // Computer wins
  }
}

char *get_choice_name(int choice) {
  switch (choice) {
    case 1: return "Rock";
    case 2: return "Paper";
    case 3: return "Scissors";
    default: return "Invalid";  
  }
}

// Main game loop
int main() {
  int play_again = 1;
  while (play_again) {
    int user_choice = get_user_choice();
    int computer_choice = get_computer_choice();

    int winner = get_winner(user_choice, computer_choice);

    printf("You chose %s, Computer chose %s.\n", get_choice_name(user_choice), get_choice_name(computer_choice));

    if (winner == 0) {
      printf("It's a tie!\n");
    } else if (winner == 1) {
      printf("You win! \n");
    } else {
      printf("Computer wins! \n");
    }

    printf("Play again? (1 - Yes, 0 - No): ");
    scanf("%d", &play_again);
  }

  printf("Thanks for playing!\n");

  return 0;
}