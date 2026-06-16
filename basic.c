#include <stdio.h>

int main()
{
    char str[50];
    int length = 0;

    printf("Enter a string: ");
    scanf("%s", str);

    while (str[length] != '\0')
    {
        length++;
    }

    printf("String: %s\n", str);
    printf("Length: %d\n", length);

    return 0;
}