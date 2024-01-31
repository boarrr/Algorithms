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