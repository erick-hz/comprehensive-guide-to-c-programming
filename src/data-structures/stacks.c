#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int stack[MAX];
int top = -1;

void push(int data)
{
    if (top >= MAX - 1)
    {
        printf("Stack Overflow\n");
        return;
    }
    stack[++top] = data;
}

int pop()
{
    if (top < 0)
    {
        printf("Stack Underflow\n");
        return -1;
    }
    return stack[top--];
}

int main()
{
    push(1);
    push(2);
    push(3);
    printf("Popped: %d\n", pop());
    printf("Popped: %d\n", pop());
    return 0;
}
