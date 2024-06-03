#include <stdio.h>

float toCelsius(float fahrenheit) {
  return (5.0 / 9.0) * (fahrenheit - 32.0);
}

int main() {
  // Set a fahrenheit value
  float f_value = 98.8;
  
   
  float result = toCelsius(f_value);

  // Print the fahrenheit value
  printf("Fahrenheit: %.2f\n", f_value);
  
  printf("Convert Fahrenheit to Celsius: %.2f\n", result);

  return 0;
}