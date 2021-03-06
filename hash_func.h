#ifndef _PHONEBOOK_H
#define _PHONEBOOK_H

#define MAX_LAST_NAME_SIZE 16
#define DICLEN 42737 //hash size
#define HASH 1

/* TODO: After modifying the original version, uncomment the following
 * line to set OPT properly */
// #define OPT 1
typedef struct __PHONE_BOOK_ENTRY {
    char lastName[MAX_LAST_NAME_SIZE];
    char firstName[16];
    char email[16];
    char phone[10];
    char cell[10];
    char addr1[16];
    char addr2[16];
    char city[16];
    char state[2];
    char zip[5];
    struct __PHONE_BOOK_ENTRY *pNext;
} detailEntry;

typedef struct __LAST_NAME_ENTRY {
    char lastName[MAX_LAST_NAME_SIZE];
    detailEntry *detail;
    struct __LAST_NAME_ENTRY *pNext;
} entry;

entry *findName(char lastName[], entry *pHead[]);
void append(char lastName[], entry *e[]);
unsigned int BKDRHash(char lastName[]);

#endif
