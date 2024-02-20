/*
  Description: A program to demonstrate bubble sort algorithm
  Author: Ryan Pitman
  Date: 20/02/2024
*/

#include <stdio.h>

void bubbleSort(int *, int);

int main(void)
{
  int arr[] = {4, 2, 6, 8, 1, 3, 7, 5};
  int n = sizeof(arr) / sizeof(arr[0]) - 1;

  printf("Unsorted array: ");
  for (int i = 0; i < n; i++)
  {
    printf("%d ", arr[i]);
  }
  printf("\n");

  bubbleSort(arr, n);

  printf("Sorted array: ");
  for (int i = 0; i < n; i++)
  {
    printf("%d ", arr[i]);
  }
  printf("\n");

  return 0;
}


void bubbleSort(int* arr, int size)
{
  int tmp;

  for (int i = 0; i < size; i++)
  {
    for (int j = 0; j < size - i; j++)
    {
      if (arr[j] > arr[j+1])
      {
        tmp = arr[j];
        arr[j] = arr[j+1];
        arr[j+1] = tmp;
      }
    }
  }
}