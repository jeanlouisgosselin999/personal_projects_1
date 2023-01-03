#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 1000

void inputString(char*);
void inputChar(char*, int*);
void calcLength(int*, char*);
void initializeComparisonResults(int*, int*);
void changeUpperCase(char*, int*, int*, int*, char*, int*);
void saveAbsentChars(int*, int*, int*, int*, char*, char*);
void printString(char*);
void NULLmessage(int*);
void notify(int*, char*, int*);

int main(int argc, char *argv[]) {
	
	char myArray[MAX], savedCharArray[MAX], absentChars[MAX];
	int length=0, countChange=0, numberOfSavedChars=0, resultsCompare[MAX], countAbsentChars=0, x=0;
			
	inputString(myArray);
	getchar();	
	calcLength(&length, myArray);			
	inputChar(savedCharArray, &numberOfSavedChars);
	initializeComparisonResults(&numberOfSavedChars, resultsCompare);						
	changeUpperCase(myArray, &length, &countChange, &numberOfSavedChars, savedCharArray, resultsCompare);
	saveAbsentChars(&numberOfSavedChars, &countAbsentChars, &x, resultsCompare, absentChars, savedCharArray);
			
	if(countChange == 0)
		NULLmessage(&numberOfSavedChars);
		
		else if(countChange > 0 && countAbsentChars > 0){
			notify(&countAbsentChars, absentChars, &numberOfSavedChars);
			printString(myArray);
		}
		
			else if(countChange > 0 && countAbsentChars == 0)
				printString(myArray);
								
	return 0;
}

void inputString(char* pointer){
	
	printf("Enter string:\n");
	scanf(" %[^\n]s", pointer);
	
	return;
}

void inputChar(char* savedCharArray, int* numberOfSavedChars){
	
	char c, answer;
	int i, probe;
	
	do{		
		printf("\nEnter character to change to uppercase (press 0 to terminate input):\n");
		scanf("%c", &c);
		getchar();
		
		probe=0;
		
		//checking for duplicates:
		for(i=0; i<(*(numberOfSavedChars)); i++){
			if(c == savedCharArray[i]){
				printf("\nCharacter already chosen. Please choose a different character.");
				probe = 1;
			}
		}
		
		if(probe == 0){    
			savedCharArray[*(numberOfSavedChars)] = c;			
			++(*(numberOfSavedChars));
		}
		
	}while(c != '0');
	
	--(*(numberOfSavedChars));
			
	return;
}


void initializeComparisonResults(int* numberOfSavedChars, int* resultsCompare){
	
	int i;
	
	for(i=0; i<(*(numberOfSavedChars)); i++)
		resultsCompare[i] = 0;
		
	return;
}	



void calcLength(int* length, char* ptr) {

	*(length) = strlen(ptr);	
	
	return;
}


void changeUpperCase(char* ptr, int* length, int* countChange, int* numberOfSavedChars, char* savedChar, int* resultsCompare){
	
	int i, j;
	
	for(i=0; i<(*(length)); i++){
		for(j=0; j<(*(numberOfSavedChars)); j++){
			if(*(ptr+i) == (*(savedChar + j))){
				*(ptr+i) -= 32;
				++(*(countChange));
				resultsCompare[j] = 1;
				break;
			}
		}						
	}	
	
	return;
}


void saveAbsentChars(int* numberOfSavedChars, int* countAbsentChars, int* x, int* resultsCompare, char* absentChars, char* savedCharArray){
	
	int i;
	
	for(i=0; i<(*(numberOfSavedChars)); i++)
		if(resultsCompare[i] == 0){
			absentChars[(*(x))] = savedCharArray[i];
			++(*(countAbsentChars));
			++(*(x));
		}	
	
	return;
}


void NULLmessage(int* numberOfSavedChars){
	
	if(*(numberOfSavedChars) == 1)	
		printf("\nSorry: the character you have chosen is not present in the string.\nString remains unchanged.");
	else if(*(numberOfSavedChars) > 1)	
		printf("\nSorry: none of the characters you have chosen are present in the string.\nString remains unchanged.");
		
	return;
}

void printString(char* p){

	printf("\nYour changed string:\n\n");
	printf("%s\n\n", p);	
	
	return;
}


void notify(int* countAbsentChars, char* absentChars, int* numberOfSavedChars){
	
	int i;
	
	if(*(countAbsentChars) == 1){
		printf("\n\nSorry: this character is not present in the string:\n");
		printf("%c\n", absentChars[0]);
	}
	
		else if(*(countAbsentChars) > 1){
			printf("\n\nSorry: these characters are not present in the string:\n");
			for(i=0; i<(*(countAbsentChars)); i++)
				printf("%c\n", absentChars[i]);	
		}
	
	if(*(numberOfSavedChars) == 1)
		printf("\nHowever the chosen character has been set to uppercase.\n");
	
		else if(*(numberOfSavedChars) > 1)
			printf("\nHowever all other chosen characters have been set to uppercase.\n");
			
	return;	
}

