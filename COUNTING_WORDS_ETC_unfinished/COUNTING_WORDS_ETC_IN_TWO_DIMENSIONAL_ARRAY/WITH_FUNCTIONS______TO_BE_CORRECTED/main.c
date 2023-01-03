#include <stdio.h>
#include <stdlib.h>

#define MAXROW 5
#define MAXCOL 20

//prototypes:
int numRows();
int numCols();
void scan_line(char [MAXROW][MAXCOL], int *, int *, int *, int *, int *, int *, int *, int *);
void result(int, int, int, int, int, int);
void resetCounter();
char continueMenu();

int main(int argc, char *argv[]) {

	char c, do_again, myArray[MAXROW][MAXCOL];
	int nrows=0, ncols=0;
	int a, b, x, y;
	int sumWords = 0;
	int vowels = 0;
	int consonants = 0;
	int digits = 0;
	int whitespc = 0;
	int other = 0;
	
	while (do_again != 'N') { 
	
		//MUST assign values to number of rows and columns, in order to initialize the 2-D array:
		nrows = numRows(nrows);		
		ncols = numCols(ncols);

		printf("Enter several lines of text:\n");	
		//enter lines of text:	
		for(a=0; a<nrows; ++a)	
			for(b=0; b<ncols; ++b)		
				scanf("%c", &myArray[a][b]);
				
		//calling our functions (NOTE: the array argument, "line", is not preceded by an &, since arrays are, by definition, pointers)
		scan_line(myArray, &nrows, &ncols, &sumWords, &vowels, &consonants, &digits, &whitespc, &other);
		result(sumWords, vowels, consonants, digits, whitespc, other);
		resetCounter(&nrows, &ncols, &sumWords, &vowels, &consonants, &digits, &whitespc, &other);
		do_again = continueMenu();
	
	} 
									
	printf("\nHave a good day!\n\n");
		
	return 0;
}

//FUNCTIONS

int numRows() {
	
	int var1;
	
	printf("How many rows?\n");
		scanf("%d", &var1);		
		
	return (var1);
	
}

int numCols() {
	
	int var2;
	
	printf("How many columns?\n");
		scanf("%d", &var2);
		
	return (var2);
	
}

void scan_line(char line[MAXROW][MAXCOL], int *nr, int *nc, int *psumWords, int *pv, int *pc, int *pd, int *pwhite, int *po) {
	
	char c; //character within the line of text
	int a, b; //counter of characters in line of text
	int i;
	*psumWords = 0; //termination of the sentence with pressing ENTER will add the last word typed in to the total number of words (see end of function)
			
	for (a=0; a<*nr; ++a) { //NOTE: we set all characters to UPPERCASE, in order to fulfil the condition statements at lines 88 and 91 (and to avoid avoid to check twice the data: for lower- AND upper-case letters)
			
		for (b=0; b<*nc; ++b) {
			
			if (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U')
				++ *pv;
					
				else if (c >= 'B' && c <= 'Z') //sinec we've already sifted through vowels, this will only identify consonants:
					++ *pc;
					
					else if (c >= '0' && c <= '9') {
						++ *pd;
					}
					
						else if (c == ' ') {							
							++ *pwhite;									
							if (b>1) {
								if (line[a][b-1] == ' ' || 
									line[a][b-1] == '0' || 
									line[a][b-1] == '1' || 
									line[a][b-1] == '2' || 
									line[a][b-1] == '3' || 
									line[a][b-1] == '4' || 
									line[a][b-1] == '5' || 
									line[a][b-1] == '6' || 
									line[a][b-1] == '7' || 
									line[a][b-1] == '8' || 
									line[a][b-1] == '9')
									*psumWords += 0;
								else
									*psumWords += 1;
									
								if (line[a][b-1] == 33 ||
									line[a][b-1] == 46 ||
									line[a][b-1] == 63)
										*psumWords += 0;
							}	
						}
						
							else if (c == 39) {								
								if (line[a][b-1] == 'i' || line[a][b-1] == 'I') 
									*psumWords += 1;
									++ *po;																	
							}
							
								else if (c == 45) {
									++ *po;
									if (line[a][b-1] != ' ')
										*psumWords += 1;
								}

									
									else {
										++ *po;	
										if ( 
											line[a][b-1] == '0' || 
											line[a][b-1] == '1' || 
											line[a][b-1] == '2' || 
											line[a][b-1] == '3' || 
											line[a][b-1] == '4' || 
											line[a][b-1] == '5' || 
											line[a][b-1] == '6' || 
											line[a][b-1] == '7' || 
											line[a][b-1] == '8' || 
											line[a][b-1] == '9')
											*psumWords -= 1;
									}			
		}
	}
		
//************************************ exceptional cases **************************************************
		
	//when a sentence starts with "I...": 
	if ((line[a][0] == 'I' || line[a][0] == 'i') && line[a][1] == ' ')
		*psumWords += 1;
	//...or a single digit ("6 is my lucky number..."):	
	if ((line[a][0] >= '0' && line[a][0] <= '9') && line[a][1] == ' ')
		*psumWords += 0;
		
	if (line[a][b-1] == ' ' ||
		line[a][b-1] == '0' || 
		line[a][b-1] == '1' || 
		line[a][b-1] == '2' || 
		line[a][b-1] == '3' || 
		line[a][b-1] == '4' || 
		line[a][b-1] == '5' || 
		line[a][b-1] == '6' || 
		line[a][b-1] == '7' || 
		line[a][b-1] == '8' ||
		line[a][b-1] == '9')
		*psumWords -= 1;
		
	if (line[a][b] == '.') {
		*psumWords -= 1;
		*po -= 1;
	}
	
			
	//this is to b the LAST word typed in and which will be added to the total number of words	
	if (c  == '\n') 
		*psumWords += 1;
	
									
	return;
}

void result(int rWord, int rV, int rC, int rD, int rSp, int rO) {

	printf("\nNumber of words: %d", rWord);
	printf("\nNumber of vowels: %d", rV);
	printf("\nNumber of consonants: %d", rC);
	printf("\nNumber of digits: %d", rD);
	printf("\nNumber of whitespaces: %d", rSp);
	printf("\nNumber of punctuation marks, symbols etc: %d", rO);
		
	return;
}


void resetCounter(int *nr, int *nc, int *pResW, int *pResV, int *pResC, int *pResD, int *RestSp, int *pResO) {
	
	*nr = 0;
	*nc = 0;
	*pResW = 0;
	*pResV = 0;
	*pResC = 0;
	*pResD = 0;
	*RestSp = 0;
	*pResO = 0;
		
	return;
}

char continueMenu() {
		
	printf("\n\nContinue? (Y/N)\n\n");
	char try_again = getchar();
	getchar(); //this is for pressed ENTER key (once Y or N has been pressed)
	printf("\n");
		
	return(try_again);
}

