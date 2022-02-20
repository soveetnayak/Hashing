#include<stdio.h>
#include<string.h>
#include"hash.h"

int main()
{
    char A[100007];
    char B[100007];
    char temp[100017];
    scanf("%s",A);
    scanf("%s",B);
    int a=strlen(A);
    int b=strlen(B);
    char A1[a+1];
    char B1[b+1];
    int count=0;
    HashTable H;
    Node m;
    Node n;
    H=sccreatehash(17);
    strinsert(A,H);
    strinsert(B,H);
    int j;
    for(int i=0;i<a;i++)
    {
        if(i<b)
        {
            temp[i]=A[i];
            if((b)%(i+1)==0&&(a)%(i+1)==0)
            {
                for(j=0;j<a;j++)
                {
                    A1[j]=temp[j%(i+1)];
                }
                A1[j]='\0';
                for(j=0;j<b;j++)
                {
                    B1[j]=temp[j%(i+1)];
                }
                B1[j]='\0';
                m=strfind(A1,H);
                n=strfind(B1,H);
                if(m!=NULL&&n!=NULL)
                {
                    if(strcmp(m->s,A)==0&&strcmp(n->s,B)==0)
                    count+=1;
                }
            }

        }
    }
    printf("%d",count);
    return 0;
}
int main()
{
    char A[100007];
    char B[100007];
    char temp[100007];
    scanf("%s",A);
    scanf("%s",B);
    int a=strlen(A);
    int b=strlen(B);
    int count=0;
    HashTable H;
    Node m;
    Node n;
    H=sccreatehash(1007);

    for (int i = 0; i < a, i<b; i++)
    {
        
    }
    
}