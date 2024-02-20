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
int sequentialSearch(int *, int*, int, int);
int searchArr1(int *, int, int, int);


int main(void)
{ 
  time_t pStart,pEnd;
  pStart = clock();

  int *arrM, *arrN;  
  int countM, countN;


  // User input
  printf("Enter the number of random numbers to generate (M): ");
  scanf("%d", &countM);

  arrM = generateRandom(countM);

  printf("Enter the number of random numbers to generate (N): ");
  scanf("%d", &countN);

  arrN = generateRandom(countN);

  // Sequential search algorithm
  printf("\nThe number of times the N numbers are repeated in the M numbers is: %d\n", sequentialSearch(arrM, arrN, countM, countN));

  // Free the memory
  free(arrM);
  free(arrN);

  pEnd = clock();
  printf("\nElapsed time is %1.7lf seconds\n", (double)(pEnd - pStart) / CLOCKS_PER_SEC);

  return 0;
}


// Generate a random number and populate the array
int* generateRandom(int count)
{
  int *arr = calloc(count, sizeof(int));

  // Check if memory allocation failed
  if (arr == NULL)
  {
    printf("Memory allocation failed");
    exit(1);
  } 

  srand(time(NULL));

  for (int i = 0; i < count; i++)
  {
    *(arr + i) = rand() % count + 1;
  }

  return arr;
}


// Sequential search algorithm
int sequentialSearch(int *arr1, int *arr2, int count1, int count2)
{
  int count = 0;

  for (int i = 0; i < count2; i++)
  {
    count += searchArr1(arr1, *(arr2 + i), 0, count1);
  }

  return count;
}

// Recursive search algorithm
int searchArr1(int *arr1, int num, int curIndex, int count1)
{
  if (curIndex == count1)
  {
    return 0;
  }

  if (*(arr1 + curIndex) == num)
  {
    return 1 + searchArr1(arr1, num, curIndex + 1, count1);
  }
  else
  {
    return searchArr1(arr1, num, curIndex + 1, count1);
  }
}