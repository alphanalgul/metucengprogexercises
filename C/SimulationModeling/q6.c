#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int main() {
    int n,check=0;
    while(check!=1){
        printf("\nEnter a value n:");
        scanf("%d",&n);
        if(n<2){
            printf("\nValue of n should be 2 or higher try again!");
        }
        else{
            check = 1;
        }
    }

    int X[n],Y[n];
    int val;

    for(int i = 0; i<n; i++){
        printf("\nEnter a value for array X:");
        scanf("%d",&val);
        X[i] = val;
    }

    for(int i = 0; i <n; i++){
        printf("\nEnter a value for array Y:");
        scanf("%d",&val);
        Y[i] = val;
    }

    for(int i = 0; i < n; i++){
        printf("%d",X[i]);
    }
    printf("\n");
    for(int i = 0; i < n; i++){
        printf("%d",Y[i]);
    }

    double mean_x = 0.0, mean_y = 0.0;
    for(int i = 0; i < n; i++){
        mean_x += X[i];
    }
    mean_x /= n;
    printf("\nMean of X is: %.2f",mean_x);

    for(int i = 0; i < n; i++){
        mean_y += Y[i];
    }
    mean_y /= n;
    printf("\nMean of Y is: %.2f",mean_y);

    double variance_x = 0.0, variance_y = 0.0;
    for(int i = 0; i < n; i++){
        variance_x += (X[i]-mean_x)*(X[i]-mean_x);
        variance_y += (Y[i]-mean_y)*(Y[i]-mean_y);
    }
    variance_x /= n-1;
    variance_y /= n-1;

    printf("\nVariance of X is: %.2f",variance_x);
    printf("\nVariance of Y is: %.2f",variance_y);

    double sample_covariance = 0.0;

    for(int i = 0; i < n; i++){
        sample_covariance += (X[i] - mean_x) * (Y[i] - mean_y);
    }
    sample_covariance /= n-1;

    printf("\nSample Covariance of X and Y is %.2f",sample_covariance);


    double r = (sample_covariance) / sqrt(variance_x * variance_y);

    printf("\nSample correlation coefficient r is: %.2f",r);

    if(r>0){
        printf("\nThe relationship between X and Y is a positive relationship");
    }
    else if (r<0){
        printf("\nThe relationship between X and Y is a negative relationship");
    }
    else{
        printf("\nThe relationship between X and Y is a zero-based relationship");
    }
}
