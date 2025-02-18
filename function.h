#ifndef FUNCTION_H
#define FUNCTION_H
#define MAX 100
typedef struct {
char id[10];
char name[50];
char major[30];
char email[50];
char phone[15];
int size;
} Student;
int isDuplicate(char id[], char email[], char phone[]);
extern Student students[MAX];
extern int student_count;
void showMenu();
void displayStudents();
void addStudent();
void updateStudent();
void deleteStudent();
void searchStudent();
void sortStudents();
void saveToFileBinary();
void loadFromFileBinary();
#endif
