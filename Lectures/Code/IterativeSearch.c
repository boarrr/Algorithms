/*
  Description: A program to find a number in an unordered array
  Author: Ryan Pitman
  Date: 20/02/2024
*/

#include <stdio.h>

#define SIZE 10

void iterativeSearch(int *, int, int);

int main(void)
{
  int arr[SIZE] = {5, 3, 7, 9, 2, 8, 4, 1, 6, 10};;
  int num = 7;

  iterativeSearch(arr, SIZE, num);

  return 0;
}

void iterativeSearch(int *arr, int size, int num)
{
  for (int i = 0; i < size; i++)
  {
    if (arr[i] == num)
    {
      printf("Number %d found at index %d\n", num, i);
      return;
    }
  }
  
  printf("Number not found\n");
}