#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

double uniform01(){
    return ((double)rand()+1.0) / ((double)RAND_MAX + 2.0);
}
int main() {
   srand(time(NULL));
   int n;
   printf("\nEnter a number N:");
   scanf("%d",&n);
   double x,y;
   int count_inside = 0;
   for(int i = 0; i < n; i++){
       x = uniform01();
       y = uniform01();

       if(x*x + y*y < 1){
           count_inside++;
       }

   }
   printf("\nNumber of inside points: %d",count_inside);

   double monte_carlo = 4 * (double) count_inside / n;

   printf("\nMonte Carlo Estimate is: %.2f",monte_carlo);

   double absolute_error = monte_carlo - 3.141593;
   if(absolute_error<0){
       absolute_error = -absolute_error;
   }

   printf("\nAbsolute error with respect to 3.141593 is : %.6f",absolute_error);

   //Dry run
   printf("\n\n\n");
   printf("\nDry Run");
   printf("\nPoint (0.2,0.3): Inside and Counted since %.2f is smaller than 1",(0.2)*(0.2) + (0.3)*(0.3));
   printf("\nPoint (0.9,0.8): Not Inside and Not Counted since %.2f is greater than 1",(0.9)*(0.9)+(0.8)*(0.8));
   printf("\nPoint (0.4,0.5): Inside and Counted since %.2f is smaller than 1", (0.4)*(0.4)+(0.5)*(0.5));

   printf("\nIn the Dry run since we have 2 points inside and 1 point outside the Monte Carlo Estimate will be %.2f",4 * (2.0/3.0));
}
