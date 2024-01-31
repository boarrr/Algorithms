#include <stdio.h>

int power(int, int);

int main(void)
{
  int x, y;

  printf("Enter X: ");
  scanf("%d", &x);

  printf("Enter Y: ");
  scanf("%d", &y);


  printf("%d to the power of %d is %d\n", x, y, power(x, y));

  return 0;
}

int power(int num, int exp)
{
  if (exp == 0)
    return 1;
  else
    return num * power(num, exp - 1);
}

// Call Stack:
//   power(2, 4)
//   power(2, 3)
//   power(2, 2)
//   power(2, 1)
//   power(2, 0)
//   return 1
//   return 2 * 1 = 2
//   return 2 * 2 = 4
//   return 2 * 4 = 8
//   return 2 * 8 = 16
//   return 16

