#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <direct.h>

void createFolder(const char *folderName);
void createFile(const char *fileName);
void deleteFile(const char *fileName);
void deleteFolder(const char *folderName);

int main()
{
    char fileName[100];
    char folderName[100];
    char choice;

    do
    {
        // Prompt the user to choose an operation
        printf("\nSelect an option:\n");
        printf("1. Create a folder on the desktop\n");
        printf("2. Create a file on the desktop\n");
        printf("3. Delete a file from the desktop\n");
        printf("4. Delete a folder from the desktop\n");
        printf("5. Exit\n");
        printf("Enter your choice (1-5): ");
        scanf(" %c", &choice);
        getchar(); // consume the newline character left in input buffer

        switch (choice)
        {
        case '1':
            printf("Enter the name of the folder to create on the desktop: ");
            fgets(folderName, sizeof(folderName), stdin);
            folderName[strcspn(folderName, "\n")] = 0;
            createFolder(folderName);
            break;

        case '2':
            printf("Enter the name of the file to create on the desktop: ");
            fgets(fileName, sizeof(fileName), stdin);
            fileName[strcspn(fileName, "\n")] = 0;
            createFile(fileName);
            break;

        case '3':
            printf("Enter the name of the file to delete from the desktop: ");
            fgets(fileName, sizeof(fileName), stdin);
            fileName[strcspn(fileName, "\n")] = 0;
            deleteFile(fileName);
            break;

        case '4':
            printf("Enter the name of the folder to delete from the desktop: ");
            fgets(folderName, sizeof(folderName), stdin);
            folderName[strcspn(folderName, "\n")] = 0;
            deleteFolder(folderName);
            break;

        case '5':
            printf("Exiting the program.\n");
            break;

        default:
            printf("Invalid choice. Please enter a number between 1 and 5.\n");
            break;
        }

    } while (choice != '5');

    return 0;
}

void createFolder(const char *folderName)
{
    char folderPath[256];
    // Define the base folder path and format it with the folder name
    // snprintf(folderPath, sizeof(folderPath), "folder path\\%s", folderName);

    int status = mkdir(folderPath);

    if (!status)
        printf("Folder \"%s\" created successfully.\n", folderName);
    else
    {
        perror("Error creating folder");
        exit(EXIT_FAILURE);
    }
}

void createFile(const char *fileName)
{
    char filePath[256];
    snprintf(filePath, sizeof(filePath), "C:\\Users\\yeric\\OneDrive\\Desktop\\%s", fileName);

    FILE *file = fopen(filePath, "w"); // create or truncate file

    if (file == NULL)
    {
        perror("Error creating file");
        exit(EXIT_FAILURE);
    }

    fclose(file);
    printf("File \"%s\" created successfully.\n", fileName);
}

void deleteFile(const char *fileName)
{
    char filePath[256];
    snprintf(filePath, sizeof(filePath), "C:\\Users\\yeric\\OneDrive\\Desktop\\%s", fileName);

    if (remove(filePath) == 0)
        printf("File \"%s\" deleted successfully.\n", fileName);
    else
    {
        perror("Error deleting file");
        exit(EXIT_FAILURE);
    }
}

void deleteFolder(const char *folderName)
{
    char folderPath[256];
    snprintf(folderPath, sizeof(folderPath), "C:\\Users\\yeric\\OneDrive\\Desktop\\%s", folderName);

    // Note: This function deletes an empty directory
    if (rmdir(folderPath) == 0)
        printf("Folder \"%s\" deleted successfully.\n", folderName);
    else
    {
        perror("Error deleting folder");
        exit(EXIT_FAILURE);
    }
}
