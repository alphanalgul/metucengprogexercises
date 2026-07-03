#include <stdio.h>
#include <math.h>

//LCG constants put here because in the main they didnt work even with unsigned long long
#define a 1664525
#define c 1013904223
#define m 4294967296
int main() {
    unsigned long long seed = 12345;
    double U;
    int lambda= 30;
    double arrival_time = 0;
    int total_minutes = 0,hours,minutes;
    for(int i = 0; i < 10; i++){
        seed = (a*seed+c) % m;
        U = (double)seed / m;//generating uniform random variable

        arrival_time += -lambda*log(1-U);//generating arrival times

        //Computing relevant time hours,minutes to display
        total_minutes += (int)(arrival_time);
        hours = 9 + total_minutes / 60;
        if(hours > 24){
            hours = hours % 24;
        }
        minutes = total_minutes % 60;
        
        printf("\nCustomer %d arrives at %02d:%02d",i+1,hours,minutes);//displaying the result
    }
}
