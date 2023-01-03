/*
This program will convert Roman numerals to a decimal total and vice versa.

To do this, we need several things:
(1) a CHAR array 
(2) an empty FOR loop (with ENTER key as its terminating element) to store the Roman Numerals
(3) check if the Roman numeral line entered by the user is valid 
(4) add all numerals
(5) print result

REMINDER:

I == 1;
V == 5;
X == 10;
L == 50;
C == 100;
D == 500;
M == 1000;

exceptions (subtractive groupings:)
IV == 4;
IX == 9;
XL == 40;
XC == 90;
CD == 400;
CM == 900;

===> all other groupings must be identified and declared as errors
for instance: 
IIIM ==> IS FALSE AND SO CANNOT BE ACCEPTED
XXM ==> IS FALSE AND SO CANNOT BE ACCEPTED
MCIXI ==> IS FALSE AND SO CANNOT BE ACCEPTED

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h> //==> this is to use the STRCPY function (to assign string content to CHAR variables)

#define MAX 20

//prototypes:
void intro();
void choice();


int main(int argc, char *argv[]) {
	
	char RomNum[MAX];
	char str1[MAX], str2[MAX], str3[MAX], str4[MAX], str5[MAX], str6[MAX], str7[MAX], str8[MAX], str9[MAX], lastStr[MAX];
	char do_again, answer;
	int DecNum[MAX];
	int i, j, x, y, z, length, size, temp, total=0;
	
	intro(); 
	
	do {
		
		choice();		
		answer = getchar();
		getchar(); //==> for ENTER key
	
		switch (answer) {
					
						
//***********************************************************************************************************************************************
//*																																		        *
//*												CONVERTING ROMAN NUMERALS TO DECIMAL                                                            *
//*																																		        *
//***********************************************************************************************************************************************
						
			case 'a':	
								
						printf("\nPlease enter your Roman numerals:\n\n");
						printf("REMEMBER: M = 1000, D = 500, C = 100, L = 50, X = 10, V = 5, I = 1\n\n");
						for(i=0; (RomNum[i] = getchar()) != '\n'; ++i)
						;
						
						length = i-1; //==> we do i-1 to get rid of the last ENTER key
						
						for(j=0; j<=length; ++j) {
							
							if (RomNum[j] == 'I' || 
								RomNum[j] == 'V' || 
								RomNum[j] == 'X' || 
								RomNum[j] == 'L' || 
								RomNum[j] == 'C' || 
								RomNum[j] == 'D' || 
								RomNum[j] == 'M') 
								{
								
					//************************************* for numeral I **************************************************************
						
									if (RomNum[j] == 'I') {
										
										if (RomNum[i-4] == 'I') {
											printf("\nERROR - not a Roman numeral expression.");
											total = 0;
											break;
										}
										
											else if ((RomNum[j-1] == 'V') && (RomNum[j-2] == 'I')) {
												printf("\nERROR - not a Roman numeral expression.");
												total = 0;
												break;
											}
											
												else if ((RomNum[j-1] == 'X') && (RomNum[j-2] == 'I')) {
													printf("\nERROR - not a Roman numeral expression.");
													total = 0;
													break;
												}
										
													else
														total += 1;	
									}
									
					//************************************* for numeral V **************************************************************
													
									if (RomNum[j] == 'V') {
										
										if (RomNum[j-2] == 'I') {
											printf("\nERROR - not a Roman numeral expression.");
											total = 0;
											break;
										}
													
											else if (RomNum[j-1] == 'I') {
												total -= 1;
												total += 4;
											}
																								
												else 
													total += 5;
									}
									
					//************************************* for numeral X **************************************************************
									
									if (RomNum[j] == 'X') {
										
										if (RomNum[j-2] == 'I') {
											printf("\nERROR - not a Roman numeral expression.");
											total = 0;
											break;
											}
											
											else if (RomNum[j-1] == 'I') {
												total -= 1;
												total += 9;
											}			
												
												else
													total += 10;
									}
									
					//************************************* for numeral L **************************************************************
									
									if (RomNum[j] == 'L') {
										
										if (RomNum[j-1] == 'I' || RomNum[j-1] == 'V' || RomNum[j-1] == 'L') {
											printf("\nERROR - not a Roman numeral expression.");
											total = 0;
											break;
										}
										
											else if (RomNum[j-1] == 'X') {
												total -= 10;
												total += 40;
											}
																
												else 
													total += 50;
									}
									
					//************************************* for numeral C **************************************************************
										
									if (RomNum[j] == 'C') {
									
										if (RomNum[j-1] == 'I' || RomNum[j-1] == 'V' || RomNum[j-1] == 'L') {
											printf("\nERROR - not a Roman numeral expression.");
											total = 0;
											break;
										}
					
											else if (RomNum[j-1] == 'X') {
												total -= 10;
												total += 90;
											}
																
												else 
													total += 100;
									}
									
					//************************************* for numeral D **************************************************************	
														
									if (RomNum[j] == 'D') {
									
										if (RomNum[j-1] == 'I' || RomNum[j-1] == 'V' || RomNum[j-1] == 'X' || RomNum[j-1] == 'L' || RomNum[j-1] == 'D') {
											printf("\nERROR - not a Roman numeral expression.");
											total = 0;
											break;
										}
										
											else if (RomNum[j-1] == 'C') {
												total -= 100;
												total += 400;
											}
																
												else 
													total += 500;
									}
									
					//************************************* for numeral M **************************************************************	
										
									if (RomNum[j] == 'M') {
										
										if (RomNum[j-1] == 'I' || RomNum[j-1] == 'V' || RomNum[j-1] == 'X' || RomNum[j-1] == 'L' || RomNum[j-1] == 'D') {
											printf("\nERROR - not a Roman numeral expression.");
											total = 0;
											break;
										}
												
											else if (RomNum[j-1] == 'C') {
												total -= 100;
												total += 900;
											}
																
												else 
													total += 1000;
									}
										
								}
					
							// FOR ALL OTHER CHARACTERS:		
							else {		
								printf("\nERROR - not a Roman numeral expression.");
								total = 0;
								break;
							}
							
						}//end of FOR loop
						
						//PRINTING:
						if (total > 0)
							printf("\n\nIts decimal equivalent is: %d", total);
							
						total = 0;	
						break;
				
				
//***********************************************************************************************************************************************
//*																																		        *
//*												CONVERTING DECIMAL TO ROMAN NUMERALS                                                            *
//*																																		        *
//***********************************************************************************************************************************************

			case 'b':
							
						printf("Enter your decimal number (smaller than 6000):\n");
						for(x=0; (DecNum[x] = getchar()) != '\n'; ++x)
						;
												
						size = x;
						
						//IF NUMBER IS NO GREATER THAN THE XXXX FORMAT:
						if (size < 5) {
							
//********************************************** IF NUMBER IS OF XXXX FORMAT:  ********************************************************************
							if (size == 4) {
								
								if (DecNum[3] != '6' && DecNum[3] != '7' || DecNum[3] != '8' || DecNum[3] != '9') {
									
									if (DecNum[0] == '1')
										strcpy(str1, "M");
										else if (DecNum[0] == '2')
											strcpy(str1, "MM");
											else if (DecNum[0] == '3')
												strcpy(str1, "MMM");
												else if (DecNum[0] == '4')
													strcpy(str1, "MMMM");
													else if (DecNum[0] == '5')
														strcpy(str1, "MMMMM");									
														else {
															printf("Number too big to compute.\n");
															break;
														}
									
									if (DecNum[1] == '1')
										strcpy(str2, "C");
										else if (DecNum[1] == '2')
											strcpy(str2, "CC");
											else if (DecNum[1] == '3')
												strcpy(str2, "CCC");
												else if (DecNum[1] == '4')
													strcpy(str2, "CD");
													else if (DecNum[1] == '5')
														strcpy(str2, "D");
														else if (DecNum[1] == '6')
															strcpy(str2, "DC");	
															else if (DecNum[1] == '7')
																strcpy(str2, "DCC");
																else if (DecNum[1] == '8')
																	strcpy(str2, "DCCC");
																	else if (DecNum[1] == '9')
																		strcpy(str2, "CM");
																															
									if (DecNum[2] == '1')
										strcpy(str3, "X");
										else if (DecNum[2] == '2')
											strcpy(str3, "XX");
											else if (DecNum[2] == '3')
												strcpy(str3, "XXX");
												else if (DecNum[2] == '4')
													strcpy(str3, "XL");
													else if (DecNum[2] == '5')
														strcpy(str3, "L");
														else if (DecNum[2] == '6')
															strcpy(str3, "LX");	
															else if (DecNum[2] == '7')
																strcpy(str3, "LXX");
																else if (DecNum[2] == '8')
																	strcpy(str3, "LXXX");
																	else if (DecNum[2] == '9')
																		strcpy(str3, "XC");
																															
									if (DecNum[3] == '1')
										strcpy(str4, "I");
										else if (DecNum[3] == '2')
											strcpy(str4, "II");
											else if (DecNum[3] == '3')
												strcpy(str4, "III");
												else if (DecNum[3] == '4')
													strcpy(str4, "IV");
													else if (DecNum[3] == '5')
														strcpy(str4, "V");
														else if (DecNum[3] == '6')
															strcpy(str4, "VI");	
															else if (DecNum[3] == '7')
																strcpy(str4, "VII");
																else if (DecNum[3] == '8')
																	strcpy(str4, "VIII");
																	else if (DecNum[3] == '9')
																		strcpy(str4, "IX");
								
									
									printf("Your decimal in Roman numerals:\n");
									printf("%s%s%s%s", str1, str2, str3, str4);
									break;
								
								}
								
								else {
									printf("Number too big to compute.\n");
									break;
								}	
							}
							
//********************************************** IF NUMBER IS OF XXX FORMAT:  ********************************************************************
							if (size == 3) {
									
									if (DecNum[0] == '1')
										strcpy(str5, "C");
										else if (DecNum[0] == '2')
											strcpy(str5, "CC");
											else if (DecNum[0] == '3')
												strcpy(str5, "CCC");
												else if (DecNum[0] == '4')
													strcpy(str5, "CD");
													else if (DecNum[0] == '5')
														strcpy(str5, "D");
														else if (DecNum[0] == '6')
															strcpy(str5, "DC");	
															else if (DecNum[0] == '7')
																strcpy(str5, "DCC");
																else if (DecNum[0] == '8')
																	strcpy(str5, "DCCC");
																	else if (DecNum[0] == '9')
																		strcpy(str5, "CM");
																															
									if (DecNum[1] == '1')
										strcpy(str6, "X");
										else if (DecNum[1] == '2')
											strcpy(str6, "XX");
											else if (DecNum[1] == '3')
												strcpy(str6, "XXX");
												else if (DecNum[1] == '4')
													strcpy(str6, "XL");
													else if (DecNum[1] == '5')
														strcpy(str6, "L");
														else if (DecNum[1] == '6')
															strcpy(str6, "LX");	
															else if (DecNum[1] == '7')
																strcpy(str6, "LXX");
																else if (DecNum[1] == '8')
																	strcpy(str6, "LXXX");
																	else if (DecNum[1] == '9')
																		strcpy(str6, "XC");
																															
									if (DecNum[2] == '1')
										strcpy(str7, "I");
										else if (DecNum[2] == '2')
											strcpy(str7, "II");
											else if (DecNum[2] == '3')
												strcpy(str7, "III");
												else if (DecNum[2] == '4')
													strcpy(str7, "IV");
													else if (DecNum[2] == '5')
														strcpy(str7, "V");
														else if (DecNum[2] == '6')
															strcpy(str7, "VI");	
															else if (DecNum[2] == '7')
																strcpy(str7, "VII");
																else if (DecNum[2] == '8')
																	strcpy(str7, "VIII");
																	else if (DecNum[2] == '9')
																		strcpy(str7, "IX");
																	
								printf("Your decimal in Roman numerals:\n");
								printf("%s%s%s", str5, str6, str7);
								break;									
							}
							
//********************************************** IF NUMBER IS OF XX FORMAT:  ********************************************************************
							if (size == 2) {
								
									if (DecNum[0] == '1')
										strcpy(str8, "X");
										else if (DecNum[0] == '2')
											strcpy(str8, "XX");
											else if (DecNum[0] == '3')
												strcpy(str8, "XXX");
												else if (DecNum[0] == '4')
													strcpy(str8, "XL");
													else if (DecNum[0] == '5')
														strcpy(str8, "L");
														else if (DecNum[0] == '6')
															strcpy(str8, "LX");	
															else if (DecNum[0] == '7')
																strcpy(str8, "LXX");
																else if (DecNum[0] == '8')
																	strcpy(str8, "LXXX");
																	else if (DecNum[0] == '9')
																		strcpy(str8, "XC");
																															
									if (DecNum[1] == '1')
										strcpy(str9, "I");
										else if (DecNum[1] == '2')
											strcpy(str9, "II");
											else if (DecNum[1] == '3')
												strcpy(str9, "III");
												else if (DecNum[1] == '4')
													strcpy(str9, "IV");
													else if (DecNum[1] == '5')
														strcpy(str9, "V");
														else if (DecNum[1] == '6')
															strcpy(str9, "VI");	
															else if (DecNum[1] == '7')
																strcpy(str9, "VII");
																else if (DecNum[1] == '8')
																	strcpy(str9, "VIII");
																	else if (DecNum[1] == '9')
																		strcpy(str9, "IX");
																	
								printf("Your decimal in Roman numerals:\n");
								printf("%s%s", str8, str9);
								break;
							}
							
//********************************************** IF NUMBER IS OF X FORMAT:  ********************************************************************
							if (size == 1) {
								
									if (DecNum[0] == '1')
										strcpy(lastStr, "I");
										else if (DecNum[0] == '2')
											strcpy(lastStr, "II");
											else if (DecNum[0] == '3')
												strcpy(lastStr, "III");
												else if (DecNum[0] == '4')
													strcpy(lastStr, "IV");
													else if (DecNum[0] == '5')
														strcpy(lastStr, "V");
														else if (DecNum[0] == '6')
															strcpy(lastStr, "VI");	
															else if (DecNum[0] == '7')
																strcpy(lastStr, "VII");
																else if (DecNum[0] == '8')
																	strcpy(lastStr, "VIII");
																	else if (DecNum[0] == '9')
																		strcpy(lastStr, "IX");
																	
								printf("Your decimal in Roman numerals:\n");
								printf("%s", lastStr);
								break;
							}
							
						}
						
						else {
							printf("Number too big too compute.\n");
							break;
						}
						
		}//end of switch-case
												
		printf("\n\nContinue? (Y/N)\n\n");
		do_again = getchar();
		getchar(); //this is for pressed ENTER key (once Y or N has been pressed)
						
	}while (do_again != 'N');//end of DO-WHILE loop
	
	printf("\nThank you! Goodbye.\n");
	
	return 0;
}

//******************* 2 functions for intro ***************************************

void intro (){
	
	printf("ROMAN NUMERAL CONVERTER\n");
	printf("\nPlease choose one of the following options:\n\n");
	return;
}

void choice() {
	
	printf("Press (a) to convert a line of Roman numerals to its decimal equivalent.\n");
	printf("Press (b) to convert a decimal number into Roman numerals.\n");
	printf("To exit this program, enter 0.\n");	
	return;
}
