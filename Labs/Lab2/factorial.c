/*
  Description: A program to calculate the factorial of an entered number via a recursive function.
  Author: Ryan Pitman
  Date: 06/02/2024
*/

#include <stdio.h>

// Function Prototype, long long int to handle large results
long long int factorial(int n);


int main(void) 
{
  int input;


  // User input
  printf("Enter a positive number: ");
  scanf("%d", &input);

  printf("The factorial of %d is %lld\n", input, factorial(input));

  return 0;
}


// Recursive function to calculate the factorial of a number
long long int factorial(int n)
{
  return n == 0 ? 1 : n * factorial(n - 1);
}