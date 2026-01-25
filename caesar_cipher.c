#include <stdio.h>
#include <ctype.h>

// Handle encryption action
void encryption(char text[], int key)
{
    for (int i = 0; i < text[i] != '\0'; i++)
    {
        char ch = text[i];
        if (isupper(ch))
        {
            int p = ch - 'A';
            int c = (p + key) % 26;
            text[i] = c + 'A';
        }
        else if (islower(ch))
        {
            int p = ch - 'a';
            int c = (p + key) % 26;
            text[i] = c + 'a';
        }
    }
}

// Handle decryption action
void decryption(char text[], int key)
{
    for (int i = 0; i < text[i] != '\0'; i++)
    {
        char ch = text[i];
        if (isupper(ch))
        {
            int c = ch - 'A';
            int p = (c - key) % 26;
            text[i] = p + 'A';
        }
        else if (islower(ch))
        {
            int c = ch - 'a';
            int p = (c - key) % 26;
            text[i] = p + 'a';
        }
    }
}

int main()
{
    char text[100];
    int key = 0, choice = 0;
    printf("Enter the text : ");
    scanf("%s", text);

    printf("Enter the shift key : ");
    scanf("%d", &key);

    printf("1. Encryption\n2. Decryption\nEnter choice: ");
    scanf("%d", &choice);

    if (choice == 1)
    {
        encryption(text, key);
        printf("Encrypted Text: %s\n", text);
    }
    else if (choice == 2)
    {
        decryption(text, key);
        printf("Decrypted Text: %s\n", text);
    }
    else
    {
        printf("Invalid choice !!!\n");
        return 0;
    }
}