#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "dictionary.h"

int word_counter = 0;

typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
} node;

const unsigned int COLUMNS = 26;

node *table[COLUMNS];

bool check(const char *word)
{
    int hash_value = hash(word);
    node *cursor = table[hash_value];

    while (cursor != NULL)
    {
        bool wordIsInDictionary = (strcasecmp(cursor->word, word) == 0);
        if (!wordIsInDictionary)
        {
            cursor = cursor->next;
        }
        else
        {
            return true;
        }
    }

    return false;
}

unsigned int hash(const char *word)
{
    return toupper(word[0]) - 'A';
}

bool load(const char *dictionary)
{
    FILE *file = fopen(dictionary, "r");

    if (file == NULL)
    {
        printf("Could not open file");

        return false;
    }
    char new_word[LENGTH + 1];

    while (fscanf(file, "%s", new_word) != EOF)
    {
        node *new_node = malloc(sizeof(node));
        if (new_node == NULL)
        {
            return false;
        }

        strcpy(new_node->word, new_word);
        unsigned int index = hash(new_word);
        new_node->next = table[index];
        table[index] = new_node;
        word_counter++;
    }
    fclose(file);

    return true;
}

unsigned int size(void)
{
    return word_counter;
}

bool unload(void)
{
    for (int i = 0; i < COLUMNS; i++)
    {
        node *cursor = table[i];

        while (cursor)
        {
            node *temp = cursor;
            cursor = cursor->next;
            free(temp);
        }
        if (cursor == NULL)
        {
            return true;
        }
    }

    return false;
}
