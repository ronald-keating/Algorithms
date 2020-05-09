/*************************
 * Id:
 *
 * Power formula
 * 
 * input: ./a.out 2 2
 *************************/

#include <stdio.h>
#include <stdlib.h>

int recursion(int n);
int power(int x, int n);

/*************************
 * Main function. Pass variables via the command line. 
 * Covert the argument to an integer in order to compute.
 *************************/

int main(int argc, char *argv[])
{
   if(argc > 3)
   {
      printf("wrong input\n");
      return 0;
   }
   int temp = atoi(argv[1]);
   int n = recursion(temp);
   printf("%d\n", n);
   return 0;
}

/**************************
 * Recursive function that does a bunch of computing power 
 * for something that we could use a single for loop.
 *************************/
int recursion(int n)
{
   if(n < 1)
   {
      return 1;
   }
   else
   {
      return recursion(n -1) + recursion(n - 1);
   }
}
