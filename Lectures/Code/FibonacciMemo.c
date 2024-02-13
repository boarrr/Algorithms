/*
  Description: A program to calculate the nth Fibonacci number using memoization
  Author: Ryan Pitman
  Date: 06/02/2024
*/

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
  unsigned int n;

  // Get the value of n
  printf("Enter the value of n: ");
  scanf("%u", &n);

  // Create an array to store the Fibonacci numbers
  unsigned long long *fib = (unsigned long long *)malloc((n + 1) * sizeof(unsigned long long));



  // Calculate the Fibonacci numbers
  for (int i = 0; i <= n; i++)
  {
    if (i == 0)
    {
      fib[i] = 0;
    }
    else if (i == 1)
    {
      fib[i] = 1;
    }
    else
    {
      fib[i] = fib[i - 1] + fib[i - 2];
    }

    printf("%d: %llu\n", i, fib[i]);
  }

  // Print the result
  printf("The %dth Fibonacci number is %llu\n", n, fib[n]);

  return 0;
}