#include <stdio.h>
#include <string.h>

int main()
{
    char str1[50] = "Hello";
    char str2[50] = "World";
    char copy[50];

    strcpy(copy, str1);

    printf("Copied String: %s\n", copy);

    strcat(str1, str2);

    printf("Concatenated String: %s\n", str1);

    printf("Length of str2: %lu\n", strlen(str2));

    return 0;
}