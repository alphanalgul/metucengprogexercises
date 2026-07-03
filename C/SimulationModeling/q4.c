#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>

//helper function for generating U(0,1)
double uniform(){
    return ((double)rand()+1.0)/((double)RAND_MAX+2.0);
}


int main() {
    srand(time(NULL));
    double arr[1000];
    double u;
    int count_02 = 0, count_04 = 0, count_06 = 0, count_08 = 0, count_1 = 0;
    //Interval count calculation
    for(int i = 0; i < 1000; i++){
        u = uniform();
        arr[i] = u;

        if(0 <= arr[i] && arr[i] < 0.2){
            count_02++;
        }
        if(0.2 <= arr[i] && arr[i] < 0.4){
            count_04++;
        }
        if(0.4 <= arr[i] && arr[i] < 0.6){
            count_06++;
        }
        if(0.6 <= arr[i] && arr[i] < 0.8){
            count_08++;
        }
        if(0.8 <= arr[i] && arr[i] < 1){
            count_1++;
        }
    }
    printf("\nValues in range [0,0.2): %d",count_02);
    printf("\nValues in range [0.2,0.4): %d",count_04);
    printf("\nValues in range [0.4,0.6): %d",count_06);
    printf("\nValues in range [0.6,0.8): %d",count_08);
    printf("\nValues in range [0.8,1): %d",count_1);

    //Mean and variance calculation
    double e_mean = 0, e_mean_squared = 0, variance;
    for(int i = 0; i < 1000; i++){
        e_mean += arr[i];
    }
    e_mean /= 1000;

    for(int i = 0; i < 1000; i++){
        e_mean_squared += arr[i]*arr[i];
    }
    e_mean_squared /= 1000;

    variance = e_mean_squared - (e_mean*e_mean);

    int a = 0, b = 1;
    //Theoretical Mean and Variance
    printf("\nTheoretical Mean: %.4f",(double)(b+a)/2);
    printf("\nTheoretical Variance: %.4f",(double)pow(b-a,2)/2);
    //Sample Mean and Variance
    printf("\nSample Mean: %.4f",e_mean);
    printf("\nSample Variance: %.4f",variance);

    //lag-1 sample auto-correlation calculation
    // I divided the formula into 3 components for ease of calculation
    double r1=0,r2=0,r3 = 0;
    //First part
    for(int i = 1; i < 999; i++){
        r2 += (arr[i] - e_mean)*(arr[i+1] - e_mean);
    }
    //Second part
    for(int i = 1; i < 1000; i++){
        r3 += pow(arr[i]-e_mean,2);
    }

    r1 = r2 / r3;//lag-1 sample auto-correlation calculation
    printf("\nlag-1 sample auto-correlation value: %.4f",r1);


    //Dry Run Section
    double dry_run_values[5] = {0.10,0.40,0.60,0.80,0.90};//Dry run array
    int dry_02 = 0, dry_04 = 0, dry_06 = 0,dry_08 = 0, dry_1 = 0;//Dry run counts
    for(int i = 0; i < 5; i++){
        if(0 <= dry_run_values[i] && dry_run_values[i] < 0.2){
            dry_02++;
        }
        if(0.2 <= dry_run_values[i] && dry_run_values[i] < 0.4){
            dry_04++;
        }
        if(0.4 <= dry_run_values[i] && dry_run_values[i] < 0.6){
            dry_06++;
        }
        if(0.6 <= dry_run_values[i] && dry_run_values[i] < 0.8){
            dry_08++;
        }
        if(0.8 <= dry_run_values[i] && dry_run_values[i] < 1){
            dry_1++;
        }
    }
    printf("\n\n\nDry Run:");
    printf("\nDry Run Values in range [0,0.2): %d",dry_02);
    printf("\nDry Run Values in range [0.2,0.4): %d",dry_04);
    printf("\nDry Run Values in range [0.4,0.6): %d",dry_06);
    printf("\nDry Run Values in range [0.6,0.8): %d",dry_08);
    printf("\nDry Run Values in range [0.8,1): %d",dry_1);

    double dry_total = 0;
    for(int i = 0; i <5 ; i++){
        dry_total += dry_run_values[i];
    }

    printf("\nDry Run Sample Mean: %.4f",dry_total/5);
}
