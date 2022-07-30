#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "headers.h"
#include<windows.h>
#include<conio.h>

extern int guessCount;
hint scores[12];

void makeCode(char secret[4][10])
{
    int i, colour;
    for(i=0; i<4; i++)  
    {
        colour = 1 + rand() % 6;     //creates a number 
        switch(colour)       //converts number created to a string
        {
            case 1: strcpy(secret[i], "red");       break;
            case 2: strcpy(secret[i], "yellow");    break;
            case 3: strcpy(secret[i], "green");     break;
            case 4: strcpy(secret[i], "blue");      break;
            case 5: strcpy(secret[i], "white");     break;
            case 6: strcpy(secret[i], "purple");    break;
        }
        // printf("%s ",secret[i]);
    }   
}


void guess(char guessCode[12][4][10])
{
    reset();
    printf("\nEnter your guess:\n");
    for(int i=0; i<4; i++)
        scanf("%s", guessCode[guessCount][i]);  
}

void codeCheck(char secret[4][10], char guessCode[12][4][10], int *redPeg, int *whitePeg)
{
    int i, j, checkSecret[4] = {1,1,1,1}, checkGuess[4] = {1,1,1,1};
    *redPeg = *whitePeg = 0;
    

    for(i=0; i<4; i++)      //if secret and guess's position and color are same, redPeg increases and mark "check"
        if(strcmp(guessCode[guessCount][i], secret[i]) == 0)   
        {
            ++*redPeg;
            checkSecret[i] = checkGuess[i] = 0;
        }            

    for(i=0; i<4; i++)
        for(j=0; j<4; j++)       
            if(strcmp(secret[i],guessCode[guessCount][j]) == 0  &&  checkGuess[i]  &&  checkSecret[j]  &&  i != j)        
            {// determines crushes and eliminates extra whitePegs 
                ++*whitePeg;
                checkSecret[j] = checkGuess[i] = 0;
            }
    guessCount++;
    scores[guessCount-1].red = *redPeg;
    scores[guessCount-1].white = *whitePeg;
    if(*redPeg == 0 && *whitePeg == 0) scores[guessCount-1].empty=1;
}

void displayGuess(char guessCode[12][4][10], int redPeg, int whitePeg)
{   
    system("cls");
    int i,j,k;
    printf("\nYour Guesses\t\t\t\tYour Score\n");   
    for(i=0; i<guessCount; i++) 
    {
        for(j=0; j<4; j++)
        {
            if (strcmp("red",guessCode[i][j])==0)
            {
                red();
                printf("%s    ", guessCode[i][j]); 
            }
            else if (strcmp("yellow",guessCode[i][j])==0)
            {
                yellow();
                printf("%s ", guessCode[i][j]); 
            }
            else if (strcmp("blue",guessCode[i][j])==0)
            {
                blue();
                printf("%s   ", guessCode[i][j]); 
            }
            else if (strcmp("green",guessCode[i][j])==0)
            {
                green();
                printf("%s  ",guessCode[i][j]); 
            }
            else if (strcmp("purple",guessCode[i][j])==0)
            {
                purple();
                printf("%s ", guessCode[i][j]); 
            }
            else if (strcmp("white",guessCode[i][j])==0)
            {
                white();
                printf("%s  ", guessCode[i][j]); 
            }
        }

        printf("\t\t");
        for(j=0; j<scores[i].red; j++)
        {   
            red();
            printf("red   ");   
        }
        for(k=0;k<scores[i].white; k++)
        {
            white();
            printf("white ");
        } 
        if(scores[i].empty==1) 
        {   
            reset();
            printf("NULL");
        }
        printf("\n");
    }           
}