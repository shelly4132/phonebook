#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "hash_func.h"

/* FILL YOUR OWN IMPLEMENTATION HERE! */
entry *findName(char lastName[], entry *pHead[])
{
    int val = BKDRHash(lastName);
    entry* tmp;
    if(pHead[val]->pNext != NULL)
        tmp = pHead[val]->pNext;
    else
        return NULL;
    while (tmp != NULL) {
        if (strcasecmp(lastName, tmp->lastName) == 0)
            return tmp;
        tmp = tmp->pNext;
    }
    return NULL;
}

void append(char lastName[], entry *e[])
{
    /* allocate memory for the new entry and put lastName */
    int val = BKDRHash(lastName);
    e[val]->pNext = (entry *) malloc(sizeof(entry));
    e[val] = e[val]->pNext;
    strcpy(e[val]->lastName, lastName);
    e[val]->pNext = NULL;

}

unsigned int BKDRHash(char lastName[])
{
    //unsigned int seed=31;
    unsigned int hash=0;
    int i=0;
    while(i<strlen(lastName)) {
        //hash = hash * seed + lastName[i];
        hash = (hash <<  5) - hash + lastName[i];
        ++i;
    }

    return hash % DICLEN;
}

