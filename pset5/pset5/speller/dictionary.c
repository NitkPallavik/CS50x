/**
 * Implements a dictionary's functionality.
 */
 #include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "dictionary.h"
#include <string.h>

#define SIZE 26
#define LENGTH 45

typedef struct node
{
    char word[LENGTH + 1];
    struct node* next;
}
node;

int hash_f(char* key)
{
    int n = key[0]-'a';
    return n % SIZE;
}

// Define the hashtable
node* hashtable[SIZE];

int count_words = 0;

bool check(const char* word)
{
// copy the word to check
int n = strlen(word);
char n_word[LENGTH + 1];

//descapitallize all word
for (int b = 0; b < n; b++)
{
    n_word[b] = tolower(word[b]);
}
n_word[strlen(word) + 1] = '\0';

// Check
int num = hash_f(n_word);
node* src = hashtable[num];

// This tell me that src is ever NULL. fix it.
if(src != NULL)
{
    while (src != NULL)
    {
        if(strcmp(src->word, n_word) == 0)
        {
            return true;
        }
        src = src->next;
    }
}
return false; 
}

   /**
   * Loads dictionary into memory.  Returns true if successful else false.
   */
bool load(const char* dictionary)
{
for (int a = 0; a < SIZE; a++)
{   
    hashtable[a] = malloc(sizeof(node));
   // hashtable[a] = NULL;
}

FILE* file = fopen(dictionary, "r");
if (file == NULL)
{
    printf("error, retry\n");
    return false;
}

//node* head = NULL;
char c_word[LENGTH];


// read each character in dictionary

int index = 0;

for(int c = fgetc(file); c != EOF; c = fgetc(file))
{
    if (isalpha(c) || (c == '\'' && index > 0))
    {
        // append character to word
        c_word[index] = c;
        index++;

     if (index >= LENGTH)
        {
            // consume remainder of alphabetical string
            while ((c = fgetc(file)) != EOF && isalpha(c));

            // prepare for new word
            index = 0;
        }
    }
    else if (index > 0)
    {
        // terminate current word
        c_word[index] = '\0';

        node* new = malloc(sizeof(node));
        strcpy(new->word, c_word);
        int num = hash_f(new->word);
            if (hashtable[num] == NULL)
            {
            hashtable[num] = new;
            }
        else
        {
        new -> next = hashtable[num] -> next;
        hashtable[num] = new;
        }
        index = 0;
        count_words++;
    }
}

fclose(file);
return true;
}

/**
 * Returns number of words in dictionary if loaded else 0 if not yet loaded.
 */
unsigned int size(void)
{
   node *ptr = NULL;
    int counter = 0;
    for(int i = 0; i < HASHTABLESIZE; i++)
    {
        if(hashtable[i] == NULL)
        {
            i++;
        }
        else
        {
            ptr = hashtable[i];
            while(ptr->next != NULL)
            {
               counter++;
               ptr=ptr->next;
            }
        }
    }
    return counter;
    if(counter == 0)
    {
        return 0;
    }
}

/**
 * Unloads dictionary from memory. Returns true if successful else false.
 */

 bool unload(void)
{
       node *ptr = NULL;
    for(int i = 0; i < HASHTABLESIZE; i++)
    {
        if(hashtable[i] == NULL)
        {
            i++;
        }
        else
        {
            ptr = hashtable[i];
            while(ptr->next != NULL)
            {
               node *temp = ptr;
               ptr=ptr->next;
               free(temp);
            }
        }
    }
    return false;

}

