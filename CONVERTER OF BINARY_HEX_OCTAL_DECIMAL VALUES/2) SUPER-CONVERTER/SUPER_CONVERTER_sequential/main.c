
#include <stdio.h>
#include <stdlib.h>
#include <math.h> //this is to use the pow() function, which calculates numbers to the power of x

#define MAX 30

int main(int argc, char *argv[]) {
	
	int a, b, c, d, e, f, g, h, i, j, k, l, m, n, p, q, r, s, t, u, v, w, x, y, z;
	int len1, len2, len3, len4, len5, len6, len7, len8, len9, leng1, leng2, sublen;
	int rem1, rem2, rem3, rem4, rem5;
	int sBin, sHex, sOcts, sDec, total, decSum, num, suNum;
	int nD1, nD2, nD3, nD4, nD5, nD6, nD7, nD8;

	char answer;
	char do_again;
	char tem1, tem2, tem3, tem4, tem5, tem6, tem7, tem8, tem9, temp1, temp2;
	char decimalLine[MAX];
	char bLine[MAX], biExpr[MAX], bCon[MAX], bFinal[MAX];
	char oLine[MAX], ocExpr[MAX], oktLine[MAX], oEx[MAX];
	char hLine[MAX], hExpr[MAX], hConv[MAX];
	char dConv[MAX];	
		
	printf("Hello! Try our cool converter!\n\n");
	printf("Simply choose one of the following options below! Our program will do all the   necessary conversions for you!\n\n");
	
	
	while (do_again != 'N') { 
	
		printf("Press (a) to enter a binary expression;\n");
		printf("Press (b) to enter a decimal number;\n");
		printf("Press (c) to enter an octal expression;\n");
		printf("Press (d) to enter a hexidecimal expression;\n");
		printf("Press (e) to exit.\n");
			
		answer = getchar();
		
		if (answer == 'a' || answer == 'b' || answer == 'c' || answer == 'd' || answer == 'e') {
		
			switch(answer) {
				
//*****************************************************************************************************************************************
//*																																	      *
//*																																	      *
//*										CASE (a) : inputting BINARY																		  *
//*																																	      *
//*																																	      *
//*****************************************************************************************************************************************
		
				
				case 'a':	
								
						//**************************** convert to DECIMAL ***********************************************
												
						printf("\nEnter your series of 1s and 0s: ");
						getchar();
		
						for(a=0; (bLine[a] = getchar()) != '\n'; ++a)
						;
								
						if ((a-1 == 0) && (bLine[0] == '0')) {
									
							printf("\n\nIts decimal equivalent: 0\n\n");
							printf("Its octal equivalent: 0\n\n");
							printf("Its hexadecimal equivalent: 0\n\n");
						}
								
						else {
								
							len1 = a;
							b=0;
							b = len1-1; //we do -1 to get rid of last ENTER input
							c=0;
									
							while(c<b) {
								tem1 = bLine[b];
								bLine[b] = bLine[c];
								bLine[c] = tem1;
								++c;
								--b;
							}
									
							for(d=0; d<len1; ++d) {
										
								if (bLine[d] == '1' || bLine[d] == '0') {
											
									if (bLine[d] == '1')
										sBin += pow(2.0, d);
								}
										
								else {
									printf("\n\nError! Invalid binary expression.\n\n");
									sBin = 0;
									break;
								}
							}
									
							if (sBin != 0) {
										
								printf("\nIts decimal equivalent: %d", sBin);
																									
							//**************************** convert to OCTAL ***********************************************
										
								nD1 = sBin;
								e=0;
										
								while(nD1 >= 8) { 
									rem1 = nD1 % 8;
									oLine[e] = '0' + rem1;
									nD1 /= 8;
									++e;	
								}
										
								oLine[e] = '0' + nD1;
								len2 = e;									
								f=0;
								g=0;
								f = len2;
																
								while(g<f) {
									tem2 = oLine[f];
									oLine[f] = oLine[g];
									oLine[g] = tem2;
									++g;
									--f;
								}
										
								printf("\n\nIts octal equivalent: ");
								for(h=0; h<=len2; ++h) 
									printf("%c", oLine[h]);
										
								
										
							//************************************ convert to HEXADECIMAL *****************************************************
										
								//case (A): numbers from 0 to 15
								nD2 = sBin;
										
								i=0;
										
								if (nD2<16){
											
									if (nD2<10)
										printf("\n\nIts hexadecimal equivalent: %d", nD2);
											
									else {	
										if (nD2==10)	
											hLine[0] = 'A';
										if (nD2==11)	
											hLine[0] = 'B';
										if (nD2==12)	
											hLine[0] = 'C';
										if (nD2==13)	
											hLine[0] = 'D';
										if (nD2==14)	
											hLine[0] = 'E';
										if (nD2==15)	
											hLine[0] = 'F';
													
										printf("\n\nIts hexadecimal equivalent: ");
										printf("%c", hLine[0]);
									}
								}			
										
								//case (B): numbers from 16 upwards
								else {
											
									//saving characters in a loop, as long as the decimal number is >= 16
									while (nD2>=16) {
												
										rem2 = nD2 % 16;
												
										//situation 1:
										if (rem2 != 10 && rem2 != 11 && rem2 != 12 && rem2 != 13 && rem2 != 14 && rem2 != 15)
											hLine[i] = '0' + rem2;
										
										//situation 2:		
										else {
											
											if (rem2==10)	
												hLine[i] = 'A';
											if (rem2==11)
												hLine[i] = 'B';
											if (rem2==12)	
												hLine[i] = 'C';
											if (rem2==13)	
												hLine[i] = 'D';
											if (rem2==14)	
												hLine[i] = 'E';
											if (rem2==15)	
												hLine[i] = 'F';	
										}
												
										nD2 /= 16;
										++i;
									}
											
									j=0;
									j=i;
											
									//when the number, after so many divisions, is no longer > 16, BUT must be displayed in its alphabetical symbol:
									if (nD2>=10 && nD2<=15) {
												
										if (nD2==10)	
											hLine[j] = 'A';
										if (nD2==11)
											hLine[j] = 'B';
										if (nD2==12)	
											hLine[j] = 'C';
										if (nD2==13)	
											hLine[j] = 'D';
										if (nD2==14)	
											hLine[j] = 'E';
										if (nD2==15)	
											hLine[j] = 'F';
									}
									//when the number, after so many divisions,	can simply be displayed in its numerical format:
									else
										hLine[j] = '0' + nD2;
											
									len3 = j;
									k=0;
									l=0;
									l = len3;
											
									while(k<l) {
										tem3 = hLine[l];
										hLine[l] = hLine[k];
										hLine[k] = tem3;
										++k;
										--l;
									}
											
									printf("\n\nIts hexadecimal equivalent: ");
									for(m=0; m<=len3; ++m) 
										printf("%c", hLine[m]);
								}						
							}
									
							else
								printf("\n");
						}
						
						sBin = 0;
										
						break;
						
//*****************************************************************************************************************************************
//*																																	      *
//*																																	      *
//*										CASE (b) : inputting DECIMAL																	  *
//*																																	      *
//*																																	      *
//*****************************************************************************************************************************************
		
		
				case 'b':
					
						//************************************ convert CHAR decimal line to integer *****************************
						
						/*
								NO IDEA WHY I HAVE CHOSEN TO INPUT A DECIMAL IN CHAR RATHER THAN IN INT!!!!!!! BUT IT WORKS...
						*/
										
						printf("\n\nEnter a decimal number of your choice:\n");
						getchar();
								
						for(i=0; (decimalLine[i] = getchar()) != '\n'; ++i)
						;
								
							if ((i-1 == 0) && (decimalLine[0] == '0')) {
									
								printf("\n\nIts binary equivalent: 0\n\n");
								printf("Its octal equivalent: 0\n\n");
								printf("Its hexadecimal equivalent: 0\n\n");
							}
								
							else {
								
								sublen = i-1;
								suNum = 0;
								
								//converting decimal line written in characters to integer:
								for(i=0; i<=sublen; ++i) {
										
									if(decimalLine[i] >= 48 && decimalLine[i] <= 57) {
											
										if (sublen > 0) //to be understood as: "if number entered is more than 1 digit long)
											suNum *= 10; //if number entered IS longer than one digit, must multiply 
															// by 10 to access next decimal place of that number
											
										if (decimalLine[i] == '0')
											suNum += 0;
										if (decimalLine[i] == '1')
											suNum += 1;
										if (decimalLine[i] == '2')
											suNum += 2;
										if (decimalLine[i] == '3')
											suNum += 3;
										if (decimalLine[i] == '4')
											suNum += 4;
										if (decimalLine[i] == '5')
											suNum += 5;
										if (decimalLine[i] == '6')
											suNum += 6;
										if (decimalLine[i] == '7')
											suNum += 7;
										if (decimalLine[i] == '8')
											suNum += 8;
										if (decimalLine[i] == '9')
											suNum += 9;
														 
									}
										
									else {
											
										printf("\n\nError! Invalid decimal number.\n");
										suNum = 0;
										break;
									}		
								}
									
								num = suNum; //taking away one decimal 0, added automatically above
									
								if (num > 0) { //ELSE found after hexadecimal
									
								//**************************** convert to BINARY  ***********************************************
															
									nD3 = num;
										
									if (num == 0) {
										biExpr[0] = '0';
										printf("\nIts binary equivalent: "); 
										printf("%c", biExpr[0]);
									}
										
									else {
											
										n=0;
										
										while (nD3 > 0) {
												
											if (nD3 % 2 == 0) {
												nD3 /= 2;
												biExpr[n] = '0';
											}
												
											else {
												nD3 /= 2;
												biExpr[n] = '1';
											}
											++n;
										}
											
										len4 = n;
										p=0;
										p = len4-1;										
										q=0;
											
										while(q<p) {
											tem4 = biExpr[p];
											biExpr[p] = biExpr[q];
											biExpr[q] = tem4;
											++q;
											--p;
										}
											
										printf("\nIts binary equivalent: ");
										for(r=0; r<len4; ++r) 
											printf("%c", biExpr[r]);
									}
											
																				
									//**************************** convert to OCTAL ***********************************************
										
									nD4 = num;	
									s=0;
										
									while(nD4 >= 8) { 
										rem3 = nD4 % 8;
										ocExpr[s] = '0' + rem3;
										nD4 /= 8;
										++s;	
									}
										
									ocExpr[s] = '0' + nD4;
									len4 = s;
									t=0;
									t = len4;
									u=0;
																
									while(u<t) {
										tem4 = ocExpr[t];
										ocExpr[t] = ocExpr[u];
										ocExpr[u] = tem4;
										++u;
										--t;
									}
										
									printf("\n\nIts octal equivalent: ");
									for(v=0; v<=len4; ++v) 
										printf("%c", ocExpr[v]);
											
				
								//**************************** convert to HEXADECIMAL ***********************************************	
										
									nD5 = num;
										
									w=0;
										
									//case (A): numbers from 0 to 15
										
									if (nD5<16){
											
										if (nD5<10)
											printf("\n\nIts hexadecimal equivalent: %d", nD5);
											
										else {	
											if (nD5==10)	
												hExpr[0] = 'A';
											if (nD5==11)	
												hExpr[0] = 'B';
											if (nD5==12)	
												hExpr[0] = 'C';
											if (nD5==13)	
												hExpr[0] = 'D';
											if (nD5==14)	
												hExpr[0] = 'E';
											if (nD5==15)	
												hExpr[0] = 'F';
													
											printf("\n\nIts hexadecimal equivalent: ");
											printf("%c", hExpr[0]);
										}
									}			
										
									//case (B): numbers from 16 upwards
									else {
											
										//saving characters in a loop, as long as the 
										while (nD5>=16) {
												
											rem4 = nD5 % 16;
												
											//situation 1:
											if (rem4 != 10 && rem4 != 11 && rem4 != 12 && rem4 != 13 && rem4 != 14 && rem4 != 15)
												hExpr[w] = '0' + rem4;
												
											//situation 2:		
											else {
													
												if (rem4==10)	
													hExpr[w] = 'A';
												if (rem4==11)
													hExpr[w] = 'B';
												if (rem4==12)	
													hExpr[w] = 'C';
												if (rem4==13)	
													hExpr[w] = 'D';
												if (rem4==14)	
													hExpr[w] = 'E';
												if (rem4==15)	
													hExpr[w] = 'F';	
											}
												
											nD5 /= 16;
											++w;
										}
											
										x=0;
										x=w;
											
										if (nD5>=10 && nD5<=15) {
												
											if (nD5==10)	
												hExpr[x] = 'A';
											if (nD5==11)
												hExpr[x] = 'B';
											if (nD5==12)	
												hExpr[x] = 'C';
											if (nD5==13)	
												hExpr[x] = 'D';
											if (nD5==14)	
												hExpr[x] = 'E';
											if (nD5==15)	
												hExpr[x] = 'F';
										}
												
										else
											hExpr[x] = '0' + nD5;
											
										len5 = x;
										y=0;
										y = len5;
										z=0;
											
										while(z<y) {
											tem5 = hExpr[y];
											hExpr[y] = hExpr[z];
											hExpr[z] = tem5;
											++z;
											--y;
										}
																					
										printf("\n\nIts hexadecimal equivalent: ");
										for(a=0; a<=len5; ++a) 
											printf("%c", hExpr[a]);
									}							
								}
								
								else
									printf("\n");								
							}
								
							suNum = 0;
										
							break;		
		
								
		//*****************************************************************************************************************************************
		//*																																	      *
		//*																																	      *
		//*										CASE (c) : inputting OCTAL																		  *
		//*																																	      *
		//*																																	      *
		//*****************************************************************************************************************************************				
					
					case 'c':
		
								printf("\n\nEnter a series of octal numbers:\n");
								printf("\n(Remember: numbers 8 and 9 not allowed in octal values.)\n\n");
								getchar();
								
								//**************************** convert to DECIMAL ***********************************************
								
								for(a=0; (oktLine[a] = getchar()) != '\n'; ++a)
								;
								
								if ((a-1 == 0) && (oktLine[0] == '0')) {
									
									printf("\n\nIts decimal equivalent: 0\n\n");
									printf("Its binary equivalent: 0\n\n");
									printf("Its hexadecimal equivalent: 0\n\n");
								}
								
								else {
															
									len6 = a;
									b=0;
									c=0;
									b = len6-1;
									
									while(c<b) {
										tem6 = oktLine[b];
										oktLine[b] = oktLine[c];
										oktLine[c] = tem6;
										++c;
										--b;
									}
									
									for(d=0; d<len6; ++d) {	
														
										if (oktLine[d] >= 48 && oktLine[d] <= 55) {	
																	
											if (oktLine[d] == '0')
												sOcts += 0;
											if (oktLine[d] == '1')
												sOcts += pow(8.0, d);
											if (oktLine[d] == '2')
												sOcts += 2*(pow(8.0, d));
											if (oktLine[d] == '3')
												sOcts += 3*(pow(8.0, d));
											if (oktLine[d] == '4')
												sOcts += 4*(pow(8.0, d));
											if (oktLine[d] == '5')
												sOcts += 5*(pow(8.0, d));
											if (oktLine[d] == '6')
												sOcts += 6*(pow(8.0, d));
											if (oktLine[d] == '7')
												sOcts += 7*(pow(8.0, d));
										}
										
										else {
											printf("\n\nError! Invalid octal expression.\n\n");
											sOcts = 0;
											break;
										}
							
									}
									
									if (sOcts != 0) {
										
										printf("\n\nIts decimal equivalent: %d", sOcts);
				
									//**************************** convert to BINARY  ***********************************************
										
										e=0;
										nD5 = sOcts;
										
										if (sOcts == 0) {
											bCon[0] = '0';
											printf("\n\nIts binary equivalent: "); 
											printf("%c", bCon[0]);
										}
										
										
										else {
											
											while (nD5 > 0) {
												
												if (nD5 % 2 == 0) {
													nD5 /= 2;
													bCon[e] = '0';
												}
												
												else {
													nD5 /= 2;
													bCon[e] = '1';
												}
												++e;
											}
											
											len7 = e;
											f=0;
											f = len7-1;										
											g=0;
											
											while(g<f) {
												tem7 = bCon[f];
												bCon[f] = bCon[g];
												bCon[g] = tem7;
												++g;
												--f;
											}
											
											printf("\n\nIts binary equivalent: ");
											for(h=0; h<len7; ++h) 
												printf("%c", bCon[h]);
											}
											
								//**************************** convert to HEXADECIMAL ***********************************************	
										
										nD6 = sOcts;									
										i=0;
										
										//case (A): numbers from 0 to 15
										
										if (nD6<16){
											
											if (nD6<10)
												printf("\n\nIts hexadecimal equivalent: %d", nD6);
											
											else {	
											
												if (nD6==10)	
													hConv[0] = 'A';
												if (nD6==11)	
													hConv[0] = 'B';
												if (nD6==12)	
													hConv[0] = 'C';
												if (nD6==13)	
													hConv[0] = 'D';
												if (nD6==14)	
													hConv[0] = 'E';
												if (nD6==15)	
													hConv[0] = 'F';
													
												printf("\n\nIts hexadecimal equivalent: ");
												printf("%c", hConv[0]);
											}
										}			
										
										//case (B): numbers from 16 upwards
										else {
											
											//saving characters in a loop, as long as the 
											while (nD6>=16) {
												
												rem5 = nD6 % 16;
												
												//situation 1:
												if (rem5 != 10 && rem5 != 11 && rem5 != 12 && rem5 != 13 && rem5 != 14 && rem5 != 15)
													hConv[i] = '0' + rem5;
												
												//situation 2:		
												else {
													
													if (rem5==10)	
														hConv[i] = 'A';
													if (rem5==11)
														hConv[i] = 'B';
													if (rem5==12)	
														hConv[i] = 'C';
													if (rem5==13)	
														hConv[i] = 'D';
													if (rem5==14)	
														hConv[i] = 'E';
													if (rem5==15)	
														hConv[i] = 'F';	
												}
													
												nD6 /= 16;
												++i;
											}
											
											j=0;
											j=i;
											
											if (nD6>=10 && nD6<=15) {
												
												if (nD6==10)	
													hConv[j] = 'A';
												if (nD6==11)
													hConv[j] = 'B';
												if (nD6==12)	
													hConv[j] = 'C';
												if (nD6==13)	
													hConv[j] = 'D';
												if (nD6==14)	
													hConv[j] = 'E';
												if (nD6==15)	
													hConv[j] = 'F';
											}
												
											else
												hConv[j] = '0' + nD6;
											
											len8 = i;
											k=0;
											k = len8;
											l=0;
											
											while(l<k) {
												tem8 = hConv[k];
												hConv[k] = hConv[l];
												hConv[l] = tem8;
												++l;
												--k;
												}
																			
											printf("\n\nIts hexadecimal equivalent: ");
											for(m=0; m<=len8; ++m) 
												printf("%c", hConv[m]);									
										}
									}
									
									else
										printf("\n");
								}
								
								sOcts = 0;
																	
								break;			
					
		//*****************************************************************************************************************************************
		//*																																	      *
		//*																																	      *
		//*										CASE (d) : inputting HEXADECIMAL																  *
		//*																																	      *
		//*																																	      *
		//*****************************************************************************************************************************************				
							
					case 'd':	
								//**************************** convert to DECIMAL ***********************************************
								
								printf("\n\nEnter your hexadecimal expression:\n");
								printf("\n(0, 1, 2, 3, 4, 5, 6, 7, 8, 9, A=10, B=11, C=12, D=13, E=14, F=15)\n");
								getchar();
								
								for(n=0; (dConv[n] = getchar()) != '\n'; ++n)
								;
								
								if ((n-1 == 0) && (dConv[0] == '0')) {
									
									printf("\n\nIts decimal equivalent: 0\n\n");
									printf("Its octal equivalent: 0\n\n");
									printf("Its binary equivalent: 0\n\n");
								}
								
								else {
								
									len9 = n;
									p=0;
									p = len9-1;
									q=0;
									
									while(q<p) {
										tem9 = dConv[p];
										dConv[p] = dConv[q];
										dConv[q] = tem9;
										++q;
										--p;
									}
									
									for(r=0; r<len9; ++r) {
										
										if ((dConv[r] >= 48 && dConv[r] <= 57) || (dConv[r] >= 65 && dConv[r] <= 70) || (dConv[r] >= 97 && dConv[r] <= 102)) {
											
											if (dConv[r] == '0')
												sDec += 0;
											if (dConv[r] == '1')
												sDec += pow(16.0, r);
											if (dConv[r] == '2')
												sDec += 2*(pow(16.0, r));
											if (dConv[r] == '3')
												sDec += 3*(pow(16.0, r));
											if (dConv[r] == '4')
												sDec += 4*(pow(16.0, r));
											if (dConv[r] == '5')
												sDec += 5*(pow(16.0, r));
											if (dConv[r] == '6')
												sDec += 6*(pow(16.0, r));
											if (dConv[r] == '7')
												sDec += 7*(pow(16.0, r));
											if (dConv[r] == '8')
												sDec += 8*(pow(16.0, r));
											if (dConv[r] == '9')
												sDec += 9*(pow(16.0, r));
											if ((dConv[r] == 'A') || (dConv[r] == 'a'))
												sDec += 10*(pow(16.0, r));
											if ((dConv[r] == 'B') || (dConv[r] == 'b'))
												sDec += 11*(pow(16.0, r));
											if ((dConv[r] == 'C') || (dConv[r] == 'c'))
												sDec += 12*(pow(16.0, r));
											if ((dConv[r] == 'D') || (dConv[r] == 'd'))
												sDec += 13*(pow(16.0, r));
											if ((dConv[r] == 'E') || (dConv[r] == 'e'))
												sDec += 14*(pow(16.0, r));
											if ((dConv[r] == 'F') || (dConv[r] == 'f'))
												sDec += 15*(pow(16.0, r));
										}
										
										else {
											printf("\n\nError! Invalid hexadecimal expression.\n\n");
											sDec = 0;
											break;
										}
									}
									
									if (sDec != 0) {
			
										printf("\n\nIts decimal equivalent: %d", sDec);
										
										
									//**************************** convert to OCTAL ***********************************************
										
										nD7 = sDec;
										
										s=0;
										while(nD7 >= 8) { 
											rem5 = nD7 % 8;
											oEx[s] = '0' + rem5;
											nD7 /= 8;
											++s;	
										}
										
										oEx[s] = '0' + nD7;
										leng1 = s;
										t=0;
										t = leng1;
										u = 0;
																
										while(u<t) {
											temp1 = oEx[t];
											oEx[t] = oEx[u];
											oEx[u] = temp1;
											++u;
											--t;
										}
										
										printf("\n\nIts octal equivalent: ");
										for(v=0; v<=leng1; ++v) 
											printf("%c", oEx[v]);
				
								
										//**************************** convert to BINARY ***********************************************
										
										nD8 = sDec;
										
										//situation 1 : decimal == 0
										if (nD8 == 0) {
											bFinal[0] = '0';
											printf("\n\nIts binary equivalent: ");
											printf("%c", bFinal[0]);
										}
				
										//situation 2 : decimal == all other values
										else  {
											
											w=0;
												
											while (nD8 > 0) {
												
												if (nD8 % 2 == 0) {
													nD8 /= 2;
													bFinal[w] = '0';
												}
												
												else {
													nD8 /= 2;
													bFinal[w] = '1';
												}
												
												++w;
											}
											
											leng2 = w;						
											x=0;
											x = leng2-1;
											y=0;
											
											while(y<x) {
												temp2 = bFinal[x];
												bFinal[x] = bFinal[y];
												bFinal[y] = temp2;
												++y;
												--x;
											}
											printf("\n\nIts binary equivalent: ");
											for(z=0; z<leng2; ++z) 
												printf("%c", bFinal[z]);
										}
									}
									
									else 
										printf("\n");
									
								}
								
								sDec = 0;
									
								break;						
																				
					case 'e':
								getchar(); //this if for pressed ENTER key, once 'e' has been pressed	
								break;									
			} //end of switch
				
		} //end of "answer" IF statement
		
		else
			printf("\n\nError! Invalid choice.\n\n");
				
		printf("\n\nContinue? (Y/N)\n\n");
		do_again = getchar();
		getchar(); //this is for pressed ENTER key (once Y or N has been pressed)
		printf("\n");
		
	} //end of "do_again" while loop
	
	printf("\nWe hope this converter was helpful! Come back anytime!\n\n");	

	return 0;
}




