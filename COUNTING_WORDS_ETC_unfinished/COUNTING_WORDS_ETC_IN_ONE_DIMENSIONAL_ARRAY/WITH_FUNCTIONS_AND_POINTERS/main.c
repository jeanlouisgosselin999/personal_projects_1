/*
This program will count the number of words, vowels, consonants, digits, whitespaces and other characters and symbols
in a line of text entered by the user.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 200

//prototypes:
void scan_line(char [], int *, int *, int *, int *, int *, int *);
void result(int, int, int, int, int, int, int);
void resetCounter();
char continueMenu();

int main(int argc, char *argv[]) {


	char line[MAX];
	char do_again;
	int m, i;
	int sumWord = 0;
	int vowels = 0;
	int consonants = 0;
	int digits = 0;
	int whitespc = 0;
	int other = 0;
	int totalChar;
	
	while (do_again != 'N') { 
	
		printf("Enter a line of text:\n\n");
		for(m=0; (line[m] = getchar()) != '\n'; ++m)
		;
		
		totalChar = m;
				
		//calling our functions (NOTE: the array argument, "line", is not preceded by an &, since arrays are, by definition, pointers)
		scan_line(line, &sumWord, &vowels, &consonants, &digits, &whitespc, &other);
		result(sumWord, vowels, consonants, digits, whitespc, other, totalChar);
		resetCounter(&sumWord, &vowels, &consonants, &digits, &whitespc, &other, &totalChar);
		do_again = continueMenu();
	} 
									
	printf("\nHave a good day!\n\n");
		
	return 0;
}

//FUNCTIONS


void scan_line(char line[], int *psumWords, int *pv, int *pc, int *pd, int *pwhite, int *po) {
	
	char c; //character within the line of text
	int count; //counter of characters in line of text
	int i;
	*psumWords = 0; //termination of the sentence with pressing ENTER will add the last word typed in to the total number of words (see end of function)
			
		for (count=0; (c = toupper(line[count])) != '\n'; ++count) { //NOTE: we set all characters to UPPERCASE, in order to fulfil the condition statements at lines 88 and 91 (and to avoid avoid to check twice the data: for lower- AND upper-case letters)
			
			if (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U')
				++ *pv;
					
				else if (c >= 'B' && c <= 'Z') //sinec we've already sifted through vowels, this will only identify consonants:
					++ *pc;
					
					else if (c >= '0' && c <= '9') {
						++ *pd;
					}
					
						else if (c == ' ') {							
							++ *pwhite;									
							if (count>1) {
								if (line[count-1] == ' ' || 
									line[count-1] == '0' || 
									line[count-1] == '1' || 
									line[count-1] == '2' || 
									line[count-1] == '3' || 
									line[count-1] == '4' || 
									line[count-1] == '5' || 
									line[count-1] == '6' || 
									line[count-1] == '7' || 
									line[count-1] == '8' || 
									line[count-1] == '9')
									*psumWords += 0;
								else
									*psumWords += 1;
									
								if (line[count-1] == 33 ||
									line[count-1] == 46 ||
									line[count-1] == 63)
										*psumWords += 0;
							}	
						}
						
							else if (c == 39) {								
								if (line[count-1] == 'i' || line[count-1] == 'I') 
									*psumWords += 1;
									++ *po;																	
							}
							
								else if (c == 45) {
									++ *po;
									if (line[count-1] != ' ')
										*psumWords += 1;
								}

									
									else {
										++ *po;	
										if ( 
											line[count-1] == '0' || 
											line[count-1] == '1' || 
											line[count-1] == '2' || 
											line[count-1] == '3' || 
											line[count-1] == '4' || 
											line[count-1] == '5' || 
											line[count-1] == '6' || 
											line[count-1] == '7' || 
											line[count-1] == '8' || 
											line[count-1] == '9')
											*psumWords -= 1;
									}							
		}
		
//************************************ exceptional cases **************************************************
		
	//when a sentence starts with "I...": 
	if ((line[0] == 'I' || line[0] == 'i') && line[1] == ' ')
		*psumWords += 1;
	//...or a single digit ("6 is my lucky number..."):	
	if ((line[0] >= '0' && line[0] <= '9') && line[1] == ' ')
		*psumWords += 0;
		
	if (line[count-1] == ' ' ||
		line[count-1] == '0' || 
		line[count-1] == '1' || 
		line[count-1] == '2' || 
		line[count-1] == '3' || 
		line[count-1] == '4' || 
		line[count-1] == '5' || 
		line[count-1] == '6' || 
		line[count-1] == '7' || 
		line[count-1] == '8' ||
		line[count-1] == '9')
		*psumWords -= 1;
		
	if (line[count] == '.') {
		*psumWords -= 1;
		*po -= 1;
	}
	
			
	//this is to count the LAST word typed in and which will be added to the total number of words	
	if (c  == '\n') 
		*psumWords += 1;
	
									
	return;
}

void result(int rWord, int rV, int rC, int rD, int rSp, int rO, int c) {

	printf("\nNumber of words: %d", rWord);
	printf("\nNumber of vowels: %d", rV);
	printf("\nNumber of consonants: %d", rC);
	printf("\nNumber of digits: %d", rD);
	printf("\nNumber of whitespaces: %d", rSp);
	printf("\nNumber of punctuation marks, symbols etc: %d", rO);
	printf("\nTotal number of characters used (including whitespaces): %d", c);
		
	return;
}


void resetCounter(int *pResW, int *pResV, int *pResC, int *pResD, int *RestSp, int *pResO, int *pRtot) {
	
	*pResW = 0;
	*pResV = 0;
	*pResC = 0;
	*pResD = 0;
	*RestSp = 0;
	*pResO = 0;
	*pRtot = 0;
		
	return;
}

char continueMenu() {
		
	printf("\n\nContinue? (Y/N)\n\n");
	char try_again = getchar();
	getchar(); //this is for pressed ENTER key (once Y or N has been pressed)
	printf("\n");
		
	return(try_again);
}

