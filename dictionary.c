// Implements a dictionary's functionality

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;
int valuei = 0;
// Number of buckets in hash table
const unsigned int N = 26;

// Hash table
node *table[N];

// Hashes word to a number
unsigned int hash(const char *word)
{
    //taken from https://www.youtube.com/watch?v=wg8hZxMRwcw&t=178s at 2:54 and also Franklin Gonzalez in the link below (scroll down till you see him)
    //https://us.edstem.org/courses/176/discussion/88659
    for (int i = 0; i< strlen(word); i++)
    {
        valuei = valuei * 37 + tolower(word[i]);
    }
    int finhash = valuei % N;
    return finhash;
}
    int wc = 0;

// Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary)
{
    FILE *file = fopen(dictionary, "r");
    if (file == NULL)
    {
        false;
    }
    char word[LENGTH + 1];
    while (fscanf(file, "%s", word) != EOF)
    {
        node *unode = malloc(sizeof(node));
        if (unode == NULL)
        {
            unload();
            return false;
        }
        strcpy(unode->word, word);
        hash(word);
        int indexnumb = hash(unode->word);
        node *pointe = table[indexnumb];
        if (pointe == NULL)
        {
            table[indexnumb] = unode;
            wc++;
        }
        else if (pointe != NULL)
        {
            unode->next = table[indexnumb];
            table[indexnumb] = unode;
            wc++;
        }
    }
    fclose(file
    return true;
}
// Returns true if word is in dictionary else false
bool check(const char *word)
{
    int tabnum = hash(word);
    node *cursor = table[tabnum];
    while(cursor != NULL)
    {
        if (strcmp(cursor->word, word) == 0)
        {
            return true;
        }
        else
        {
            cursor = cursor -> next;
        }
    }
    return false;
}
// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    return wc;
}

// Unloads dictionary from memory, returning true if successful else false
// modified with some help from https://us.edstem.org/courses/176/discussion/83876
bool unload(void)
{
    for (int i = 0; i < N; i++)
    {
        node* freedomSeeker = table[i];
        while (freedomSeeker->next != NULL)
        {
            node *temp = freedomSeeker;
            freedomSeeker = freedomSeeker -> next;
            free(temp);
        }
        free(freedomSeeker);
    }
    return true;
}
