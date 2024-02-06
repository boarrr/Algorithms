/*
  Description: This program calculates the fibonacci sequence up to a given number using a recursive function.
  Author: Ryan Pitman
  Date: 06/02/2024
*/

#include <stdio.h>


// Function Prototype, long long int to handle large numbers
long long int fibonacci(int n);


int main(void) 
{
  // Assuming positive numbers only due to the nature of the fibonacci sequence
  unsigned int input;


  // User input
  printf("Enter a positive number of terms: ");
  scanf("%u", &input);

  printf("The fibonacci sequence up to %u terms is: ", input);

  // Print the fibonacci sequence up to the given number
  for (unsigned int i = 0; i < input; i++)
  {
    printf("%lld ", fibonacci(i));
  }

}


// Recursive function to calculate the fibonacci sequence
long long int fibonacci(int n)
{
  return n <= 1 ? n : fibonacci(n - 1) + fibonacci(n - 2);
}