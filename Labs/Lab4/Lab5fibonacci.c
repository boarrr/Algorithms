/*
  Description: A program to recursively call the Fibonacci function to calculate the nth Fibonacci number
  Author: Ryan Pitman
  Date: 20/02/2024
*/

#include <stdio.h>
#include <time.h>

unsigned long long fibonacci(int);

int main(void)
{
  time_t pStart,pEnd;
  pStart = clock();

  unsigned int n;

  // Get the value of n
  printf("Enter the value of n: ");
  scanf("%u", &n);

  // Print the result
  printf("\nThe %dth Fibonacci number is %llu\n", n, fibonacci(n));

  pEnd = clock();
  printf("\nElapsed time is %1.7lf seconds\n", (double)(pEnd - pStart) / CLOCKS_PER_SEC);
  
  return 0;
}

// Calculate the Fibonacci numbers
unsigned long long fibonacci(int n)
{
    switch (n)
    {
    case 0:
    {
      return 0;
      break;
    }

    case 1:
    {
      return 1;
      break;
    }
    
    default:
    {
      return fibonacci(n - 1) + fibonacci(n - 2);
    }
  }
}