/*
  Description: A simple implementation of binary search, to find a number in a sorted array
  Author: Ryan Pitman
  Date: 12/03/2024
*/

#include <stdio.h>

#define SIZE 6

void search(int*, int, int);

int main(void)
{
  int nums[SIZE] = {1,2,3,4,5,6}; 
  int numToFind = 5;

  search(nums, sizeof(nums) / sizeof(nums[0]), numToFind);
  
  return 0;
}

void search(int* nums, int size, int numToFind)
{
  int low = 0;
  int high = size - 1;
  int mid;

  while (low <= high)
  {
    mid = (low + high) / 2;
    if (nums[mid] == numToFind)
    {
      printf("Number %d found at index %d\n", numToFind, mid);
      break;
    }
    else if (nums[mid] < numToFind) low = mid + 1;
    else high = mid - 1;
  }

  if (low > high) printf("Number %d not found\n", numToFind);
}