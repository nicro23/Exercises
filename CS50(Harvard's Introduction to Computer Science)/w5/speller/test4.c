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
    // hashes for a try of 3
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
                printf("%s\n", word);
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
        printf("file error\n");
        return false;
    }
    char *temp = malloc(sizeof(char));
    if(temp == NULL)
    {
        fclose(dict);
        printf("char error\n");
        return false;
    }
    int ltr_ct = 0;
    char *wrd = malloc((LENGTH + 1) * sizeof(char));
    if(wrd == NULL)
    {
        fclose(dict);
        free(temp);
        printf("word error1\n");
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
                printf("node error\n");
                fclose(dict);
                free(temp);
                free(wrd);
                return false;
            }
            strcpy(n->word, wrd);
            free(wrd);
            unsigned int h = hash(n->word);
            printf("%i\n", h);
            // strcpy(table[h]->word, n->word);
            // table[h]->word = "hello";
            if(table[h] == NULL)
            {
                table[h] = n;
            }
            else
            {
                n->next = table[h];
                table[h] = n;
            }

            //reset counter and wrd?
            ltr_ct = 0;
            wrd = malloc((LENGTH + 1) * sizeof(char));
            if(wrd == NULL)
            {
                printf("word error2\n");
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
    // TODO
    return 0;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO
    return false;
}

int main()
{
    bool h = load("dictionaries/large");
    if(!h)
    {
        printf("h\n");
    }

}
