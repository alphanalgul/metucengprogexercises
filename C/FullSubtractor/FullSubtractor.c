#include<stdio.h>
#define LF 10
int main()
{
    int a,b,bin;//variables for base 2
    int a2,b2,bin2;//variables for base 16
    int binary_check;//variable to check if a value is invalid in base 2
    char ch;//char input for base 2
    char ch2;//char input for base 16
    int num_bits;//variable for checking the number of bits in base 2
    int ANANDB,AORB,AXORB,AXORB_NAND_BIN,AXORB_OR_BIN,AXORB_XOR_BIN;//variables for calculating D and Bout
    int D,Bout;//output variables
    int option=0;//variable for the user's choice
    int base=0;//variable for which base to use
    while(option!=2)//menu loop
{
        printf("\nWelcome to Full Subtractor");
        printf("\n(1)Compute and Display the outputs");
        printf("\n(2)Quit");
        printf("\nYou choose:");//Asking users choice
        scanf("%d",&option);//Reading users choice
        if(option==1)//Compute and Display Outputs
        {
         printf("You have chosen option %d",option);
         printf("\nWhich base will you use to enter input(base 2 or base 16)?");//Asking the user which base to use
         scanf("%d",&base);//Reading which base to use
         ch=0;//resetting the variable for base 2
         num_bits=0;//resetting the variable for checking the number of bits in base 2
         binary_check=1;//resetting the variable to check if a value is invalid in base 2
         if(base==2)//Computing and Displaying outputs for base 2
         {
             fflush(stdin);/*resetting the previous inputs so that they can't interfere in the while loop
                         without the fflush  the while loop takes the base value as input and will not function properly*/
          printf("Please enter your input:");//taking the char input for base 2
         while(ch!=LF)//while loop to read characters
         {
             scanf("%c",&ch);//reading the characters
        if(num_bits==0)//checking the first digit
        {
            if(ch==48)//checking if it is 0 (48 is the ASCII value for 0)
                a=0;//assigning 0 to a it ch==48
            if(ch==49)//checking if it is 1 (49 is the ASCII value for 1)
                a=1;//assigning 0 to a it ch==48
        }
        if(num_bits==1)//checking the second digit
        {
             if(ch==48)//checking if it is 0 (48 is the ASCII value for 0)
                b=0;//assigning 0 to b if ch==48
            if(ch==49)//checking if it is 1(49 is the ASCII value for 1)
                b=1;//assigning 1 to b if ch==49
        }
        if(num_bits==2)//checking the third digit
        {
             if(ch==48)//checking if it is 0 (48 is the ASCII value for 0)
                bin=0;//assigning 0 to bin if ch==48
            if(ch==49)//checking if it is 1 (49 is the ASCII value for 1)
                bin=1;//assigning 1 to bin if ch==49
        }
        num_bits++;//incrementing so that the while loop checks every digit in the character
        if(!((ch==48)||(ch==49)||(ch==LF)))//checking if the input is valid in base 2
       {
           binary_check=0;//assigning 0 to binary check to validate if the input is valid  in base 2
       }
         }
       num_bits--;//decrementing because LF(enter) also counts as a digit where it should not be

       if(binary_check==0)//validating if the input is in base 2 or not
       {
           printf("Invalid number in base 2! Please try again");
       }
       else if(num_bits<3)//checking if the number of bits is less than 3
          {
              printf("You entered less than 3 bits! Please try again!");
          }
       else if(num_bits>3)//checking if the number of bits is larger than 3
          {
              printf("You entered more than 3 bits! Please try again!");
          }
       else if((((a==0)||(a==1))&&((b==0)||(b==1))&&((bin==0)||(bin==1))))/*Checking if A B and Bin are valid in base 2
                                                                          and Calculating D and Bout*/
       {
           //XOR GATE Consists of (A NAND B) AND (A OR B)
           ANANDB=(!(a&&b));// Calculating A NAND B
           AORB=(a||b);//Calculating A OR B
           AXORB=(!(a&&b))&&(a||b);//Calculating A XOR B
           AXORB_NAND_BIN=(!(AXORB&&bin));//Calculating (A XOR B) NAND (Bin)
           AXORB_OR_BIN=(AXORB||bin);// Calculating (A XOR B) OR (Bin)
           AXORB_XOR_BIN=(AXORB_NAND_BIN)&&(AXORB_OR_BIN);//Calculating D , D=((A XOR B) NAND Bin) AND ((A XOR B) OR Bin)
           D=AXORB_XOR_BIN;
           Bout=((!a)&&bin)||((!a)&&(b))||((b)&&(bin));//Calculating Bout, Bout= (NOT(A )AND Bin) OR (NOT(A) AND B) OR (B AND Bin)
           printf("D is %d Bout is %d",D,Bout);//Printing D and Bout
       }
            }
        ch2=0;//resetting the variable for base 16
        if(base==16)
        {
        fflush(stdin);/*resetting the previous inputs so that they can't interfere in the while loop
                      without the fflush  the while loop takes the base value as input and will not function properly*/
        printf("Please enter your input:");//taking the char input for base 16
        while(ch2!=LF)//while loop to read characters
         {
             scanf("%c",&ch2);//reading characters
            if(ch2==48)//Converting 0 in base 16 to base 2 (000), 48 is the ASCII value for 0
            {
                a2=0;
                b2=0;
                bin2=0;
            }
            else if(ch2==49)//Converting 1 in base 16 to base 2 (001), 49 is the ASCII value for 1
            {
                a2=0;
                b2=0;
                bin2=1;
            }
            else if(ch2==50)//Converting 2 in base 16 to base 2 (010), 50 is the ASCII value for 2
            {
                a2=0;
                b2=1;
                bin2=0;
            }
            else if(ch2==51)//Converting 3 in base 16 to base 2 (011), 51 is the ASCII value for 3
            {
                a2=0;
                b2=1;
                bin2=1;
            }
            else if(ch2==52)//Converting 4 in base 16 to base 2 (100), 52 is the ASCII value for 4
            {
                a2=1;
                b2=0;
                bin2=0;
            }
            else if(ch2==53)//Converting 5 in base 16 to base 2 (101), 53 is the ASCII value for 5
            {
                a2=1;
                b2=0;
                bin2=1;
            }
            else if(ch2==54)//Converting 6 in base 16 to base 2 (110), 54 is the ASCII value for 6
            {
                a2 = 1;
                b2 = 1;
                bin2 = 0;
            }
            else if(ch2==55)//Converting 7 in base 16 to base 2 (111), 55 is the ASCII value for 7
            {
                a2=1;
                b2=1;
                bin2=1;
            }
            //Checking 8(ch==56) 9(ch==57) A(ch==65) B(ch==66) C(ch==67) D(ch==68) E(ch==69) F(ch==70)
            //These are valid numbers in base 16, but we are unable to convert them to a 3-digit binary number
            else if(ch2==56||ch2==57||ch2==65||ch2==66||ch2==67||ch2==68||ch2==69||ch2==70)
            {
                printf("Not possible to convert it to 3-digit binary number. Please try again!");
            }
            //Checking ASCII Values larger than 70
            //These are invalid in base 16
            else if(ch2>70)
            {
                printf("Invalid number in base 16! Please try again!");
            }

            //Checking ASCII Values between 10 and 48(ASCII Value for 0)
            //These are invalid in base 16
           else if(ch2<48&&ch2>10)
                   {
                     printf("Invalid number in base 16! Please try again!");
                   }
            //Checking ASCII Values less than 10
            //These are invalid in base 16
            else if(ch2<10)
            {
                printf("Invalid number in base 16! Please try again!");
            }
         //Checking if A B and Bin are valid in base 16 and Calculating D and Bout
         if(ch2==48||ch2==49||ch2==50||ch2==51||ch2==52||ch2==53||ch2==54||ch2==55)
         {
           //XOR GATE Consists of (A NAND B) AND (A OR B)
           ANANDB=(!(a2&&b2));// Calculating A NAND B
           AORB=(a2||b2);//Calculating A OR B
           AXORB=(!(a2&&b2))&&(a2||b2);//Calculating A XOR B
           AXORB_NAND_BIN=(!(AXORB&&bin2));//Calculating (A XOR B) NAND (Bin)
           AXORB_OR_BIN=(AXORB||bin2);// Calculating (A XOR B) OR (Bin)
           AXORB_XOR_BIN=(AXORB_NAND_BIN)&&(AXORB_OR_BIN);//Calculating D , D=((A XOR B) NAND Bin) AND ((A XOR B) OR Bin)
           D=AXORB_XOR_BIN;
           Bout=((!a2)&&bin2)||((!a2)&&(b2))||((b2)&&(bin2));//Calculating Bout, Bout= (NOT(A )AND Bin) OR (NOT(A) AND B) OR (B AND Bin)
           printf("D is %d Bout is %d",D,Bout);//Printing D and Bout
         }
         }
        }
        }
       if(option==2)//getting out of the menu loop
         {
         printf("You have chosen option %d",option);
         printf("\nBYEE!!!");
         }
}
return 0;
}
