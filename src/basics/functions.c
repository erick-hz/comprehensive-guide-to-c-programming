#include <stdio.h>

int add(int a, int b)
{
    return a + b;
}

int subtract(int a, int b)
{
    return a - b;
}

int multiply(int a, int b)
{
    return a * b;
}

double divide(int a, int b)
{
    if (b != 0)
    {
        return (double)a / b;
    }
    else
    {
        printf("Error: Division by zero.\n");
        return 0;
    }
}

int main()
{
    int x = 10, y = 5;

    printf("Add: %d + %d = %d\n", x, y, add(x, y));
    printf("Subtract: %d - %d = %d\n", x, y, subtract(x, y));
    printf("Multiply: %d * %d = %d\n", x, y, multiply(x, y));
    printf("Divide: %d / %d = %.2f\n", x, y, divide(x, y));

    return 0;
}
