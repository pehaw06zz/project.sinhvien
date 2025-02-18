#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "function.h"
#include "datatype.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
Student students[MAX];
int student_count = 0;

int authenticateUser(char *username,char*password){
    if(strcmp(username,"admin")==0&&strcmp(password,"admin123")==0){
       return 1;
    }else if(strcmp(username,"student")==0&&strcmp(password,"student123")==0){
       return 2;
    }
    return 0;
}
void showMenu() {
    const char *border="+======+=====+=====+=====+=====+======+\n";
    printf("%s",border);
    printf("+====|------- %-10s -------|====+\n", "MAIN MENU ");
    printf("%s",border);
    printf("|%-2d. %-30s ===|\n",1,"Print student list");
    printf("|%-2d. %-30s ===|\n",2,"Add student");
    printf("|%-2d. %-30s ===|\n",3,"Edit student information");
    printf("|%-2d. %-30s ===|\n",4,"Delete student");
    printf("|%-2d. %-30s ===|\n",5,"Search student");
    printf("|%-2d. %-25s      ===|\n",6,"Sort student list");
    printf("|%-2d. %-30s ===|\n",7,"Save list to File");
    printf("|%-2d. %-30s ===|\n",8,"Load list from File");
    printf("|%-2d. %-30s ===|\n",9,"Exit");
    printf("%s", border);
}
void displayStudents(){
    if(student_count==0){
        printf("There are no students.\n");
        return;
    }
    printf("Student list:\n");
    printf("======================================== STUDENT LIST ========================================\n");
    printf("+------+----------------------+----------------------+----------------------+---------------+------+\n");
    printf("| ID   | Name                 | Major                | Email                | Phone         | Age  |\n");
    printf("+------+----------------------+----------------------+----------------------+---------------+------+\n");
    for(int i=0;i<student_count;i++){
        printf("| %-4s | %-20s | %-20s | %-20s | %-13s | %-4d |\n",students[i].id,students[i].name,students[i].major,students[i].email,students[i].phone,students[i].size);
    }
    printf("+------+----------------------+----------------------+----------------------+---------------+------+\n");
}
int isStudentIDExists(char *id){
    for(int i=0;i<student_count;i++){
        if(strcmp(students[i].id,id)==0){
            return 1;
        }
    }
    return 0;
}
int isDuplicate(char id[],char email[],char phone[]){
    for(int i=0;i<student_count;i++) {
        if(strcmp(students[i].id,id)==0||strcmp(students[i].email,email)==0||strcmp(students[i].phone,phone)==0){
            return 1;
        }
    }
    return 0;
}
void addStudent(){
    if(student_count>=MAX){
        printf("The student list is full.\n");
        return;
    }
    Student newStudent;
    do {
        printf("Enter ID: ");
        scanf("%s",newStudent.id);
        while (getchar()!='\n');
        printf("Enter name: ");
        scanf("%[^\n]",newStudent.name);
        while (getchar()!='\n');
        printf("Enter Major: ");
        scanf("%[^\n]",newStudent.major);
        while (getchar()!='\n');
        printf("Enter Email: ");
        scanf("%s",newStudent.email);
        while(getchar()!='\n');
        printf("Enter Phone number: ");
        scanf("%s",newStudent.phone);
        while(getchar()!='\n');
        printf("Enter Age: ");
        if (scanf("%d", &newStudent.size) != 1) {
            printf("Invalid age. Please enter again!\n");
            while (getchar() != '\n');
            continue;
        }
        while(getchar()!='\n');
        if(strlen(newStudent.id)==0||strlen(newStudent.name)==0||strlen(newStudent.major)==0||strlen(newStudent.email)==0||strlen(newStudent.phone)==0){
            printf("Student information cannot be left blank. Please enter again.\n");
            continue;
        }
        if(isDuplicate(newStudent.id,newStudent.email,newStudent.phone)){
            printf("ID, Email, or Phone number already exists. Please enter again.\n");
            continue;
        }
        students[student_count++]=newStudent;
        printf("Student added successfully!\n");
        break;
    } while (1);
}
void updateStudent(){
    char id[10];
    printf("Enter the ID of the student to edit: ");
    scanf("%s", id);
    for(int i=0;i<student_count;i++){
        if(strcmp(students[i].id,id)==0){
            while (getchar()!='\n');
            printf("Enter new name: ");
            fgets(students[i].name,sizeof(students[i].name),stdin);
            students[i].name[strcspn(students[i].name,"\n")]='\0';
            printf("Enter new major: ");
            fgets(students[i].major, sizeof(students[i].major),stdin);
            students[i].major[strcspn(students[i].major,"\n")]='\0';
            printf("Enter new Email: ");
            fgets(students[i].email,sizeof(students[i].email),stdin);
            students[i].email[strcspn(students[i].email,"\n")]='\0';
            printf("Enter new Phone number :");
            fgets(students[i].phone,sizeof(students[i].phone),stdin);
            students[i].phone[strcspn(students[i].phone,"\n")]='\0';
            printf("Enter new Age: ");
            scanf("%d",&students[i].size);
            printf("Student information updated successfully.\n");
            return;
        }
    }
    printf("Student not found.\n");
}
void deleteStudent(){
    char id[10];
    printf("Enter the ID of the student to delete: ");
    scanf("%s",id);
    for(int i=0;i<student_count;i++){
        if(strcmp(students[i].id, id) == 0){
            printf("Are you sure you want to delete student %s?(yes/no): ",students[i].name);
            char confirm[4];
            scanf("%s", confirm);
            if (strcmp(confirm, "yes")!=0&&strcmp(confirm,"y")!=0){
                printf("Cancelled student deletion.\n");
                return;
            }
            for(int j=i;j<student_count-1;j++){
                students[j]=students[j+1];
            }
            student_count--;
            printf("Deleted successfully.\n");
            return;
        }
    }
    printf("Student not found.\n");
}
void searchStudent(){
    char name[50];
    printf("Enter the NAME of the student to search: ");
    scanf("%s",name);
    int found=0;
    for(int i=0;i<student_count;i++){
        if(strcmp(students[i].name,name)==0){
            printf("================================ STUDENT FOUND ================================\n");
            printf("+-------+--------------------+--------------------+\n");
            printf("|  ID   |       Name         |       Major        |\n");
            printf("+-------+--------------------+--------------------+\n");
            printf("| %-5s | %-18s | %-18s |\n", students[i].id, students[i].name, students[i].major);
            printf("+-------+--------------------+--------------------+\n");
            found = 1;
            break;
        }
    }
    if(!found){
        printf("No student found with Name %s.\n",name);
    }
}
void sortStudents(){
    int i,j;
    for(i=0; i<student_count-1; i++){
        for(j=i+1;j<student_count;j++){
            if(strcmp(students[i].name,students[j].name)>0){
                Student temp=students[i];
                students[i]=students[j];
                students[j]=temp;  
            }
        }
    }
    printf("Student list sorted successfully.\n");
}
void saveToFileBinary(){
    FILE *file=fopen("students.dat", "wb");
    if(!file){
        printf("Error opening file\n");
        return;
    }
    fwrite(&student_count,sizeof(int),1,file);
    fwrite(students,sizeof(Student),student_count,file);
    fclose(file);
    printf("Student list saved to file successfully.\n");
}
void loadFromFileBinary(){
    FILE *file=fopen("students.dat","rb");
    if(!file){
        printf("File not found!\n");
        return;
    }
    fread(&student_count, sizeof(int),1,file);
    fread(students,sizeof(Student),student_count,file);
    fclose(file);
    printf("Student list loaded from file successfully!\n");
}

