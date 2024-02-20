/*
  Description: Code to demonstrate the selection sort algorithm
  Author: Ryan Pitman
  Date: 20/02/2024
*/

#include <stdio.h>

void selectionSort(int *, int);

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

  selectionSort(arr, n);

  printf("Sorted array: ");
  for (int i = 0; i < n; i++)
  {
    printf("%d ", arr[i]);
  }
  printf("\n");

  return 0;
}

void selectionSort(int *arr, int size)
{
  int min, temp;

  // Iterate through the array
  for (int i = 0; i < size; i++)
  {
    min = i;

    // Find the minimum element in the unsorted part of the array
    for (int j = i+1; j < size; j++)
    {
      if (arr[j] < arr[min]) min = j;
    }

    // Swap the minimum element with the first unsorted element
    temp = arr[i];
    arr[i] = arr[min];
    arr[min] = temp;
  }
}