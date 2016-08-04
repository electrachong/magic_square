#include <stdio.h>

int is_magic_square(int square[3][3]);

/* Create test case */
int main(void)
{
  int square_a[3][3] = {
    {0, 1, 2},
    {2, 2, 1},
    {1, 2, 1}
  };
  int square_b[3][3] = {
    {1, 2, 3},
    {1, 2, 3},
    {1, 2, 3}
  };

  if (is_magic_square(square_a)) {
    printf("Square  A is a magic square\n");
  } else {
    printf("Square A is not a magic square\n");
  }
  if (is_magic_square(square_b)) {
    printf("Square B is a magic square\n");
  } else {
    printf("Square B is not a magic square\n");
  }

  return 0;
  
}

/* Check whether a given 3x3 square is a magic square. 
   Return 0 if false, 1 if true 
   Note: in retrospect, would have been better to code each
   check in separate functions to better test if each works
*/

int is_magic_square(int square[3][3])
{
  int sum;
  int current_sum;
  int another_sum;
  int i;
  int j;

  sum = 0;

  /* Calculate the sum from the first row */
  for (i = 0, j = 0; i < 3; i++) {
    sum += square[i][j];
  }

  /* Compare this sum to the remaining sums for the rows */
  for (j = 1; j < 3; j++) {
    current_sum = 0;
    /* Add up each row in a column */
    for (i = 0; i < 3; i++) {
      current_sum += square[i][j];
    }
    if (current_sum != sum) {
	return 0;
    } 
  }

  /* Now compare this sum to sum of the columns */
  for (i = 0; i < 3; i++) {
    current_sum = 0;
    /* Add up each column in a row */
    for (j = 0; j < 3; j++) {
      current_sum += square[i][j];
    }
    if (current_sum != sum) {
	return 0;
    } 
  }

  /* Now finally, to check diagonals */
  current_sum = 0;
  another_sum = 0;
  /* Check going left to right */
  for (j = 0, i = 0; j < 3; i++, j++) {
    current_sum += square[i][j];
    /* Check from the other direction at the same time */
    another_sum += square[i][2 - i];
  }
  if (current_sum != sum || another_sum != sum) {
      return 0;
  } 

  /* If all checks have passed, return 0 */
  return 1;
}
