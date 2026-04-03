#include <string.h>
#include <stdio.h>
#include <stdbool.h>

void encryption(char inputText[], int key)
{
    int len = strlen(inputText);
    char rail[key][100];

    for (int i = 0; i < key; i++)
        for (int j = 0; j < len; j++)
            rail[i][j] = '\n';

    int row = 0, down = 1;

    for (int i = 0; i < len; i++)
    {
        rail[row][i] = inputText[i];

        if (row == 0)
            down = 1;
        else if (row == key - 1)
            down = -1;

        row += down;
    }

    printf("Encrypted Text: ");
    for (int i = 0; i < key; i++)
        for (int j = 0; j < len; j++)
            if (rail[i][j] != '\n')
                printf("%c", rail[i][j]);

    printf("\n");
}

void decryption(char inputText[], int key)
{
    int len = strlen(inputText);
    char rail[key][100];

    for (int i = 0; i < key; i++)
        for (int j = 0; j < len; j++)
            rail[i][j] = '\n';

    int row = 0, down = 0;

    for (int i = 0; i < len; i++)
    {
        if (row == 0)
            down = 1;
        if (row == key - 1)
            down = -1;

        rail[row][i] = '*';
        row += down;
    }

    int index = 0;

    for (int i = 0; i < key; i++)
        for (int j = 0; j < len; j++)
            if (rail[i][j] == '*' && index < len)
                rail[i][j] = inputText[index++];

    row = 0;
    down = 0;

    printf("Decrypted Text: ");

    for (int i = 0; i < len; i++)
    {
        if (row == 0)
            down = 1;
        if (row == key - 1)
            down = -1;

        printf("%c", rail[row][i]);
        row += down;
    }

    printf("\n");
}

int main()
{
    char inputText[100];
    int key, choice;

    printf("Enter Text Message : ");
    fgets(inputText, 100, stdin);

    /* FIX ADDED HERE */
    inputText[strcspn(inputText, "\n")] = '\0';

    printf("Enter the key : ");
    scanf("%d", &key);

    printf("1. Encryption\n2. Decryption\nEnter choice: ");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
        encryption(inputText, key);
        break;

    case 2:
        decryption(inputText, key);
        break;

    default:
        printf("Enter valid choice");
        break;
    }

    return 0;
}