#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#include "HASHING.h"

void initDict(Dictionary *d, int size){
	int i;

	d->elems = malloc(sizeof(SType) * size);
	d->count = 0;
	d->max = size;

	for(i=0;i<d->max;++i){
		d->elems[i].data = newStudent(" "," "," "," "," ",false,0,0,0,0);
		d->elems[i].next = NULL;
	}

}

Student newStudent(String studID, String fname, String mname, String lname, String program, bool sex, int sy, int day, int month, int year){
	Student newStud;
	strcpy(newStud.studID, studID);
	strcpy(newStud.studName.firstname, fname);
	strcpy(newStud.studName.middlename, mname);
	strcpy(newStud.studName.lastname, lname);
	strcpy(newStud.program, program);
	newStud.sex = sex;
	newStud.year = sy;
	newStud.birthdate.date = day;
	newStud.birthdate.month = month;
	newStud.birthdate.year = year;
	
	return newStud;
}

SType* createNode(Dictionary d, Student stud){
	SType *newNode = malloc(sizeof(SType));
	newNode->data = stud;
	newNode->next = NULL;
	return newNode;
}

int hash(Dictionary d, String lastname){
	return toupper(lastname[0]) % d.max;
}

bool insertSortedStudent(Dictionary *d, Student stud, int key){
	SType* newNode = createNode(*d, stud);
	Student newStud;
	SType* temp = &d->elems[key];
	if(atoi(d->elems[key].data.studID) == 0){  	       
		d->elems[key].data = stud;
		return true;
	}
	else if(strcmp(d->elems[key].data.studID, stud.studID)>0){
		temp = temp->next;
		newStud = d->elems[key].data;
		d->elems[key].data = stud;
		newNode = createNode(*d, newStud);
		newNode->next = temp;
		d->elems[key].next = newNode;
		return true;
	}
	else{
		SType* current = &d->elems[key];

		while(current->next != NULL && strcmp(current->data.studID, stud.studID)<0){
			current = current->next;
		}
		newNode->next = current->next;
		current->next = newNode;
		
		return false;	
	}

}


bool removeStudent(Dictionary *d, String studID, String lname, int key){
	int count = 0;
	SType* curr = &d->elems[key];
	SType* temp = &d->elems[key];
	SType* trav = &d->elems[key];
	Student newStud;
	
	SType* prev = NULL;
	while(curr!=NULL && strcmp(curr->data.studID, studID)!=0 && strcmp(curr->data.studName.lastname, lname)!=0){
		prev = curr;
		curr = curr->next;
		count++;
	}
	if(strcmp(curr->data.studID, studID)==0 && strcmp(curr->data.studName.lastname, lname)==0 && count==0){
		curr = curr->next;
		trav = curr;
		newStud = curr->data;
		d->elems[key].data = newStudent(newStud.studID, newStud.studName.firstname, newStud.studName.middlename, newStud.studName.lastname, 
							newStud.program,newStud.sex,newStud.year,newStud.birthdate.date,newStud.birthdate.month,newStud.birthdate.year);
		trav = trav->next;
		d->elems[key].next = trav;
		free(curr);
							
	}
	else if(curr->next==NULL){
		prev->next = NULL;
		free(curr);
	}
}

void visualize(Dictionary d, int size){

	String month;
	char sex;
	
	

	int i;
	for(i=0;i<size;++i){
		switch(d.elems[i].data.birthdate.month){
			case 0:
				strcpy(month, "January");
				break;
			case 1:
				strcpy(month, "February");
				break;
			case 2:
				strcpy(month, "March");
				break;
			case 3:
				strcpy(month, "April");
				break;
			case 4:
				strcpy(month, "May");
				break;
			case 5:
				strcpy(month, "June");
				break;
			case 6:
				strcpy(month, "July");
				break;
			case 7:
				strcpy(month, "August");
				break;
			case 8:
				strcpy(month, "September");
				break;
			case 9:
				strcpy(month, "October");
				break;
			case 10:
				strcpy(month, "November");
				break;
			case 11:
				strcpy(month, "December");
				break;
			default:
				break;	
		}
		
		if(d.elems[i].data.sex){
			sex = 'm';
		}
		else{
			sex = 'f';
		}
		
		SType* current = &d.elems[i];
		printf("INDEX %d:\n", i);
		printf("%8s | %15s | %10s | %10s | %s | %2s | %2s | %4s | %4s | %4s |\n",
				"ID NUMBER", "FIRST NAME", "MIDDLE NAME", 
				"LAST NAME", "SEX", "BIRTHMONTH", "BIRTHDAY", 
				"BIRTHYEAR", "PROGRAM", "STUDENT YEAR");
		printf("------------------------\n");
		while(current !=NULL){
			printf("%10s ", current->data.studID);
			printf("%16s ", current->data.studName.firstname);
			printf("%13s ", current->data.studName.middlename);
			printf("%12s ", current->data.studName.lastname);
			printf("%4c ", sex);
			printf("%13s ", month);
			printf("%6d ", current->data.birthdate.date);
			printf("%12d ", current->data.birthdate.year);
			printf("%10s ", current->data.program);
			printf("%12d\n", current->data.year);
			current = current->next;
		}
		printf("\n\n");
	}
	
}
