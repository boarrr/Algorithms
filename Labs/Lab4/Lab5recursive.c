/*
  Description: A program to generate M random numbers, then generate N random numbers. Counting how many times the N numbers are repeated in the M numbers
  //           using a recursive sequential search algorithm.
  Author: Ryan Pitman
  Date: 20/02/2024
*/ 

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int* generateRandom(int);
int recursiveSearchM(int *, int, int);
int recursiveSearch(int *, int*, int, int);

int main(void)
{ 
  time_t pStart, pEnd;
  pStart = clock();

  int *arrM, *arrN;  
  int countM, countN;

  printf("Enter the number of random numbers to generate (M): ");
  scanf("%d", &countM);
  arrM = generateRandom(countM);

  printf("Enter the number of random numbers to generate (N): ");
  scanf("%d", &countN);
  arrN = generateRandom(countN);

  printf("\nThe number of times the N numbers are repeated in the M numbers is: %d\n", recursiveSearch(arrM, arrN, countM, countN));

  free(arrM);
  free(arrN);

  pEnd = clock();
  printf("\nElapsed time is %1.7lf seconds\n", (double)(pEnd - pStart) / CLOCKS_PER_SEC);

  return 0;
}

int* generateRandom(int count)
{
  int *arr = calloc(count, sizeof(int));
  if (arr == NULL)
  {
    printf("Memory allocation failed");
    exit(1);
  } 

  srand(time(NULL));
  for (int i = 0; i < count; i++)
  {
    arr[i] = rand() % count + 1;
  }

  return arr;
}

int recursiveSearch(int* arr1, int* arr2, int sizeM, int sizeN)
{
  // Base case
  if (sizeN == 0) return 0; 

  // Check if the current element of arr2 is in arr1, then add the result to recursive call
  return recursiveSearchM(arr1, sizeM, arr2[0]) + recursiveSearch(arr1, arr2 + 1, sizeM, sizeN - 1);
}

int recursiveSearchM(int *arr, int size, int num)
{
  // Base case
  if (size == 0) return 0; 

  // If the last element matches, return 1 (found) + recursive call for rest of the array
  return (arr[size - 1] == num) + recursiveSearchM(arr, size - 1, num);
}
