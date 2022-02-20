#include "hash.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

array createhash(int size)
{
    array Table;
    Table=(array)malloc(sizeof(struct arr));
    Table->TableSize = size;
    Table->ptr = (Element*)malloc(size * sizeof(Element));
    for (int i = 0; i < size; i++)
    {
        Table->ptr[i]= INT_MIN;
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
    Table->ptr[k % Table->TableSize]=x;
}
int find(Element x, array Table)
{
    key k;
    k= hashfunc(x, Table->TableSize);
    while (Table->ptr[k % Table->TableSize] != INT_MIN)
    {
        if(Table->ptr[k % Table->TableSize]==x)
        {
            return k% Table->TableSize;
        }
        else{
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
    int i=0;
    while (Table->ptr[(k+ i*i) % Table->TableSize] != INT_MIN)
    {
        if (count == Table->TableSize)
        {
            //printf("Table Full\n");
            return ;
        }
        i++;
        count++;
        
    }
    Table->ptr[(k+ i*i) % Table->TableSize]=x;
}
int qpfind(Element x, array Table)
{
    key k;
    k= hashfunc(x, Table->TableSize);
    int i=0;
    while (Table->ptr[(k+i*i) % Table->TableSize] != INT_MIN)
    {
        if(Table->ptr[(k+i*i) % Table->TableSize]==x)
        {
            return (k+i*i) % Table->TableSize;
        }
        else{
            
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
    H->start =(Node*) malloc(size * sizeof(Node));
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
        H->start[i]->level= -1;
    }
    return H;
}
void scinsert(Element n, HashTable myHt)
{
    Node Position;
    Node P;
    key k;
        Position = (Node)malloc(sizeof(struct structNode));
        if (Position == NULL)
        {
            printf("Out of Memory\n");
            exit(0);
        }
        k = hashfunc(n, myHt->TableSize);
        P=myHt->start[k];
        while(P->next!=NULL)
        {
            P=P->next;
        }
        Position->next = NULL;
        Position->level = P->level+1;
        Position->elem = n;
        return;
 
}
Node scfind(Element n, HashTable myHT)
{
    Node Position = NULL;
    Node P= NULL;
    key k;
    k = hashfunc(n, myHT->TableSize);
    Position = myHT->start[k]->next;
    while ((Position != NULL))
    {
        if(Position->elem==n)
        P=Position;
        Position = Position->next;
    }

    return P;
}
void strinsert(char* word,HashTable Table)
{
    Node Position;
    Node P;
    long int k;

        Position = (Node)malloc(sizeof(struct structNode));
        k = horner(word, Table->TableSize);
        P=Table->start[k];
        while(P->next!=NULL)
        {
            P=P->next;
        }
        Position->next =NULL;
        Position->s=word;
        P->next = Position;

    return;
}
Node strfind(char* word,HashTable Table)
{
    Node Position = NULL;
    long int k;
    k = horner(word, Table->TableSize);
    Position = Table->start[k]->next;
    while ((Position != NULL) && (strcmp(Position->s,word) != 0))
        Position = Position->next;

    return Position;
}


int hashfunc(Element key, int size)
{
    if (size != 0)
        return (key% size);
    else
    {
        printf("Table Size 0\n");
        return -1;
    }
}
long int horner(char* word,long int size)
{
    long int hashval=0;
    for (int i = 0; i < strlen(word);i++)
    {
        hashval = (33* hashval + word[i])%size;
    }
    return hashval;
    
}

