#include <stdio.h>
#include <stdlib.h>
#include "header.h"

int main()
{
    moment *v;
    int n,i;
    printf("Introduceti cate momente doriti sa contorizati: ");
    scanf("%d",&n);
    v=malloc(n*sizeof(moment));
    if(v==NULL)
    {
        printf("Alocarea dinamica a esuat!");
        exit(0);
    }
    printf("Momentele zilei sunt (ora,minut,secunda):\n");
    for(i=0;i<n;i++)
    {
       v[i].ora=rand()%23;
       v[i].minut=rand()%59;
       v[i].secunda=rand()%59;
    }
    for(i=0;i<n;i++)
    {
        printf("%d %d %d\n",v[i].ora,v[i].minut,v[i].secunda);
    }

    quickSort(v,0,n-1);

    printf("\n");

    for(i=0;i<n;i++)
    {
        printf("%d %d %d\n",v[i].ora,v[i].minut,v[i].secunda);
    }

    return 0;
}
