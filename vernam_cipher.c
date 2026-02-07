#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char alpha[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char inputText[50], keyText[50], encryptText[50], decryptText[50];
    int inputTextArr[50], keyTextArr[50], encryptTextArr[50], decryptTextArr[50], choice = 0;

    printf("Enter plain Text : ");
    scanf("%49s", inputText);

    printf("Enter Key text : ");
    scanf("%49s", keyText);

    printf("1. Encryption\n2. Decryption\nEnter choice: ");
    scanf("%d", &choice);

    if (strlen(inputText) != strlen(keyText))
    {
        printf("ERROR : Please enter same char length key");
        return 0;
    }

    // Convert to uppercase
    for (int i = 0; inputText[i] != '\0'; i++)
    {
        inputText[i] = toupper(inputText[i]);
        keyText[i] = toupper(keyText[i]);
    }

    // Convert characters to numbers (A=0)
    for (int i = 0; i < strlen(inputText); i++)
    {
        inputTextArr[i] = inputText[i] - 'A';
        keyTextArr[i] = keyText[i] - 'A';
    }

    if (choice == 1)
    {
        // Encryption
        for (int i = 0; i < strlen(inputText); i++)
        {
            encryptTextArr[i] = (inputTextArr[i] + keyTextArr[i]) % 26;
            encryptText[i] = alpha[encryptTextArr[i]];
        }
        encryptText[strlen(inputText)] = '\0';
        printf("Cipher Text: %s\n", encryptText);
        return 0;
    }
    else if (choice == 2)
    {
        // Decryption
        for (int i = 0; i < strlen(inputText); i++)
        {
            decryptTextArr[i] = (inputText[i] - 'A' - keyTextArr[i] + 26) % 26;
            decryptText[i] = alpha[decryptTextArr[i]];
        }
        decryptText[strlen(inputText)] = '\0';
        printf("Plain Text: %s\n", decryptText);
        return 0;
    }
    else
    {
        printf("Invalid choice. Please select 1 for Encryption or 2 for Decryption.\n");
        return 0;
    }
}
