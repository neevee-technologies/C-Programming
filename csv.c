#include <stdio.h>

int main()
{
    FILE *fp;

    fp = fopen("student.csv", "w");

    fprintf(fp, "Name,RollNo,Section,Department,College\n");
    fprintf(fp, "Harshini,101,A,CSE,ABC College\n");
    fprintf(fp, "Priya,102,B,ECE,ABC College\n");

    fclose(fp);

    printf("CSV File Created Successfully\n");

    return 0;
}