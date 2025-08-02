#ifndef TYPE_H
#define TYPE_H
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_SIZE 100
#define PASSWORD "1234"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef unsigned long long u64;
typedef char s8;
typedef short s16;
typedef int s32;
typedef long long s64;

typedef struct Student
{
    u16 ID ;
    u16 math;
    u16 language;
    u16 physics;
    u16 chemistry;
    s8 name[25];
} Student;

void printMainMenu(); 
void checkMenuInput(); // process menu input if user or admin.
void handleAdmin (); // handle admin operations.
void addStudent(); // add a new student .
void editStudent(u16 idx); // edit student data and validate it.
void showStudentInfo(u16 idx); // show student's informations.
void handleUser(); // handle user operations.
void editDegree(u16* degree); // edit a degree for a specific student and validate it.
void addDegree(u16* degree); // add a degree for a new student and validate it.
u8 processID(u16* id, u16* idx, u8 flag); /* takes ID and return index of the student in idx.
the flag parameter is passed to determine the mode is user or admin, 0 for admin and 1 for user. */
s8 setID(u16* id, u16* idx); // assigns an ID with a value and validate it.
s8 searchID (u16 id, u16* idx); // search if and an ID exists and returb the index of it in idx.
void clearInputBuffer(); // clear buffer from invalid input. If not, it will cause an infinite loop as scanf will absorb it again.
#endif