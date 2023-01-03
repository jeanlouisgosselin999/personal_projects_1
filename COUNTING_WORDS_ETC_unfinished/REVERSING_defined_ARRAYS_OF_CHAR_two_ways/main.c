#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MROW 30
#define MCOL 100

int main(int argc, char *argv[]) {
		
	char c, myText[MROW][MCOL];	
	int nrows, ncols, row, col, length=0, l1, l2, rev1, rev2, count;	
	int a, b, i, j, s, t, e, f, g, h;
	int x, y, v, w;
	int m, n;
	int sumWords = 0, vowels = 0, consonants = 0, digits = 0, whitespaces = 0, other = 0, totchar=0;
	
	//defining size:
	printf("How many lines?\n");
		scanf("%d", &nrows);	
	printf("How many characters per line?\n");
		scanf("%d", &ncols);

	//reading input:			
	printf("\nEnter several lines of text:\n\n");
	for(row=0; row<nrows; ++row)		
		for(col=0; col<ncols; ++col) {
			scanf("%c", &myText[row][col]);
			if (myText[row][col] == '\n')
				--col;
		}
	
	//printing text:
	printf("\n\nYour text:\n\n");
	for(x=0; x<nrows; ++x) {
		printf("\n");
		for(y=0; y<ncols; ++y)
			printf("%c", myText[x][y]);
	}

//**************************************************** REVERSING (1) *************************************************************
	
	printf("\n\n\n(1) Text backwards (in line by line order):\n\n");
	for(x=0; x<nrows; ++x) {
		printf("\n");
		for(rev2=ncols-1; rev2>=0; --rev2)
			printf("%c", myText[x][rev2]);
	}
	
//**************************************************** REVERSING (2) *************************************************************
	
	printf("\n\n\n(2) Text backwards (from end of paragraph to start of paragraph):\n\n");
	for(rev1=nrows-1; rev1>=0; --rev1) {
		printf("\n");
		for(rev2=ncols-1; rev2>=0; --rev2)
			printf("%c", myText[rev1][rev2]);
	}
	
	printf("\n\n\n");
	
	return 0;
}


