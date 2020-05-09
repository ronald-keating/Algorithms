/*********************************************
 * Id: 
 * NOT QUICKSORT
 *
 * Uses quick sort to sort the array elements from least to greatest and
 * subtracts the neighoring values. Compare these instead.
 * This version runs through theoretically two four loops rather than a nested 
 * for loop that runs as many times as the parent for loops requires.
 * Note that to simplify the programming, I copied argv over to another int array
 * and used this instead. So there is an extra for loop that is technically 
 * unnecessary.
 * 
 * Execute: a./out 1 2 3 4 5 6 7 8 9 
 *********************************************/
#include <stdlib.h>					//atoi and abs
#include <stdio.h>					//printf
#include <string.h>

void quickSort(int argc, int *cpyArgv, char **argv);	/* quick sort to sort the elements of the array first. */

int main(int argc, char *argv[]) 			//argv is a double pointer
{ 
   int i, dmin;				//declare variables
   int cpyArgv[argc];
   if(argc < 3)
   {
      printf("Wrong input");
      return 0;
   }
   quickSort(argc, cpyArgv, argv);
   dmin = abs(cpyArgv[1] - cpyArgv[2]);
   for(i = 2; i < argc - 1; i++)
   {
      if(dmin > (abs(cpyArgv[i] - cpyArgv[i + 1])))
      {
         dmin = abs(cpyArgv[i] - cpyArgv[i + 1]);
      }
   }
   printf("%d\n", dmin);				//print min
   return 0;						//could have made another function to call through main, but not a lot of code
}

/*********************************************
 * Quicksort function
 ********************************************/
void quickSort(int argc, int *cpyArgv, char **argv)     /* quick sort to sort the elements of the array first */
{
   int i, j;
   int temp;
   for(i = 1; i < argc; i++)
   {
      cpyArgv[i] = atoi(argv[i]);
   }
   for(i = 1; i < argc; i++)
   {
      for(j = 1; j < argc; j++)
      {
         if(cpyArgv[i] < cpyArgv[j])
         {
            temp = cpyArgv[i];
            cpyArgv[i] = cpyArgv[j];
            cpyArgv[j] = temp;
         }
      }
   }
}

