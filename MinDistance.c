/*********************************************
 * Id: 
 *
 * This program finds the minimum distance between 
 * any data points that are given through command 
 * line arguments. The algorithm works by first 
 * initializing the min variable with the first two 
 * elements of argv (the 2d array that is passed 
 * through the command line) and then creating a 
 * temp variable that finds every other distance between 
 * any of the points. This temp each time is compared to 
 * the min variable to see if it is less of a distance. 
 * If it is, then the min is set equal to the temp.
 * 
 * Original min distance from FasterMinDistance.c
 * 
 * input: ./a.out 1 2 3 4 5 6 7 8 
 * probably do not want to use a sorted array already, with the min distance always being 1
 *********************************************/
#include <stdlib.h>					//atoi and abs
#include <stdio.h>					//printf

int main(int argc, char *argv[]) 			//argv is a double pointer
{ 
   int i, j, dmin, temp;				//declare variables
   if(argc < 3)
   {
      printf("Wrong input");
   }
   else{
      dmin = abs(atoi(argv[1]) - atoi(argv[2]));		//initialize min with first two elements
      for(i = 1; i < argc; i++)				//given a single element, subtract every number before and after it and compare
      {
         for(j = 1; j < argc; j++)				//every number before and after
         {
            if(i == j)
            {					//dont want to subtract itself, use i and j, not agrv elements, as we can have the same number and distance be 0
               continue;
            }
            else
            {
               temp = abs(atoi(argv[i]) - atoi(argv[j]));  //put value into a temo variable to compare to min
               if(temp < dmin)
               {				//if less, then make min equal to temp
                  dmin = temp;
               }
            }
         }
      }
   }
   printf("%d\n", dmin);				//print min
   return 0;						//could have made another function to call through main, but not a lot of code
}
