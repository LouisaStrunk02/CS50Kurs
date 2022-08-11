#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

bool only_alphas(string keyinput);
string cipher(string text, string k);

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");

        return 1;
    }

    if (!only_alphas(argv[1]))
    {
        printf("the key can only contain letters\n");

        return 1;
    }

    if (strlen(argv[1]) != 26)
    {
        printf("The key must contain 26 different letters\n");

        return 1;
    }

    for (int i = 0, length = strlen(argv[1]); i < length; i++)
    {
        char letter = toupper(argv[1][i]);

        for (int j = i + 1; j < length; j++)
        {
            if (letter == toupper(argv[1][j]))
            {
                printf("The key must not contain the same letter twice\n");

                return 1;
            }
        }
    }

    string key = argv[1];
    string plaintext = get_string("Plaintext: ");

    for (int i = 0, length = strlen(key); i < length; i++)
    {
        if (islower(key[i]))
        {
            key[i] = toupper(key[i]);
        }
    }
    printf("Ciphertext: ");
    cipher(plaintext, key);
}

bool only_alphas(string keyinput)
{

    for (int i = 0, length = strlen(keyinput); i < length; i++)
    {
        if (!isalpha(keyinput[i]))
        {
            return false;
        }
    }

    return true;
}

string cipher(string text, string k)
{
    for (int i = 0, length = strlen(text); i < length; i++)
    {
        if (isupper(text[i]))
        {
            int letter = text[i] - 'A';
            printf("%c", k[letter]);
        }
        else if (islower(text[i]))
        {
            int letter = text[i] - 'a';
            printf("%c", k[letter] + 32);
        }
        else
        {
            printf("%c", text[i]);
        }
    }
    printf("\n");

    return text;
}
