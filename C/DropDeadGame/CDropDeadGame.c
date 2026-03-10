
#include <stdio.h>
#include<stdlib.h>
#include<time.h>
int roll_a_dice()//roll a dice() function
{
    int dice;
    dice=rand()%6+1;//generating a random  number between 1 and 6
    return dice;
}
int play_computer(total_score_computer)//play_computer() function
{
    int i;
    int dice;
    int dice1,dice2,dice3,dice4,dice5;//a variable for each dice
    int check1=0,check2=0,check3=0,check4=0,check5=0;//a check for each dice to determine if its excluded or not
    int check_dropdead=0;//a check to make sure that the function runs until all dices are excluded
    int dice_excluded=0;//a check to make sure that when a dice is excluded the score is 0
    int score=0;
    int num_rounds;
    int j;
    while(check_dropdead!=1)
    {
        printf("\nI got:");
        dice_excluded=0;
        score=0;
        for(i=0;i<5;i++)//rolling 5 dices
        {
            dice=roll_a_dice();
            if(i==0&&check1!=1)//assigning the first rolled dice to dice1 and checking if this dice is excluded or not
            {
                dice1=dice;
                printf("\n[Dice %d ]:%d\t",i+1,dice1);;
                if(dice1==2||dice1==5)//checking if the dice1 is 2 or 5
                {
                    printf("Dice 1 is excluded");
                    check1=1;//excluding dice1
                    dice_excluded=1;
                }
                else if(check1!=1)
                {
                    score=score+dice1;//calculating the score
                }
            }
            if(i==1&&check2!=1)//assigning the second rolled dice to dice2 and checking if this dice is excluded or not
            {
                dice2=dice;
                printf("\n[Dice %d ]:%d\t",i+1,dice2);
                if(dice2==2||dice2==5)//checking if the dice2 is 2 or 5
                {
                    printf("Dice 2 is excluded");
                    check2=1;//excluding dice2
                    dice_excluded=1;
                }
                else if(check2!=1)
                {
                    score=score+dice2;//calculating the score
                }
            }
            if(i==2&&check3!=1)//assigning the third rolled dice to dice3 and checking if this dice is excluded or not
            {
                dice3=dice;
                printf("\n[Dice %d ]:%d\t",i+1,dice3);
                if(dice3==2||dice3==5)//checking if the dice3 is 2 or 5
                {
                    printf("Dice 3 is excluded");
                    check3=1;//excluding dice3
                    dice_excluded=1;
                }
                else if(check3!=1)
                {
                    score=score+dice3;//calculating the score
                }
            }
            if(i==3&&check4!=1)//assigning the fourth rolled dice to dice4 and checking if this dice is excluded or not
            {
                dice4=dice;
                printf("\n[Dice %d ]:%d\t",i+1,dice4);
                if(dice4==2||dice4==5)//checking if the dice4 is 2 or 5
                {
                    printf("Dice 4 is excluded");
                    check4=1;//excluding dice4
                    dice_excluded=1;
                }
                else if(check4!=1)
                {
                    score=score+dice4;//calculating the score
                }
            }
            if(i==4&&check5!=1)//assigning the fifth rolled dice to dice5 and checking if this dice is excluded or not
            {
                dice5=dice;
                printf("\n[Dice %d ]:%d\t",i+1,dice5);
                if(dice5==2||dice5==5)//checking if the dice5 is 2 or 5
                {
                    printf("Dice 5 is excluded");
                    check5=1;//excluding dice5
                    dice_excluded=1;
                }
                else if(check5!=1)
                {
                    score=score+dice5;//calculating the score
                }
            }
            if(dice_excluded==1)//condition to make sure that when a dice is excluded score is 0
            {
                score=0;
            }
            if(check1==1&&check2==1&&check3==1&&check4==1&&check5==1&&check_dropdead!=1)//when all dices are excluded it should print Drop Dead
            {
                printf("\nDrop Dead!");
                check_dropdead=1;
            }
        }
        printf("\nMy score: %d",score);
        total_score_computer=total_score_computer+score;
        printf("\nTotal score: %d",total_score_computer);
    }
    return total_score_computer;//returning the total score for the computer
}
int play_user(total_score_user)//play user() function
{
    int i;
    int dice;
    int dice1,dice2,dice3,dice4,dice5;//a variable for each dice
    int check1=0,check2=0,check3=0,check4=0,check5=0;//a check for each dice to determine if its excluded or not
    int check_dropdead=0;//a check to make sure that the function runs until all dices are excluded
    int dice_excluded=0;//a check to make sure that when a dice is excluded the score is 0
    int score=0;
    int num_rounds;
    int j;
    printf("\nAre you ready to play!");
    while(check_dropdead!=1)
    {
        printf("\nI rolled and you got:");
        dice_excluded=0;
        score=0;
        for(i=0;i<5;i++)//rolling 5 dices
        {
            dice=roll_a_dice();
            if(i==0&&check1!=1)//assigning the first rolled dice to dice1 and checking if this dice is excluded or not
            {
                dice1=dice;
                printf("\n[Dice %d ]:%d\t",i+1,dice1);;
                if(dice1==2||dice1==5)//checking if the dice1 is 2 or 5
                {
                    printf("Dice 1 is excluded");
                    check1=1;//excluding dice1
                    dice_excluded=1;
                }
                else if(check1!=1)
                {
                    score=score+dice1;//calculating the score
                }
            }
            if(i==1&&check2!=1)//assigning the second rolled dice to dice2 and checking if this dice is excluded or not
            {
                dice2=dice;
                printf("\n[Dice %d ]:%d\t",i+1,dice2);
                if(dice2==2||dice2==5)//checking if the dice2 is 2 or 5
                {
                    printf("Dice 2 is excluded");
                    check2=1;//excluding dice2
                    dice_excluded=1;
                }
                else if(check2!=1)
                {
                    score=score+dice2;//calculating the score
                }
            }
            if(i==2&&check3!=1)//assigning the third rolled dice to dice3 and checking if this dice is excluded or not
            {
                dice3=dice;
                printf("\n[Dice %d ]:%d\t",i+1,dice3);
                if(dice3==2||dice3==5)//checking if the dice3 is 2 or 5
                {
                    printf("Dice 3 is excluded");
                    check3=1;//excluding dice3
                    dice_excluded=1;
                }
                else if(check3!=1)
                {
                    score=score+dice3;//calculating the score
                }
            }
            if(i==3&&check4!=1)//assigning the fourth rolled dice to dice4 and checking if this dice is excluded or not
            {
                dice4=dice;
                printf("\n[Dice %d ]:%d\t",i+1,dice4);
                if(dice4==2||dice4==5)//checking if the dice4 is 2 or 5
                {
                    printf("Dice 4 is excluded");
                    check4=1;//excluding dice4
                    dice_excluded=1;
                }
                else if(check4!=1)
                {
                    score=score+dice4;//calculating the score
                }
            }
            if(i==4&&check5!=1)//assigning the fifth rolled dice to dice5 and checking if this dice is excluded or not
            {
                dice5=dice;
                printf("\n[Dice %d ]:%d\t",i+1,dice5);
                if(dice5==2||dice5==5)//checking if the dice5 is 2 or 5
                {
                    printf("Dice 5 is excluded");
                    check5=1;//excluding dice5
                    dice_excluded=1;
                }
                else if(check5!=1)
                {
                    score=score+dice5;//calculating the score
                }
            }
            if(dice_excluded==1)//condition to make sure that when a dice is excluded score is 0
            {
                score=0;
            }
            if(check1==1&&check2==1&&check3==1&&check4==1&&check5==1&&check_dropdead!=1)//when all dices are excluded it should print Drop Dead
            {
                printf("\nDrop Dead!");
                check_dropdead=1;
            }
        }
        printf("\nYour score: %d",score);
        total_score_user=total_score_user+score;
        printf("\nTotal score: %d",total_score_user);
    }
    return total_score_user;//returning the total score for the function
}
void scoresheet(total_score_computer,total_score_user,i)//scoresheet() function
{
    //It takes total score of the computer and the total score of the user and prints them round by round
    printf("\nOur scoresheet after round %d is:",i+1);
    printf("\n======================================");
    printf("\nMy score is: %d",total_score_computer);//printing the total score of the computer at the end of each round
    printf("\nYour score is : %d",total_score_user);//printing the total score of the  user at the end of the each round
}
int main()
{
    srand(time(NULL));
    int total_score_user,total_score_computer;
    total_score_user=0;
    total_score_computer=0;
    int num_rounds;
    printf("Welcome to the Drop Dead game.");
    printf("\nLet's get started!");
    printf("\nHow many rounds would you like to play?");
    scanf("%d",&num_rounds);
    int starting_dice_user,starting_dice_computer,i,j;
    starting_dice_user=roll_a_dice();
    starting_dice_computer=roll_a_dice();
    //rolling 2 dices 1 for the computer and 1 for the user to determine who will start first
    for(i=0;i<num_rounds;i++)
    {
        if(starting_dice_user>starting_dice_computer)//user will start first
        {
            total_score_user=play_user(total_score_user);
            total_score_computer=play_computer(total_score_computer);
            scoresheet(total_score_computer,total_score_user,i);

        }
        else//computer will start first
        {
            total_score_computer=play_computer(total_score_computer);
            total_score_user=play_user(total_score_user);
            scoresheet(total_score_computer,total_score_user,i);
        }
    }
    fflush(stdin);
    if(total_score_computer>total_score_user)
    {
        printf("\nI AM THE WINNER!");
    }
    if(total_score_user>total_score_computer)
    {
        printf("\nYou are the winner");
    }
}
