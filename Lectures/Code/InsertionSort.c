/*
  Description: A program to illustrate insertion sort in C
  Author: Ryan Pitman
  Date: 27/02/2024
*/

#include <stdio.h>

#define SIZE 8

void insertionSort(int*);

int main(void)
{
  int arr[8] = {4, 2, 6, 8, 1, 3, 7, 5};

  insertionSort(arr);

  for (int i = 0; i < SIZE; i++)
  {
    printf("%d ", arr[i]);
  }

  return 0;
}


void insertionSort(int* arr)
{
  int i, j, current;

  for (i = 1; i < SIZE; i++)
  {
    current = arr[i];
    j = i;

    while (arr[j - 1] > current && j > 0)
    {
      arr[j] = arr[j - 1];
      j = j - 1;
    }

    arr[j] = current;
  }
}