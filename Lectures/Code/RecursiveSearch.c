/*
  Description: A program to find a number in an unordered array using recursion
  Author: Ryan Pitman
  Date: 20/02/2024
*/

#include <stdio.h>

#define SIZE 10

void recursiveSearch(int *, int, int);

int main(void)
{
  int arr[SIZE] = {5, 3, 7, 9, 2, 8, 4, 1, 6, 10};;
  int num = 7;

  recursiveSearch(arr, SIZE, num);

  return 0;
}

void recursiveSearch(int *arr, int size, int num)
{
  if (size == 0)
  {
    printf("Number not found\n");
    return;
  }

  if (arr[size - 1] == num)
  {
    printf("Number %d found at index %d\n", num, size - 1);
    return;
  }

  recursiveSearch(arr, size - 1, num);
}