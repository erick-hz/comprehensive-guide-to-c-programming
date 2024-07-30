#include <stdio.h>
#include <stdlib.h>

// Definición de un nodo del BST
typedef struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
} Node;

// Crear un nuevo nodo
Node *createNode(int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (!newNode)
    {
        printf("Error en la asignación de memoria.\n");
        exit(1);
    }
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Insertar un nodo en el BST
Node *insertNode(Node *root, int data)
{
    if (root == NULL)
    {
        root = createNode(data);
        return root;
    }

    if (data < root->data)
    {
        root->left = insertNode(root->left, data);
    }
    else if (data > root->data)
    {
        root->right = insertNode(root->right, data);
    }

    return root;
}

// Buscar un nodo en el BST
Node *searchNode(Node *root, int data)
{
    if (root == NULL || root->data == data)
    {
        return root;
    }

    if (data < root->data)
    {
        return searchNode(root->left, data);
    }

    return searchNode(root->right, data);
}

// Traversal en orden
void inorderTraversal(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    inorderTraversal(root->left);
    printf("%d ", root->data);
    inorderTraversal(root->right);
}

// Liberar memoria del BST
void freeTree(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

int main()
{
    Node *root = NULL;
    root = insertNode(root, 50);
    insertNode(root, 30);
    insertNode(root, 70);
    insertNode(root, 20);
    insertNode(root, 40);
    insertNode(root, 60);
    insertNode(root, 80);

    printf("Inorder traversal del BST: ");
    inorderTraversal(root);
    printf("\n");

    int key = 40;
    if (searchNode(root, key))
    {
        printf("Nodo %d encontrado en el BST.\n", key);
    }
    else
    {
        printf("Nodo %d no encontrado en el BST.\n", key);
    }

    freeTree(root);
    return 0;
}
