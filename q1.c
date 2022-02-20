#ifndef __HASH
#define __HASH

typedef int Element;
typedef int key;
typedef struct HT *HashTable;
typedef struct structNode *Node;
typedef struct arr *array;
typedef struct streadme readme;

struct HT
{
    int TableSize;
    Node *start;
};

struct structNode
{
   // int garbage[100000];
    Element elem;
    int level;
    Node next;
};
struct arr
{
    int TableSize;
    readme *ptr;
    int total;
};
struct streadme
{
    //int garbage[100000];
    Element elem;
    
};
array createhash(int size);
int insert(Element x, array Table);
int find(Element x, array Table);
int qpinsert(Element x, array Table);
int qpfind(Element x, array Table);
HashTable sccreatehash(int size);
HashTable sccreatehash1(int size);
int scinsert(Element n, HashTable myHt);
Node scfind(Element n, HashTable myHT);
void strinsert(char *word, HashTable Table);
Node strfind(char *word, HashTable Table);
int hashfunc(Element key, int size);
long int horner(char *word, long int size);
#endif
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include<assert.h>
array createhash(int size)
{
    array Table;
    Table = (array)malloc(sizeof(struct arr));
    Table->TableSize = size;
    Table->ptr = (readme *)malloc(size * sizeof(readme));
    assert(Table->ptr!=NULL);
    for (int i = 0; i < size; i++)
    {
        Table->ptr[i].elem= INT_MIN;
    }
    Table->total=0;
    return Table;
}
int insert(Element x, array Table)
{
    key k;
    k = hashfunc(x, Table->TableSize);
    int count = 0;
    while (Table->ptr[k % Table->TableSize].elem != INT_MIN)
    {
        if (count == Table->TableSize)
        {
            printf("Table Full\n");
            exit(0);
        }
        k++;
        count++;
    }
    Table->ptr[k % Table->TableSize].elem = x;
    return count;
}
int find(Element x, array Table)
{
    key k;
    k = hashfunc(x, Table->TableSize);
    while (Table->ptr[k % Table->TableSize].elem != INT_MIN)
    {
        if (Table->ptr[k % Table->TableSize].elem == x)
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
int qpinsert(Element x, array Table)
{
    if(x==INT_MIN)
    return 0;
    Table->total++;
    key k;
    k = hashfunc(x, Table->TableSize);
    int count = 0;
    int i = 0;
    while (Table->ptr[(k + i * i) % Table->TableSize].elem != INT_MIN)
    {
        i++;
        count++;
    }
    Table->ptr[(k + i * i) % Table->TableSize].elem = x;
    return count;
}
int qpfind(Element x, array Table)
{
    key k;
    k = hashfunc(x, Table->TableSize);
    int i = 0;
    while (Table->ptr[(k + i * i) % Table->TableSize].elem != INT_MIN)
    {
        if (Table->ptr[(k + i * i) % Table->TableSize].elem == x)
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
    }
    return H;
}
int scinsert(Element n, HashTable myHt)
{
    Node Position;
    Node P;
    key k;
    if (1)
    {
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
        if (myHt->start[k]->next != NULL)
            Position->level = (myHt->start[k]->next->level) + 1;
        else
            Position->level = 0;
        Position->elem = n;
        P->next = Position;
    }

    return Position->level;
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
// void strinsert(char* word,HashTable Table)
// {
//     Node Position;
//     long int k;

//         Position = (Node)malloc(sizeof(struct structNode));
//         k = horner(word, Table->TableSize);
//         Position->next = Table->start[k]->next;
//         Position->s=word;
//         Table->start[k]->next = Position;

//     return;
// }
// Node strfind(char* word,HashTable Table)
// {
//     Node Position = NULL;
//     long int k;
//     k = horner(word, Table->TableSize);
//     Position = Table->start[k]->next;
//     while ((Position != NULL) && (strcmp(Position->s,word) != 0))
//         Position = Position->next;

//     return Position;
// }

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
long int horner(char *word, long int size)
{
    long int hashval = 0;
    for (int i = 0; i < strlen(word); i++)
    {
        hashval = (33 * hashval + word[i]) % size;
    }
    return hashval;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <limits.h>

int main()
{
    char input[20];
    scanf("%s", input);
    int size = 2003;
    int num;
    int m = 100;
    int avgprobe[10] = {0};
    float alpha = 0;
    int alphacheck = 0;
    double time_spent = 0.0;
    clock_t begin = clock();
    if (strcmp(input, "1") == 0)
    {
        srand(time(0));
        for (int n = 0; n < m; n++)
        {
            array Table;
            Table = createhash(size);
            for (int i = 0; i < 2000; i++)
            {
                num = (rand() % 10000) * 2;
                if ((i + 1) % 200 == 0)
                {
                    avgprobe[alphacheck] += insert(num, Table);
                    alphacheck += 1;
                }
                else
                    insert(num, Table);
            }
            alphacheck = 0;
        }
    }
    else if (strcmp(input, "2") == 0)
    {
        srand(time(0));
        for (int n = 0; n < m; n++)
        {
            array Table;
            Table = createhash(size);
            int i;
            for (i = 0; i < 2000; i++)
            {
                num = (rand() % (10000)) * 2;

                if ((i+1)%200==0)
                {
                    alphacheck += 1;
                    avgprobe[alphacheck] += qpinsert(num, Table);
                    
                }
                else
                    qpinsert(num, Table);
                if (alphacheck == 5)
                   break;
            }
            printf("1%d",Table->total);
            array TableRehash;
            size=4007;
            TableRehash = createhash(size);
            for (int k = 0; k < 2003; k++)
            {
                    qpinsert(Table->ptr[k].elem, TableRehash);
            }
            printf("2%d",TableRehash->total);
            for (int j = i + 1; j < 2000; j++)
            {
                num = (rand() % (10000)) * 2;
                if ((j+1)%200==0)
                {
                    alphacheck += 1;
                    avgprobe[alphacheck] += qpinsert(num, TableRehash);
                    
                }
                else
                    qpinsert(num, TableRehash);
            }
            printf("3%d",TableRehash->total);
            alphacheck=0;
        }
    }
    else if (strcmp(input, "3") == 0)
    {
        srand(time(0));
        for (int n = 0; n < m; n++)
        {
            HashTable Table;
            Table = sccreatehash(size);
            for (int i = 0; i < 2000; i++)
            {

                num = (rand() % 10000) * 2;
                if ((i + 1) % 200 == 0)
                {
                    avgprobe[alphacheck] += scinsert(num, Table);
                    alphacheck += 1;
                }
                else
                    scinsert(num, Table);
            }
            alphacheck = 0;
        }
    }
    else
        return 0;

    for (int i = 0; i < 9; i++)
    {
        printf("%f\n", (float)avgprobe[i] / m);
    }
    clock_t end = clock();
    time_spent += ((double)end - (double)begin) / 1000000;

    printf("Time elpased is %lf seconds", time_spent);
}