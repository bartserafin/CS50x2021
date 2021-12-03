// Implements a dictionary's functionality

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <strings.h>
#include <ctype.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// Number of buckets in hash table
// number of letters in english alphabet
const unsigned int N = 26;

// Hash table
node *table[N];


// var for dictionary size
int dict_size = 0;

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    int hash_value = hash(word);

    // get linked list at word index
    node *n = table[hash_value];

    // look for word in linked list
    while (n != NULL)
    {
        if (strcasecmp(word, n -> word) == 0)
        {
            return true;
        }

        n = n -> next;
    }

    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO
    long sum = 0;

    // loop to add ASCI values of all letters in a word
    for (int i = 0; i < strlen(word); i++)
    {
        sum += tolower(word[i]);
    }
    return sum % N;

}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // TODO
    // open dictioanry file
    FILE *file = fopen(dictionary, "r");

    if (dictionary == NULL)
    {
        printf("Invalid file.");
        return false;
    }

    // array for each letter in a word
    char next_word[LENGTH + 1];

    // scan dictionary
    while (fscanf(file, "%s", next_word) != EOF)
    {
        // create node for each word
        node *n = malloc(sizeof(node));
        if (n == NULL)
        {
            return false;
        }

        // move word into node
        strcpy(n -> word, next_word);

        // hash word to get hash value
        int hash_value = hash(next_word);

        // insert node at index into hash table
        n -> next = table[hash_value];
        table[hash_value] = n;
        dict_size++;
    }

    fclose(file);

    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    return dict_size;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO
    // free noes in linked list
    for (int i = 0; i < N; i++)
    {
        // set cursor position
        node *n = table[i];

        // loop through linked list
        while (n != NULL)
        {
            // assign cursor to temp
            node *tmp = n;

            // poin to next
            n = n -> next;

            free(tmp);
        }

        if (n == NULL && i == N - 1)
        {
            return true;
        }
    }
    return false;
}
