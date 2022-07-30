typedef struct score
{
	int red;
	int white;
	int empty;
}hint;


//func.c
void makeCode(char secret[4][10]);
void guess(char guessCode[12][4][10]);
void codeCheck(char secret[4][10], char guessCode[12][4][10], int *redPeg, int *whitePeg);
void displayGuess(char guessCode[12][4][10], int redPeg, int whitePeg);


//colours.c
void red();
void yellow();
void reset();
void white();
void blue();
void green();
void purple();
void reset();
void unknown();