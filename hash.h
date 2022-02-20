#ifndef __HASH
#define __HASH

typedef int Element;
typedef int key;
typedef struct HT * HashTable;
typedef struct structNode * Node;
typedef struct arr* array;

struct HT{
    int TableSize;
    Node * start;
};

struct structNode{
    int level;
    char *s;
    Element elem;
    Node next;
};
struct arr{
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
void strinsert(char* word,HashTable Table);
Node strfind(char* word,HashTable Table);
int hashfunc(Element key, int size);
long int horner(char* word,long int size);
#endif