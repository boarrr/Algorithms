/*
  Description: A program to sort an array using merge sort
  Author: Ryan Pitman
  Date: 07/04/2024
*/

#include <stdio.h>

#define SIZE 8

void mergeSort(int*, int, int);
void merge(int*, int, int, int);


int main(void)
{
  int nums[SIZE] = {5,2,4,7,6,8,3,1};

  printf("The unsorted array is: ");
  for (int i = 0; i < SIZE; i++)
  {
    printf("%d ", nums[i]);
  }
  printf("\n");

  mergeSort(nums, 0, SIZE);
  
  printf("\nThe sorted array is: ");
  for (int i = 0; i < SIZE; i++)
  {
    printf("%d ", nums[i]);
  }

  return 0;
}


void mergeSort(int* arr, int low, int high)
{
  if (low < high)
  {
    int mid = (low + high) / 2;

    mergeSort(arr, low, mid);
    mergeSort(arr, mid + 1, high);
    merge(arr, low, mid, high);
  }
}

void merge(int* arr, int low, int mid, int high)
{
  int temp[high - low + 1];
  int i = 0;
  int leftPointer = low, rightPointer = mid + 1;

  while(leftPointer <= mid && rightPointer <= high)
  {
    if (arr[leftPointer] <= arr[rightPointer])
    {
      temp[i++] = arr[leftPointer++];
    }
    else
    {
      temp[i++] = arr[rightPointer++];
    }
  }

  while (leftPointer <= mid) temp[i++] = arr[leftPointer++];

  while (rightPointer <= high) temp[i++] = arr[rightPointer++];

  for(i = 0; i < high - low + 1; i++)
  {
    arr[low + i] = temp[i];
  }
}