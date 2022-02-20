#ifndef __HASH
#define __HASH

typedef int Element;
typedef int key;
typedef struct HT *HashTable;
typedef struct structNode *Node;
typedef struct arr *array;

struct HT
{
    int TableSize;
    Node *start;
};

struct structNode
{
    int level;
    char *s;
    Element elem;
    Node next;
};
struct arr
{
    int TableSize;
    Element *ptr;
};

array createhash(int size);
void insert(Element x, array Table);
int find(Element x, array Table);
void qpinsert(Element x, array Table);
int qpfind(Element x, array Table);
HashTable sccreatehash(int size);
HashTable sccreatehash1(int size);
void scinsert(Element n, HashTable myHt);
Node scfind(Element n, HashTable myHT);
void strinsert(char *word, HashTable Table);
Node strfind(char *word, HashTable Table);
int hashfunc(Element key, int size);
long int horner(char *word, long int size);
#endif //#include "hash.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

array createhash(int size)
{
    array Table;
    Table = (array)malloc(sizeof(struct arr));
    Table->TableSize = size;
    Table->ptr = (Element *)malloc(size * sizeof(Element));
    for (int i = 0; i < size; i++)
    {
        Table->ptr[i] = INT_MIN;
    }
    return Table;
}
void insert(Element x, array Table)
{
    key k;
    k = hashfunc(x, Table->TableSize);
    int count = 1;
    while (Table->ptr[k % Table->TableSize] != INT_MIN)
    {
        if (count == Table->TableSize)
        {
            printf("Table Full\n");
            exit(0);
        }
        k++;
        count++;
    }
    Table->ptr[k % Table->TableSize] = x;
}
int find(Element x, array Table)
{
    key k;
    k = hashfunc(x, Table->TableSize);
    while (Table->ptr[k % Table->TableSize] != INT_MIN)
    {
        if (Table->ptr[k % Table->TableSize] == x)
        {
            return k % Table->TableSize;
        }
        else
        {
            k++;
        }
    }
    return -1;
}
void qpinsert(Element x, array Table)
{
    key k;
    k = hashfunc(x, Table->TableSize);
    int count = 1;
    int i = 0;
    while (Table->ptr[(k + i * i) % Table->TableSize] != INT_MIN)
    {
        if (count == Table->TableSize)
        {
            //printf("Table Full\n");
            return;
        }
        i++;
        count++;
    }
    Table->ptr[(k + i * i) % Table->TableSize] = x;
}
int qpfind(Element x, array Table)
{
    key k;
    k = hashfunc(x, Table->TableSize);
    int i = 0;
    while (Table->ptr[(k + i * i) % Table->TableSize] != INT_MIN)
    {
        if (Table->ptr[(k + i * i) % Table->TableSize] == x)
        {
            return (k + i * i) % Table->TableSize;
        }
        else
        {

            i++;
        }
    }
    return -1;
}
HashTable sccreatehash(int size)
{
    HashTable H;

    H = (HashTable)malloc(sizeof(struct HT));
    H->TableSize = size;
    H->start = (Node *)malloc(size * sizeof(Node));
    if (H->start == NULL)
    {
        printf("Memory Full!!\n");
        exit(0);
    }

    for (int i = 0; i < size; i++)
    {
        H->start[i] = (Node)malloc(sizeof(struct structNode));
        if (H->start[i] == NULL)
        {
            printf("Memory Full!!\n");
            exit(0);
        }
        (H->start[i])->next = NULL;
        H->start[i]->elem = INT_MIN;
        H->start[i]->level = -1;
    }
    return H;
}
void scinsert(Element n, HashTable myHt)
{
    Node Position;
    key k;
    //Position = scfind(n, myHt);
    if (1)
    {
        Position = (Node)malloc(sizeof(struct structNode));
        if (Position == NULL)
        {
            printf("Out of Memory\n");
            exit(0);
        }
        k = hashfunc(n, myHt->TableSize);
        Position->next = myHt->start[k]->next;
        Position->elem = n;
        if (myHt->start[k]->next != NULL)
            Position->level = (myHt->start[k]->next->level) + 1;
        else
            Position->level = 0;
        myHt->start[k]->next = Position;
    }

    return;
}
Node scfind(Element n, HashTable myHT)
{
    Node Position = NULL;
    Node P = NULL;
    key k;
    k = hashfunc(n, myHT->TableSize);
    Position = myHT->start[k]->next;
    while ((Position != NULL))
    {
        if (Position->elem == n)
            P = Position;
        Position = Position->next;
    }

    return P;
}
void strinsert(char *word, HashTable Table)
{
    Node Position;
    long int k;

    Position = (Node)malloc(sizeof(struct structNode));
    k = horner(word, Table->TableSize);
    Position->next = Table->start[k]->next;
    Position->s = word;
    if (Table->start[k]->next != NULL)
        Position->level = (Table->start[k]->next->level) + 1;
    else
        Position->level = 0;
    Table->start[k]->next = Position;

    return;
}
Node strfind(char *word, HashTable Table)
{
    Node Position = NULL;
    long int k;
    k = horner(word, Table->TableSize);
    Position = Table->start[k]->next;
    while ((Position != NULL) && (strcmp(Position->s, word) != 0))
        Position = Position->next;

    return Position;
}

int hashfunc(Element key, int size)
{
    if (size != 0)
        return (key % size);
    else
    {
        printf("Table Size 0\n");
        return -1;
    }
}
long int horner(char word[], long int size)
{
    long int hashval = 0;
    for (int i = 0; i < strlen(word); i++)
    {
        hashval = ((hashval * 32) + word[i]) % size;
    }
    return hashval % size ;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<time.h>
typedef char *charptr;
int main()
{
    clock_t begin=clock();
    FILE *fp = fopen("dist/dictionary.txt", "r");
    char word[84095][30];
    HashTable Table;
    int i = 0;
    int size = 84507;
    Table = sccreatehash(size);
    for (i = 0; i < 84095; i++)
    {
        //fgets(word[i], 30, fp);
        fscanf(fp,"%s",word[i]);
        strinsert(word[i], Table);
    }
    printf("%s",word[84000]);
    float count = 0;
    // for(int j=0;j<i;j++)
    // {
    //     printf("%s",word[j]);
    // }
    for (int j = 0; j < size; j++)
    {
        if (Table->start[j]->next != NULL)
        {
            //printf("%s\n",Table->start[j]->next->s); 
            count+= ((Table->start[j]->next->level)*((Table->start[j]->next->level)+1))/2.0;
        }
    }
    clock_t end=clock();

    printf("%f\n",(float)(end-begin)/1000000.0);
    printf("%f\n", (float)count/size);

    return 0;
}