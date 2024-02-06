/*
  Description: A program to calculate the sum of the digits of an entered number via a recursive function.
  Author: Ryan Pitman
  Date: 06/02/2024
*/

#include <stdio.h>


// Function Prototype
int sumDigits(int n);


int main(void)
{
  // Assuming positive numbers only
  unsigned int input;


  // User input
  printf("Enter a positive number: ");
  scanf("%u", &input);

  printf("The sum of the digits of %u is %d\n", input, sumDigits(input));

  return 0;
}


// Recursive function to calculate the sum of the digits of a number
int sumDigits(int n)
{
  // Get last digit of N,  remove it and add it to the sum, repeat until no more digits remain
  return n == 0 ? 0 : n % 10 + sumDigits(n / 10);
}