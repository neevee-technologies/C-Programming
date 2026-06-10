#include <stdio.h>

int area(int l, int b)
{
    return l * b;
}

int perimeter(int l, int b)
{
    return 2 * (l + b);
}

int main()
{
    int length, breadth;

    printf("Enter length and breadth: ");
    scanf("%d %d", &length, &breadth);

    printf("Area of rectangle: %d\n", area(length, breadth));
    printf("Perimeter of rectangle: %d\n", perimeter(length, breadth));

    return 0;
}