/*
 * This program analyzes patient cholesterol levels entered as characters 
 *(D/d, R/r, H/h)
 * and categorizes them into three health groups: Dangerous, At Risk, and Healthy.
 * It calculates and displays the percentage of patients in each category
 * for a specific lab identified by its Lab ID.
 */

#include <stdio.h>

int main() {
    int dangerous = 0, at_risk = 0, healthy = 0;
    float total = 0;
    float dangerous_percent, at_risk_percent, healthy_percent;
    printf("Welcome to Lab!");
    int lab_id;
    printf("\nEnter the lab ID:");
    scanf("%d", &lab_id);
    fflush(stdin);
    char c = 0;
    printf("\nPlease input the cholesterol levels of your patients:");
    while (c != '\n') {
        scanf("%c", &c);

        if (c == 'D' || c == 'd') {
            dangerous++;
        }
        if (c == 'R' || c == 'r') {
            at_risk++;
        }
        if (c == 'H' || c == 'h') {
            healthy++;
        }
    }


    if (dangerous == 0 && at_risk == 0 && healthy == 0) {//To check if the user entered any character
        printf("No Statistics for Lab %d!", lab_id);
    } else {

        total = dangerous + at_risk + healthy;
        dangerous_percent = (dangerous / total) * 100;
        at_risk_percent = (at_risk / total) * 100;
        healthy_percent = (healthy / total) * 100;

        printf("\nStatistics for Lab %d:", lab_id);
        printf("\nDangerous Level: %.1f %%", dangerous_percent);
        printf("\nAt Risk: %.1f %%", at_risk_percent);
        printf("\nHeart Healthy: %.1f %%", healthy_percent);
    }
}
