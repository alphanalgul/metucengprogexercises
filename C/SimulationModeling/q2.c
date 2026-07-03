#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>
int main() {
    srand(42);
    double a =1, b = 6;
    int dices[7];

    //Initializing the array
    for(int i = 0; i < 7; i++){
        dices[i] = 0;
    }

    //Storing the num of occurrences for each face in the array
    for(int i = 0; i < 1000; i++){
       int roll = rand()%6 + 1;

       if(roll == 1){
          dices[1]++;
       }
       else if(roll == 2){
            dices[2]++;
       }
       else if(roll == 3){
            dices[3]++;
       }
       else if(roll == 4){
            dices[4]++;
       }
       else if(roll == 5){
            dices[5]++;
       }
       else if(roll == 6){
            dices[6]++;
       }
    }

    printf("\nNumber of 1s: %d",dices[1]);
    printf("\nNumber of 2s: %d",dices[2]);
    printf("\nNumber of 3s: %d",dices[3]);
    printf("\nNumber of 4s: %d",dices[4]);
    printf("\nNumber of 5s: %d",dices[5]);
    printf("\nNumber of 6s: %d",dices[6]);

    //Empirical Probability of Each face
    printf("\nEmpirical Probability of Rolling 1: %.3f",(double)dices[1] / 1000);
    printf("\nEmpirical Probability of Rolling 2: %.3f",(double)dices[2] / 1000);
    printf("\nEmpirical Probability of Rolling 3: %.3f",(double)dices[3] / 1000);
    printf("\nEmpirical Probability of Rolling 4: %.3f",(double)dices[4] / 1000);
    printf("\nEmpirical Probability of Rolling 5: %.3f",(double)dices[5] / 1000);
    printf("\nEmpirical Probability of Rolling 6: %.3f",(double)dices[6] / 1000);

    //Theoretical Mean and Variance Calculations
    printf("\nTheoretical Mean: %.3f",(a+b)/2);
    printf("\nTheoretical Variance: %.3f",(double )((pow(b-a+1,2)-1)/12));


    double e_x = 0, e_x_squared = 0, variance;

    //Empirical Mean Calculation
    for(int i = 0; i < 7; i++){
        e_x += i * dices[i];
    }
    e_x /= 1000;
    printf("\nEmpirical Mean: %.3f",e_x);


    for(int i = 0; i < 7; i++){
        e_x_squared += i * i * dices[i];
    }
    e_x_squared /= 1000;

    //Empirical Variance Calculation
    variance = e_x_squared - (e_x*e_x);

    printf("\nEmpirical Variance: %.3f",variance);

}
