#include <stdio.h>

struct Student
{
    char name[50];
    int rollNo;
    char section[10];
    char dept[20];
    char college[50];
};

int main()
{
    FILE *fp;
    struct Student s;

    fp = fopen("student.csv", "r");

    if(fp == NULL)
    {
        printf("File cannot be opened\n");
        return 1;
    }

    char header[100];

    /* Skip header row */
    fgets(header, sizeof(header), fp);

    while(fscanf(fp,
                 "%49[^,],%d,%9[^,],%19[^,],%49[^\n]\n",
                 s.name,
                 &s.rollNo,
                 s.section,
                 s.dept,
                 s.college) == 5)
    {
        printf("\nStudent Details\n");
        printf("Name      : %s\n", s.name);
        printf("Roll No   : %d\n", s.rollNo);
        printf("Section   : %s\n", s.section);
        printf("Department: %s\n", s.dept);
        printf("College   : %s\n", s.college);
    }

    fclose(fp);

    return 0;
}