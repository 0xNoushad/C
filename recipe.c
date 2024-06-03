#include <stdio.h>

int main() {
  float servings, current, target;

  printf("Enter current recipe servings: ");
  scanf("%f", &current);

  printf("Enter desired number of servings: ");
  scanf("%f", &target);

  for (int i = 0; i < 5; i++) { // loop   5 ingredients ke liye
    float amount;
    char ingredient[20];

    printf("Enter ingredient %d name: ", i + 1);
    scanf("%s", ingredient);

    printf("Enter ingredient %d amount: ", i + 1);
    scanf("%f", &amount);

    printf("%.2f of %s for %d servings\n", amount * target / current, ingredient, target);
  }

  return 0;
}