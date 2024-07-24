#include <stdio.h>
#include <stdlib.h>

// Define the structure for a tree node
struct TreeNode
{
    int value;
    struct TreeNode *left;
    struct TreeNode *right;
};

// Function to create a new tree node
struct TreeNode *createNode(int value)
{
    struct TreeNode *newNode = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    newNode->value = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to insert a node in the binary tree
struct TreeNode *insertNode(struct TreeNode *root, int value)
{
    if (root == NULL)
    {
        root = createNode(value);
    }
    else if (value < root->value)
    {
        root->left = insertNode(root->left, value);
    }
    else
    {
        root->right = insertNode(root->right, value);
    }
    return root;
}

// Function to perform an in-order traversal of the tree
void inOrderTraversal(struct TreeNode *root)
{
    if (root != NULL)
    {
        inOrderTraversal(root->left);
        printf("%d ", root->value);
        inOrderTraversal(root->right);
    }
}

int main()
{
    struct TreeNode *root = NULL;
    root = insertNode(root, 5);
    root = insertNode(root, 3);
    root = insertNode(root, 8);
    root = insertNode(root, 2);
    root = insertNode(root, 4);

    printf("In-order traversal: ");
    inOrderTraversal(root);
    printf("\n");

    return 0;
}
