/*
 * This program simulates a flight booking system with economy and business class seats.
 * - Prompts the user to make bookings until all seats are filled or the user exits.
 * - Economy and business classes are evenly split in total seats.
 * - After booking, calculates total earnings and projects the amount if invested at 25% annual return using recursion.
 * - Recommends future actions based on the return on investment.
 */

#include <stdio.h>
double invest(double money,int years)
{
    if(years==0)
    {
        return money;
    }
    else
    {
        return invest(money,years-1)+invest(money,years-1)*0.25;
    }
}
void recommender(double originalIncome,double investedIncome)
{
    if(investedIncome-originalIncome>900)
    {
        printf("\nPlan more such flights!");
    }
    else if(investedIncome-originalIncome>300)
    {
        printf("\nPlan the flight!");
    }
    else if(investedIncome-originalIncome>0)
    {
        printf("\nCancel the flight!");
    }
}
void menu(void)
{
    printf("\nType 1 for economy");
    printf("\nType 2 for business");
    printf("\nYour choice:");
}
int main() {
    char choice = 0;
    int choice_check=0;
    int n;
    printf("\nEnter an even integer:");
    scanf("%d", &n);
    int array[n];
    int k;
    for(k=0;k<n;k++)//initialising the elements of the array to 0
    {
        array[k]=0;
    }
    while (choice != 'N'&&choice_check!=1) {
        fflush(stdin);
        printf("\nWould you like to do a booking:");
        scanf("%c", &choice);
        int i = 0;
        if (choice == 'Y') {
            int num_economy = n / 2, num_business = n / 2;
            int economy_check = 0, business_check = 0;
            int check1=0,check2=0;
            while (i < n) {
                fflush(stdin);
                menu();
                int booking;
                scanf("%d", &booking);

                if (booking == 1 &&check1!=1 ) {
                    if (economy_check == num_economy&&check1!=1) {
                        printf("\nEconomy class is full! Please try business class!");
                        check1=1;
                    }
                    if(check1!=1) {
                        array[i] = 1;
                        printf("\nYour booking is successfully done in seat %d", i + 1);
                        economy_check++;
                    }
                    }

                else if (booking == 2 && check2!=1) {
                    if (business_check == num_business&&check2!=1) {
                        printf("\nBusiness class is full! Please try economy class!");
                        check2=1;
                    }
                    if(check2!=1) {
                        array[i] = 2;
                        printf("\nYour booking is successfully done in seat %d", i + 1);
                        business_check++;
                    }
                }

                if(i==n-1)
                {
                    i==n;
                }
                i++;
            }

            }
        if (choice != 'Y' && choice != 'N') {
            printf("\nI dont understand!");
        }
        }
    int j;
    int economySeat=0,businessSeat=0;
    for(j=0;j<n;j++)
    {
        if(array[j]==1)
        {
            economySeat++;
        }
        if(array[j]==2)
        {
            businessSeat++;
        }
    }
    double money;
    money=economySeat*100+businessSeat*200;
    printf("\nYou had %d economy and %d business seats booked and you earned %lf",economySeat,businessSeat,money);
    int year;
    printf("\nHow many years would you like to invest this money?");
    scanf("%d",&year);
    double investment;
    investment=invest(money,year);
    printf("\nYou earned %lf and at the end of %d years, you will have %lf",money,year,investment);
    recommender(money,investment);
    printf("\nByee...");
}
