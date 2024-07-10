#include <stdio.h>

// Definition of a structure
struct Person
{
    char name[50];
    int age;
};

// Definition of a union
union Data
{
    int i;
    float f;
    char str[20];
};

// Enumeration
enum Color
{
    RED,
    GREEN,
    BLUE
};

int main()
{
    // Basic variables
    int integer = 10;
    char character = 'A';
    float floating = 3.14f;
    double double_val = 3.141592653589793;

    // Modifiers
    short short_val = 5;
    long long_val = 100000L;
    unsigned int unsigned_val = 15;

    // Array
    int array[5] = {1, 2, 3, 4, 5};

    // Pointer
    int *pointer = &integer;

    // Use of structure
    struct Person person1 = {"John", 30};

    // Use of union
    union Data data;
    data.i = 10;

    // Use of enumeration
    enum Color color = RED;

    // Output
    printf("Integer: %d\n", integer);
    printf("Character: %c\n", character);
    printf("Float: %.2f\n", floating);
    printf("Double: %.15lf\n", double_val);
    printf("Short: %d\n", short_val);
    printf("Long: %ld\n", long_val);
    printf("Unsigned: %u\n", unsigned_val);
    printf("Array: %d\n", array[0]);
    printf("Pointer: %d\n", *pointer);
    printf("Person: Name = %s, Age = %d\n", person1.name, person1.age);
    printf("Union: i = %d\n", data.i);
    printf("Color: %d\n", color);

    return 0;
}
