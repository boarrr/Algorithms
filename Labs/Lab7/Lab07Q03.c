/*
  Description: A simple searching algorithm to find the max and min in an unsorted array
  Author: Ryan Pitman
  Date: 12/03/2024
*/

#include <stdio.h>

#define SIZE 6

void search(int*, int);

int main(void) 
{
  int nums[SIZE] = {4,2,6,1,8,3};

  search(nums, (sizeof(nums) / sizeof(nums[0])));

  return 0;
}

void search (int* arr, int len)
{
  int min = arr[0], max = arr[0];

  for (int i = 1; i < len; i++)
  {
    if (arr[i] < min) min = arr[i];
    else if (arr[i] > max) max = arr[i];
  }

  printf("The min is: %d, and the max is: %d\n", min, max);
}