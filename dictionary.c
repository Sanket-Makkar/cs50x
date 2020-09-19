// Implements a dictionary's functionality

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <strings.h>
#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;
int wc = 0;
// Number of buckets in hash table
const unsigned int N = 100000;

// Hash table
node *table[N];






// Hashes word to a number
unsigned int hash(const char *word)
{
    int valuei = 0;
    for (int i = 0; i < strlen(word); i++)
    {
        valuei = valuei + tolower(word[i]);
    }
    return valuei % N;
}







// Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary)
{
    char word[LENGTH + 1];
    FILE *file = fopen(dictionary, "r");
    while (fscanf(file, "%s", word) != EOF)
    {
        if (file == NULL)
        {
            return false;
        }
        node *unode = malloc(sizeof(node));
        memset(unode, 0, sizeof(node));
        if (unode == NULL)
        {
            unload();
            return false;
        }
        strcpy(unode -> word, word);
        int indexnumb = hash(unode -> word);
        node *listpointer = table[indexnumb];
        if (listpointer != NULL)
        {
            unode -> next = table[indexnumb];
            table[indexnumb] = unode;
            wc++;
        }
        else
        {
            table[indexnumb] = unode;
            wc++;
        }
    }
    fclose(file);
    return true;
}







// Returns true if word is in dictionary else false
bool check(const char *word)
{
    char wordcarbon[LENGTH + 1];
    for (int i = 0; i < strlen(word); i++)
    {
        wordcarbon[i] = tolower(word[i]);
    }
    int wordlen = strlen(word);
    wordcarbon[wordlen] = '\0';
    int indexnumb = hash(wordcarbon);
    if (table[indexnumb] == NULL)
    {
        return false;
    }
    node *pointer = table[indexnumb];
    
    while (pointer != NULL)
    {
        if (strcasecmp(pointer -> word, wordcarbon) == 0)
        {
            return true;
        }
        pointer = pointer -> next;
    }
    return false;
}






// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    return wc;
}






// Unloads dictionary from memory, returning true if successful else false
//Assisted by https://stackoverflow.com/questions/61806250/cs50-speller-all-words-are-misspelled
bool unload(void)
{
    for (int i = 0; i < N; i++)
    {
        node *freedomseeker = table[i];
        if (table[i] != NULL)
        {
            while (freedomseeker != NULL)
            {
                node *copycat = freedomseeker;
                freedomseeker = freedomseeker -> next;
                free(copycat);
            }
        }
    }
    return true;
}
