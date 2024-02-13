/*
  Description: A program to calculate if any combination of three numbers in a 6 number array sum to zero.
  Author: Ryan Pitman
  Date: 13/02/2024
*/

#include <stdio.h>
#include <time.h> 

#define SIZE 6

void threeSum(int *);

int main()
{
  clock_t start = clock();
  int a[SIZE] = {0};


  for (int i = 0; i < SIZE; i++)
  {
    printf("Enter a number: "); 
    scanf("%d", &a[i]);
  }

  threeSum(a);

  printf("Time taken: %lu ms\n", (clock() - start));
  
  return 0;
}


void threeSum(int *a)
{
  int count = 0;

  for (int i = 0; i < SIZE; i++)
  {
    for (int j = i + 1; j < SIZE; j++)
    {
      for (int k = j + 1; k < SIZE; k++)
      {
        if (a[i] + a[j] + a[k] == 0)
        {
          printf("%d %d %d\n", a[i], a[j], a[k]);
          count++;
        }
      }
    }
  }

  if (count == 0)
  {
    printf("No pairs found\n");
  }
}