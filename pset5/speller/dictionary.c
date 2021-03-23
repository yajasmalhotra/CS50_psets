// Implements a dictionary's functionality

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <strings.h>
#include "dictionary.h"

#define N 26

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

unsigned int hash(const char *string) //djb2, https://doc.riot-os.org/group__sys__hashes__djb2.html
{
    unsigned int hash = 5381;
    int c = 0;

    while (c == *string++)
    {
        hash = ((hash << 5) + hash) + tolower(c); // ignores case of strings
    }

    return hash % N;
}

// Hash table
node *Table[N] = {NULL};

// Returns true if word is in dictionary else false
bool check(const char *word)
{
    unsigned int hashval = hash(word);
    node *temp = Table[hashval];

    while (temp != NULL)
    {
        if (strcasecmp(temp -> word, word) == 0)
        {
            return true;
        }

        temp = temp -> next;
    }

    return false;
}

// Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary)
{
    FILE *file = fopen(dictionary, "r");
    if (file == NULL)
    {
        fprintf(stderr, "File does not exist\n");
        unload();
        return false;
    }

    char word[LENGTH + 1] = {0};

    while (fscanf(file, "%s", word) != EOF)
    {
        unsigned int hashval = hash(word);

        node *newnode = malloc(sizeof(node));
        if (newnode == NULL)
        {
            unload();
            return false;
        }

        strcpy(newnode -> word, word);

        newnode -> next = Table[hashval];
        Table[hashval] = newnode;
    }
    fclose(file);
    return true;
}

// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    int count = 0;

    for (int i = 0; i < N; i++)
    {
        node *temp = Table[i];

        while (temp != NULL)
        {
            ++count;
            temp = temp -> next;
        }
    }
    return count;
}

// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
    int buckets = 0;

    for (int i = 0; i < N; i++)
    {
        node *temp = Table[i];

        while (Table[i] != NULL)
        {
            temp = temp -> next;
            free(Table[i]);
            Table[i] = temp;
        }

        if (Table[i] == NULL)
        {
            buckets++;
        }
    }

    if (buckets == N)
    {
        return true;
    }

    return false;
}
