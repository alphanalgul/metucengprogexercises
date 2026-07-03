#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

//helper function
double uniform01(){
    return ((double)rand()+1.0)/((double)RAND_MAX+2.0);
}

int main() {
    srand(time(NULL));
    int N;
    printf("\nEnter the value of N: ");
    scanf("%d",&N);

    //Inside Point count calculation
    int count_inside = 0;
    for(int i = 0; i < N; i++){
        double x = uniform01();
        double y = uniform01();

        if(x*x + y*y <=1){
            count_inside++;
        }
    }
    printf("\nNumber of Inside Points: %d",count_inside);

    //Monte Carlo Estimate Calculation
    double monte_carlo_estimate = 4 * ((double)count_inside / N);
    printf("\nMonte Carlo Estimate: %.4f",monte_carlo_estimate);

    //Absolute Error with respect to pi calculation
    double absolute_error = monte_carlo_estimate - 3.141593;
    if(absolute_error < 0){
        absolute_error = -absolute_error;
    }
    printf("\nAbsolute Error: %.6f",absolute_error);

}
