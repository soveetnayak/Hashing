#include "hash1.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <limits.h>

int main()
{
    char input[20];
    scanf("%s", input);
    int size;
    int num;
    int m = 100;
    float avgprobe[9];
    float alpha = 0;
    float alphacheck = 0;
    scanf("%d", &size);
    time_t t;
    srand(time(&t));

    if (strcmp(input, "linear-probing") == 0)
    {
        array Table;
        Table = createhash(size);
        for (float i = 0; i < 2000; i++)
        {
            alpha = i / size;
            num = (rand() % (INT_MAX / 2)) * 2;
            if (alpha > alphacheck)
            {
                avgprobe[(int)alphacheck]+=qpinsert(num, Table);
                alphacheck++;
            }
            else
                insert(num, Table);
        }
    }
    else if (strcmp(input, "quadratic-probing") == 0)
    {
        array Table;
        Table = createhash(size);
        float i;

        for (i = 0; i < 2000; i++)
        {
            
                alpha = i / size;
                num = (rand() % (INT_MAX / 2)) * 2;
                if (alpha > alphacheck)
                {
                    avgprobe[(int)alphacheck]+=qpinsert(num, Table);
                    alphacheck++;
                }
                else
                    qpinsert(num, Table);
            if(alpha>0.5)
            break;
        }

        array Table2;
        Table2 = createhash(4007);
        for (int i = 0; i < 2000; i++)
        {
            if (Table->ptr[i].elem != INT_MIN)
                insert(Table->ptr[i].elem, Table2);
        }
        for(int j=i+1;j<2000;j++)
        {
            alpha = j / size;
                num = (rand() % (INT_MAX / 2)) * 2;
                if (alpha > alphacheck)
                {
                    avgprobe[(int)alphacheck]+=qpinsert(num, Table);;
                    alphacheck++;
                }
                else
                    qpinsert(num, Table);
        }

    }
    else if (strcmp(input, "separate-chaining") == 0)
    {
        HashTable Table;
        Table = sccreatehash(size);
        for (float i = 0; i < 2000; i++)
        {
            alpha = i / size;
            num = (rand() % (INT_MAX / 2)) * 2;
            if (alpha > alphacheck)
            {
                avgprobe[(int)alphacheck]+=qpinsert(num, Table);
                alphacheck++;
            }
            else
                scinsert(num, Table);
        }
    }
    else
        return 0;

    for(int i=0;i<9;i++)
    {
        printf("%f\n",avgprobe[i]);
    }
}