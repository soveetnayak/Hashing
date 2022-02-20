#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"hash.h"
typedef char* charptr;
int main()
{
    FILE *fp=fopen("dist/dictionary.txt","r");
    char word[100007][20];
    HashTable Table;
    Node n;
    int i=0;
    int size=100007;
    Table=sccreatehash(size);
    for(i=0;i<84095;i++)
    {
        fgets(word[i],20,fp);
        strinsert(word[i],Table);
    }
    int total= i;
    int count=0;
    for(int j=0;j<i;j++)
    {
        printf("%s",word[j]);
    }

    return 0;
}