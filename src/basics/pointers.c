#include <stdio.h>

int main()
{
    int num = 10;    // Declare an integer variable
    int *ptr = &num; // Declare a pointer to an integer and initialize it with the address of num

    printf("Value of num: %d\n", num);             // Output the value of num
    printf("Address of num: %p\n", &num);          // Output the address of num
    printf("Value of ptr: %p\n", ptr);             // Output the value of ptr (address of num)
    printf("Value pointed to by ptr: %d\n", *ptr); // Output the value pointed to by ptr (value of num)

    *ptr = 20; // Change the value of num using the pointer

    printf("New value of num: %d\n", num); // Output the new value of num

    return 0;
}
