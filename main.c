#include <stdio.h>
#include "function.h"

int main(int argc, char *argv[]){
    char username[20],password[20];
    int role = 0;
    int attempts=0;
    printf("|======Login=====|\n");
    while (role==0) {
        if(attempts>=3){
            printf("You have entered the wrong password 3 times. Exiting program.\n");
            return 0;
        }
        printf("Username: ");
        scanf("%s", username);
        printf("Password: ");
        scanf("%s", password);
        role=authenticateUser(username,password);
        if(role==0){
            attempts++;
            printf("Login failed! Please try again (%d/3)\n", attempts);
        }
    }
    int choice;
    do {
        showMenu();
        printf("Your choice: ");
        if(scanf("%d",&choice)!=1){
            printf("Please enter a choice from 1-9.\n");
            while (getchar()!='\n');
            continue;
        }
        switch (choice) {
            case 1:
                printf("Displaying student list\n");
                displayStudents();
                break;
            case 2:
                printf("Adding a student\n");
                addStudent();
                break;
            case 3:
                printf("Updating student information\n");
                updateStudent();
                break;
            case 4:
                printf("Deleting a student\n");
                deleteStudent();
                break;
            case 5:
                printf("Searching for a student\n");
                searchStudent();
                break;
            case 6:
                printf("Sorting student list\n");
                sortStudents();
                break;
            case 7:
                printf("Saving student list to file\n");
                saveToFileBinary();
                break;
            case 8:
                printf("Reading student list from file\n");
                loadFromFileBinary();
                break;
            case 9:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice, please select from 1-9.\n");
        }
    } while (choice != 9);
    return 0;
}
