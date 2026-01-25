#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main()
{
    char numbers[] = "1234567890";
    char lowerCase[] = "abcdefghijklmnopqrstuvwxyz";
    char upperCase[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char symbol[] = "!@#$^&*()-_=+[]{}|;:,.<>/?";
    int randomNum, size;
    srand(time(0));
    randomNum = rand() % 4;
    printf("Enter the length of password: ");
    scanf("%d", &size);
    int len = size;
    char password[size + 1];
    int indx = 0;
    while (len != 0)
    {
        randomNum = rand() % 4;
        if (randomNum == 0)
        {
            password[indx] = lowerCase[rand() % 26];
        }
        else if (randomNum == 1)
        {
            password[indx] = numbers[rand() % 10];
        }
        else if (randomNum == 2)
        {
            password[indx] = symbol[rand() % 26];
        }
        else if (randomNum == 3)
        {
            password[indx] = upperCase[rand() % 26];
        }
        len--;
        indx++;
    }
    password[indx] = '\0';
    printf("Password is %s\n", password);
    return 0;
}