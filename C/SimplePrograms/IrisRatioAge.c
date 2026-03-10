/*
 * This program simulates eye dilation data for a number of users.
 * For each user, it randomly generates iris and pupil radii,
 * calculates a dilation ratio using a custom formula, and then
 * classifies the user into an age group (Young, Adult, Elderly)
 * based on the computed dilation ratio.
 */
#include <stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
float dilation_ratio(int IrisRadius, int PupilRadius)
{
    int i;
    float dilation,dilation_ratio=0;
    for(i=1;i<=5;i++)
    {
        dilation=i*i*((IrisRadius)*1.0/(PupilRadius)*1.0);//Multiplying by 1.0 to get a float, i*i to get i^2
        dilation_ratio=dilation_ratio+dilation;
    }
    return dilation_ratio;
}
void display_agegroup(float dilation_ratio)
{
    if(dilation_ratio<200.0)
    {
        printf("  Age=Young");
    }
    else if(dilation_ratio<300.0)
    {
        printf("  Age=Adult");
    }
    else if(dilation_ratio>=300.0)
    {
        printf("  Age=Elderly");
    }
}
int main() {
  int num_users,i;
  int IrisRadius,PupilRadius;
  float dilation;
  printf("\nEnter the number of users:");
  scanf("%d",&num_users);
  srand(time(NULL));
  for(i=0;i<num_users;i++)
  {
    IrisRadius=100+(int)(rand()%(81));
    PupilRadius=10+(int)(rand()%(71));
    printf("\nIris radius = %d,",IrisRadius);
    printf("  Pupil radius = %d, ",PupilRadius);
    dilation= dilation_ratio(IrisRadius,PupilRadius);
    printf("  DilationRatio = %.1f,",dilation);
    display_agegroup(dilation);
  }
}
