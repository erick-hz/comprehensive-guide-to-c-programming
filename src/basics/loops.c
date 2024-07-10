#include <stdio.h>

int forLoop()
{
    for (int i = 0; i < 5; i++)
    {
        printf("i = %d\n", i);
    }

    return 0;
}

int whileLoop()
{
    int i = 0;
    while (i < 5)
    {
        printf("i = %d\n", i);
        i++;
    }

    return 0;
}

int main()
{
    
    forLoop();
    whileLoop();

    return 0;
}
