#include <stdio.h>
int power(int v, int i)
{
    return v * i;
}
int energy(int p, int d)
{
    return p * d;
}
int main()
{
    int voltage, current, duration;
    printf("Enter the voltage: ");
    scanf("%d", &voltage);
    printf("Enter the current: ");
    scanf("%d", &current);
    printf("Enter the duration: ");
    scanf("%d", &duration);
    printf("The power consumption is: %d", power(voltage, current));
    printf("\nThe energy consumption is: %d", energy(power(voltage, current), duration));
    return 0;
}