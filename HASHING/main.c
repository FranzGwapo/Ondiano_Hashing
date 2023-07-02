#include <stdio.h>
#include <stdlib.h>

#include "HASHING.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int size, key, choice;
	bool state;
	
//	Test Cases
//	int sy = 2022, day = 2, month = 2, year = 2002;
//	int sy1 = 2023, day1 = 3, month1 = 3, year1 = 3;
//	bool sex = 1;
//	bool sex1 = 1;
//	String studID = "19104001", fname = "Franz Casimir", mname = "Casimir", lname = "Ondiano", program = "BSIT";
//	String studID1 = "19105001", fname1 = "qweqw", mname1 = "asdas", lname1 = "Ondiano", program1 = "BSCS";
	
	int sy, day, month, year;
	String studID, fname, mname, lname, program;
	bool sex;
	Student stud, stud1;
	Dictionary dict;


	printf("MAIN MENU\n");
	printf("How much is the size? ");
	scanf("%d", &size);
	initDict(&dict, size);
	
	do{
		printf("Pick a choice:\n1. Insert a Student\n2. Remove a student\n3. Visualize\n0. Exit\nChoice: ");
		scanf("%d", &choice);
		printf("\n");
		switch(choice){
			case 1:	
				printf("Enter Student ID: ");
				scanf("%s", &studID);
				printf("Enter First name: ");
				scanf("%s", &fname);
				printf("Enter Middle name: ");
				scanf("%s", &mname);
				printf("Enter Last name: ");
				scanf("%s", &lname);
				printf("Enter Sex (1-male 0-female): ");
				scanf("%d", &sex);
				printf("Enter Program: ");
				scanf("%s", &program);
				printf("Enter what Student Year: ");
				scanf("%d", &sy);
				printf("Enter day of birth: ");
				scanf("%d", &day);
				printf("Enter month of birth (0(January)-11(December)): ");
				scanf("%d", &month);
				printf("Enter year of birth: ");
				scanf("%d", &year);
				
				stud = newStudent(studID, fname,mname,lname,program,sex,sy,day,month,year);
				key = hash(dict, lname);
	
				state = insertSortedStudent(&dict,stud, key);
				break;
			case 2:
				printf("Enter Student ID: ");
				scanf("%s", &studID);
				printf("Enter Family Name: ");
				scanf("%s", &lname);
				key = hash(dict, lname);
				state = removeStudent(&dict,studID,lname, key);
				
				break;
			case 3:
				visualize(dict, size);
			default:
				printf("Thank you!\n");
		}
	}while(choice!=0);
	
	return 0;
}