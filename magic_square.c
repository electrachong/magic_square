#include <stdio.h>

int is_magic_square(int square[3][3]);

/* Create test case */
int main(void)
{
  int square_a[3][3] = {
    {0, 1, 2},
    {2, 0, 1},
    {1, 2, 0}
  };
  int square_b[3][3] = {
    {1, 2, 3},
    {1, 2, 3},
    {1, 2, 3}
  };

  is_magic_square(square_a);
  return 0;
  
}

/* Check whether a given 3x3 square is a magic square. 
   Return 0 if false, 1 if true */
int is_magic_square(int square[3][3])
{
  int sum;
  int i;
  int j;

  sum = 0;

  /* Calculate the sum from the first row */
  for (i = 0, j = 0; i < 3; i++) {
    sum += square[i][j];
  }

  printf("sum of first row: %d", sum);

  return 0;
}
