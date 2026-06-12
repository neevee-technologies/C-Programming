#include <stdio.h>

int main()
{
    int arr[100], n, sum = 0;
    int *ptr;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter array elements:\n");

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    ptr = arr;

    for (int i = 0; i < n; i++)
    {
        sum = sum + *(ptr + i);
    }

    printf("Sum of elements = %d\n", sum);

    return 0;
}