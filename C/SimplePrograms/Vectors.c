/*
 * This program calculates the Mean Squared Error (MSE) between two vectors:
 * - One vector is filled by user input (with values between 1 and 100).
 * - The second vector is randomly generated (values 1–100).
 *
 * The program prints both vectors and computes:
 *     MSE = sum((A[i] - B[i])²) / N
 */


#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
void populateVector(int *vector,int length)
{
    int i;
    for(i=0;i<length;i++)
    {
        printf("\nEnter the measurement [%d]:",i+1);
        scanf("%d",&vector[i]);
        if(vector[i]>100||vector[i]<1)
        {
            printf("\nThis is not a valid input!");
            printf("\nEnter the measurement [%d]:",i+1);
            scanf("%d",&vector[i]);
        }
    }
}
void populateVectorRandomly(int *vector,int length)
{
    srand(time(NULL));
    int i;
    for(i=0;i<length;i++)
    {
        vector[i]=rand()%100+1;
    }
    int j;
    printf("\nThe Predicted Values:\n");
    for(j=0;j<length;j++)
    {
        printf("%d  ",vector[j]);
    }
}
double meanSquareError(int *vectorA,int *vectorB,int length)
{
    int i;
    double mean,total_mean=0,mean_squared_error;
    for(i=0;i<length;i++)
    {
        mean= pow(vectorA[i]-vectorB[i],2);
        total_mean=total_mean+mean;
    }
    mean_squared_error=((total_mean)/(length));
    return mean_squared_error;
}
int main() {
    int size, *vector,*vector2;
    int check=0;
    double MSE;
    while(check!=1) {
        printf("\nEnter the number of measurements:");
        scanf("%d", &size);
        if(size<=0)
        {
            printf("\nThis is not a valid input!");
        }
        else
        {
            check=1;
        }
    }
    vector=(int *)malloc(sizeof(int)*size);
    vector2=(int *)malloc(sizeof(int)*size);
    populateVector(vector,size);
    populateVectorRandomly(vector2,size);
    int j;
    for(j=0;j<size;j++)
    {
        printf("%d ",vector[j]);
    }

    MSE= meanSquareError(vector,vector2,size);
    printf("\nMSE = %lf",MSE);
}
