/*********************
 * Id:
 *
 * This program determines the Guassian Elimination of a n x n matrix
 * 
 * input: ./a.out 1 2 3 4 5 6 7 8 9
 * Inputs maybe a little off, it has been a while since I wrote these
 ********************/

#include <stdio.h>
#include <stdlib.h>

void printMatrix(int row, int cols, float matrix[row][cols]);

int main(int argc, char *argv[])
{
   if(argc < 2)
   {
      return 0;
   }
   int i, j, k, n = atoi(argv[1]);
   if(argc != ((n+1)*n) + 2)
   {
      return 0;
   }
   int row = n, cols = n+1;
   float matrix[row][cols];
   k = 2;
   for(i = 0; i < row; i++)
   {
      for(j = 0; j < cols; j++)
      {
         matrix[i][j] = atof(argv[k]);
         k++;
      }
   }
   printMatrix(row, cols, matrix);
   float tempji;
   for(i = 0; i <= n-2; i++)
   {
      for(j = i + 1; j <= n - 1; j++)
      {
         tempji = matrix[j][i];
         for(k = i; k <= n; k++)
         {
            matrix[j][k] = matrix[j][k] - (matrix[i][k] * tempji / matrix[i][i]);
         }
      }
      printMatrix(row, cols, matrix);
   }
   return 0;
}

/**********************
 * Comments go up here
 * 
 * print matrix function
 *********************/

void printMatrix(int row, int cols, float matrix[row][cols]) // simple print matrix function so we can call at any time without having to retype
{
   int i, j;
   for(i = 0; i < row; i++)
   {
      for(j = 0; j < cols; j++)
      {
         printf("%.2f ", matrix[i][j]);
      }
      printf("\n");
   }
   printf("\n");
}
