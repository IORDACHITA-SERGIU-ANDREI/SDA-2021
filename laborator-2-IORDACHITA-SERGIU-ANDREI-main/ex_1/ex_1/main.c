#include <stdio.h>
#include <stdlib.h>
#include "header.h"

int a,b;

int main()
{
    int i,v1[20],v2[20];
    for(i=0;i<20;i++)
    {
        v1[i]=rand()%100;
        v2[i]=v1[i];
    }
    for(i=0;i<20;i++)
    {
       printf("%d ",v1[i]);
    }

    a=bubblesort(v1,20,a);
    quickSort(v2,0,19,&b);

    printf("\n");

    for(i=0;i<20;i++)
    {
       printf("%d ",v2[i]);
    }


    printf("\nBubblesort a executat %d operatii si quickSort a executat %d operatii!",a,b);

    return 0;


}
