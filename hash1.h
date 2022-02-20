#ifndef __HASH
#define __HASH

typedef int Element;
typedef int key;
typedef struct HT * HashTable;
typedef struct structNode * Node;
typedef struct arr* array;
typedef struct streadme readme;

struct HT{
    int TableSize;
    Node * start;
};

struct structNode{
    int garbage[1000000];
    Element elem;
    int level;
    Node next;
};
struct arr{
    int TableSize;
    readme *ptr;
};
struct streadme{
    int garbage[1000000];
    Element elem;
    int probe;
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
void strinsert(char* word,HashTable Table);
Node strfind(char* word,HashTable Table);
int hashfunc(Element key, int size);
long int horner(char* word,long int size);
#endif