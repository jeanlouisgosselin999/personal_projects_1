/*
This programme will display the following figure:

				1
			   1 1
			  1 3 1
			 1 3 3 1
			1 3 5 3 1
		   1 3 5 5 3 1
		  1 3 5 7 5 3 1
		 1 3 5 7 7 5 3 1
		etc...
		
********************************************************************************************************************************

									DIFFERENT WAY:
									
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
									
	int i, j, k, n;
	n=12;
	for(i=1; i<=n; i++){
		for(j=i; j<n; j++){
			printf(" ");
		}
	for(j=1, k=1; j<=i; j++){
		printf("%d ", k);
		if(j<i/2 + i%2)
			k+=2;
		else if(j>i/2)
			k-=2;
	}
	printf("\n");	
	}
	return 0;
}
	
********************************************************************************************************************************

									MY CODE, BUT WITH SHORTER VARIABLES:
									
#include <stdio.h>
#include <stdlib.h>

const int MAX = 16;

int main(int argc, char *argv[]) {
		
	int a=0, b, c, d, e=0, f, g, h, i, j=1, k, l, array[MAX];

	printf("Starting number:\n");
	scanf("%d", &a);
	
	printf("\n\nNumber of rows:\n");
	scanf("%d", &b);
	
	if(b > 30)
		printf("\nNumber of rows exceeds screen capacity!");		
	else{	
		k = b;
		c = b-1;	
		l = c/2 + 1;
		for(d=0; d<l; d++){
			array[d] = a;
			a+=2;
		}
		for(i=0; i<k; i++)
			printf(" ");				
		printf("%d ", array[0]);				
		--k;
		printf("\n");	
		for(e=1; e<=c; e++) {	
			if(e%2 != 0) {
				for(f=0; f<k; f++)
					printf(" ");				
				for(g=0; g<j; g++)
					printf("%d ", array[g]);			
				for(h=j-1; h>=0; h--)
					printf("%d ", array[h]);
				--k;
				printf("\n");				
			}					
			else {				
				++j;
				for(f=0; f<k; f++)
					printf(" ");					
				for(g=0; g<j; g++)
					printf("%d ", array[g]);
				for(h=j-2; h>=0; h--)
					printf("%d ", array[h]);
				--k;
				printf("\n");							
			}
		}
	}					
	return 0;
}
	
	
*/

#include <stdio.h>
#include <stdlib.h>

const int MAX = 16;

int main(int argc, char *argv[]) {
		
	int start=0, rows, trueNumRows, i, line=0, j, k, l, a, internalNum=1, whitespaces, numberValuesOfArray, array[MAX];

	printf("What is your starting number (top of pyramid)?\n");
	scanf("%d", &start);
	
	printf("\n\nHow many rows in your pyramid (including top point) (MAX 30)?\n");
	scanf("%d", &rows);
	
	if(rows > 30)
		printf("\nNumber of rows exceeds screen capacity!");
		
	else{
	
		whitespaces = rows;
		trueNumRows = rows-1;
	
		numberValuesOfArray = trueNumRows/2 + 1;
		
		//filling in array:	
		for(i=0; i<numberValuesOfArray; i++){
			array[i] = start;
			start+=2;
		}
			
		printf("\n\nValues of your array which will be used in the pyramid:\n");
		for(i=0; i<numberValuesOfArray; i++)
			printf("%d ", array[i]);
		printf("\n\n\n");
		
		//for FIRST line (top of pyramid):
		for(a=0; a<whitespaces; a++)
			printf(" ");
				
		printf("%d ", array[0]);
				
		--whitespaces;
		printf("\n");
	
		//for all other lines:
		for(line=1; line<=trueNumRows; line++) {
	
			if(line%2 != 0) {
					
				//(1) whitespaces to the left:
				for(j=0; j<whitespaces; j++)
					printf(" ");
					
				//(2) first occurence of array value(s):				
				for(k=0; k<internalNum; k++)
					printf("%d ", array[k]);
	
				//(3) repeating occurrence of array value(s) in reverse order WITH repeating last value:			
				for(l=internalNum-1; l>=0; l--)
					printf("%d ", array[l]);
					
				--whitespaces;
				printf("\n");				
			}
					
			else {
				
				++internalNum;
				
				//(1) whitespaces to the left:
				for(j=0; j<whitespaces; j++)
					printf(" ");
				
				//(2) first occurence of array value(s):					
				for(k=0; k<internalNum; k++)
					printf("%d ", array[k]);
				
				//(3) repeating occurrence of array value(s) in reverse order WITHOUT repeating last value:
				for(l=internalNum-2; l>=0; l--)
					printf("%d ", array[l]);
					
				--whitespaces;
				printf("\n");		
					
			}
		}
	}		
			
	return 0;
}

