/*
  Description: A program to calculate number X to the power of Y via a recursive function.
  Author: Ryan Pitman
  Date: 06/02/2024
*/

#include <stdio.h>


// Function Prototype
int power(int x, int y);


int main(void) 
{
  int inputX, inputY;


  // User input
  printf("Enter a positive number for X: ");
  scanf("%d", &inputX);

  printf("Enter a positive number for Y: ");
  scanf("%d", &inputY);

  printf("%d to the power of %d is %d\n", inputX, inputY, power(inputX, inputY));

  return 0;
}


// Recursive function to calculate number X to the power of Y
int power(int x, int y)
{
  return y == 0 ? 1 : x * power(x, y - 1);
}