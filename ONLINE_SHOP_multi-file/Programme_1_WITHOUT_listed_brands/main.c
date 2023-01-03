
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 200

typedef struct {
	char cusNumber[MAX];
	char name[MAX];
	char address[MAX];
	char tel_num[MAX];
} customer;


typedef struct {
	char brHat[MAX]; //brand		
	int sHat; //size
	float prHat; //price
} hat;


typedef struct {
	char brCoat[MAX]; 		
	int sCoat;
	float prCoat;			
} coat;


typedef struct {
	char brBlou[MAX];		
	int sBlou;
	float prBlou;				
} blouse;

	
typedef struct {
	char brShir[MAX];	
	int sShir;
	float prShir;				
} shirt;


typedef struct {
	char brSkir[MAX];
	int sSkir;
	float prSkir;	
} skirt;
	
	
typedef struct {
	char brTrou[MAX];		
	int sTrou;
	float prTrou;		
} trousers;
	

typedef struct {
	char brShoe[MAX];
	int sShoe;
	float prShoe;		
} shoes;


//NOTICE: DIFFERENCE WITH THIS STRUCTURE IS THAT WE ARE NOT USING typedef, WE ARE INSTEAD DECLARING THE TYPE struct list, AND THE VARIABLE OF THIS TYPE IS AN ARRAY order[x]	
struct list {
	int numHat; //number of hats desired
	int numCoat;
	int numBlou;
	int numShir;
	int numSkir;
	int numTrou;
	int numShoe;
	char a1, a2, a3;
	char courServ;
	char indCom; // this is to identify if the customer has left a comment or not (y/n)
	char comment[MAX];
	float total;
	customer ID;	
	hat head[MAX];
	coat bMF1[MAX];
	blouse bodF[MAX];
	shirt bMF2[MAX];
	skirt legF[MAX];
	trousers legMF[MAX];
	shoes feet[MAX];		
} order[MAX]; 

	
//prototypes:
void intro();
void menu();
char choice();
int numCust();
void rOrCus(int);
void rOrHat(int);
void rOrCoat(int);
void rOrBlou(int);
void rOrShirt(int);
void rOrSkirt(int);
void rOrTrou(int);
void rOrSoe(int);
void courrierServ(int);
void comment(int);
void billIntro();
void printBill(int);
float printTotal(int);
void totalIntake(float);

//*******************************************************************************************************************************************

int main(int argc, char *argv[]) {
	
	int i, j, x, num_Cust;
	char option, do_again;
	float tt, grandTot;
	
	intro();
	
	do {
	
		menu();
		option = choice();
		
		switch (option) {
			
					case 'a':
								num_Cust = numCust();
								
								for(x=0; x<num_Cust; ++x) {
									
									rOrCus(x);
									rOrHat(x);
									rOrCoat(x);
									rOrBlou(x);
									rOrShirt(x);
									rOrSkirt(x);
									rOrTrou(x);
									rOrSoe(x);									
									courrierServ(x);								
									comment(x);
								}
								
								billIntro();
								
								for(i=0; i<num_Cust ; ++i) {
									printBill(i);
									tt = printTotal(i);
									grandTot += tt;
								}
								
								totalIntake(grandTot);
									
								break;
						
					case 'b':
								break;			
		}
	
		printf("\n\nDo again? (Y/N)\n");
		scanf("%c", &do_again);
		getchar();
		
	} while (do_again != 'N');
	
	printf("\n\nThanks, goodbye!\n");
	return 0;
}


//******************************************************************* FUNCTIONS: ******************************************************************

void intro() {
	
	printf("\tTHE MAZANON ONLINE CLOTHES SHOP - SUMMARY OF CUSTOMER ORDERS\n\n");
	
	return;
}


void menu() {
	
	printf("Please choose one of the following options:\n\n");
	printf("Press (a) to enter details of order(s)\n");
	printf("Press (b) to exit.\n");

	return;
}


char choice() {
	
	char answer;
	
	scanf("%c", &answer);

	getchar();
	return(answer);
}


int numCust() {
	
	int i;
	
	printf("\nHow many customers?\n");
	scanf("%d", &i);
	
	return(i);
}

//************************** reading input for members of structure type CUSTOMER *******************************************************

void rOrCus(int x) {
	
	printf("\n******************Customer number %d: **********************\n", x+1);
	
	printf("\nIndividual Customer ID:\n");
	scanf(" %[^\n]", order[x].ID.cusNumber);
	
	printf("\nCustomer name:\n");
	scanf(" %[^\n]", order[x].ID.name);		
		
	printf("\nCustomer address:\n");
	scanf(" %[^\n]", order[x].ID.address);
	
	printf("\nCustomer telephone number:\n");
	scanf(" %[^\n]", order[x].ID.tel_num);


	getchar();
	return;
}

//************************** reading input for members of structure type HAT *******************************************************

void rOrHat(int x) {
		
	char an1;
	int i, nHat;
	
	printf("\nAny hats bought? (y/n)\n");
	an1 = getchar();
	getchar();
	
	if (an1 == 'y') {
			
		printf("How many hats?\n");
		scanf("%d", &order[x].numHat);
		
		nHat = order[x].numHat;
		
		if (nHat == 1) {
			
			for(i=0; i<nHat; ++i) {
			
				printf("\nBrand of hat:\n");
				scanf(" %[^\n]", order[x].head[i].brHat);
					
				printf("\nSize of hat:\n");
				scanf("%d", &order[x].head[i].sHat);
					
				printf("\nPrice of hat:\n");
				scanf("%f", &order[x].head[i].prHat);
					
				order[x].total += order[x].head[i].prHat;
			
			}			
		}
		
		else {
			
			for(i=0; i<nHat; ++i) {
			
				printf("\nBrand of hat no.%d:\n", i+1);
				scanf(" %[^\n]", order[x].head[i].brHat);
				
				printf("\nSize of hat no.%d:\n", i+1);
				scanf("%d", &order[x].head[i].sHat);
				
				printf("\nPrice of hat no.%d:\n", i+1);
				scanf("%f", &order[x].head[i].prHat);
				
				order[x].total += order[x].head[i].prHat;
							
			}
		}
				
		getchar();
	}

	return;
}

//************************** reading input for members of structure type COAT *******************************************************

void rOrCoat(int x) {

	int i, nCoat;
	char an2;
	
	printf("\nAny coats bought? (y/n)\n");
	an2 = getchar();
	getchar();
	
	if (an2 == 'y') {
			
		printf("How many coats?\n");
		scanf("%d", &order[x].numCoat);
		
		nCoat = order[x].numCoat;
		
		if (nCoat == 1) {
			
			for(i=0; i<nCoat; ++i) {
			
				printf("\nBrand of coat:\n");
				scanf(" %[^\n]", order[x].bMF1[i].brCoat);
				
				printf("\nSize of coat:\n");
				scanf("%d", &order[x].bMF1[i].sCoat);
					
				printf("\nPrice of coat:\n");
				scanf("%f", &order[x].bMF1[i].prCoat);
				
				order[x].total += order[x].bMF1[i].prCoat;	
			}		
		}
		
		else {
			
			for(i=0; i<nCoat; ++i) {
				
				printf("\nBrand of coat no.%d:\n", i+1);
				scanf(" %[^\n]", order[x].bMF1[i].brCoat);
				
				printf("\nSize of coat no.%d:\n", i+1);
				scanf("%d", &order[x].bMF1[i].sCoat);
				
				printf("\nPrice of coat no.%d:\n", i+1);
				scanf("%f", &order[x].bMF1[i].prCoat);	
				
				order[x].total += order[x].bMF1[i].prCoat;			
			}
		}
		
		getchar();
	}

	return;
}	

//************************** reading input for members of structure type BLOUSE *******************************************************

void rOrBlou(int x) {
	
	int i, nBlouse;
	char an3;
	
	printf("\nAny blouses bought? (y/n)\n");
	an3 = getchar();
	getchar();
	
	if (an3 == 'y') {
			
		printf("How many blouses?\n");
		scanf("%d", &order[x].numBlou);
		
		nBlouse = order[x].numBlou;
		
		if (nBlouse == 1) {
			
			for(i=0; i<nBlouse; ++i) {
			
				printf("\nBrand of blouse:\n");
				scanf(" %[^\n]", order[x].bodF[i].brBlou);
				
				printf("\nSize of blouse:\n");
				scanf("%d", &order[x].bodF[i].sBlou);
					
				printf("\nPrice of blouse:\n");
				scanf("%f", &order[x].bodF[i].prBlou);	
					
				order[x].total += order[x].bodF[i].prBlou;	
			}
		}
		
		else {
			
			for(i=0; i<nBlouse; ++i) {
				
				printf("\nBrand of blouse no.%d:\n", i+1);
				scanf(" %[^\n]", order[x].bodF[i].brBlou);
			
				printf("\nSize of blouse no.%d:\n", i+1);
				scanf("%d", &order[x].bodF[i].sBlou);
				
				printf("\nPrice of blouse no.%d:\n", i+1);
				scanf("%f", &order[x].bodF[i].prBlou);	
				
				order[x].total += order[x].bodF[i].prBlou;		
			}			
		}
				
		getchar();
	}

	return;
}

//************************** reading input for members of structure type SHIRT *******************************************************

void rOrShirt(int x) {

	int i, nShirt;
	char an4;
	
	printf("\nAny shirts bought? (y/n)\n");
	an4 = getchar();
	getchar();
	
	if (an4 == 'y') {
			
		printf("How many shirts?\n");
		scanf("%d", &order[x].numShir);
		
		nShirt = order[x].numShir;
		
		if (nShirt == 1) {
			for(i=0; i<nShirt; ++i) {
			
				printf("\nBrand of shirt:\n");
				scanf(" %[^\n]", order[x].bMF2[i].brShir);
					
				printf("\nSize of shirt:\n");
				scanf("%d", &order[x].bMF2[i].sShir);
					
				printf("\nPrice of shirt:\n");
				scanf("%f", &order[x].bMF2[i].prShir);	
					
				order[x].total += order[x].bMF2[i].prShir;	
			}		
		}
		
		else {
		
			for(i=0; i<nShirt; ++i) {
				
				printf("\nBrand of shirt no.%d:\n", i+1);
				scanf(" %[^\n]", order[x].bMF2[i].brShir);
				
				printf("\nSize of shirt no.%d:\n", i+1);
				scanf("%d", &order[x].bMF2[i].sShir);
				
				printf("\nPrice of shirt no.%d:\n", i+1);
				scanf("%f", &order[x].bMF2[i].prShir);	
				
				order[x].total += order[x].bMF2[i].prShir;		
			}
		}
		
		getchar();
	}
	
	return;
}

//************************** reading input for members of structure type SKIRT *******************************************************
	
void rOrSkirt(int x) {

	int i, nSkir;
	char an5;
	
	printf("\nAny skirts bought? (y/n)\n");
	an5 = getchar();
	getchar();
	
	if (an5 == 'y') {
			
		printf("How many skirts?\n");
		scanf("%d", &order[x].numSkir);
		
		nSkir = order[x].numSkir;
		
		if (nSkir == 1) {
			
			for(i=0; i<nSkir; ++i) {
			
				printf("\nBrand of skirt:\n");
				scanf(" %[^\n]", order[x].legF[i].brSkir);
		
				printf("\nSize of skirt:\n");
				scanf("%d", &order[x].legF[i].sSkir);
					
				printf("\nPrice of skirt:\n");
				scanf("%f", &order[x].legF[i].prSkir);	
				
				order[x].total += order[x].legF[i].prSkir;	
			}			
		}
		
		else {
		
			for(i=0; i<nSkir; ++i) {
				
				printf("\nBrand of skirt no.%d:\n", i+1);
				scanf(" %[^\n]", order[x].legF[i].brSkir);
	
				printf("\nSize of skirt no.%d:\n", i+1);
				scanf("%d", &order[x].legF[i].sSkir);
				
				printf("\nPrice of skirt no.%d:\n", i+1);
				scanf("%f", &order[x].legF[i].prSkir);	
				
				order[x].total += order[x].legF[i].prSkir;			
			}
		}
		
		getchar();
	}

	return;
}

//************************** reading input for members of structure type TROUSERS *******************************************************

void rOrTrou(int x) {

	int i, nTrous;
	char an6;
	
	printf("\nAny pairs of trousers bought? (y/n)\n");
	an6 = getchar();
	getchar();
	
	if (an6 == 'y') {
			
		printf("How many pairs of trousers?\n");
		scanf("%d", &order[x].numTrou);
		
		nTrous = order[x].numTrou;
		
		if (nTrous == 1) {
			
			for(i=0; i<nTrous; ++i) {
			
				printf("\nBrand of pair of trousers:\n");
				scanf(" %[^\n]", order[x].legMF[i].brTrou);
		
				printf("\nSize of pair of trousers:\n");
				scanf("%d", &order[x].legMF[i].sTrou);
					
				printf("\nPrice of pair of trousers\n");
				scanf("%f", &order[x].legMF[i].prTrou);	
					
				order[x].total += order[x].legMF[i].prTrou;
			}			
		}
		
		else  {
		
			for(i=0; i<nTrous; ++i) {
				
				printf("\nBrand of pair of trousers no.%d:\n", i+1);
				scanf(" %[^\n]", order[x].legMF[i].brTrou);
	
				printf("\nSize of pair of trousers no.%d:\n", i+1);
				scanf("%d", &order[x].legMF[i].sTrou);
				
				printf("\nPrice of pair of trousers no.%d:\n", i+1);
				scanf("%f", &order[x].legMF[i].prTrou);	
				
				order[x].total += order[x].legMF[i].prTrou;		
			}
		}
		
		getchar();
	}

	return;
}

//************************** reading input for members of structure type SHOES *******************************************************

void rOrSoe(int x) {

	int i, nShoes;
	char an7;
	
	printf("\nAny pairs of shoes bought? (y/n)\n");
	an7 = getchar();
	getchar();
	
	if (an7 == 'y') {
			
		printf("How many pairs of shoes?\n");
		scanf("%d", &order[x].numShoe);
		
		nShoes = order[x].numShoe;
		
		if (nShoes == 1) {
			
			for(i=0; i<nShoes; ++i) {
		
				printf("\nBrand of pair of shoes:\n");
				scanf(" %[^\n]", order[x].feet[i].brShoe);
		
				printf("\nSize of pair of shoes:\n");
				scanf("%d", &order[x].feet[i].sShoe);
					
				printf("\nPrice of pair of shoes:\n");
				scanf("%f", &order[x].feet[i].prShoe);	
					
				order[x].total += order[x].feet[i].prShoe;	
			}			
		}
		
		else {
		
			for(i=0; i<nShoes; ++i) {			
					
				printf("\nBrand of pair of shoes no.%d:\n", i+1);
				scanf(" %[^\n]", order[x].feet[i].brShoe);
	
				printf("\nSize of pair of shoes no.%d:\n", i+1);
				scanf("%d", &order[x].feet[i].sShoe);
				
				printf("\nPrice of pair of shoes no.%d:\n", i+1);
				scanf("%f", &order[x].feet[i].prShoe);	
				
				order[x].total += order[x].feet[i].prShoe;		
			}
		}
		
		getchar();
	}

	return;
}

//*************************** type of courrier service *****************************************************************

void courrierServ(int x) {
	
	printf("\nType of courrier service:\n");
	printf("Press (a) for SUPER-FAST POSTAGE [2 working days] = 14.99$\n");		
	printf("Press (b) for NORMAL POSTAGE [7-10 working days] = 9.99$\n");
	printf("Press (c) for DISCOUNT POSTAGE [2-3 weeks] = 2.99$\n");
	printf("Press (d) if number of orders is void.\n");
				
	order[x].courServ = getchar();

	if (order[x].courServ == 'a')
		order[x].total += 14.99;
		else if (order[x].courServ == 'b')
			order[x].total += 9.99;
			else if (order[x].courServ == 'c')
				order[x].total += 2.99;	
				else
					printf("");	
							
	getchar();			
	return;
}

//*************************** CUSTOMER COMMENT (IF ANY) *****************************************************************

void comment(int x) {
	
	printf("\nHas this customer left a message regarding his/her order(s) (y/n)?\n");
	
	order[x].indCom = getchar();
		
	if (order[x].indCom == 'y') {
		printf("Re-type the customer's message:\n");
		scanf(" %[^\n]", order[x].comment);
		getchar();
	}
	
	else
		printf("");

	return;			
}

//***********************************************************************************************************************
//***********************************************************************************************************************
//***********************************************************************************************************************
//***********************************************************************************************************************
//***********************************************************************************************************************

void billIntro() {
	
	printf("\n\n");
	printf("*********************************************\n");
	printf("*                                           *\n");
	printf("*         SUMMARY OF CUSTOMER ORDERS:       *\n");
	printf("*                                           *\n");
	printf("*********************************************\n");
	
	return;
}


//***********************************************************************************************************************
//***********************************************************************************************************************
//***********************************************************************************************************************
//***********************************************************************************************************************
//***********************************************************************************************************************

void printBill(int x) {
	
	int a, b, c, d, e, f, g;
	
	printf("\n\n");
	printf("\n\tSUMMARY OF CUSTOMER no.%d:\n\n\n", x+1);
	printf("CUSTOMER ID: %s\n", order[x].ID.cusNumber);
	printf("CUSTOMER NAME: %s\n", order[x].ID.name);
	printf("CUSTOMER ADDRESS: %s\n", order[x].ID.address);		
	printf("CUSTOMER TELEPHONE NUMBER: %s\n", order[x].ID.tel_num);
	
	//if no items have been bought at all:
	if (order[x].numHat == 0 && order[x].numCoat == 0 && order[x].numBlou == 0 && order[x].numShir == 0 && order[x].numSkir == 0 && order[x].numTrou == 0 && order[x].numShoe == 0) {
		
		printf("\n%s has not passed any orders.", order[x].ID.name);
		
		if (order[x].indCom == 'y')
			printf("\n\n%s has posted a comment:\n\n%s", order[x].ID.name, order[x].comment);
		else
			printf("\n\n%s has left no comment.", order[x].ID.name);
	}
		
	else {
	
		
//******************************** hats *******************************************************	
	
		if (order[x].numHat > 0) {
			
			if (order[x].numHat == 1) {
					
				for(a=0; a<order[x].numHat; ++a) {
					
					printf("\n\n%s has ordered one hat:\n", order[x].ID.name);
					printf("\nBrand of hat: %s", order[x].head[a].brHat);
					printf("\nSize of hat: %d", order[x].head[a].sHat);
					printf("\nPrice of hat: %.2f$", order[x].head[a].prHat);
				}
			}
				
			else {
				
				printf("\n\n%s has ordered %d hats:\n", order[x].ID.name, order[x].numHat);
					
				for(a=0; a<order[x].numHat; ++a) {
					
					printf("\nBrand of hat no.%d: %s", a+1, order[x].head[a].brHat);
					printf("\nSize of hat no.%d: %d\n", a+1, order[x].head[a].sHat);
					printf("Price of hat no.%d: %.2f$\n", a+1, order[x].head[a].prHat);
				}
			}		
		}	
			
	//******************************** coats *******************************************************
			
		if (order[x].numCoat > 0) {
			
			if (order[x].numCoat == 1) {
				
				for(b=0; b<order[x].numCoat; ++b) {
				
				printf("\n\n%s has ordered one coat:\n", order[x].ID.name);
				printf("\nBrand of coat: %s", order[x].bMF1[b].brCoat);
				printf("\nSize of coat: %d\n", order[x].bMF1[b].sCoat);
				printf("Price of coat: %.2f$\n", order[x].bMF1[b].prCoat);
				}	
			}
				
			else {
				
				printf("\n\n%s has ordered %d coats:\n", order[x].ID.name, order[x].numCoat);
			
				for(b=0; b<order[x].numCoat; ++b) {
					
					printf("\nBrand of coat no.%d: %s", b+1, order[x].bMF1[b].brCoat);
					printf("\nSize of coat no.%d: %d\n", b+1, order[x].bMF1[b].sCoat);
					printf("Price of coat no.%d: %.2f$\n", b+1, order[x].bMF1[b].prCoat);
				}	
			}	
		}

			
	//******************************** blouses *******************************************************
			
		if (order[x].numBlou > 0) {
			
			if (order[x].numBlou == 1) {
				
				for(c=0; c<order[x].numBlou; ++c) {
				
				printf("\n\n%s has ordered one blouse:\n", order[x].ID.name);
				printf("\nBrand of blouse: %s", order[x].bodF[c].brBlou);
				printf("\nSize of blouse: %d\n", order[x].bodF[c].sBlou);
				printf("Price of blouse: %.2f$\n", order[x].bodF[c].prBlou);
				}	
			}
			
			else {
			
				printf("\n\n%s has ordered %d blouses:\n", order[x].ID.name, order[x].numBlou);
				
				for(c=0; c<order[x].numBlou; ++c) {
					printf("\nBrand of blouse no.%d: %s", c+1, order[x].bodF[c].brBlou);
					printf("\nSize of blouse no.%d: %d\n", c+1, order[x].bodF[c].sBlou);
					printf("Price of blouse no.%d: %.2f$\n", c+1, order[x].bodF[c].prBlou);
				}
			}
		}

			
	//******************************** shirts *******************************************************
	
		if (order[x].numShir > 0) {
			
			if (order[x].numShir == 1) {
				
				for(d=0; d<order[x].numShir; ++d) {
			
				printf("\n\n%s has ordered one shirt:\n", order[x].ID.name);
				printf("\nBrand of shirt: %s", order[x].bMF2[d].brShir);
				printf("\nSize of shirt: %d\n", order[x].bMF2[d].sShir);
				printf("Price of shirt: %.2f$\n", order[x].bMF2[d].prShir);	
				}
			}
			
			else {
				
				printf("\n\n%s has ordered %d shirts:\n", order[x].ID.name, order[x].numShir);
				
				for(d=0; d<order[x].numShir; ++d) {
					printf("\nBrand of shirt no.%d: %s", d+1, order[x].bMF2[d].brShir);
					printf("\nSize of shirt no.%d: %d\n", d+1, order[x].bMF2[d].sShir);
					printf("Price of shirt no.%d: %.2f$\n", d+1, order[x].bMF2[d].prShir);
				}
			}
		}

			
	//******************************** skirts *******************************************************
		
		if (order[x].numSkir > 0) {
			
			if (order[x].numSkir == 1) {
				
				for(e=0; e<order[x].numSkir; ++e) {
				
				printf("\n\n%s has ordered one skirt:\n", order[x].ID.name);
				printf("\nBrand of skirt: %s", order[x].legF[e].brSkir);
				printf("\nSize of skirt: %d\n", order[x].legF[e].sSkir);
				printf("Total price of skirt: %.2f$\n", order[x].legF[e].prSkir);
				}			
			}
			
			else {
				
				printf("\n\n%s has ordered %d skirts:\n", order[x].ID.name, order[x].numSkir);
				
				for(e=0; e<order[x].numSkir; ++e) {
					printf("\nBrand of skirt no.%d: %s", e+1, order[x].legF[e].brSkir);
					printf("\nSize of skirt no.%d: %d\n", e+1, order[x].legF[e].sSkir);
					printf("Price of skirt no.%d: %.2f$\n", e+1, order[x].legF[e].prSkir);
				}
			}
		}

		
	//******************************** trousers *******************************************************
		
		if (order[x].numTrou > 0) {
			
			if (order[x].numTrou == 1) {
				
				for(f=0; f<order[x].numTrou; ++f) {
			
				printf("\n\n%s has ordered one pair of trousers:\n", order[x].ID.name);
				printf("\nBrand of pair of trousers: %s", order[x].legMF[f].brTrou);
				printf("\nSize of pair of trousers: %d\n", order[x].legMF[f].sTrou);
				printf("Price of pair of trousers: %.2f$\n", order[x].legMF[f].prTrou);
				}
			}
			
			else {
				
				printf("\n\n%s has ordered %d pairs of trousers:\n", order[x].ID.name, order[x].numTrou);
				
				for(f=0; f<order[x].numTrou; ++f) {
					printf("\nBrand of pair of trousers no.%d: %s", f+1, order[x].legMF[f].brTrou);
					printf("\nSize of pair of trousers no.%d: %d\n", f+1, order[x].legMF[f].sTrou);
					printf("Price of pair of trousers no.%d: %.2f$\n", f+1, order[x].legMF[f].prTrou);
				}
			}
		}

		
	//******************************** shoes ***********************************************************
		
		if (order[x].numShoe > 0) {
			
			if (order[x].numShoe == 1) {
				
				for(g=0; g<order[x].numShoe; ++g) {
				
				printf("\n\n%s has ordered one pair of shoes:\n", order[x].ID.name);
				printf("\nBrand of pair of shoes: %s", order[x].feet[g].brShoe);
				printf("\nSize of pair of shoes: %d\n", order[x].feet[g].sShoe);
				printf("Price of pair of shoes: %.2f$\n", order[x].feet[g].prShoe);	
				}
			}
			
			else {
				
				printf("\n\n%s has ordered %d pairs of shoes:\n", order[x].ID.name, order[x].numShoe);
				
				for(g=0; g<order[x].numShoe; ++g) {
					printf("\nBrand of pair of shoes no.%d: %s", g+1, order[x].feet[g].brShoe);
					printf("\nSize of pair of shoes no.%d: %d\n", g+1, order[x].feet[g].sShoe);
					printf("Price of pair of shoes no.%d: %.2f$\n", g+1, order[x].feet[g].prShoe);
				}	
			}
		}
		
		
	//******************************** type of postage ************************************************************	
	
		
		if (order[x].courServ == 'a')
			printf("\nType of postage: SUPER-FAST POSTAGE [2 working days] = 14.99$\n");
			else if (order[x].courServ == 'b')
				printf("\nType of postage: NORMAL POSTAGE [7-10 working days] = 9.99$\n");
				else if (order[x].courServ == 'c')
					printf("\nType of postage: DISCOUNT POSTAGE [2-3 weeks] = 2.99$\n");
					
						
		
	//******************************** customer comment ***********************************************************
		
		if (order[x].indCom == 'y') {
			printf("\n%s has posted a comment with regard to this order:\n\n", order[x].ID.name);
			printf("\t'%s'", order[x].comment);
		}	
		else 
			printf("\n%s has posted no comment with regard to this order.", order[x].ID.name);		
	}
			
	return;	
}
//end of printBill() function


//***********************************************************************************************************************
//***********************************************************************************************************************
//***********************************************************************************************************************
//***********************************************************************************************************************
//***********************************************************************************************************************

/*
void printTotal (int x) {

	if (order[x].total > 0)
		printf("\n\nTotal amount to be paid, including postage fee and tax (3.80%%):\n\n\t%.2f$\n\n", (order[x].total + (order[x].total * 0.38)));
	else
		printf("\n\nTotal amount to be paid: 0.00$");
		
	return;
}
*/

float printTotal (int x) {
	
	float tot = order[x].total + (order[x].total * 0.38);

	if (order[x].total > 0)
		printf("\n\nTotal amount to be paid, including postage fee and tax (3.80%%):\n\n\t%.2f$\n\n", tot);
	else {
		tot = 0.0;
		printf("\n\nTotal amount to be paid: 0.00$");
	}
				
	return(tot);
}

void totalIntake (float grandTotal) {
	
	printf("\n\n");
	printf("*********************************************\n");
	printf("*                                           *\n");
	printf("*         TODAY'S TOTAL CASH INTAKE:        *\n");
	printf("*                                           *\n");
	printf("*********************************************\n");
	
	printf("\n\nTotal amount of money taken in by online store today: \n\n\t%.2f$\n\n", grandTotal);
	
	return;
}

