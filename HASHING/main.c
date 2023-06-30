#include <stdio.h>
#include <stdlib.h>

#include "HASHING.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int size, key;
	
	int sex, sy, day, month, year;
	String studID, fname, mname, lname, program;
	
	Student stud;
	Dictionary dict;
	printf("How much is the size?");
	scanf("%d", &size);
	initDict(&dict, size);
	
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
	
	stud = newStudent(studID,fname,mname,lname,program,sex,sy,day,month,year);
	key = hash(dict, lname);
	
	insertSortedStudent(&dict,stud, key);
	
	printf("%s", dict.elems[100].data.studName.firstname);
	return 0;
}
