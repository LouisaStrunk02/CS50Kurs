#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

bool only_digits(string key);
char rotate(char text[], int k);

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");

        return 1;
    }

    if (!only_digits(argv[1]))
    {
        printf("Usage: ./caesar key\n");

        return 1;
    }

    int key = atoi(argv[1]);
    string plaintext = get_string("Plaintext: ");
    printf("Ciphertext: ");

    for (int i = 0, length = strlen(plaintext); i < length; i++)
    {
        if (isupper(plaintext[i]))
        {
            printf("%c", (plaintext[i] - 'A' + key) % 26 + 'A');
        }
        else if (islower(plaintext[i]))
        {
            printf("%c", (plaintext[i] - 'a' + key) % 26 + 'a');
        }
        else
        {
            printf("%c", plaintext[i]);
        }
    }
    printf("\n");
}

bool only_digits(string keyinput)
{
    return true;

    for (int i = 0, length = strlen(keyinput); i < length; i++)
    {
        if (!isdigit(keyinput[i]))
        {
            return false;
        }
    }
}

// char rotate(char text[], int k)
// {

//     for (int i = 0, length = sizeof(text[]) / sizeof(int); i < length; i++)
//     {
//         char cipherletter[i];
//         if (isupper(text[i]))
//         {
//             cipherletter[i] = ((text[i] - 'A' + k) % 26 + 'A');
//             printf("%c", cipherletter[i]);
//         }
//         else if (islower(text[i]))
//         {
//             cipherletter[i] = ((text[i] - 'a' + k) % 26 + 'a');
//             printf("%c", cipherletter[i]);
//         }
//         else
//         {
//             cipherletter[i] = text[i];
//             printf("%c", cipherletter[i]);
//         }
//         // printf("%c\n", cipherletter[i]);
//         // return (char)cipherletter[i];
//     }
//     return 0;
//     printf("\n");
// }
