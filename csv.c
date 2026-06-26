#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Student
{
    char name[50];
    char dept[30];
    int marks;
    int totalMarks;
    char remarks[50];
    float attendance;

    struct Student *prev;
    struct Student *next;

} Student;

Student *head = NULL;
Student *tail = NULL;

// Function to create CSV file
void createCSV()
{
    FILE *fp = fopen("students.csv", "w");

    if (fp == NULL)
    {
        printf("Error creating file!\n");
        return;
    }

    fprintf(fp, "Harshini,ECE,89,100,Excellent,95.5\n");
    fprintf(fp, "Rahul,CSE,76,100,Good,88.2\n");
    fprintf(fp, "Priya,EEE,67,100,Average,81.5\n");
    fprintf(fp, "Arun,IT,92,100,Outstanding,97.1\n");
    fprintf(fp, "Divya,ECE,58,100,Needs Improvement,74.6\n");

    fclose(fp);

    printf("CSV File Created Successfully.\n");
}

// Function to create a new node
Student *createNode(char name[], char dept[], int marks, int totalMarks,
                    char remarks[], float attendance)
{
    Student *newNode = (Student *)malloc(sizeof(Student));

    strcpy(newNode->name, name);
    strcpy(newNode->dept, dept);
    newNode->marks = marks;
    newNode->totalMarks = totalMarks;
    strcpy(newNode->remarks, remarks);
    newNode->attendance = attendance;

    newNode->prev = NULL;
    newNode->next = NULL;

    return newNode;
}

// Insert node at end
void insertEnd(Student *newNode)
{
    if (head == NULL)
    {
        head = tail = newNode;
    }
    else
    {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
}

// Read CSV file and populate DLL
void readCSV()
{
    FILE *fp = fopen("students.csv", "r");

    if (fp == NULL)
    {
        printf("Error opening file!\n");
        return;
    }

    char name[50], dept[30], remarks[50];
    int marks, totalMarks;
    float attendance;

    while (fscanf(fp, "%49[^,],%29[^,],%d,%d,%49[^,],%f",
                  name,
                  dept,
                  &marks,
                  &totalMarks,
                  remarks,
                  &attendance) == 6)
    {
        Student *newNode = createNode(name, dept, marks, totalMarks,
                                      remarks, attendance);

        insertEnd(newNode);
    }

    fclose(fp);

    printf("CSV Data Loaded into Doubly Linked List.\n");
}

// Display all students
void display()
{
    Student *temp = head;

    if (temp == NULL)
    {
        printf("List is Empty.\n");
        return;
    }

    printf("\n============= STUDENT DETAILS =============\n\n");

    while (temp != NULL)
    {
        printf("Name       : %s\n", temp->name);
        printf("Department : %s\n", temp->dept);
        printf("Marks      : %d\n", temp->marks);
        printf("TotalMarks : %d\n", temp->totalMarks);
        printf("Remarks    : %s\n", temp->remarks);
        printf("Attendance : %.2f%%\n", temp->attendance);
        printf("----------------------------------------\n");

        temp = temp->next;
    }
}

// Search by Name
void searchByName()
{
    char searchName[50];
    int found = 0;

    printf("Enter Student Name: ");
    scanf("%s", searchName);

    Student *temp = head;

    while (temp != NULL)
    {
        if (strcmp(temp->name, searchName) == 0)
        {
            printf("\nRecord Found\n");
            printf("Name       : %s\n", temp->name);
            printf("Department : %s\n", temp->dept);
            printf("Marks      : %d\n", temp->marks);
            printf("Attendance : %.2f%%\n", temp->attendance);

            found = 1;
            break;
        }

        temp = temp->next;
    }

    if (!found)
        printf("Student Not Found.\n");
}

// Search by Marks
void searchByMarks()
{
    int searchMarks;
    int found = 0;

    printf("Enter Marks: ");
    scanf("%d", &searchMarks);

    Student *temp = head;

    while (temp != NULL)
    {
        if (temp->marks == searchMarks)
        {
            printf("\nName       : %s\n", temp->name);
            printf("Department : %s\n", temp->dept);
            printf("Attendance : %.2f%%\n", temp->attendance);
            printf("----------------------------------------\n");

            found = 1;
        }

        temp = temp->next;
    }

    if (!found)
        printf("No Student Found with %d Marks.\n", searchMarks);
}

// Search by Attendance
void searchByAttendance()
{
    float percentage;
    int found = 0;

    printf("Enter Minimum Attendance Percentage: ");
    scanf("%f", &percentage);

    Student *temp = head;

    while (temp != NULL)
    {
        if (temp->attendance >= percentage)
        {
            printf("\nName       : %s\n", temp->name);
            printf("Attendance : %.2f%%\n", temp->attendance);
            printf("Marks      : %d\n", temp->marks);
            printf("----------------------------------------\n");

            found = 1;
        }

        temp = temp->next;
    }

    if (!found)
        printf("No Student Found.\n");
}

// Free the linked list memory
void freeList()
{
    Student *temp;

    while (head != NULL)
    {
        temp = head;
        head = head->next;
        free(temp);
    }
}

// Main Function
int main()
{
    int choice;

    createCSV();

    readCSV();

    do
    {
        printf("\n========== MENU ==========\n");
        printf("1. Display All Students\n");
        printf("2. Search by Name\n");
        printf("3. Search by Marks\n");
        printf("4. Search by Attendance\n");
        printf("5. Exit\n");
        printf("Enter your Choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            display();
            break;

        case 2:
            searchByName();
            break;

        case 3:
            searchByMarks();
            break;

        case 4:
            searchByAttendance();
            break;

        case 5:
            freeList();
            printf("Program Exited Successfully.\n");
            break;

        default:
            printf("Invalid Choice!\n");
        }

    } while (choice != 5);

    return 0;
}