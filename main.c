#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "headers.h"
#include<time.h>

int guessCount=0;

int main()
{
    srand(time(NULL));
    int i, option=1, redPeg, whitePeg, wrongGuess;
    char secret[4][10], guessCode[12][4][10];  
    reset();
	
	printf("WELCOME TO MASTERMIND!\nRules:\n");
 	printf("1.The opponent randomly selects four colours out of seven and places them in an order.This code is kept hidden from the other player\n");
 	printf("2.The player can now try to guess the code set by the opponent.\n3.The opponent will give feedback on how good their guess was.\n");
 	printf("    i) A red peg denotes that one of the guessed colours is correct and is in the right place.\n");
 	printf("    ii) A white peg denotes that one of the guessed colours is correct but in the wrong place.\n");
 	printf("    iii) No peg means that both the colour and the position is wrong.\n");
 	printf("4.The player now has some information about the code and can try to guess another combination\n");
 	printf("5.The game continues until the code is guessed or there are no more guesses left.\n\n");
  
    printf("MASTER MIND! \nPress 1 to start game \nPress any number to exit\n\n");
    scanf("%d", &option);        
    if(option == 1)
    {
        makeCode(secret);
        for(wrongGuess=1; wrongGuess<=12; wrongGuess++)      //gives 12 rights to guess
        {
            guess(guessCode);
            codeCheck(secret, guessCode, &redPeg, &whitePeg);
            displayGuess(guessCode, redPeg, whitePeg);
            if(redPeg == 4)           //if player guess correct all, than the game finishes
            {
                reset();
                printf("\nYou Win in %d guesses!\n\n\n\n",guessCount);  break;
            }
        }
    if(wrongGuess == 13)     //if player cannot guess correct colors in 12 rounds, he losts
        {
            reset();
            printf("\nYou Lost!\nSecret Code: %s %s %s %s\n\n\n\n\n", secret[0], secret[1], secret[2], secret[3]);
        }  
    }
    else
        exit(1);
}
