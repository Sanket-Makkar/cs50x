// Implements a dictionary's functionality
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "dictionary.h"
#include <strings.h>

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
    int hash = 0;
    for (int i = 0; word[i] != '\0'; i++)
    {
        valuei = valuei * 37 + tolower(word[i]);
    }
    return valuei;
}
    int wc = 0;

// Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary)
{
    FILE *file = fopen(dictionary, "r");
    if (file == NULL)
    {
        return false;
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
    fclose(file);
    return true;
}
// Returns true if word is in dictionary else false
bool check(const char *word)
{
    char word_carbon[strlen(word)];
    for (int i = 0; i < strlen(word); i++)
    {
        word_carbon[i] = tolower(word[i]);
    }
    
    int word_carbon_hashindex = hash(word_carbon);
    
    node *point = malloc(sizeof(node));
    point = table[word_carbon_hashindex];
    if (point != NULL)
    {
        if (table[word_carbon_hashindex] != NULL)
            {
            while (point -> next != NULL)
            {
                if (strcasecmp(word_carbon, point -> word) == 0)
                {
                    return true;
                }
                else 
                {
                    point = point -> next;
                }
            }
            return false;
        }
        else
        {
            return false;
        }
    }
    else
    {
        return false;
    }
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