#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"

int main()
{
    int n,i,j;
    printf("Introduceti nr de cuvinte: ");
    scanf("%d",&n);
    char x[n+1][5];
    printf("Introduceti cuvintele:\n");
    getchar();
    for(i=0; i<n; i++)
    {
        scanf("%s",&x[i]);
        getchar();
    }
    bubblesort(x,n);
    for(i=0; i<n; i++)
    {
        for(j=0; j<4; j++)
        {
            printf("%c",x[i][j]);
        }
        printf("\n");
    }

    return 0;
}
