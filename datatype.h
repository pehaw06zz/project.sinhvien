#ifndef DATATYPE_H
#define DATATYPE_H
#define MAX 100
typedef struct Student {
char id[10];
char name[50];
char major[30];
char email[50];
char phone[15];
int size;
int age;
float gpa; 
};
extern Student students[MAX];
extern int student_count;
#endif
