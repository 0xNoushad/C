#include <stdio.h>

int main() {
  float value, temperature;
  char unit, target_unit;

  printf("Enter value: ");
  scanf("%f", &value);

  printf("Current unit (C/F): ");
  scanf("%c", &unit);

  printf("Target unit (C/F): ");
  scanf("%c", &target_unit);
  if (unit == 'C' && target_unit == 'F') {
    temperature = value * 9/5 + 32;
  } else if (unit == 'F' && target_unit == 'C') {
    temperature = (value - 32) * 5/9;
  } else {
    printf("Invalid units!");
    return 1;
  }

  printf("%.2f %c is %.2f %c\n", value, unit, temperature, target_unit);

  return 0;