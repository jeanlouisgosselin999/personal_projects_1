/*
NOTE:
because we are using ARRAY OF POINTERS instead of char arrays for typing in the brand names of items, for now this program will function properly only if we choose ONE
item per selection.
Several choices will lead to errors (null??).
*/



#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 200

typedef struct {
	char cusNumber[MAX];
	char name[MAX];
	char address[MAX];
	char tel_num[MAX];
} cust_details;


typedef struct {
	char* ptBHat;	
	int sHat; //size
	float prHat; //price
} hat;


typedef struct {
	char* ptBCoat; 		
	int sCoat;
	float prCoat;			
} coat;


typedef struct {
	char* ptBBlou;		
	int sBlou;
	float prBlou;				
} blouse;

	
typedef struct {
	char* ptBShir;	
	int sShir;
	float prShir;				
} shirt;


typedef struct {
	char* ptBSkir;
	int sSkir;
	float prSkir;	
} skirt;
	
	
typedef struct {
	char* ptBTrou;		
	int sTrou;
	float prTrou;		
} trousers;
	

typedef struct {
	char* ptBShoe;
	int sShoe;
	float prShoe;		
} shoes;


//NOTICE: DIFFERENCE WITH THIS STRUCTURE IS THAT WE ARE NOT USING typedef, WE ARE INSTEAD DECLARING THE TYPE struct list, AND THE VARIABLE OF THIS TYPE IS AN ARRAY customer[x]	
struct list {
	int numHat; //number of hats desired
	int numCoat;
	int numBlou;
	int numShir;
	int numSkir;
	int numTrou;
	int numShoe;
	char chHat[MAX]; //==> this is for choice of hat brand
	char chCoat[MAX]; //==> this is for choice of coat brand
	char chBlou[MAX]; //==> this is for choice of blouse brand
	char chShir[MAX]; //==> this is for choice of shirt brand
	char chSkir[MAX]; //==> this is for choice of skirt brand
	char chTrou[MAX]; //==> this is for choice of trouser brand
	char chShoe[MAX]; //==> this is for choice of shoe brand
	char courServ;
	char indCom; // this is to identify if the customer has left a comment or not (y/n)
	char comment[MAX];
	float total;
	float allOrderPrices[MAX];
	cust_details ID;	
	hat head[MAX];
	coat bMF1[MAX];
	blouse bodF[MAX];
	shirt bMF2[MAX];
	skirt legF[MAX];
	trousers legMF[MAX];
	shoes feet[MAX];		
} customer[MAX]; //==> reminder: CUSTOMER[] is an array of structure-type LIST

	
void intro();
void menu();
char choice();
int numCust();
void rOrCus(int); //customer's personal details
void rOrHat(int, int*); 
void rOrCoat(int, int*); 
void rOrBlou(int, int*); 
void rOrShirt(int, int*); 
void rOrSkirt(int, int*); 
void rOrTrou(int, int*); 
void rOrSoe(int, int*); 
void courrierServ(int, int*, int*, int*);
void comment(int, int*);
void incr1(int);
void incr2(int);
void incr3(int);
void incr4(int);
void incr5(int);
void incr6(int);
void incr7(int);
void billIntro();
void printBill(int);
void printTotal(int, float*, float*);
void numItemsBought(int*);
void detailItems(int, int, int, int, int, int, int);
void averagePurch(float, int);
void totalIntake(float);
void decr1(int);
void decr2(int);
void decr3(int);
void decr4(int);
void decr5(int);
void decr6(int);
void decr7(int);
void num_Comments(int, int); //total number of comments left by customers
void num_Post(int*, int*, int*); //number of customers who have chosen "Super-Fast", "Normal" and "Discount" postage services
									//NOTE: since there is one postage service per customer, then customer == postage service


//*******************************************************************************************************************************************

int main(int argc, char *argv[]) {
	
	int a, b, i, j, x;
	int num_Cust, nCom=0;
	int t1=0, t2=0, t3=0, t4=0, t5=0, t6=0, t7=0;
	int static y, z, tIB; //==> tIB = total of items bought
	int in1, in2, in3, in4, in5, in6, in7;
	int i1, i2, i3, i4, i5, i6, i7;
	int nI1, nI2, nI3, nI4, nI5, nI6, nI7;
	int a1, a2, a3, a4, a5, a6, a7;
	int sLE1, sLE2, sME1, sME2; //sLE == least expensive; sME == most expensive
	int max1, max2;
	float temp1, temp2;
	int temp3, temp4;
	int super_fast=0, normal=0, discount=0;
	char option, do_again;
	int tHat=0, tCoat=0, tBlou=0, tShir=0, tSkir=0, tTrou=0, tShoe=0;
	float total=0, grandTot=0;	
	float leastExp[100], mostExp[100];
	int bestseller[7], worstseller[7];
	char itN1[100][20], itN2[100][20], t_a1[1][20], t_a2[1][20]; //==> 2D arrays for storing names of items (for least/most expensive items, below)


										
	char brandHat1[] = "Kangol";
	char brandHat2[] = "Jaxon";
	char brandHat3[] = "Tilley";
	char brandHat4[] = "Stetson";
	char brandHat5[] = "Maddox";
	
//**************************************
	
	char brandCoat1[] = "Astley";
	char brandCoat2[] = "Burton";
	char brandCoat3[] = "Haddington";
	char brandCoat4[] = "Jaeger";
	char brandCoat5[] = "Jack & Jones";	

	
//**************************************
	
	char brandBlouse1[] = "Bellfield";
	char brandBlouse2[] = "883 Police";
	char brandBlouse3[] = "Duck & Cover";
	char brandBlouse4[] = "Foray";
	char brandBlouse5[] = "Nanny State";
	
//**************************************
	
	char brandShirt1[] = "Abercrombie & Fitch";
	char brandShirt2[] = "Ben Sherman";
	char brandShirt3[] = "Calvin Klein";
	char brandShirt4[] = "Dolce & Gabbana";
	char brandShirt5[] = "Emporio Armani";
	
//**************************************
	
	char brandSkirt1[] = "Karl Lagerfeld";
	char brandSkirt2[] = "Jonathan Saunders";
	char brandSkirt3[] = "Nina Ricci";
	char brandSkirt4[] = "Moschino";
	char brandSkirt5[] = "Lanvin";
	
//**************************************	
	
	char brandTrou1[] = "G-Star";
	char brandTrou2[] = "Vivienne Westwood";
	char brandTrou3[] = "Levi's";
	char brandTrou4[] = "Tommy Hilfiger";
	char brandTrou5[] = "Skopes";
	
//**************************************
	
	char brandShoe1[] = "New Balance";
	char brandShoe2[] = "Zara";
	char brandShoe3[] = "Nike";
	char brandShoe4[] = "Minnetonka Moccasin";
	char brandShoe5[] = "Fergalicious";	
			
	intro();
	
	do {
	
		menu();
		option = choice();
		
		switch (option) {
			
					case 'a':
						
		//*****************************PART 1: ENTEREING DATA ***********************************************
		
								// (1) DEFINING NUMBER OF CUSTOMERS
								num_Cust = numCust();
								
								// (2) PROCESSING ALL ORDERS FOR ALL CUSTOMER:
								for(x=0; x<num_Cust; ++x) {
									
									//customer's personal details:
									rOrCus(x);
									
									//customer's orders (per item category):
									rOrHat(x, &tIB);									
									rOrCoat(x, &tIB);									
									rOrBlou(x, &tIB);							
									rOrShirt(x, &tIB);								
									rOrSkirt(x, &tIB);								
									rOrTrou(x, &tIB);									
									rOrSoe(x, &tIB);
									
									//customer's chosen courrier service:																		
									courrierServ(x, &super_fast, &normal, &discount);
									//customer's comment:								
									comment(x, &nCom);									
								}
		
		//*****************************PART 2: DISPLAYING DATA ***********************************************	
															
								billIntro();
								
								for(i=0; i<num_Cust ; ++i) {
									// 1) printing each customer's detailed orders:
									printBill(i);
									// 2) printing amount of money paid in, per customer and in total:
									printTotal(i, &total, &grandTot);
								}
								
								//printing total number of items bought, all customers included:
								numItemsBought(&tIB);
								
								//calculating the total number of hats, coats, blouses, shirts, skirts, trousers and shoes bought by all customers:
								for(i=0; i<num_Cust ; ++i) {
									
									tHat += customer[i].numHat;
									tCoat += customer[i].numCoat;
									tBlou += customer[i].numBlou;
									tShir += customer[i].numShir;
									tSkir += customer[i].numSkir;
									tTrou += customer[i].numTrou;
									tShoe += customer[i].numShoe;									
								}
								
								//printing detailed number of items bought, per item category:	
								detailItems(tHat, tCoat, tBlou, tShir, tSkir, tTrou, tShoe);
								
								
								//*********************************************************************
								//*															          *
								//*              1) determining the best-selling item:                *
								//*															          *
								//*********************************************************************
								
								//(here: randomly assigning each total number of items by category randomly into array "bestseller"):
								bestseller[0] = tHat;
								bestseller[1] = tCoat;
								bestseller[2] = tBlou;
								bestseller[3] = tShir;
								bestseller[4] = tSkir;
								bestseller[5] = tTrou;
								bestseller[6] = tShoe;
								
								//bubble sorting the array "bestseller", in DECREASING order, from biggest to smallest (so: first [0] box of array == best-selling item):
								for(a=0; a<7; ++a) 
									//finding the biggest of all remaining elements:
									for(b=0; b<7; ++b)
										if(bestseller[b] < bestseller[b+1]) {
											//swapping:
											temp3 = bestseller[b+1];
											bestseller[b+1] = bestseller[b];
											bestseller[b] = temp3;
										}
								
									
									if (bestseller[0] == tHat) {
										
										if (bestseller[0] == 1)			
											printf("\n\nThe best-selling item is:\n\n\thats (1 sold).");
										else 
											printf("\n\nThe best-selling item is:\n\n\thats (%d sold).", tHat);
									}
										else if (bestseller[0] == tCoat) {
											
											if (bestseller[0] == 1)			
												printf("\n\nThe best-selling item is:\n\n\tcoats (1 sold).");
											else 
												printf("\n\nThe best-selling item is:\n\n\tcoats (%d sold).", tCoat);
										}
											else if (bestseller[0] == tBlou) {
												
												if (bestseller[0] == 1)			
													printf("\n\nThe best-selling item is:\n\n\tblouses (1 sold).");
												else 
													printf("\n\nThe best-selling item is:\n\n\tblouses (%d sold).", tBlou);
											}
												else if (bestseller[0] == tShir) {
													
													if (bestseller[0] == 1)			
														printf("\n\nThe best-selling item is:\n\n\tshirts (1 sold).");
													else 
														printf("\n\nThe best-selling item is:\n\n\tshirts (%d sold).", tShir);
												}
													else if (bestseller[0] == tSkir) {
													
														if (bestseller[0] == 1)			
															printf("\n\nThe best-selling item is:\n\n\tskirts (1 sold).");
														else 
															printf("\n\nThe best-selling item is:\n\n\tskirts (%d sold).", tSkir);
													}
														else if (bestseller[0] == tTrou) {
													
															if (bestseller[0] == 1)			
																printf("\n\nThe best-selling item is:\n\n\ttrousers (1 pair sold).");
															else 
																printf("\n\nThe best-selling item is:\n\n\ttrousers (%d pairs sold).", tTrou);
														}
															else if (bestseller[0] == tShoe) {
													
																if (bestseller[0] == 1)			
																	printf("\n\nThe best-selling item is:\n\n\tshoes (1 pair sold).");
																else 
																	printf("\n\nThe best-selling item is:\n\n\tshoes (%d pairs sold).", tShoe);
															}						
																	else
																		printf("\n\nThere is no individual best-selling item.");
									
																		
								totalIntake(grandTot);
								averagePurch(grandTot, num_Cust);
								
																
								//*********************************************************************
								//*																      *
								//*	 3) finding least expensive item bought (all customers included)  *					
								//*																      *	
								//*********************************************************************
																
								for(x=0; x<num_Cust; ++x) {
									
									if (customer[x].numHat > 0)
										incr1(x); //bubble sorting in increasing order									
									if (customer[x].numCoat > 0)	
										incr2(x);										
									if (customer[x].numBlou > 0)	
										incr3(x);										
									if (customer[x].numShir > 0)	
										incr4(x);										
									if (customer[x].numSkir > 0)	
										incr5(x);										
									if (customer[x].numTrou > 0)	
										incr6(x);										
									if (customer[x].numShoe > 0)
										incr7(x);
								
								}
								
								/*
								NOTE: the following loop assigns all the least expensive prices of all item categories to a FLOAT-type array "leastExp[]
								NOTE: this loop inputs data into TWO arrays: leastExp[y] and itN1[y]! BOTH go hand-in-hand. It is why we are assigning the same
								array box number to both (variable Y being the all-important counter for BOTH arrays)
								*/
								
								for(x=0, y=0; x < num_Cust; ++x) {
									
									if(customer[x].head[0].prHat > 0) {
										leastExp[y] = customer[x].head[0].prHat;
										strcpy(itN1[y], "hat");
										++y;
									}
										
									if(customer[x].bMF1[0].prCoat > 0) {
										leastExp[y] = customer[x].bMF1[0].prCoat;
										strcpy(itN1[y], "coat");
										++y;
									}
									
									if(customer[x].bodF[0].prBlou > 0)	{
										leastExp[y] = customer[x].bodF[0].prBlou;
										strcpy(itN1[y], "blouse");
										++y;
									}
									
									if(customer[x].bMF2[0].prShir > 0) {
										leastExp[y] = customer[x].bMF2[0].prShir;
										strcpy(itN1[y], "shirt");
										++y;
									}
									
									if(customer[x].legF[0].prSkir > 0) {
										leastExp[y] = customer[x].legF[0].prSkir;
										strcpy(itN1[y], "skirt");
										++y;
									}
									
									if(customer[x].legMF[0].prTrou > 0) {
										leastExp[y] = customer[x].legMF[0].prTrou;
										strcpy(itN1[y], "shirt");
										++y;
									}
									
									if(customer[x].feet[0].prShoe > 0) {
										leastExp[y] = customer[x].feet[0].prShoe;
										strcpy(itN1[y], "pair of trousers");
										++y;
									}									
								}
								
								max1 = y;
								
								/*
								NOTE: the final loop below sorts all the prices in ascending order (so: address 0 of the array will be the least expensive price of ALL items bought by all customers):
								*/
								
								//BUBBLE SORT TECHNIQUE (sorting all LEAST EXPENSIVE prices of all item categories in ascending order, from the smallest to the highest):
								for(sLE1=0; sLE1 < max1-1; ++sLE1) //REMINDER: arrays are sorted from 0 to n-1; hence: "a<n-1"
									//finding the smallest of all remaining elements:
									for(sLE2=0; sLE2 < max1-1; ++sLE2)
										if(leastExp[sLE2] > leastExp[sLE2+1]) { //NOTE: if we want to reorder in DECREASING order, simply change > to <
											//first swap: PRICES
											temp1 = leastExp[sLE2+1];
											leastExp[sLE2+1] = leastExp[sLE2];
											leastExp[sLE2] = temp1;
											//second swap: CORRESPONDING ITEMS
											strcpy(t_a1[0], itN1[sLE2+1]);											
											strcpy(itN1[sLE2+1], itN1[sLE2]);
											strcpy(itN1[sLE2], t_a1[0]);											
										}
								
								
								//using STRCMP function (when equals zero, both strings are identical):
								//NOTE: we are using the very FIRST box [0] of the array leastExp[] as the price for the least expensive item!
								if (strcmp(itN1[0], "hat") == 0) {
																	
									if (num_Cust == 1)
										printf("\n\nThe least expensive of all %d items bought by the customer is: \n\n\ta hat worth %.2f$", tIB, leastExp[0]);									
									else
										printf("\n\nThe least expensive of all %d items bought by all %d customers is: \n\n\ta hat worth %.2f$", tIB, num_Cust, leastExp[0]);						
								}
								
									else if (strcmp(itN1[0], "coat") == 0) {
										
										if (num_Cust == 1)
											printf("\n\nThe least expensive of all %d items bought by the customer is: \n\n\ta coat worth %.2f$", tIB, leastExp[0]);									
										else
											printf("\n\nThe least expensive of all %d items bought by all %d customers is: \n\n\ta coat worth %.2f$", tIB, num_Cust, leastExp[0]);						
									}
									
										else if (strcmp(itN1[0], "blouse") == 0) {
											
											if (num_Cust == 1)
												printf("\n\nThe least expensive of all %d items bought by the customer is: \n\n\ta blouse worth %.2f$", tIB, leastExp[0]);									
											else
												printf("\n\nThe least expensive of all %d items bought by all %d customers is: \n\n\ta blouse worth %.2f$", tIB, num_Cust, leastExp[0]);						
										}
										
											else if (strcmp(itN1[0], "shirt") == 0) {
												
												if (num_Cust == 1)
													printf("\n\nThe least expensive of all %d items bought by the customer is: \n\n\ta shirt worth %.2f$", tIB, leastExp[0]);									
												else
													printf("\n\nThe least expensive of all %d items bought by all %d customers is: \n\n\ta shirt worth %.2f$", tIB, num_Cust, leastExp[0]);						
											}
											
												else if (strcmp(itN1[0], "skirt") == 0) {
													
													if (num_Cust == 1)
														printf("\n\nThe least expensive of all %d items bought by the customer is: \n\n\ta skirt worth %.2f$", tIB, leastExp[0]);									
													else
														printf("\n\nThe least expensive of all %d items bought by all %d customers is: \n\n\ta skirt worth %.2f$", tIB, num_Cust, leastExp[0]);						
												}
												
													else if (strcmp(itN1[0], "pair of trousers") == 0) {
														
														if (num_Cust == 1)
															printf("\n\nThe least expensive of all %d items bought by the customer is: \n\n\ta pair of trousers worth %.2f$", tIB, leastExp[0]);									
														else
															printf("\n\nThe least expensive of all %d items bought by all %d customers is: \n\n\ta pair of trousers worth %.2f$", tIB, num_Cust, leastExp[0]);						
													}
													
														else if (strcmp(itN1[0], "pair of shoes") == 0) {
															
															if (num_Cust == 1)
																printf("\n\nThe least expensive of all %d items bought by the customer is: \n\n\ta pair of shoes worth %.2f", tIB, leastExp[0]);									
															else
																printf("\n\nThe least expensive of all %d items bought by all %d customers is: \n\n\ta pair of shoes worth %.2f", tIB, num_Cust, leastExp[0]);						
														}
	
									
								
								//*********************************************************************
								//*																      *
								//*	 4) finding most expensive item bought (all customers included)   *					
								//*																      *	
								//*********************************************************************
									
								
								for(x=0; x<num_Cust; ++x) {
									
									if (customer[x].numHat > 0)
										decr1(x); //bubble sorting in decreasing order									
									if (customer[x].numCoat > 0)	
										decr2(x);										
									if (customer[x].numBlou > 0)	
										decr3(x);										
									if (customer[x].numShir > 0)	
										decr4(x);										
									if (customer[x].numSkir > 0)	
										decr5(x);										
									if (customer[x].numTrou > 0)	
										decr6(x);										
									if (customer[x].numShoe > 0)
										decr7(x);
								}
								
								for(x=0, y=0; x < num_Cust; ++x) {
									
									if(customer[x].head[0].prHat > 0) {
										mostExp[y] = customer[x].head[0].prHat;
										strcpy(itN2[y], "hat");
										++y;
									}
										
									if(customer[x].bMF1[0].prCoat > 0) {
										mostExp[y] = customer[x].bMF1[0].prCoat;
										strcpy(itN2[y], "coat");
										++y;
									}
									
									if(customer[x].bodF[0].prBlou > 0)	{
										mostExp[y] = customer[x].bodF[0].prBlou;
										strcpy(itN2[y], "blouse");
										++y;
									}
									
									if(customer[x].bMF2[0].prShir > 0) {
										mostExp[y] = customer[x].bMF2[0].prShir;
										strcpy(itN2[y], "shirt");
										++y;
									}
									
									if(customer[x].legF[0].prSkir > 0) {
										mostExp[y] = customer[x].legF[0].prSkir;
										strcpy(itN2[y], "skirt");
										++y;
									}
									
									if(customer[x].legMF[0].prTrou > 0) {
										mostExp[y] = customer[x].legMF[0].prTrou;
										strcpy(itN2[y], "pair of trousers");
										++y;
									}
									
									if(customer[x].feet[0].prShoe > 0) {
										mostExp[y] = customer[x].feet[0].prShoe;
										strcpy(itN2[y], "pair of shoes");
										++y;
									}									
								}
								
								max2 = y;
								
								//BUBBLE SORT TECHNIQUE (in decreasing order):
								for(sME1=0; sME1 < max2-1; ++sME1) //REMINDER: arrays are sorted from 0 to n-1; hence: "a<n-1"
									//finding the biggest of all remaining elements:
									for(sME2=0; sME2 < max2-1; ++sME2)
										if(mostExp[sME2] < mostExp[sME2+1]) {
											//swapping (prices AND names of items):
											temp2 = mostExp[sME2+1];
											mostExp[sME2+1] = mostExp[sME2];
											mostExp[sME2] = temp2;
											//second swap: CORRESPONDING ITEMS
											strcpy(t_a2[0], itN2[sME2+1]);											
											strcpy(itN2[sME2+1], itN2[sME2]);
											strcpy(itN2[sME2], t_a2[0]);	
										}
								

									
								if (strcmp(itN2[0], "hat") == 0) {
																	
									if (num_Cust == 1)
										printf("\n\nThe most expensive of all %d items bought by the customer is:\n\n\ta hat worth %.2f$\n\n", tIB, mostExp[0]);
									else
										printf("\n\nThe most expensive of all %d items bought by all %d customers is:\n\n\ta hat worth %.2f$\n\n", tIB, num_Cust, mostExp[0]);						
								}
								
									else if (strcmp(itN2[0], "coat") == 0) {
										
										if (num_Cust == 1)
											printf("\n\nThe most expensive of all %d items bought by the customer is:\n\n\ta coat worth %.2f$\n\n", tIB, mostExp[0]);
										else
											printf("\n\nThe most expensive of all %d items bought by all %d customers is:\n\n\ta coat worth %.2f$\n\n", tIB, num_Cust, mostExp[0]);						
									}
									
										else if (strcmp(itN2[0], "blouse") == 0) {
											
											if (num_Cust == 1)
												printf("\n\nThe most expensive of all %d items bought by the customer is:\n\n\ta blouse worth %.2f$\n\n", tIB, mostExp[0]);
											else
												printf("\n\nThe most expensive of all %d items bought by all %d customers is:\n\n\ta blouse worth %.2f$\n\n", tIB, num_Cust, mostExp[0]);						
										}
										
											else if (strcmp(itN2[0], "shirt") == 0) {
												
												if (num_Cust == 1)
													printf("\n\nThe most expensive of all %d items bought by the customer is:\n\n\ta shirt worth %.2f$\n\n", tIB, mostExp[0]);
												else
													printf("\n\nThe most expensive of all %d items bought by all %d customers is:\n\n\ta shirt worth %.2f$\n\n", tIB, num_Cust, mostExp[0]);						
											}
											
												else if (strcmp(itN2[0], "skirt") == 0) {
													
													if (num_Cust == 1)
														printf("\n\nThe most expensive of all %d items bought by the customer is:\n\n\ta skirt worth %.2f$\n\n", tIB, mostExp[0]);
													else
														printf("\n\nThe most expensive of all %d items bought by all %d customers is:\n\n\ta skirt worth %.2f$\n\n", tIB, num_Cust, mostExp[0]);						
												}
												
													else if (strcmp(itN2[0], "pair of trousers") == 0) {
														
														if (num_Cust == 1)
															printf("\n\nThe most expensive of all %d items bought by the customer is:\n\n\ta pair of trousers worth %.2f$\n\n", tIB, mostExp[0]);
														else
															printf("\n\nThe most expensive of all %d items bought by all %d customers is:\n\n\ta a pair of trousers worth %.2f$\n\n", tIB, num_Cust, mostExp[0]);						
													}
													
														else if (strcmp(itN2[0], "pair of shoes") == 0) {
																
															if (num_Cust == 1)
																printf("\n\nThe most expensive of all %d items bought by the customer is:\n\n\ta pair of shoes worth %.2f$\n\n", tIB, mostExp[0]);
															else
																printf("\n\nThe most expensive of all %d items bought by all %d customers is:\n\n\ta pair of shoes worth %.2f$\n\n", tIB, num_Cust, mostExp[0]);						
														}
														
								//NUMBER OF COMMENTS LEFT BY CUSTOMER(S):
								num_Comments(num_Cust, nCom);
								
								//details of postage services chosen by all customers:
								num_Post(&super_fast, &normal, &discount);
									
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
	
	printf("\tWELCOME TO THE MAZANON ONLINE CLOTHES SHOP\n\n");
	
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
	scanf(" %[^\n]", customer[x].ID.cusNumber);
	
	printf("\nCustomer name:\n");
	scanf(" %[^\n]", customer[x].ID.name);		
		
	printf("\nCustomer address:\n");
	scanf(" %[^\n]", customer[x].ID.address);
	
	printf("\nCustomer telephone number:\n");
	scanf(" %[^\n]", customer[x].ID.tel_num);


	getchar();
	return;
}

//************************** reading input for members of structure type HAT *******************************************************

void rOrHat(int x, int* allIB) {
		
	char an1;
	int i, nHat;

	
	printf("\nAny hats bought? (y/n)\n");
	an1 = getchar();
	getchar();
	
	if (an1 == 'y') {
			
		printf("How many hats?\n");
		scanf("%d", &customer[x].numHat);
		//NEW ADDITION: ANOTHER getchar(), otherwise it does not work!!!!!!!!!!!!!!!!!!
		getchar();
		
		nHat = customer[x].numHat;
		
		if (nHat == 1) {
			
			for(i=0; i<nHat; ++i) {
				
				printf("\nChoose brand of hat:\n");
				printf("(a) Kangol\n");
				printf("(b) Jaxon\n");
				printf("(c) Tilley\n");
				printf("(d) Stetson\n");
				printf("(e) Maddox\n");
				
				customer[x].chHat[i] = getchar();
				getchar();
				
				if (customer[x].chHat[i] == 'a')
					customer[x].head[i].ptBHat = "Kangol";
					else if (customer[x].chHat[i] == 'b')
						customer[x].head[i].ptBHat = "Jaxon";
						else if (customer[x].chHat[i] == 'c')
							customer[x].head[i].ptBHat = "Tilley";
							else if (customer[x].chHat[i] == 'd')
								customer[x].head[i].ptBHat = "Stetson";
									else if (customer[x].chHat[i] == 'e')
										customer[x].head[i].ptBHat = "Maddox";
				
				printf("\n\nSize of hat:\n");
				scanf("%d", &customer[x].head[i].sHat);
					
				printf("\nPrice of hat:\n");
				scanf("%f", &customer[x].head[i].prHat);
					
				customer[x].total += customer[x].head[i].prHat;
				
				*allIB += 1;
			
			}			
		}
		
		else {
			
			for(i=0; i<nHat; ++i) {
			
				printf("\nChoose brand of hat no.%d:\n", i+1);
				printf("(a) Kangol\n");
				printf("(b) Jaxon\n");
				printf("(c) Tilley\n");
				printf("(d) Stetson\n");
				printf("(e) Maddox\n");
				
				customer[x].chHat[i] = getchar();
				getchar();
				

				if (customer[x].chHat[i] == 'a')
					customer[x].head[i].ptBHat = "Kangol";
					else if (customer[x].chHat[i] == 'b')
						customer[x].head[i].ptBHat = "Jaxon";
						else if (customer[x].chHat[i] == 'c')
							customer[x].head[i].ptBHat = "Tilley";
							else if (customer[x].chHat[i] == 'd')
								customer[x].head[i].ptBHat = "Stetson";
									else if (customer[x].chHat[i] == 'e')
										customer[x].head[i].ptBHat = "Maddox";
												
				
				printf("\n\nSize of hat no.%d:\n", i+1);
				scanf("%d", &customer[x].head[i].sHat);
					
				printf("\nPrice of hat no.%d:\n", i+1);
				scanf("%f", &customer[x].head[i].prHat);
				
				customer[x].total += customer[x].head[i].prHat;
				
				*allIB += 1;
							
			}
		}
		
		getchar();
	}

	return;
}

//************************** reading input for members of structure type COAT *******************************************************

void rOrCoat(int x, int *allIB) {

	int i, nCoat;
	char an2;
	
	printf("\nAny coats bought? (y/n)\n");
	an2 = getchar();
	getchar();
	
	if (an2 == 'y') {
			
		printf("How many coats?\n");
		scanf("%d", &customer[x].numCoat);
		//NEW ADDITION: ANOTHER getchar(), otherwise it does not work!!!!!!!!!!!!!!!!!!
		getchar();
		
		nCoat = customer[x].numCoat;
		
		if (nCoat == 1) {
			
			for(i=0; i<nCoat; ++i) {
			
				printf("\nChoose brand of coat:\n");
				printf("(a) Astley\n");
				printf("(b) Burton\n");
				printf("(c) Haddington\n");
				printf("(d) Jaeger\n");
				printf("(e) Jack & Jones\n");
				
				customer[x].chCoat[i] = getchar();
				getchar();
				
				if (customer[x].chCoat[i] == 'a')
					customer[x].bMF1[i].ptBCoat = "Astley";
					else if (customer[x].chCoat[i] == 'b')
						customer[x].bMF1[i].ptBCoat = "Burton";
						else if (customer[x].chCoat[i] == 'c')
							customer[x].bMF1[i].ptBCoat = "Haddington";
							else if (customer[x].chCoat[i] == 'd')
								customer[x].bMF1[i].ptBCoat = "Jaeger";
									else if (customer[x].chCoat[i] == 'e')
										customer[x].bMF1[i].ptBCoat = "Jack & Jones";
				
				printf("\nSize of coat:\n");
				scanf("%d", &customer[x].bMF1[i].sCoat);
					
				printf("\nPrice of coat:\n");
				scanf("%f", &customer[x].bMF1[i].prCoat);
				
				customer[x].total += customer[x].bMF1[i].prCoat;
				
				*allIB += 1;	
			}		
		}
		
		else {
			
			for(i=0; i<nCoat; ++i) {
				
				printf("\nChoose brand of coat no.%d:\n", i+1);
				printf("(a) Astley\n");
				printf("(b) Burton\n");
				printf("(c) Haddington\n");
				printf("(d) Jaeger\n");
				printf("(e) Jack & Jones\n");
				
				customer[x].chCoat[i] = getchar();
				getchar();
				
				if (customer[x].chCoat[i] == 'a')
					customer[x].bMF1[i].ptBCoat = "Astley";
					else if (customer[x].chCoat[i] == 'b')
						customer[x].bMF1[i].ptBCoat = "Burton";
						else if (customer[x].chCoat[i] == 'c')
							customer[x].bMF1[i].ptBCoat = "Haddington";
							else if (customer[x].chCoat[i] == 'd')
								customer[x].bMF1[i].ptBCoat = "Jaeger";
									else if (customer[x].chCoat[i] == 'e')
										customer[x].bMF1[i].ptBCoat = "Jack & Jones";
				
				printf("\nSize of coat no.%d:\n", i+1);
				scanf("%d", &customer[x].bMF1[i].sCoat);
				
				printf("\nPrice of coat no.%d:\n", i+1);
				scanf("%f", &customer[x].bMF1[i].prCoat);	
				
				customer[x].total += customer[x].bMF1[i].prCoat;
				
				*allIB += 1;			
			}
		}
		
		getchar();
	}

	return;
}	

//************************** reading input for members of structure type BLOUSE *******************************************************

void rOrBlou(int x, int *allIB) {
	
	int i, nBlouse;
	char an3;
	
	printf("\nAny blouses bought? (y/n)\n");
	an3 = getchar();
	getchar();
	
	if (an3 == 'y') {
			
		printf("How many blouses?\n");
		scanf("%d", &customer[x].numBlou);
		//NEW ADDITION: ANOTHER getchar(), otherwise it does not work!!!!!!!!!!!!!!!!!!
		getchar();
		
		nBlouse = customer[x].numBlou;
		
		if (nBlouse == 1) {
			
			for(i=0; i<nBlouse; ++i) {
			
				printf("\nChoose brand of blouse:\n");
				printf("(a) Bellfield\n");
				printf("(b) 883 Police\n");
				printf("(c) Duck & Cover\n");
				printf("(d) Foray\n");
				printf("(e) Nanny State\n");
				
				customer[x].chBlou[i] = getchar();
				getchar();
				
				if (customer[x].chBlou[i] == 'a')
					customer[x].bodF[i].ptBBlou = "Bellfield";
					else if (customer[x].chBlou[i] == 'b')
						customer[x].bodF[i].ptBBlou = "883 Police";
						else if (customer[x].chBlou[i] == 'c')
							customer[x].bodF[i].ptBBlou = "Duck & Cover";
							else if (customer[x].chBlou[i] == 'd')
								customer[x].bodF[i].ptBBlou = "Foray";
									else if (customer[x].chBlou[i] == 'e')
										customer[x].bodF[i].ptBBlou = "Nanny State";
				
				printf("\nSize of blouse:\n");
				scanf("%d", &customer[x].bodF[i].sBlou);
					
				printf("\nPrice of blouse:\n");
				scanf("%f", &customer[x].bodF[i].prBlou);	
					
				customer[x].total += customer[x].bodF[i].prBlou;	
				
				*allIB += 1;
			}
		}
		
		else {
			
			for(i=0; i<nBlouse; ++i) {
				
				printf("\nChoose brand of blouse no.%d:\n", i+1);
				printf("(a) Bellfield\n");
				printf("(b) 883 Police\n");
				printf("(c) Duck & Cover\n");
				printf("(d) Foray\n");
				printf("(e) Nanny State\n");
				
				customer[x].chBlou[i] = getchar();
				getchar();
				
				if (customer[x].chBlou[i] == 'a')
					customer[x].bodF[i].ptBBlou = "Bellfield";
					else if (customer[x].chBlou[i] == 'b')
						customer[x].bodF[i].ptBBlou = "883 Police";
						else if (customer[x].chBlou[i] == 'c')
							customer[x].bodF[i].ptBBlou = "Duck & Cover";
							else if (customer[x].chBlou[i] == 'd')
								customer[x].bodF[i].ptBBlou = "Foray";
									else if (customer[x].chBlou[i] == 'e')
										customer[x].bodF[i].ptBBlou = "Nanny State";
			
				printf("\nSize of blouse no.%d:\n", i+1);
				scanf("%d", &customer[x].bodF[i].sBlou);
				
				printf("\nPrice of blouse no.%d:\n", i+1);
				scanf("%f", &customer[x].bodF[i].prBlou);	
				
				customer[x].total += customer[x].bodF[i].prBlou;
				
				*allIB += 1;		
			}			
		}
				
		getchar();
	}

	return;
}

//************************** reading input for members of structure type SHIRT *******************************************************

void rOrShirt(int x, int *allIB) {

	int i, nShirt;
	char an4;
	
	printf("\nAny shirts bought? (y/n)\n");
	an4 = getchar();
	getchar();
	
	if (an4 == 'y') {
			
		printf("How many shirts?\n");
		scanf("%d", &customer[x].numShir);
		//NEW ADDITION: ANOTHER getchar(), otherwise it does not work!!!!!!!!!!!!!!!!!!
		getchar();
		
		nShirt = customer[x].numShir;
		
		if (nShirt == 1) {
			for(i=0; i<nShirt; ++i) {
			
				printf("\nChoose brand of shirt:\n");
				printf("(a) Abercrombie & Fitch\n");
				printf("(b) Ben Sherman\n");
				printf("(c) Calvin Klein\n");
				printf("(d) Dolce & Gabbana\n");
				printf("(e) Emporio Armani\n");
				
				customer[x].chShir[i] = getchar();
				getchar();
				
				if (customer[x].chShir[i] == 'a')
					customer[x].bMF2[i].ptBShir = "Abercrombie & Fitch";
					else if (customer[x].chShir[i] == 'b')
						customer[x].bMF2[i].ptBShir = "Ben Sherman";
						else if (customer[x].chShir[i] == 'c')
							customer[x].bMF2[i].ptBShir = "Calvin Klein";
							else if (customer[x].chShir[i] == 'd')
								customer[x].bMF2[i].ptBShir = "Dolce & Gabbana";
									else if (customer[x].chShir[i] == 'e')
										customer[x].bMF2[i].ptBShir = "Emporio Armani";
					
				printf("\nSize of shirt:\n");
				scanf("%d", &customer[x].bMF2[i].sShir);
					
				printf("\nPrice of shirt:\n");
				scanf("%f", &customer[x].bMF2[i].prShir);	
					
				customer[x].total += customer[x].bMF2[i].prShir;	
				
				*allIB += 1;
			}		
		}
		
		else {
		
			for(i=0; i<nShirt; ++i) {
				
				printf("\nChoose brand of shirt no.%d:\n", i+1);
				printf("(a) Abercrombie & Fitch\n");
				printf("(b) Ben Sherman\n");
				printf("(c) Calvin Klein\n");
				printf("(d) Dolce & Gabbana\n");
				printf("(e) Emporio Armani\n");
				
				customer[x].chShir[i] = getchar();
				getchar();
				
				if (customer[x].chShir[i] == 'a')
					customer[x].bMF2[i].ptBShir = "Abercrombie & Fitch";
					else if (customer[x].chShir[i] == 'b')
						customer[x].bMF2[i].ptBShir = "Ben Sherman";
						else if (customer[x].chShir[i] == 'c')
							customer[x].bMF2[i].ptBShir = "Calvin Klein";
							else if (customer[x].chShir[i] == 'd')
								customer[x].bMF2[i].ptBShir = "Dolce & Gabbana";
									else if (customer[x].chShir[i] == 'e')
										customer[x].bMF2[i].ptBShir = "Emporio Armani";
				
				printf("\nSize of shirt no.%d:\n", i+1);
				scanf("%d", &customer[x].bMF2[i].sShir);
				
				printf("\nPrice of shirt no.%d:\n", i+1);
				scanf("%f", &customer[x].bMF2[i].prShir);	
				
				customer[x].total += customer[x].bMF2[i].prShir;
				
				*allIB += 1;		
			}
		}
		
		getchar();
	}
	
	return;
}

//************************** reading input for members of structure type SKIRT *******************************************************
	
void rOrSkirt(int x, int *allIB) {

	int i, nSkir, tot5;
	char an5;
	
	printf("\nAny skirts bought? (y/n)\n");
	an5 = getchar();
	getchar();
	
	if (an5 == 'y') {
			
		printf("How many skirts?\n");
		scanf("%d", &customer[x].numSkir);
		//NEW ADDITION: ANOTHER getchar(), otherwise it does not work!!!!!!!!!!!!!!!!!!
		getchar();
		
		nSkir = customer[x].numSkir;
		
		if (nSkir == 1) {
			
			for(i=0; i<nSkir; ++i) {
			
				printf("\nChoose brand of skirt:\n");
				printf("(a) Karl Lagerfeld\n");
				printf("(b) Jonathan Saunders\n");
				printf("(c) Nina Ricci\n");
				printf("(d) Moschino\n");
				printf("(e) Lanvin\n");
				
				customer[x].chSkir[i] = getchar();
				getchar();
				
				if (customer[x].chSkir[i] == 'a')
					customer[x].legF[i].ptBSkir = "Karl Lagerfeld";
					else if (customer[x].chSkir[i] == 'b')
						customer[x].legF[i].ptBSkir = "Jonathan Saunders";
						else if (customer[x].chSkir[i] == 'c')
							customer[x].legF[i].ptBSkir = "Nina Ricci";
							else if (customer[x].chSkir[i] == 'd')
								customer[x].legF[i].ptBSkir = "Moschino";
									else if (customer[x].chSkir[i] == 'e')
										customer[x].legF[i].ptBSkir = "Lanvin";
		
				printf("\nSize of skirt:\n");
				scanf("%d", &customer[x].legF[i].sSkir);
					
				printf("\nPrice of skirt:\n");
				scanf("%f", &customer[x].legF[i].prSkir);	
				
				customer[x].total += customer[x].legF[i].prSkir;
				
				*allIB += 1;	
			}			
		}
		
		else {
		
			for(i=0; i<nSkir; ++i) {
				
				printf("\nChoose brand of skirt no.%d:\n", i+1);
				printf("(a) Karl Lagerfeld\n");
				printf("(b) Jonathan Saunders\n");
				printf("(c) Nina Ricci\n");
				printf("(d) Moschino\n");
				printf("(e) Lanvin\n");
				
				customer[x].chSkir[i] = getchar();
				getchar();
				
				if (customer[x].chSkir[i] == 'a')
					customer[x].legF[i].ptBSkir = "Karl Lagerfeld";
					else if (customer[x].chSkir[i] == 'b')
						customer[x].legF[i].ptBSkir = "Jonathan Saunders";
						else if (customer[x].chSkir[i] == 'c')
							customer[x].legF[i].ptBSkir = "Nina Ricci";
							else if (customer[x].chSkir[i] == 'd')
								customer[x].legF[i].ptBSkir = "Moschino";
									else if (customer[x].chSkir[i] == 'e')
										customer[x].legF[i].ptBSkir = "Lanvin";
	
				printf("\nSize of skirt no.%d:\n", i+1);
				scanf("%d", &customer[x].legF[i].sSkir);
				
				printf("\nPrice of skirt no.%d:\n", i+1);
				scanf("%f", &customer[x].legF[i].prSkir);	
				
				customer[x].total += customer[x].legF[i].prSkir;
				
				*allIB += 1;			
			}
		}
		
		getchar();
	}

	return;
}

//************************** reading input for members of structure type TROUSERS *******************************************************

void rOrTrou(int x, int *allIB) {

	int i, nTrous;
	char an6;
	
	printf("\nAny pairs of trousers bought? (y/n)\n");
	an6 = getchar();
	getchar();
	
	if (an6 == 'y') {
			
		printf("How many pairs of trousers?\n");
		scanf("%d", &customer[x].numTrou);
		//NEW ADDITION: ANOTHER getchar(), otherwise it does not work!!!!!!!!!!!!!!!!!!
		getchar();
		
		nTrous = customer[x].numTrou;
		
		if (nTrous == 1) {
			
			for(i=0; i<nTrous; ++i) {
			
				printf("\nChoose brand of trousers:\n");
				printf("(a) G-Star\n");
				printf("(b) Vivienne Westwood\n");
				printf("(c) Levi's\n");
				printf("(d) Tommy Hilfiger\n");
				printf("(e) Skopes\n");
				
				customer[x].chTrou[i] = getchar();
				getchar();
				
				if (customer[x].chTrou[i] == 'a')
					customer[x].legMF[i].ptBTrou = "G-Star";
					else if (customer[x].chTrou[i] == 'b')
						customer[x].legMF[i].ptBTrou  = "Vivienne Westwood";
						else if (customer[x].chTrou[i] == 'c')
							customer[x].legMF[i].ptBTrou  = "Levi's";
							else if (customer[x].chTrou[i] == 'd')
								customer[x].legMF[i].ptBTrou  = "Tommy Hilfiger";
									else if (customer[x].chTrou[i] == 'e')
										customer[x].legMF[i].ptBTrou = "Skopes";
		
				printf("\nSize of pair of trousers:\n");
				scanf("%d", &customer[x].legMF[i].sTrou);
					
				printf("\nPrice of pair of trousers\n");
				scanf("%f", &customer[x].legMF[i].prTrou);	
					
				customer[x].total += customer[x].legMF[i].prTrou;
				
				*allIB += 1;
			}			
		}
		
		else  {
		
			for(i=0; i<nTrous; ++i) {
				
				printf("\nChoose brand of trousers no.%d:\n", i+1);
				printf("(a) G-Star\n");
				printf("(b) Vivienne Westwood\n");
				printf("(c) Levi's\n");
				printf("(d) Tommy Hilfiger\n");
				printf("(e) Skopes\n");
				
				customer[x].chTrou[i] = getchar();
				getchar();
				
				if (customer[x].chTrou[i] == 'a')
					customer[x].legMF[i].ptBTrou  = "G-Star";
					else if (customer[x].chTrou[i] == 'b')
						customer[x].legMF[i].ptBTrou  = "Vivienne Westwood";
						else if (customer[x].chTrou[i] == 'c')
							customer[x].legMF[i].ptBTrou  = "Levi's";
							else if (customer[x].chTrou[i] == 'd')
								customer[x].legMF[i].ptBTrou  = "Tommy Hilfiger";
									else if (customer[x].chTrou[i] == 'e')
										customer[x].legMF[i].ptBTrou  = "Skopes";
	
				printf("\nSize of pair of trousers no.%d:\n", i+1);
				scanf("%d", &customer[x].legMF[i].sTrou);
				
				printf("\nPrice of pair of trousers no.%d:\n", i+1);
				scanf("%f", &customer[x].legMF[i].prTrou);	
				
				customer[x].total += customer[x].legMF[i].prTrou;	
				
				*allIB += 1;	
			}
		}
		
		getchar();
	}

	return;
}

//************************** reading input for members of structure type SHOES *******************************************************

void rOrSoe(int x, int *allIB) {

	int i, nShoes;
	char an7;
	
	printf("\nAny pairs of shoes bought? (y/n)\n");
	an7 = getchar();
	getchar();
	
	if (an7 == 'y') {
			
		printf("How many pairs of shoes?\n");
		scanf("%d", &customer[x].numShoe);
		//NEW ADDITION: ANOTHER getchar(), otherwise it does not work!!!!!!!!!!!!!!!!!!
		getchar();
		
		nShoes = customer[x].numShoe;
		
		if (nShoes == 1) {
			
			for(i=0; i<nShoes; ++i) {
		
				printf("\nChoose brand of shoes:\n");
				printf("(a) New Balance\n");
				printf("(b) Zara\n");
				printf("(c) Nike\n");
				printf("(d) Minnetonka Moccasin\n");
				printf("(e) Fergalicious\n");
				
				customer[x].chShoe[i] = getchar();
				getchar();
				
				if (customer[x].chShoe[i] == 'a')
					customer[x].feet[i].ptBShoe  = "New Balance";
					else if (customer[x].chShoe[i] == 'b')
						customer[x].feet[i].ptBShoe = "Zara";
						else if (customer[x].chShoe[i] == 'c')
							customer[x].feet[i].ptBShoe = "Nike";
							else if (customer[x].chShoe[i] == 'd')
								customer[x].feet[i].ptBShoe = "Minnetonka Moccasin";
									else if (customer[x].chShoe[i] == 'e')
										customer[x].feet[i].ptBShoe = "Fergalicious";
		
				printf("\nSize of pair of shoes:\n");
				scanf("%d", &customer[x].feet[i].sShoe);
					
				printf("\nPrice of pair of shoes:\n");
				scanf("%f", &customer[x].feet[i].prShoe);	
					
				customer[x].total += customer[x].feet[i].prShoe;
				
				*allIB += 1;	
			}			
		}
		
		else {
		
			for(i=0; i<nShoes; ++i) {			
					
				printf("\nChoose brand of shoes no.%d:\n", i+1);
				printf("(a) New Balance\n");
				printf("(b) Zara\n");
				printf("(c) Nike\n");
				printf("(d) Minnetonka Moccasin\n");
				printf("(e) Fergalicious\n");
				
				customer[x].chShoe[i] = getchar();
				getchar();
				
				if (customer[x].chShoe[i] == 'a')
					customer[x].feet[i].ptBShoe = "New Balance";
					else if (customer[x].chShoe[i] == 'b')
						customer[x].feet[i].ptBShoe = "Zara";
						else if (customer[x].chShoe[i] == 'c')
							customer[x].feet[i].ptBShoe = "Nike";
							else if (customer[x].chShoe[i] == 'd')
								customer[x].feet[i].ptBShoe = "Minnetonka Moccasin";
									else if (customer[x].chShoe[i] == 'e')
										customer[x].feet[i].ptBShoe = "Fergalicious";
	
				printf("\nSize of pair of shoes no.%d:\n", i+1);
				scanf("%d", &customer[x].feet[i].sShoe);
				
				printf("\nPrice of pair of shoes no.%d:\n", i+1);
				scanf("%f", &customer[x].feet[i].prShoe);	
				
				customer[x].total += customer[x].feet[i].prShoe;
				
				*allIB += 1;		
			}
		}
		
		getchar();
	}

	return;
}

//*************************** type of courrier service *****************************************************************

void courrierServ(int x, int *sup_F, int *norm, int *disc) {
	
	printf("\nType of courrier service:\n");
	printf("Press (a) for SUPER-FAST POSTAGE [2 working days] = 14.99$\n");		
	printf("Press (b) for NORMAL POSTAGE [7-10 working days] = 9.99$\n");
	printf("Press (c) for DISCOUNT POSTAGE [2-3 weeks] = 2.99$\n");
	printf("Press (d) if number of orders is void.\n");
				
	customer[x].courServ = getchar();

	if (customer[x].courServ == 'a') {
		customer[x].total += 14.99;
		*sup_F += 1;
	}		
		else if (customer[x].courServ == 'b') {
			customer[x].total += 9.99;
			*norm += 1;
		}			
			else if (customer[x].courServ == 'c') {
				customer[x].total += 2.99;
				*disc += 1;				
			}					
				else
					printf("");	
							
	getchar();			
	return;
}

//*************************** CUSTOMER COMMENT (IF ANY) *****************************************************************

void comment(int x, int *numCom) {
	
	printf("\nHas this customer left a message regarding his/her order(s) (y/n)?\n");
	
	customer[x].indCom = getchar();
	getchar();
		
	if (customer[x].indCom == 'y') {
		++(*numCom);
		printf("Re-type the customer's message:\n");
		scanf(" %[^\n]", customer[x].comment);
		getchar();
	}
	
	else
		printf("");

	return;			
}

//*************************** FIND LEAST EXPENSIVE ITEM PER CATEGORY *****************************************************************

/*
NOTE:
the following  "incr" functions below find the least expensive item per item category for all customers.
*/
void incr1 (int x) {
	
	int a, b;
	float temp;

		//BUBBLE SORT TECHNIQUE:
	for(a=0; a<customer[x].numHat-1; ++a) //REMINDER: arrays are sorted from 0 to n-1; hence: "a<n-1"
		//finding the smallest of all remaining elements:
		for(b=0; b<customer[x].numHat-1; ++b)
			if(customer[x].head[b].prHat > customer[x].head[b+1].prHat) { //NOTE: if we want to reorder in DECREASING order (ie: sorting from biggest to smallest), simply change > to <
				//swapping:
				temp = customer[x].head[b+1].prHat;
				customer[x].head[b+1].prHat = customer[x].head[b].prHat;
				customer[x].head[b].prHat = temp;
			}

	return;
}

void incr2 (int x) {
	
	int a, b;
	float temp;

	for(a=0; a<customer[x].numCoat-1; ++a)
		for(b=0; b<customer[x].numCoat-1; ++b)
			if(customer[x].bMF1[b].prCoat > customer[x].bMF1[b+1].prCoat) {
				temp = customer[x].bMF1[b+1].prCoat;
				customer[x].bMF1[b+1].prCoat = customer[x].bMF1[b].prCoat;
				customer[x].bMF1[b].prCoat = temp;
			}

	return;
}


void incr3 (int x) {
	
	int a, b;
	float temp;

	for(a=0; a<customer[x].numBlou-1; ++a)
		for(b=0; b<customer[x].numBlou-1; ++b)
			if(customer[x].bodF[b].prBlou > customer[x].bodF[b+1].prBlou) {
				temp = customer[x].bodF[b+1].prBlou;
				customer[x].bodF[b+1].prBlou = customer[x].bodF[b].prBlou;
				customer[x].bodF[b].prBlou = temp;
			}

	return;
}


void incr4 (int x) {
	
	int a, b;
	float temp;

	for(a=0; a<customer[x].numShir-1; ++a)
		for(b=0; b<customer[x].numShir-1; ++b)
			if(customer[x].bMF2[b].prShir > customer[x].bMF2[b+1].prShir) {
				temp = customer[x].bMF2[b+1].prShir;
				customer[x].bMF2[b+1].prShir = customer[x].bMF2[b].prShir;
				customer[x].bMF2[b].prShir = temp;
			}

	return;
}


void incr5 (int x) {
	
	int a, b;
	float temp;

	for(a=0; a<customer[x].numSkir-1; ++a)
		for(b=0; b<customer[x].numSkir-1; ++b)
			if(customer[x].legF[b].prSkir > customer[x].legF[b+1].prSkir) {
				temp = customer[x].legF[b+1].prSkir;
				customer[x].legF[b+1].prSkir = customer[x].legF[b].prSkir;
				customer[x].legF[b].prSkir = temp;
			}

	return;
}


void incr6 (int x) {
	
	int a, b;
	float temp;

	for(a=0; a<customer[x].numTrou-1; ++a)
		for(b=0; b<customer[x].numTrou-1; ++b)
			if(customer[x].legMF[b].prTrou > customer[x].legMF[b+1].prTrou) {
				temp = customer[x].legMF[b+1].prTrou;
				customer[x].legMF[b+1].prTrou = customer[x].legMF[b].prTrou;
				customer[x].legMF[b].prTrou = temp;
			}

	return;
}


void incr7 (int x) {
	
	int a, b;
	float temp;

	for(a=0; a<customer[x].numShoe-1; ++a)
		for(b=0; b<customer[x].numShoe-1; ++b)
			if(customer[x].feet[b].prShoe > customer[x].feet[b+1].prShoe) {
				temp = customer[x].feet[b+1].prShoe;
				customer[x].feet[b+1].prShoe = customer[x].feet[b].prShoe;
				customer[x].feet[b].prShoe = temp;
			}

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
	printf("CUSTOMER ID: %s\n", customer[x].ID.cusNumber);
	printf("CUSTOMER NAME: %s\n", customer[x].ID.name);
	printf("CUSTOMER ADDRESS: %s\n", customer[x].ID.address);		
	printf("CUSTOMER TELEPHONE NUMBER: %s\n", customer[x].ID.tel_num);
	
	//if no items have been bought at all:
	if (customer[x].numHat == 0 && customer[x].numCoat == 0 && customer[x].numBlou == 0 && customer[x].numShir == 0 && customer[x].numSkir == 0 && customer[x].numTrou == 0 && customer[x].numShoe == 0) {
		
		printf("\n%s has not passed any orders.", customer[x].ID.name);
		
		if (customer[x].indCom == 'y')
			printf("\n\n%s has posted a comment:\n\n%s", customer[x].ID.name, customer[x].comment);
		else
			printf("\n\n%s has left no comment.", customer[x].ID.name);
	}
		
	else {
	
		
//******************************** hats *******************************************************	
	
		if (customer[x].numHat > 0) {
			
			if (customer[x].numHat == 1) {
					
				for(a=0; a<customer[x].numHat; ++a) {
					
					printf("\n\n%s has ordered one hat:\n", customer[x].ID.name);
					printf("\nBrand of hat: %s", customer[x].head[a].ptBHat);
					printf("\nSize of hat: %d", customer[x].head[a].sHat);
					printf("\nPrice of hat: %.2f$", customer[x].head[a].prHat);
				}
			}
				
			else {
				
				printf("\n\n%s has ordered %d hats:\n", customer[x].ID.name, customer[x].numHat);
					
				for(a=0; a<customer[x].numHat; ++a) {
					
					printf("\nBrand of hat no.%d: %s", a+1, customer[x].head[a].ptBHat);
					printf("\nSize of hat no.%d: %d\n", a+1, customer[x].head[a].sHat);
					printf("Price of hat no.%d: %.2f$\n", a+1, customer[x].head[a].prHat);
				}
			}		
		}	
			
	//******************************** coats *******************************************************
			
		if (customer[x].numCoat > 0) {
			
			if (customer[x].numCoat == 1) {
				
				for(b=0; b<customer[x].numCoat; ++b) {
				
				printf("\n\n%s has ordered one coat:\n", customer[x].ID.name);
				printf("\nBrand of coat: %s", customer[x].bMF1[b].ptBCoat);
				printf("\nSize of coat: %d\n", customer[x].bMF1[b].sCoat);
				printf("Price of coat: %.2f$\n", customer[x].bMF1[b].prCoat);
				}	
			}
				
			else {
				
				printf("\n\n%s has ordered %d coats:\n", customer[x].ID.name, customer[x].numCoat);
			
				for(b=0; b<customer[x].numCoat; ++b) {
					
					printf("\nBrand of coat no.%d: %s", b+1, customer[x].bMF1[b].ptBCoat);
					printf("\nSize of coat no.%d: %d\n", b+1, customer[x].bMF1[b].sCoat);
					printf("Price of coat no.%d: %.2f$\n", b+1, customer[x].bMF1[b].prCoat);
				}	
			}	
		}

			
	//******************************** blouses *******************************************************
			
		if (customer[x].numBlou > 0) {
			
			if (customer[x].numBlou == 1) {
				
				for(c=0; c<customer[x].numBlou; ++c) {
				
				printf("\n\n%s has ordered one blouse:\n", customer[x].ID.name);
				printf("\nBrand of blouse: %s", customer[x].bodF[c].ptBBlou);
				printf("\nSize of blouse: %d\n", customer[x].bodF[c].sBlou);
				printf("Price of blouse: %.2f$\n", customer[x].bodF[c].prBlou);
				}	
			}
			
			else {
			
				printf("\n\n%s has ordered %d blouses:\n", customer[x].ID.name, customer[x].numBlou);
				
				for(c=0; c<customer[x].numBlou; ++c) {
					printf("\nBrand of blouse no.%d: %s", c+1, customer[x].bodF[c].ptBBlou);
					printf("\nSize of blouse no.%d: %d\n", c+1, customer[x].bodF[c].sBlou);
					printf("Price of blouse no.%d: %.2f$\n", c+1, customer[x].bodF[c].prBlou);
				}
			}
		}

			
	//******************************** shirts *******************************************************
	
		if (customer[x].numShir > 0) {
			
			if (customer[x].numShir == 1) {
				
				for(d=0; d<customer[x].numShir; ++d) {
			
				printf("\n\n%s has ordered one shirt:\n", customer[x].ID.name);
				printf("\nBrand of shirt: %s", customer[x].bMF2[d].ptBShir);
				printf("\nSize of shirt: %d\n", customer[x].bMF2[d].sShir);
				printf("Price of shirt: %.2f$\n", customer[x].bMF2[d].prShir);	
				}
			}
			
			else {
				
				printf("\n\n%s has ordered %d shirts:\n", customer[x].ID.name, customer[x].numShir);
				
				for(d=0; d<customer[x].numShir; ++d) {
					printf("\nBrand of shirt no.%d: %s", d+1, customer[x].bMF2[d].ptBShir);
					printf("\nSize of shirt no.%d: %d\n", d+1, customer[x].bMF2[d].sShir);
					printf("Price of shirt no.%d: %.2f$\n", d+1, customer[x].bMF2[d].prShir);
				}
			}
		}

			
	//******************************** skirts *******************************************************
		
		if (customer[x].numSkir > 0) {
			
			if (customer[x].numSkir == 1) {
				
				for(e=0; e<customer[x].numSkir; ++e) {
				
				printf("\n\n%s has ordered one skirt:\n", customer[x].ID.name);
				printf("\nBrand of skirt: %s", customer[x].legF[e].ptBSkir);
				printf("\nSize of skirt: %d\n", customer[x].legF[e].sSkir);
				printf("Total price of skirt: %.2f$\n", customer[x].legF[e].prSkir);
				}			
			}
			
			else {
				
				printf("\n\n%s has ordered %d skirts:\n", customer[x].ID.name, customer[x].numSkir);
				
				for(e=0; e<customer[x].numSkir; ++e) {
					printf("\nBrand of skirt no.%d: %s", e+1, *customer[x].legF[e].ptBSkir);
					printf("\nSize of skirt no.%d: %d\n", e+1, customer[x].legF[e].sSkir);
					printf("Price of skirt no.%d: %.2f$\n", e+1, customer[x].legF[e].prSkir);
				}
			}
		}

		
	//******************************** trousers *******************************************************
		
		if (customer[x].numTrou > 0) {
			
			if (customer[x].numTrou == 1) {
				
				for(f=0; f<customer[x].numTrou; ++f) {
			
				printf("\n\n%s has ordered one pair of trousers:\n", customer[x].ID.name);
				printf("\nBrand of pair of trousers: %s", customer[x].legMF[f].ptBTrou);
				printf("\nSize of pair of trousers: %d\n", customer[x].legMF[f].sTrou);
				printf("Price of pair of trousers: %.2f$\n", customer[x].legMF[f].prTrou);
				}
			}
			
			else {
				
				printf("\n\n%s has ordered %d pairs of trousers:\n", customer[x].ID.name, customer[x].numTrou);
				
				for(f=0; f<customer[x].numTrou; ++f) {
					printf("\nBrand of pair of trousers no.%d: %s", f+1, customer[x].legMF[f].ptBTrou);
					printf("\nSize of pair of trousers no.%d: %d\n", f+1, customer[x].legMF[f].sTrou);
					printf("Price of pair of trousers no.%d: %.2f$\n", f+1, customer[x].legMF[f].prTrou);
				}
			}
		}

		
	//******************************** shoes ***********************************************************
		
		if (customer[x].numShoe > 0) {
			
			if (customer[x].numShoe == 1) {
				
				for(g=0; g<customer[x].numShoe; ++g) {
				
				printf("\n\n%s has ordered one pair of shoes:\n", customer[x].ID.name);
				printf("\nBrand of pair of shoes: %s", customer[x].feet[g].ptBShoe);
				printf("\nSize of pair of shoes: %d\n", customer[x].feet[g].sShoe);
				printf("Price of pair of shoes: %.2f$\n", customer[x].feet[g].prShoe);	
				}
			}
			
			else {
				
				printf("\n\n%s has ordered %d pairs of shoes:\n", customer[x].ID.name, customer[x].numShoe);
				
				for(g=0; g<customer[x].numShoe; ++g) {
					printf("\nBrand of pair of shoes no.%d: %s", g+1, customer[x].feet[g].ptBShoe);
					printf("\nSize of pair of shoes no.%d: %d\n", g+1, customer[x].feet[g].sShoe);
					printf("Price of pair of shoes no.%d: %.2f$\n", g+1, customer[x].feet[g].prShoe);
				}	
			}
		}
		
		
	//******************************** type of postage ************************************************************	
	
		
		if (customer[x].courServ == 'a')
			printf("\nType of postage: SUPER-FAST POSTAGE [2 working days] = 14.99$\n");
			else if (customer[x].courServ == 'b')
				printf("\nType of postage: NORMAL POSTAGE [7-10 working days] = 9.99$\n");
				else if (customer[x].courServ == 'c')
					printf("\nType of postage: DISCOUNT POSTAGE [2-3 weeks] = 2.99$\n");
					
						
		
	//******************************** customer comment ***********************************************************
		
		if (customer[x].indCom == 'y') {
			printf("\n%s has posted a comment regarding this order:\n\n", customer[x].ID.name);
			printf("\t'%s'", customer[x].comment);
		}	
		else 
			printf("\n%s has posted no comment with regard to this order.", customer[x].ID.name);		
	}
			
	return;	
}
//end of printBill() function


//***********************************************************************************************************************
//***********************************************************************************************************************
//***********************************************************************************************************************
//***********************************************************************************************************************
//***********************************************************************************************************************


void printTotal (int x, float *tt, float *grTT) {
	
	*tt = customer[x].total + (customer[x].total * 0.38);

	if (customer[x].total > 0.0)
		printf("\n\nTotal amount to be paid, including postage fee and tax (3.80%%):\n\n\t%.2f$\n\n", *tt);
	else {
		*tt = 0.00;
		printf("\n\nTotal amount to be paid: 0.00$");
	}
	
	*grTT += *tt;
				
	return;
}

void numItemsBought(int *itemTT) {
	
	printf("\n\n");
	printf("*********************************************\n");
	printf("*                                           *\n");
	printf("*                DATA ANALYSIS              *\n");
	printf("*                                           *\n");
	printf("*********************************************\n");
	
	if (*itemTT == 0)
		printf("\n\nNo items have been ordered today.");
		else if (*itemTT == 1)
			printf("\n\n1 item has been ordered today:\n", *itemTT);
			else
				printf("\n\nA total of %d items have been ordered today:\n", *itemTT);
					
	return;
	
}


void detailItems(int allHat, int allCoat, int allBlou, int allShir, int allSkir, int allTrou, int allShoe) {
	
	if (allHat > 0) {
		
		if (allHat == 1)
			printf("\n\t1 hat");
		else
			printf("\n\t%d hats", allHat);
	}
	
	if (allCoat > 0) {
		
		if (allCoat == 1)
			printf("\n\t1 coat");
		else
			printf("\n\t%d coats", allCoat);
	}
	
	if (allBlou > 0) {
		
		if (allBlou == 1)
			printf("\n\t1 blouse");
		else
			printf("\n\t%d blouses", allBlou);
	}
	
	if (allShir > 0) {
		
		if (allShir == 1)
			printf("\n\t1 shirt");
		else
			printf("\n\t%d shirts", allShir);
	}
	
	if (allSkir > 0) {
		
		if (allSkir == 1)
			printf("\n\t1 skirt");
		else
			printf("\n\t%d skirts", allSkir);
	}
	
	if (allTrou > 0) {
		
		if (allTrou == 1)
			printf("\n\t1 pair of trousers");
		else
			printf("\n\t%d pairs of trousers", allTrou);
	}
	
	if (allShoe > 0) {
		
		if (allShoe == 1)
			printf("\n\t1 pair of shoes");
		else
			printf("\n\t%d pairs of shoes", allShoe);
	}
	
	return;
	
}

void totalIntake (float bigT) {
	
	printf("\n\nTotal amount of money taken in by online store today: \n\n\t%.2f$", bigT);
	
	return;
}

void averagePurch(float bigT, int nCust) {
	
	if (nCust > 1)
		printf("\n\nThe average amount of money spent per customer is: \n\n\t%.2f&", bigT / nCust);
	
	return;
}

/*
NOTE:
the following  "decr" functions below find the most expensive item per item category for all customers:
*/

void decr1 (int x) {
	
	int a, b;
	float temp;

		//BUBBLE SORT TECHNIQUE:
	for(a=0; a<customer[x].numHat-1; ++a) //REMINDER: arrays are sorted from 0 to n-1; hence: "a<n-1"
		//finding the biggest of all remaining elements:
		for(b=0; b<customer[x].numHat-1; ++b)
			if(customer[x].head[b].prHat < customer[x].head[b+1].prHat) { //NOTE: if we wanted to reorder in INCREASING order (ie: sorting from smallest to biggest), simply change < to >
				//swapping:
				temp = customer[x].head[b+1].prHat;
				customer[x].head[b+1].prHat = customer[x].head[b].prHat;
				customer[x].head[b].prHat = temp;
			}

	return;
}

void decr2 (int x) {
	
	int a, b;
	float temp;

	for(a=0; a<customer[x].numCoat-1; ++a)
		for(b=0; b<customer[x].numCoat-1; ++b)
			if(customer[x].bMF1[b].prCoat < customer[x].bMF1[b+1].prCoat) {
				temp = customer[x].bMF1[b+1].prCoat;
				customer[x].bMF1[b+1].prCoat = customer[x].bMF1[b].prCoat;
				customer[x].bMF1[b].prCoat = temp;
			}

	return;
}


void decr3 (int x) {
	
	int a, b;
	float temp;

	for(a=0; a<customer[x].numBlou-1; ++a)
		for(b=0; b<customer[x].numBlou-1; ++b)
			if(customer[x].bodF[b].prBlou < customer[x].bodF[b+1].prBlou) {
				temp = customer[x].bodF[b+1].prBlou;
				customer[x].bodF[b+1].prBlou = customer[x].bodF[b].prBlou;
				customer[x].bodF[b].prBlou = temp;
			}

	return;
}


void decr4 (int x) {
	
	int a, b;
	float temp;

	for(a=0; a<customer[x].numShir-1; ++a)
		for(b=0; b<customer[x].numShir-1; ++b)
			if(customer[x].bMF2[b].prShir < customer[x].bMF2[b+1].prShir) {
				temp = customer[x].bMF2[b+1].prShir;
				customer[x].bMF2[b+1].prShir = customer[x].bMF2[b].prShir;
				customer[x].bMF2[b].prShir = temp;
			}

	return;
}


void decr5 (int x) {
	
	int a, b;
	float temp;

	for(a=0; a<customer[x].numSkir-1; ++a)
		for(b=0; b<customer[x].numSkir-1; ++b)
			if(customer[x].legF[b].prSkir < customer[x].legF[b+1].prSkir) {
				temp = customer[x].legF[b+1].prSkir;
				customer[x].legF[b+1].prSkir = customer[x].legF[b].prSkir;
				customer[x].legF[b].prSkir = temp;
			}

	return;
}


void decr6 (int x) {
	
	int a, b;
	float temp;

	for(a=0; a<customer[x].numTrou-1; ++a)
		for(b=0; b<customer[x].numTrou-1; ++b)
			if(customer[x].legMF[b].prTrou < customer[x].legMF[b+1].prTrou) {
				temp = customer[x].legMF[b+1].prTrou;
				customer[x].legMF[b+1].prTrou = customer[x].legMF[b].prTrou;
				customer[x].legMF[b].prTrou = temp;
			}

	return;
}


void decr7 (int x) {
	
	int a, b;
	float temp;

	for(a=0; a<customer[x].numShoe-1; ++a)
		for(b=0; b<customer[x].numShoe-1; ++b)
			if(customer[x].feet[b].prShoe < customer[x].feet[b+1].prShoe) {
				temp = customer[x].feet[b+1].prShoe;
				customer[x].feet[b+1].prShoe = customer[x].feet[b].prShoe;
				customer[x].feet[b].prShoe = temp;
			}

	return;
}

void num_Comments(int nCust, int totCom) {
		
	if (totCom > 0) {
		
		if (totCom == 1)
			printf("\nOnly one comment has been posted.");
					
		else
			printf("\n%d comments have been posted.", totCom);		
	}
	
	else 
		printf("\nNo comments have been posted today.");		
		
	return;
}


void num_Post(int *sFast, int *nor, int *dis) {
	
	if(*sFast > 0) {
		
		if (*sFast == 1)
			printf("\n\nOne customer has chosen Super-Fast postal service.");
		else
			printf("\n\n%d customers have chosen Super-Fast postal service.", *sFast);
	}
			
	if(*nor > 0) {
		
		if (*nor == 1)
			printf("\n\nOne customer has chosen Normal postal service.");
		else
			printf("\n\n%d customers have chosen Normal postal service.", *nor);
	}
		
	if(*dis > 0) {
		
		if (*dis == 1)
			printf("\n\nOne customer has chosen Discount postal service.");
		else
			printf("\n\n%d customers have chosen Discount postal service.", *dis);
	}
	
	return;				
}


