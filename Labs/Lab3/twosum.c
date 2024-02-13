/*
  Description: A program to calculate the pairs of numbers in an array that sum to zero.
  Author: Ryan Pitman
  Date: 13/02/2024
*/

#include <stdio.h>
#include <time.h> 

#define SIZE 6

void twoSum(int *);

int main()
{
  clock_t start, end;
  start = clock();
  int a[SIZE] = {0};


  for (int i = 0; i < SIZE; i++)
  {
    printf("Enter a number: ");
    scanf("%d", &a[i]);
  }

  twoSum(a);

  end = clock();

  printf("Time taken: %lu ms\n", (end - start));

  return 0;
}


void twoSum(int *a)
{
  int pairs[SIZE][2] = {0};
  int count = 0;

  for (int i = 0; i < SIZE; i++)
  {
    for (int j = i + 1; j < SIZE; j++)
    {
      if (a[i] + a[j] == 0)
      {
        pairs[count][0] = a[i];
        pairs[count][1] = a[j];
        count++;
      }
    }
  }

  for (int i = 0; i < count; i++)
  {
    printf("%d %d\n", pairs[i][0], pairs[i][1]);
  }
}