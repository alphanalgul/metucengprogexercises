
#include <stdio.h>
#include<time.h>
#include<stdlib.h>
int roll_a_dice(void)//Function to roll a dice(roll_a_dice() function)
{
    int dice;
    dice=1+rand()%6;//Generating a number between 1 and 3
    return dice;
}
int play_computer(void)//play_user() function
{
   int comp_score;
   int dice_1,dice_2,dice_3;
   int crag_check_2=0;//Crag and Thirteen has the same sum of dices(13), So this is a variable that is used for differentiating the two
   int i=0;
   while(i!=1) {//Ensuring that the function will only run once
       //Rolling 3 dices
       printf("\nI rolled the dice and I got:");
       printf("\n--->");
       dice_1 = roll_a_dice();
       dice_2 = roll_a_dice();
       dice_3 = roll_a_dice();
       printf("  \n[Dice 1]: %d  [Dice 2]:  %d  [Dice 3]:  %d", dice_1, dice_2, dice_3);
       //Computer will only re-roll if it is close to getting a high straight(i.e, 4 5 6)
       if (dice_1 != 4 && dice_2 == 5 && dice_3 == 6) {//If the dice 2 and dice 3 are 5 and 6 but dice 1 is different(i.e, 1 5 6 or  6 5 6 etc.)
           printf("\nRolled dice 1");
           dice_1 = roll_a_dice();
           printf("  \n[Dice 1]: %d  [Dice 2]:  %d  [Dice 3]:  %d", dice_1, dice_2, dice_3);
       }
       if (dice_1 == 4 && dice_2 != 5 && dice_3 == 6) {//If the dice 1 and dice 3 are 4 and 6 but dice 2 is different(i.e, 4 4 6 or  4 1 6 etc.)
           printf("\nRolled dice 2");
           dice_2 = roll_a_dice();
           printf("  \n[Dice 1]: %d  [Dice 2]:  %d  [Dice 3]:  %d", dice_1, dice_2, dice_3);
       }
       if (dice_1 == 4 && dice_2 == 5 && dice_3 != 6) {//If the dice 1 and dice 2 are 4 and 5 but dice 3 is different(i.e, 4 5 5 or  4 5 3 etc.)
           printf("\nRolled dice 3");
           dice_3 = roll_a_dice();
           printf("  \n[Dice 1]: %d  [Dice 2]:  %d  [Dice 3]:  %d", dice_1, dice_2, dice_3);
       }
       i = 1;
   }
       //Checking for Crag
       if (dice_1 == 6 && dice_2 == 6 && dice_3 == 1) {
           printf("\nCrag!");
           comp_score = 50;
           crag_check_2 = 1;
       }
       else if (dice_1 == 6 && dice_2 == 1 && dice_3 == 6) {
           printf("\nCrag!");
           comp_score = 50;
           crag_check_2 = 1;
       }
       else if (dice_1 == 1 && dice_2 == 6 && dice_3 == 6) {
           printf("\nCrag!");
           comp_score = 50;
           crag_check_2 = 1;
       }
       else if (dice_1 == 5 && dice_2 == 5 && dice_3 == 3) {
           printf("\nCrag!");
           comp_score = 50;
           crag_check_2 = 1;
       }
       else if (dice_1 == 5 && dice_2 == 3 && dice_3 == 5) {
           printf("\nCrag!");
           comp_score = 50;
           crag_check_2 = 1;
       }
       else if (dice_1 == 3 && dice_2 == 5 && dice_3 == 5) {
           printf("\nCrag!");
           comp_score = 50;
           crag_check_2 = 1;
       }
       else if (dice_1 == 5 && dice_2 == 4 && dice_3 == 4) {
           printf("\nCrag!");
           comp_score = 50;
           crag_check_2 = 1;
       }
       else if (dice_1 == 4 && dice_2 == 5 && dice_3 == 4) {
           printf("\nCrag!");
           comp_score = 50;
           crag_check_2 = 1;
       }
       else if (dice_1 == 4 && dice_2 == 4 && dice_3 == 5) {
           printf("\nCrag!");
           comp_score = 50;
           crag_check_2 = 1;
       }
       //Checking for Thirteen
       else if (dice_1 + dice_2 + dice_3 == 13 && crag_check_2 != 1) {
           comp_score = 26;
       }
       //Checking for Three-Of-A-Kind
       else if ((dice_1 == dice_2)&&(dice_1 == dice_3)&&(dice_2 == dice_3)) {
           comp_score = 25;
       }
       //Checking for Low Straight
       else if (dice_1 == 1 && dice_2 == 2 && dice_3 == 3) {
           comp_score = 20;
       }
       //Checking for High Straight
       else if (dice_1 == 4 && dice_2 == 5 && dice_3 == 6) {
           comp_score = 20;
       }
       //Checking for Odd Straight
       else if (dice_1 == 1 && dice_2 == 3 && dice_3 == 5) {
           comp_score = 20;
       }
       //Checking for Even Straight
       else if (dice_1 == 2 && dice_2 == 4 && dice_3 == 6) {
           comp_score = 20;
       }
       //Checking for Sum
       else
       {
           comp_score = dice_1 + dice_2 + dice_3;
       }
       //Printing the score for computer
       printf("\nMy score: %d",comp_score);
       return comp_score;
}
int play_user(void) {//play_user() function
    int user_score;
    int j=0;
    char choice;
    int crag_check=0; //Crag and Thirteen has the same sum of dices(13), So this is a variable that is used for differentiating the two
    int dice_kept_check = 0;//A variable that ensures dices are only rerolled once
    int choice_check = 0;// A variable for controlling when the user enters anything other than Y or N
    int dice_1, dice_2, dice_3;
    int dice_kept_1, dice_kept_2;
    fflush(stdin);
    while(j!=1) {
        //Rolling 3 dices
        fflush(stdin);
        dice_1 = roll_a_dice();
        dice_2 = roll_a_dice();
        dice_3 = roll_a_dice();
        printf("\nYou got--->[Dice 1]: %d  [Dice 2]:  %d  [Dice 3]:  %d", dice_1, dice_2, dice_3);
        fflush(stdin);
        //Asking the user if they want to reroll the dice or not
        printf("\nShall I roll for you(Y/N)?:");
        scanf("%c", &choice);
        fflush(stdin);
        if (choice == 'Y') {//If they say yes
            while (dice_kept_check != 1) {//Ensuring that the user will be able to re-roll only once
                printf("\nWhich ones do you want to keep?");
                scanf("%d %d", &dice_kept_1, &dice_kept_2);
                if (dice_kept_1 < 1 || dice_kept_1 > 3 || dice_kept_2 < 1 || dice_kept_2 > 3) {//If the user enter anything higher than 3
                                                                                               //Since there are only 3 dices
                    printf("\nSorry,wrong input!");
                } else {
                    dice_kept_check = 1;//Setting the condition to 1 to indicate that the dices have been rerolled
                    if (dice_kept_1 == 1 && dice_kept_2 == 2) {//Re-rolling dice 3
                        dice_3=roll_a_dice();
                        printf("\nYou got--->[Dice 1]: %d  [Dice 2]:  %d  [Dice 3]:  %d", dice_1, dice_2,
                               dice_3);
                    }
                    if (dice_kept_1 == 1 && dice_kept_2 == 3) {//Re-rolling dice 2
                        dice_2=roll_a_dice();
                        printf("\nYou got--->[Dice 1]: %d  [Dice 2]:  %d  [Dice 3]:  %d", dice_1, dice_2,
                               dice_3);
                    }
                    if (dice_kept_1 == 2 && dice_kept_2 == 3) {//Re-rolling dice 1
                        dice_1=roll_a_dice();
                        printf("\nYou got--->[Dice 1]: %d  [Dice 2]:  %d  [Dice 3]:  %d", dice_1, dice_2,
                               dice_3);
                    }
                }
            }
        }
        if (choice == 'N') {//If they say no
            //Doing nothing since the answer is no so no dice will be rerolled
        } else if (choice != 'Y' && choice != 'N') {//If the user enters anything other than Y or N
            choice_check=0;//Resetting the control variable if the user again enters anything other than Y or N
            while (choice_check != 1) {//Ensuring that "Sorry I don't understand" and "Shall I roll for you(Y/N)? are not printed twice"
                fflush(stdin);
                printf("\nSorry, I don't understand!");
                printf("\nShall I roll for you(Y/N)?:");
                scanf("%c", &choice);
                fflush(stdin);
                if (choice == 'Y') {//If the user says yes
                    while (dice_kept_check != 1) {
                        printf("\nWhich ones do you want to keep?");
                        scanf("%d %d", &dice_kept_1, &dice_kept_2);
                        if (dice_kept_1 < 1 || dice_kept_1 > 3 || dice_kept_2 < 1 || dice_kept_2 > 3) {
                            printf("\nSorry,wrong input!");
                        } else {
                            dice_kept_check = 1;
                            if (dice_kept_1 == 1 && dice_kept_2 == 2) {
                                dice_3=roll_a_dice();
                                printf("\nYou got--->[Dice 1]: %d  [Dice 2]:  %d  [Dice 3]:  %d", dice_1, dice_2,
                                       dice_3);
                            }
                            if (dice_kept_1 == 1 && dice_kept_2 == 3) {
                                dice_2=roll_a_dice();
                                printf("\nYou got--->[Dice 1]: %d  [Dice 2]:  %d  [Dice 3]:  %d", dice_1, dice_2,
                                       dice_3);
                            }
                            if (dice_kept_1 == 2 && dice_kept_2 == 3) {
                                dice_1=roll_a_dice();
                                printf("\nYou got--->[Dice 1]: %d  [Dice 2]:  %d  [Dice 3]:  %d", dice_1, dice_2,
                                       dice_3);
                            }
                        }
                        choice_check=1;//Ending the loop
                    }
                    choice_check = 1;//Ending the loop
                }
                if (choice == 'N') {//If the user says no
                    choice_check = 1;//Ending the loop
                }
            }
        }
        j=1;
    }
        //Checking for Crag
        if (dice_1 == 6 && dice_2 == 6 && dice_3 == 1) {
            printf("\nCrag!");
            user_score = 50;
            crag_check = 1;//Setting the control variable to 1 so it will not enter the Thirteen condition
        } else if (dice_1 == 6 && dice_2 == 1 && dice_3 == 6) {
            printf("\nCrag!");
            user_score = 50;
            crag_check = 1;//Setting the control variable to 1 so it will not enter the Thirteen condition
        } else if (dice_1 == 1 && dice_2 == 6 && dice_3 == 6) {
            printf("\nCrag!");
            user_score = 50;
            crag_check = 1;//Setting the control variable to 1 so it will not enter the Thirteen condition
        } else if (dice_1 == 5 && dice_2 == 5 && dice_3 == 3) {
            printf("\nCrag!");
            user_score = 50;
            crag_check = 1;//Setting the control variable to 1 so it will not enter the Thirteen condition
        } else if (dice_1 == 5 && dice_2 == 3 && dice_3 == 5) {
            printf("\nCrag!");
            user_score = 50;
            crag_check = 1;//Setting the control variable to 1 so it will not enter the Thirteen condition
        } else if (dice_1 == 3 && dice_2 == 5 && dice_3 == 5) {
            printf("\nCrag!");
            user_score = 50;
            crag_check = 1;//Setting the control variable to 1 so it will not enter the Thirteen condition
        } else if (dice_1 == 5 && dice_2 == 4 && dice_3 == 4) {
            printf("\nCrag!");
            user_score = 50;
            crag_check = 1;//Setting the control variable to 1 so it will not enter the Thirteen condition
        } else if (dice_1 == 4 && dice_2 == 5 && dice_3 == 4) {
            printf("\nCrag!");
            user_score = 50;
            crag_check = 1;//Setting the control variable to 1 so it will not enter the Thirteen condition
        } else if (dice_1 == 4 && dice_2 == 4 && dice_3 == 5) {
            printf("\nCrag!");
            user_score = 50;
            crag_check = 1;//Setting the control variable to 1 so it will not enter the Thirteen condition



        } else if (dice_1 + dice_2 + dice_3 == 13 && crag_check != 1) { //Checking for Thirteen
            user_score = 26;

        } else if (dice_1 == dice_2 && dice_1 == dice_3 && dice_2 == dice_3) {//Checking for Three-Of-A-Kind
            user_score = 25;

        } else if (dice_1 == 1 && dice_2 == 2 && dice_3 == 3) {//Checking for Low Straight
            user_score = 20;

        } else if (dice_1 == 4 && dice_2 == 5 && dice_3 == 6) {//Checking for High Straight
            user_score = 20;

        } else if (dice_1 == 1 && dice_2 == 3 && dice_3 == 5) {//Checking for Odd Straight
            user_score = 20;

        } else if (dice_1 == 2 && dice_2 == 4 && dice_3 == 6) {//Checking for Even Straight
            user_score = 20;

        } else {//Checking for sum
            user_score = dice_1 + dice_2 + dice_3;
        }
        //Printing the scores
    printf("\nYour score:%d",user_score);
    return user_score;
}
void scoresheet(int computer_score,int player_score,int i)//scoresheet() function
{
  printf("\n \nOur scoresheet after round %d",i+1);
  printf("\n \n=============================");
  printf("\n \nMy score: %d      Your score:  %d",computer_score,player_score);
}
int main() {
    int num_rounds,i,j=0;
    int roll_player,roll_comp;
    int player_score,comp_score;
    int total_player_score=0,total_comp_score=0;
    srand(time(NULL));
    printf("Welcome to Crag game");
    printf("\nLet's get started!");
    printf("\nHow many rounds would you like to play:");
    scanf("%d",&num_rounds);
    fflush(stdin);
    while(j!=1) {//Ensuring that If the player and the computer rolls the same dice, it will re-roll and decide who will start
        roll_player = roll_a_dice();
        roll_comp = roll_a_dice();
        if (roll_player == roll_comp) {
            printf("We got the same dice! I will roll again!");
        } else {
            printf("\nI have rolled the dice and got %d! ", roll_comp);
            printf("\nI have rolled the dice for you and you got %d!", roll_player);
            j=1;
        }
    }
    for(i=0;i<num_rounds;i++)//Maintaining the number of rounds
    {
        if(roll_player>roll_comp) {//If the player starts
            printf("\nRound %d -- Your Turn: ",i+1);
            printf("\n=============================");
            player_score=play_user();
            total_player_score=total_player_score+player_score;
            fflush(stdin);
            printf("   Total score:%d",total_player_score);
            printf("\nRound %d -- My Turn:",i+1);
            printf("\n=============================");
            comp_score=play_computer();
            total_comp_score=total_comp_score+comp_score;
            fflush(stdin);
            printf("  Total score:%d",total_comp_score);
            scoresheet(total_comp_score,total_player_score,i);

        }
        if(roll_comp>roll_player)//If the computer starts
        {
            printf("\nRound %d -- My Turn:",i+1);
            printf("\n=============================");
            comp_score=play_computer();
            total_comp_score=total_comp_score+comp_score;
            fflush(stdin);
            printf("  Total score:%d",total_comp_score);
            printf("\nRound %d -- Your Turn:",i+1);
            printf("\n============= ================");
            player_score=play_user();
            total_player_score=total_player_score+player_score;
            fflush(stdin);
            printf("   Total score:%d",total_player_score);
            scoresheet(total_comp_score,total_player_score,i);
        }
    }
    if(total_player_score>total_comp_score)//If the player wins
    {
        printf("\n\nYOU ARE THE WINNER!");
    }
    else if(total_comp_score>total_player_score)//If the computer wins
    {
        printf("\n\nI AM THE WINNER!");
    }
    else//If the scores are equal
    {
        printf("\n\nWE TIED!");
    }

}
