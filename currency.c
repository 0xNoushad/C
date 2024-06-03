#include <stdio.h>
#include <stdlib.h>

typedef struct Transaction {
  char type; // 'i' mtlb income, 'e'  mtlb expense
  char category[20];
  float amount;
} Transaction;

int main() {
  int num_transactions;
  float total_income, total_expense;

  printf("Enter number of transactions: ");
  scanf("%d", &num_transactions);

  Transaction transactions[num_transactions];

  for (int i = 0; i < num_transactions; i++) {
    printf("Transaction %d type (i/e): ", i + 1);
    scanf("%c", &transactions[i].type);

    printf("Transaction %d category: ", i + 1);
    scanf("%s", transactions[i].category);

    printf("Transaction %d amount: ", i + 1);
    scanf("%f", &transactions[i].amount);
  }

  for (int i = 0; i < num_transactions; i++) {
    if (transactions[i].type == 'i') {
      total_income += transactions[i].amount;
    } else {
      total_expense += transactions[i].amount;
    }
  }

  printf("Total Income: %.2f\n", total_income);
  printf("Total Expense: %.2f\n", total_expense);
  printf("Balance: %.2f\n", total_income - total_expense);

  return 0;
}