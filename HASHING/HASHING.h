#ifndef HASHING_H
#define HASHING_H
#include <stdbool.h>
#include <ctype.h>

typedef char String[20];

typedef struct{
	String firstname;
	String middlename;
	String lastname;
}Name;

typedef struct{
	int date;
	int month;
	int year;
}myDate;

typedef struct{
	String studID;
	Name studName;
	bool sex; //1 for male 00 for female
	myDate birthdate;
	String program;
	int year;
}Student;

typedef struct node{
	Student data;
	struct node *next;
}SType;

typedef struct{
	SType *elems;
	int count;
	int max;
}Dictionary;

//25 max SType
//Hash number for lastname

void initDict(Dictionary *d, int size);

Student newStudent(String studID, String fname, String mname, String lname, String program, int sex, int sy, int day, int month, int year);

SType* createNode(Student stud);
void insertSortedStudent(Dictionary *d, Student stud, int key);
void removeStudent();
int hash(Dictionary d, String lastname);
void visualize(Dictionary d);


#endif
