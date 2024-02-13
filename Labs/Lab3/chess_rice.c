/*
  Description: A program to calculate how many seconds it would take to count grains of rice on a chessboard, where the number of grains doubles for each square.
  Author: Ryan Pitman
  Date: 13/02/2024
*/

#include <stdio.h>


int main()
{
  long long unsigned int grains = 1;
  long long unsigned int total = 0;

  for (int i = 0; i < 64; i++)
  {
    total += grains;
    grains *= 2;
  }

  printf("Total grains: %llu\n", total);
  
  return 0;
}