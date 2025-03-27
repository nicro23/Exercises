// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "dictionary.h"
#include <string.h>

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
    // int ct;
} node;

// TODO: Choose number of buckets in hash table
const unsigned int N = 26*26*26 + 26*26 + 26;

// Hash table
//node *table[N][N][N];
node *table[N];

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // TODO
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO: Improve this hash function
        int ltr_ct = 0;
        char s[3];
        for(int i = 0; word[i] != '\0'; i++)
        {
            s[ltr_ct] = word[i];
            ltr_ct++;
            if(ltr_ct > 2)
            {
                break;
            }
            if(word[i] == '\'')
            {
                ltr_ct--;
            }
        }
        if(ltr_ct > 2)
        {
            return (toupper(s[0]) - 'A' + 1) * 26 + (toupper(s[1]) - 'A' + 1) * 26* 26 + (toupper(s[2]) - 'A' + 1);
        }
        else if(ltr_ct == 2)
        {
            return (toupper(s[0]) - 'A' + 1) * 26 + (toupper(s[1]) - 'A' + 1);
        }
        else
        {
            return (toupper(s[0]) - 'A' + 1);
        }
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // TODO
    FILE *dict = fopen(dictionary, "r");
    if(dict == NULL)
    {
        return false;
    }
    char *temp = malloc(sizeof(char));
    if(temp == NULL)
    {
        fclose(dict);
        return false;
    }
    int ltr_ct = 0;
    char *wrd = malloc((LENGTH + 1) * sizeof(char));
    if(wrd == NULL)
    {
        fclose(dict);
        free(temp);
        return false;
    }
    while(fread(temp,1,1,dict))
    {
        // found end of word
        if(*temp == '\n')
        {
            // add a null to the end of the word
            wrd[ltr_ct] = '\0';
            // assign the word to a node
            node *n = malloc(sizeof(node));
            if(n == NULL)
            {
                fclose(dict);
                free(temp);
                free(wrd);
                return false;
            }
            strcpy(n->word, wrd);
            free(wrd);
            unsigned int h = hash(n->word);
            if(table[h] == NULL)
            {
                table[h] = n;
                //table[h]->ct = 1;
            }
            else
            {
                //table[h]->ct++;
                //  n->ct = table[h]->ct;
                n->next = table[h];
                table[h] = n;
            }
            //reset counter and wrd?
            ltr_ct = 0;
            wrd = malloc((LENGTH + 1) * sizeof(char));
            if(wrd == NULL)
            {
                fclose(dict);
                free(temp);
                return false;
            }
        }

        // appending char to an array and count letters
        else
        {
            wrd[ltr_ct] = *temp;
            ltr_ct++;
        }
    }
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    unsigned int count = 0;
    // from 1 cuz table one based
    for(int i = 0; i <= N; i++)
    {
            if(table[i] != NULL)
            {
                // count += table[i]->ct;
                for(node *ptr = table[i];ptr->next != NULL;ptr = ptr->next)
                {
                    count++;
                }
            }
    }
    return count;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    for(int i = 1; i < N; i++)
    {
            // count += table[i]->ct;
            if (table[i] != NULL)
            {
                node *ptr = table[i];
                while(ptr->next != NULL)
                {
                    node* l = ptr->next;
                    free(ptr);
                    ptr = l;
                }
            }
    }
    return true;
}
