/*
  Description: An implementation of the selection sort algorithm in C
  Author: Ryan Pitman
  Date: 27/02/2024
*/

#include <stdio.h>

#define SIZE 4

int selectionSort(int*);
int isSorted(int*);

int main (void)
{
  // Base array test
  int arr[SIZE] = {4, 6, 1, 2};

  // Output the returned iterations
  printf("Array sorted in %d iterations", selectionSort(arr));

  // Output the sorted array
  printf("\nSorted array: ");
  for (int i = 0; i < SIZE; i++)
  {
    printf("%d ", arr[i]);
  }

  return 0;
}

// Check if the array is sorted
int isSorted(int* arr)
{
  for (int i = 0; i < SIZE - 1; i++)
  {
    if (arr[i] > arr[i + 1]) return 0;
  }

  return 1;
}

// Selection sort algorithm
int selectionSort(int* arr)
{
  int min, temp, count = 0;

  // If the array is already sorted, return 0
  if (isSorted(arr)) return 0;

  // Selection sort algorithm
  for (int i = 0; i < SIZE - 1; i++)
  {
    min = i;
    for (int j = i + 1; j < SIZE; j++)
    {
      if (arr[j] < arr[min]) min = j;
      
      count++;
    }

    temp = arr[i];
    arr[i] = arr[min];
    arr[min] = temp;
  }
  
  return count;
}