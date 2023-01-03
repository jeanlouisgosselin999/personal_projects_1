#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXSIZE 4

//function prototypes:
void readinput(int);
void writeoutput(int);
void average();
void sortingEnglishScores();
void sortingFrenchScores();
void sortingMathsScores();
void sortingChemistryScores();
void sortingMusicScores();


//EXTERNAL STRUCTURE (secondary structure):
typedef struct{
	double scoreEnglish;
	double scoreFrench;
	double scoreMaths;
	double scoreChemistry;
	double scoreMusic;	
}marks;


//EXTERNAL MAIN STRUCTURE:
struct studentFile {
	char name[80];
	char rollNumber[10]; //===> NOTE: a roll number can often consist of a series of numbers AND letters; hence: the CHAR array
	marks studentScores;
} student[MAXSIZE]; 


int main(int argc, char *argv[]) {
	
	int i, numStudents;
	
	printf("TEST SCORING LOG\n\n");
	printf("Enter 4 names:");	
	//calling our first function to assign all the information to each student:
	for(i=0; i<4; ++i)
		readinput(i);
	
	//calling our second functionto print all created students and related info:
	printf("\nAll 8 students + scores:\n\n");	
	for(i=0; i<4; ++i)
		writeoutput(i);
		
	//printing total marks (ie: average) of each student:
	printf("\n\nAverages of each student:\n\n");	
	average();
		
	//sorting each student's result per subject and printing the highest result + corresponding name and roll number:
	sortingEnglishScores();
	sortingFrenchScores();
	sortingMathsScores();
	sortingChemistryScores();
	sortingMusicScores();
	
	getchar();	
	return 0;
}


void readinput(int i) { 

	int a, b;
	
	printf("\n\n\nStudent no. %d\n", i+1);

	//assigning a name to the member "name" through our variable "customer" 
	printf("   Name:              ");
	scanf(" %[^\n]", student[i].name); 
	

	//assigning a floating-point value to the member "rollNumber" through our variable "student" 
	printf("   Student roll number:    ");
	scanf(" %[^\n]", student[i].rollNumber);

		
	//assigning a floating-point value to the member "score" through our variable "student" 
	printf("\n   Student score per subject:\n");
	printf("English:	");
	scanf("%lg", &student[i].studentScores.scoreEnglish);
	printf("French:		");
	scanf("%lg", &student[i].studentScores.scoreFrench);
	printf("Maths:		");
	scanf("%lg", &student[i].studentScores.scoreMaths);
	printf("Chemistry:	");
	scanf("%lg", &student[i].studentScores.scoreChemistry);
	printf("Music:		");
	scanf("%lg", &student[i].studentScores.scoreMusic);
	
	getchar();	
	return;
}



void writeoutput(int i) {
	
	int a, b;
		
	printf("\n\n***********************************************************");
	printf("\n\n	Name:\t\t%s\n", student[i].name); //===> NOTICE: no & symbol preceding a CHAR array
	
	printf("\n\n	Student roll number:\t\t%s\n", student[i].rollNumber);
	
	printf("\n\n	Scores obtained per subject:\n\n");
	printf("	English:	%g", student[i].studentScores.scoreEnglish);
	printf("\n	French:		%g", student[i].studentScores.scoreFrench);
	printf("\n	Maths:		%g", student[i].studentScores.scoreMaths);
	printf("\n	Chemistry:	%g", student[i].studentScores.scoreChemistry);
	printf("\n	Music:		%g", student[i].studentScores.scoreMusic);	

		
	return;
}

void average() {
	
	int i;
	double totalAverage[4];
	
	for(i=0; i<4; i++) {

		totalAverage[i] = (student[i].studentScores.scoreEnglish + student[i].studentScores.scoreFrench + student[i].studentScores.scoreMaths
							+ student[i].studentScores.scoreChemistry + student[i].studentScores.scoreMusic) / 5;		
		printf("\nAverage of student %d (%s, roll number %s) is %g\n\n", i+1, student[i].name, student[i].rollNumber, totalAverage[i]);

	}
	
	return;
}

void sortingEnglishScores() {
	
	int a, i, j, k;
	double temp;
	char* tempName;
	char* tempRollNum;
	char* duplicateName[4];
	char* duplicateRollNum[4];
		
	//saving names and roll numbers in duplicate pointers, so as not to change their initial order from function to function:
	for(a=0; a<4; a++)
		duplicateName[a] = student[a].name;
		
	//saving names and roll numbers in duplicate pointers, so as not to change their initial order from function to function:
	for(a=0; a<4; a++)
		duplicateRollNum[a] = student[a].rollNumber;		
					
	//using bubble sort to sort each mark per subject and per student, from highest to lowest:
	for(i=0; i<4; i++) {
		
		for(j=0; j<3; j++) {
		
			if(student[j].studentScores.scoreEnglish < student[j+1].studentScores.scoreEnglish){
				
				temp = student[j+1].studentScores.scoreEnglish;
				student[j+1].studentScores.scoreEnglish = student[j].studentScores.scoreEnglish;
				student[j].studentScores.scoreEnglish = temp;
				
				tempName = duplicateName[j+1];
				duplicateName[j+1] = duplicateName[j];
				duplicateName[j] = tempName;
				
				tempRollNum = duplicateRollNum[j+1];
				duplicateRollNum[j+1] = duplicateRollNum[j];
				duplicateRollNum[j] = tempRollNum;				
			}
		}
	}

	
	printf("\n\nThe highest score in English is: %g", student[0].studentScores.scoreEnglish);	
	printf("\nStudent: %s (roll number: %s) has obtained this score.", duplicateName[0], duplicateRollNum[0]);
				
	return;
}

void sortingFrenchScores() {
	
	int a, i, j, k;
	double temp;
	char* tempName;
	char* tempRollNum;
	char* duplicateName[4];
	char* duplicateRollNum[4];
		
	//saving names and roll numbers in duplicate pointers, so as not to change their initial order from function to function:
	for(a=0; a<4; a++)
		duplicateName[a] = student[a].name;
		
	//saving names and roll numbers in duplicate pointers, so as not to change their initial order from function to function:
	for(a=0; a<4; a++)
		duplicateRollNum[a] = student[a].rollNumber;
	
	//using bubble sort to sort each mark per subject and per student, from highest to lowest:
	for(i=0; i<4; i++) {
		
		for(j=0; j<3; j++) {
		
			if(student[j].studentScores.scoreFrench < student[j+1].studentScores.scoreFrench) {
				
				temp = student[j+1].studentScores.scoreFrench;
				student[j+1].studentScores.scoreFrench = student[j].studentScores.scoreFrench;
				student[j].studentScores.scoreFrench = temp;
				
				tempName = duplicateName[j+1];
				duplicateName[j+1] = duplicateName[j];
				duplicateName[j] = tempName;
				
				tempRollNum = duplicateRollNum[j+1];
				duplicateRollNum[j+1] = duplicateRollNum[j];
				duplicateRollNum[j] = tempRollNum;
			}
		}
	}
	
	printf("\n\nThe highest score in French is: %g", student[0].studentScores.scoreFrench);
	printf("\nStudent: %s (roll number: %s) has obtained this score.", duplicateName[0], duplicateRollNum[0]);

	return;
}

void sortingMathsScores() {
	
	int a, i, j, k;
	double temp;
	char* tempName;
	char* tempRollNum;
	char* duplicateName[4];
	char* duplicateRollNum[4];
		
	//saving names and roll numbers in duplicate pointers, so as not to change their initial order from function to function:
	for(a=0; a<4; a++)
		duplicateName[a] = student[a].name;
		
	//saving names and roll numbers in duplicate pointers, so as not to change their initial order from function to function:
	for(a=0; a<4; a++)
		duplicateRollNum[a] = student[a].rollNumber;
	
	//using bubble sort to sort each mark per subject and per student, from highest to lowest:
	for(i=0; i<4; i++) {
		
		for(j=0; j<3; j++) {
		
			if(student[j].studentScores.scoreMaths < student[j+1].studentScores.scoreMaths){
				
				temp = student[j+1].studentScores.scoreMaths;
				student[j+1].studentScores.scoreMaths = student[j].studentScores.scoreMaths;
				student[j].studentScores.scoreMaths = temp;
				
				tempName = duplicateName[j+1];
				duplicateName[j+1] = duplicateName[j];
				duplicateName[j] = tempName;
				
				tempRollNum = duplicateRollNum[j+1];
				duplicateRollNum[j+1] = duplicateRollNum[j];
				duplicateRollNum[j] = tempRollNum;
			}
		}
	}
	
	printf("\n\nThe highest score in Maths is: %g", student[0].studentScores.scoreMaths);
	printf("\nStudent: %s (roll number: %s) has obtained this score.", duplicateName[0], duplicateRollNum[0]);
		
	return;
}

void sortingChemistryScores() {
	
	int a, i, j, k;
	double temp;
	char* tempName;
	char* tempRollNum;
	char* duplicateName[4];
	char* duplicateRollNum[4];
		
	//saving names and roll numbers in duplicate pointers, so as not to change their initial order from function to function:
	for(a=0; a<4; a++)
		duplicateName[a] = student[a].name;
		
	//saving names and roll numbers in duplicate pointers, so as not to change their initial order from function to function:
	for(a=0; a<4; a++)
		duplicateRollNum[a] = student[a].rollNumber;
	
	//using bubble sort to sort each mark per subject and per student, from highest to lowest:
	for(i=0; i<4; i++) {
		
		for(j=0; j<3; j++) {		
		
			if(student[j].studentScores.scoreChemistry < student[j+1].studentScores.scoreChemistry){
				
				temp = student[j+1].studentScores.scoreChemistry;
				student[j+1].studentScores.scoreChemistry = student[j].studentScores.scoreChemistry;
				student[j].studentScores.scoreChemistry = temp;
				
				tempName = duplicateName[j+1];
				duplicateName[j+1] = duplicateName[j];
				duplicateName[j] = tempName;
				
				tempRollNum = duplicateRollNum[j+1];
				duplicateRollNum[j+1] = duplicateRollNum[j];
				duplicateRollNum[j] = tempRollNum;
			}
		}
	}
	
	printf("\n\nThe highest score in Chemistry is: %g", student[0].studentScores.scoreChemistry);
	printf("\nStudent: %s (roll number: %s) has obtained this score.", duplicateName[0], duplicateRollNum[0]);
		
	return;
}

void sortingMusicScores() {
	
	int a, i, j, k;
	double temp;
	char* tempName;
	char* tempRollNum;
	char* duplicateName[4];
	char* duplicateRollNum[4];
	
	//saving names and roll numbers in duplicate pointers, so as not to change their initial order from function to function:
	for(a=0; a<4; a++)
		duplicateName[a] = student[a].name;
		
	//saving names and roll numbers in duplicate pointers, so as not to change their initial order from function to function:
	for(a=0; a<4; a++)
		duplicateRollNum[a] = student[a].rollNumber;
	
	//using bubble sort to sort each mark per subject and per student, from highest to lowest:
	for(i=0; i<4; i++) {		
				
		for(j=0; j<3; j++) {
		
			if(student[j].studentScores.scoreMusic < student[j+1].studentScores.scoreMusic){
				
				temp = student[j+1].studentScores.scoreMusic;
				student[j+1].studentScores.scoreMusic = student[j].studentScores.scoreMusic;
				student[j].studentScores.scoreMusic = temp;
				
				tempName = duplicateName[j+1];
				duplicateName[j+1] = duplicateName[j];
				duplicateName[j] = tempName;
				
				tempRollNum = duplicateRollNum[j+1];
				duplicateRollNum[j+1] = duplicateRollNum[j];
				duplicateRollNum[j] = tempRollNum;
			}
		}
	}
	
	printf("\n\nThe highest score in Music is: %g", student[0].studentScores.scoreMusic);
	printf("\nStudent: %s (roll number: %s) has obtained this score.", duplicateName[0], duplicateRollNum[0]);
		
	return;
}
