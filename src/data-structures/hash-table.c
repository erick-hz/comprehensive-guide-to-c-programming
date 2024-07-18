#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

// Define the structure for the hash table's elements
typedef struct HashNode
{
    char *key;
    int value;
    struct HashNode *next;
} HashNode;

// Define the structure for the hash table
typedef struct HashTable
{
    HashNode **buckets;
    int size;
} HashTable;

// Hash function to generate an index
unsigned int hash(const char *key, int size)
{
    unsigned long int hashval = 0;
    int i = 0;
    // Convert our string to an integer
    while (hashval < ULONG_MAX && i < strlen(key))
    {
        hashval = hashval << 8;
        hashval += key[i];
        i++;
    }
    return hashval % size;
}

// Create a hash table
HashTable *create_table(int size)
{
    HashTable *table = (HashTable *)malloc(sizeof(HashTable));
    table->size = size;
    table->buckets = (HashNode **)malloc(sizeof(HashNode *) * size);
    for (int i = 0; i < size; i++)
    {
        table->buckets[i] = NULL;
    }
    return table;
}

// Insert a key-value pair into the hash table
void insert(HashTable *table, const char *key, int value)
{
    unsigned int bucket = hash(key, table->size);
    HashNode *new_node = (HashNode *)malloc(sizeof(HashNode));
    new_node->key = strdup(key);
    new_node->value = value;
    new_node->next = table->buckets[bucket];
    table->buckets[bucket] = new_node;
}

// Search for a value by key in the hash table
int search(HashTable *table, const char *key)
{
    unsigned int bucket = hash(key, table->size);
    HashNode *node = table->buckets[bucket];
    while (node != NULL && strcmp(node->key, key) != 0)
    {
        node = node->next;
    }
    if (node == NULL)
    {
        return -1; // Key not found
    }
    else
    {
        return node->value;
    }
}

// Free the hash table
void free_table(HashTable *table)
{
    for (int i = 0; i < table->size; i++)
    {
        HashNode *node = table->buckets[i];
        while (node != NULL)
        {
            HashNode *temp = node;
            node = node->next;
            free(temp->key);
            free(temp);
        }
    }
    free(table->buckets);
    free(table);
}

// Main function to demonstrate usage
int main()
{
    HashTable *table = create_table(100);

    insert(table, "key1", 1);
    insert(table, "key2", 2);
    insert(table, "key3", 3);

    printf("Value for key1: %d\n", search(table, "key1"));
    printf("Value for key2: %d\n", search(table, "key2"));
    printf("Value for key3: %d\n", search(table, "key3"));
    printf("Value for key4: %d\n", search(table, "key4")); // should return -1

    free_table(table);

    return 0;
}
