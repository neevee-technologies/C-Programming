#include <stdio.h>

void binary(int n)
{
    int binary[32];
    int i = 0;

    while (n > 0)
    {
        binary[i] = n % 2;
        n = n / 2;
        i++;
    }

    printf("Binary: ");

    for (int j = i - 1; j >= 0; j--)
    {
        printf("%d", binary[j]);
    }

    printf("\n");
}

void octal(int n)
{
    printf("Octal: %o\n", n);
}

void hexadecimal(int n)
{
    printf("Hexadecimal: %X\n", n);
}

int main()
{
    int num;

    printf("Enter a decimal number: ");
    scanf("%d", &num);

    binary(num);
    octal(num);
    hexadecimal(num);

    return 0;
}