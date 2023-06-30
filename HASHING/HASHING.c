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
		d->elems[i].data = newStudent(" "," "," "," "," ",0,0,0,0,0);
		d->elems[i].next = NULL;
	}

}

Student newStudent(String studID, String fname, String mname, String lname, String program, int sex, int sy, int day, int month, int year){
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

SType* createNode(Student stud){
	SType *newNode = malloc(sizeof(SType) * size);
	newNode->data = stud;
	newNode->next = NULL;
	return newNode;
}

int hash(Dictionary d, String lastname){
	return toupper(lastname[0]) % d.max;
}

void insertSortedStudent(Dictionary *d, Student stud, int key){
	SType* newNode = createNode(stud);
	SType current = d->elems[key];
	SType* prev = NULL;
	SType* temp = NULL;
	
	if(d->elems[key].data.studID == " " || atoi(d->elems[key].data.studID) > atoi(stud.studID)){
		newNode->next = d->elems;
		d->elems[key].next = newNode;
	}
	
	while(current.data[key].studID != " " && atoi(current.data[key].studID) < atoi(stud.studID)){
		current = current.next;
	}
	
	
}


