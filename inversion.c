#include <stdio.h>

int main()
{
    char str[50];
    int length = 0;
    char temp;

    printf("Enter a string: ");
    scanf("%s", str);

    while (str[length] != '\0')
        length++;

    for (int i = 0; i < length / 2; i++)
    {
        temp = str[i];
        str[i] = str[length - 1 - i];
        str[length - 1 - i] = temp;
    }

    printf("Reversed String: %s\n", str);

    return 0;
}