/*
  Description: An implementation of insertion sort in C, with a loop counter for each iteration.
  Author: Ryan Pitman
  Date: 05/03/2024
*/

#include <stdio.h>

#define SIZE 4

void insertionSort(int*, int n);

int main(void)
{
  int arr1[SIZE] = {4, 6, 1, 2};
  int arr2[SIZE] = {6, 4, 2, 1};
  int arr3[SIZE] = {1, 4, 2, 6};


  // Pass the arrays to the insertion sort function
  insertionSort(arr1, SIZE);
  insertionSort(arr2, SIZE);
  insertionSort(arr3, SIZE);

  return 0;
}


// Insertion sort function with counters
void insertionSort(int* arr, int numEle)
{
  int current, countLoops = 0, countOps = 0;

  printf("\nUnsorted array: ");
  for (int i = 0; i < numEle; i++) printf("%d ", arr[i]);

  // Loop through the array
  for (int i = 1; i < numEle; i++)
  {
    int j = i - 1;
    current = arr[i];

    countOps += 2; // Increment the counter for the two operations

    // Move elements of arr[0..i-1], that are greater than current, to one position ahead of their current position
    while (j >= 0 && arr[j] > current)
    {
      arr[j + 1] = arr[j];
      j--;

      countOps += 2; // Increment the counter for the two operations
      countLoops++; // Increment the counter 
    }

    arr[j + 1] = current;
    countOps++; // Increment the counter for the operation
  }

  printf("\nSorted array: ");
  for (int i = 0; i < numEle; i++) printf("%d ", arr[i]);

  printf("\nTotal Loops Run: %d, Total Operations Performed: %d", countLoops, countOps);
  printf("\n");
}