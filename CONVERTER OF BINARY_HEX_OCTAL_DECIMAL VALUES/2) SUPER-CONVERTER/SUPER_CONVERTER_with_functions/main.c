
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX 40

void introMessage();
void menu(char*);

void inputDecimal(int*);
void inputBinary(int*, char*);
void inputOctal(int*, char*);
void inputHex(int*, char*);
 
void swapBinary(int*, char*);
void swapOctal1(int*, char*);
void swapOctal2(int*, char*); //***
void swapHex1(int*, char*);
void swapHex2(int*, char*); //***

void convertDecBinary(int*, int*, char*);
void convertDecOctal(int*, int*, int*, char*);
void convertDecHex(int*, int*, int*, int*, int*, char*);
void convertBinaryDec(int*, int*, char*);
void convertOctDec(int*, int*, char*);
void convertHexDec(int*, int*, char*);

void printDecimal(int*);
void printBinary(int*, int*, char*);
void printOctal(int*, int*, char*);
void printHex(int*, int*, char*);

/*
the reason we have added a second "swapOctal" and "swapHex" function is because we need to do - 1 to the length of both the octal
and hexadecimal expressions in order to get rid of the "Enter" value.								
*/

int main(int argc, char *argv[]) {	

		int i=0, x=0, nDiv=0, numDiv=0, decimal=0, lengthHex=0, divResult=0, lengthOctal=0, lengthBinary=0;	
		char do_again, answer, hexLine[MAX], binaryLine[MAX], octalLine[MAX];

		introMessage();
	
		menu(&answer);
		
		if (answer == 'a' || answer == 'b' || answer == 'c' || answer == 'd' || answer == 'e') {
		
			switch(answer) {
				
					case 'a':
								inputDecimal(&decimal);
								divResult = decimal;	
								convertDecBinary(&divResult, &lengthBinary, binaryLine);
								swapBinary(&lengthBinary, binaryLine);
								printBinary(&decimal, &lengthBinary, binaryLine);
								convertDecOctal(&decimal, &numDiv, &lengthOctal, octalLine);
								swapOctal1(&lengthOctal, octalLine);
								printOctal(&decimal, &lengthOctal, octalLine);
								nDiv = decimal;
								convertDecHex(&nDiv, &i, &x, &lengthHex, &decimal, hexLine);
								swapHex1(&lengthHex, hexLine);
								printHex(&decimal, &lengthHex, hexLine);					
								break;
							
					case 'b':								
								inputBinary(&lengthBinary, binaryLine);									
								swapBinary(&lengthBinary, binaryLine);							
								convertBinaryDec(&lengthBinary, &decimal, binaryLine);					
								printDecimal(&decimal);
								convertDecOctal(&decimal, &numDiv, &lengthOctal, octalLine);
								swapOctal1(&lengthOctal, octalLine);
								printOctal(&decimal, &lengthOctal, octalLine);
								nDiv = decimal;
								convertDecHex(&nDiv, &i, &x, &lengthHex, &decimal, hexLine);
								swapHex1(&lengthHex, hexLine);
								printHex(&decimal, &lengthHex, hexLine);								
								break;
								
					case 'c':
								inputOctal(&lengthOctal, octalLine);									
								swapOctal2(&lengthOctal, octalLine);														
								convertOctDec(&lengthOctal, &decimal, octalLine);	
								printDecimal(&decimal);
								printf("\n");
								divResult = decimal;	
								convertDecBinary(&divResult, &lengthBinary, binaryLine);
								swapBinary(&lengthBinary, binaryLine);
								printBinary(&decimal, &lengthBinary, binaryLine);
								printf("\n\n");
								nDiv = decimal;
								convertDecHex(&nDiv, &i, &x, &lengthHex, &decimal, hexLine);
								swapHex1(&lengthHex, hexLine);
								printHex(&decimal, &lengthHex, hexLine);																
								break;
								
					case 'd':
								inputHex(&lengthHex, hexLine);
								swapHex2(&lengthHex, hexLine);														
								convertHexDec(&lengthHex, &decimal, hexLine);							
								printDecimal(&decimal);
								printf("\n");
								divResult = decimal;	
								convertDecBinary(&divResult, &lengthBinary, binaryLine);
								swapBinary(&lengthBinary, binaryLine);
								printBinary(&decimal, &lengthBinary, binaryLine);								
								convertDecOctal(&decimal, &numDiv, &lengthOctal, octalLine);
								swapOctal1(&lengthOctal, octalLine);
								printOctal(&decimal, &lengthOctal, octalLine);								
								break;
																						
					case 'e':
								printf("\nYou have chosen to exit the programme.\n");		
								break;									
			}			
		}
		
		else
			printf("\n\nError! Invalid choice.\n\n");
			
	printf("\nEnd of programme.");	
		
	return 0;
}


void introMessage(){
	
	printf("This is a decimal/octal/binary/hexadecimal converter.\n\n");
	printf("Choose one of five following options:\n\n");
		
	return;
}


void menu(char* answer) {
	
	printf("Press (a) to enter a decimal expression;\n");
	printf("Press (b) to enter a binary number;\n");
	printf("Press (c) to enter an octal expression;\n");
	printf("Press (d) to enter a hexidecimal expression;\n");
	printf("Press (e) to exit.\n");
	
	scanf("%c", answer);
	getchar(); //this is for pressed ENTER key
	
	return;
}

/*****************************************************************************************************
*																								     *
*																								     *
*										INPUT functions 											 *
*																								     *
*																								     *
*****************************************************************************************************/

void inputDecimal(int* decimal) {
	
	printf("Enter an integer:\n");
	scanf("%d", decimal);
	
	return;
}

void inputBinary(int* lengthBinary, char* binaryLine) {
	
	printf("Enter your series of 1s and 0s:\n");
	for((*(lengthBinary))=0; (binaryLine[(*(lengthBinary))] = getchar()) != '\n'; ++(*(lengthBinary)))
	;
	
	return;	
}

void inputOctal(int* lengthOct, char* octVals) {
	
	printf("\n\nEnter a series of octal value:");
	printf("\n(Remember: numbers 8 and 9 not allowed in octal values.)\n\n");
	for((*(lengthOct))=0; (octVals[*(lengthOct)] = getchar()) != '\n'; ++(*(lengthOct)))
	;

	return;	
}

void inputHex(int* lengthHex, char* hexVals) {
	
	printf("Enter a series of hexadecimal numbers:\n\n");
	printf("REMINDER! these are:\n0, 1, 2, 3, 4, 5, 6, 7, 8, 9, A=10, B=11, C=12, D=13, E=14, F=15\n");
	for((*(lengthHex))=0; (hexVals[*(lengthHex)] = getchar()) != '\n'; ++(*(lengthHex)))
	;

	return;
}

/*****************************************************************************************************
*																								     *
*																								     *
*										SWAP functions 											 	 *
*																								     *
*																								     *
*****************************************************************************************************/


void swapBinary(int* lengthBinary, char* binaryLine){
	
	char temp;
	int l=0, k=0;
	
	l = (*(lengthBinary))-1; //---> HERE: -1 to get rid of "Enter" value 
	
	while(k<=l) {
		temp = binaryLine[l];
		binaryLine[l] = binaryLine[k];
		binaryLine[k] = temp;
		++k;
		--l;
	}
		
	return;
}

void swapOctal1(int* lengthOctal, char* octalLine){
	
	int k = (*(lengthOctal));
	int j=0;
	char temp; 
	
	while(j<=k) {
		temp = octalLine[k];
		octalLine[k] = octalLine[j];
		octalLine[j] = temp;
		++j;
		--k;
	}	
	return;
}

void swapOctal2(int* lengthOctal, char* octalLine){

	int k = (*(lengthOctal))-1; //---> HERE: -1 to get rid of "Enter" value 
	int j=0;
	char temp; 
	
	while(j<=k) {
		temp = octalLine[k];
		octalLine[k] = octalLine[j];
		octalLine[j] = temp;
		++j;
		--k;
	}	
	return;		
}

void swapHex1(int* lengthHex, char* hexLine){
	
	int k=0, j=0;
	k = (*(lengthHex));
	char temp;
	
	while(j<=k) {
		temp = hexLine[k];
		hexLine[k] = hexLine[j];
		hexLine[j] = temp;
		++j;
		--k;
	}
	
	return;
}

void swapHex2(int* lengthHex, char* hexLine){
	
	int k=0, j=0;
	k = (*(lengthHex))-1; //---> HERE: -1 to get rid of "Enter" value 
	char temp;
	
	while(j<=k) {
		temp = hexLine[k];
		hexLine[k] = hexLine[j];
		hexLine[j] = temp;
		++j;
		--k;
	}
	
	return;
}

/*****************************************************************************************************
*																								     *
*																								     *
*										CONVERSION functions 										 *
*																								     *
*																								     *
*****************************************************************************************************/


void convertBinaryDec(int* lengthBinary, int* totalSum, char* binaryLine) {
	
	int i;

	for(i=0; i<=(*(lengthBinary)); ++i) {
		if (binaryLine[i] == '1')
			(*(totalSum)) += pow(2.0, i);
	}	
	return;	
}

void convertDecOctal(int* decimal, int* numDiv, int* lengthOctal, char* octalLine){
	
	int r;
		
	(*(numDiv)) = (*(decimal));
	
	while((*(numDiv)) >= 8) { 
		r = (*(numDiv)) % 8;
		octalLine[*(lengthOctal)] = '0' + r; //--> formula for casting int to char
		(*(numDiv)) /= 8;
		++(*(lengthOctal));	
	}
	octalLine[*(lengthOctal)] = '0' + (*(numDiv));
		
	return;
}


void convertDecHex(int* nDiv, int* i, int* x, int* lengthHex, int* decimal, char* hexLine){
	
	int rem=0;
	
	//case (A): decimals from 0 to 15
	
	if ((*(nDiv))<16){
		
		if ((*(nDiv))<10){
			printf("\n\nThe hexadecimal equivalent of %d is: %d", (*(decimal)), (*(nDiv)));
			printf("\n\n");
		}
		
		else {	
			if ((*(nDiv))==10)	
				hexLine[0] = 'A';
			if ((*(nDiv))==11)	
				hexLine[0] = 'B';
			if ((*(nDiv))==12)	
				hexLine[0] = 'C';
			if ((*(nDiv))==13)	
				hexLine[0] = 'D';
			if ((*(nDiv))==14)	
				hexLine[0] = 'E';
			if ((*(nDiv))==15)	
				hexLine[0] = 'F';
				
			printf("\n\nThe hexadecimal equivalent of %d is: ", (*(nDiv)));
			printf("%c", hexLine[0]);
			printf("\n\n");
		}
	}			
	
	//case (B): decimals from 16 upwards
	else {
		
		//saving characters in a loop, as long as the 
		while ((*(nDiv))>=16) {
			
			rem = (*(nDiv)) % 16;
			
			//situation 1:
			if (rem != 10 && rem != 11 && rem != 12 && rem != 13 && rem != 14 && rem != 15)
				hexLine[*(i)] = '0' + rem;
			
			//situation 2:		
			else {
				if (rem==10)	
					hexLine[*(i)] = 'A';
				if (rem==11)
					hexLine[*(i)] = 'B';
				if (rem==12)	
					hexLine[*(i)] = 'C';
				if (rem==13)	
					hexLine[*(i)] = 'D';
				if (rem==14)	
					hexLine[*(i)] = 'E';
				if (rem==15)	
					hexLine[*(i)] = 'F';	
			}
			
			(*(nDiv)) /= 16;
			++(*(i));
		}
		
		(*(x)) = (*(i));
		
		if ((*(nDiv))>=10 && (*(nDiv))<=15) {
			
			if ((*(nDiv))==10)	
				hexLine[*(x)] = 'A';
			if ((*(nDiv))==11)
				hexLine[*(x)] = 'B';
			if ((*(nDiv))==12)	
				hexLine[*(x)] = 'C';
			if ((*(nDiv))==13)	
				hexLine[*(x)] = 'D';
			if ((*(nDiv))==14)	
				hexLine[*(x)] = 'E';
			if ((*(nDiv))==15)	
				hexLine[*(x)] = 'F';
		}	
		else
			hexLine[*(x)] = '0' + (*(nDiv));
		
		(*(lengthHex)) = (*(i));
	}
	
	return;
}

void convertOctDec(int* lengthOct, int* decimal, char* octVals) {
	
	int n;
	
	for(n=0; n<(*(lengthOct)); n++) {
		
		if (octVals[n] >= 48 && octVals[n] <= 55) { //--->for numbers 1 to 7, ie: from ASCII values 48 to 55
			
			if (octVals[n] == '0')
				(*(decimal)) += 0;
			if (octVals[n] == '1')
				(*(decimal)) += pow(8.0, n);
			if (octVals[n] == '2')
				(*(decimal)) += 2*(pow(8.0, n));
			if (octVals[n] == '3')
				(*(decimal)) += 3*(pow(8.0, n));
			if (octVals[n] == '4')
				(*(decimal)) += 4*(pow(8.0, n));
			if (octVals[n] == '5')
				(*(decimal)) += 5*(pow(8.0, n));
			if (octVals[n] == '6')
				(*(decimal)) += 6*(pow(8.0, n));
			if (octVals[n] == '7')
				(*(decimal)) += 7*(pow(8.0, n));
		}
		
		else {
			printf("Error! Not an octal value.");
			break;
		}		
	}	
	return;	
}

void convertDecBinary(int* divResult, int* i, char* binaryLine){
	
	while ((*(divResult)) != 0) {
		
		((*(divResult))%2 == 0) ? ((*(divResult)) /= 2, binaryLine[(*(i))] = '0') : ((*(divResult)) /= 2, binaryLine[(*(i))] = '1');

		++(*(i));
	}	
	return;
}

void convertHexDec(int* lengthHex, int* sumHex, char* hexVals) {
	
	int n;
	
	for(n=0; n<(*(lengthHex)); ++n) {
		
		if ((hexVals[n] >= 48 && hexVals[n] <= 57) || (hexVals[n] >= 65 && hexVals[n] <= 70)) {
			
			if (hexVals[n] == '0')
				(*(sumHex)) += 1;
			if (hexVals[n] == '1')
				(*(sumHex)) += pow(16.0, n);
			if (hexVals[n] == '2')
				(*(sumHex)) += 2*(pow(16.0, n));
			if (hexVals[n] == '3')
				(*(sumHex)) += 3*(pow(16.0, n));
			if (hexVals[n] == '4')
				(*(sumHex)) += 4*(pow(16.0, n));
			if (hexVals[n] == '5')
				(*(sumHex)) += 5*(pow(16.0, n));
			if (hexVals[n] == '6')
				(*(sumHex)) += 6*(pow(16.0, n));
			if (hexVals[n] == '7')
				(*(sumHex)) += 7*(pow(16.0, n));
			if (hexVals[n] == '8')
				(*(sumHex)) += 8*(pow(16.0, n));
			if (hexVals[n] == '9')
				(*(sumHex)) += 9*(pow(16.0, n));
			if (hexVals[n] == 'A')
				(*(sumHex)) += 10*(pow(16.0, n));
			if (hexVals[n] == 'B')
				(*(sumHex)) += 11*(pow(16.0, n));
			if (hexVals[n] == 'C')
				(*(sumHex)) += 12*(pow(16.0, n));
			if (hexVals[n] == 'D')
				(*(sumHex)) += 13*(pow(16.0, n));
			if (hexVals[n] == 'E')
				(*(sumHex)) += 14*(pow(16.0, n));
			if (hexVals[n] == 'F')
				(*(sumHex)) += 15*(pow(16.0, n));
		}
		
		else {
			printf("\n\nError! Invalid hexadecimal expression.\n");
			(*(sumHex)) = 0;
			break;
		}
	}
				
	return;	
}

/*****************************************************************************************************
*																								     *
*																								     *
*										PRINTING functions 										     *
*																								     *
*																								     *
*****************************************************************************************************/

void printDecimal(int* decimal) {
	
	printf("\nThe decimal equivalent is: %d", (*(decimal)));
	
	return;	
}

void printBinary(int* decimal, int* lengthBinary, char* binaryLine){

	int i;
	
	printf("\nThe binary equivalent of %d is: ", (*(decimal)));
	for(i=0; i<(*(lengthBinary)); ++i) 
		printf("%c", binaryLine[i]);	
	
	return;
}

void printOctal(int* decimal, int* lengthOctal, char* octalLine) {
	
	int i;
	
	printf("\n\nThe octal equivalent of %d is: ", (*(decimal)));
	for(i=0; i<=(*(lengthOctal)); ++i) 
		printf("%c", octalLine[i]);
	printf("\n\n");
		
	return;
}

void printHex(int* decimal, int* lengthHex, char* hexLine) {
	
	int i;
	
	printf("The hexadecimal equivalent of %d is: ", (*(decimal)));
	for(i=0; i<=(*(lengthHex)); ++i) 
		printf("%c", hexLine[i]);
	printf("\n\n");
		
	return;
}

