#include "header.h"
#include <stdio.h>

int v[1001];

void sortare()
{
    int n, i, nr;

    scanf("%d", &n);
    for (i = 0; i < n ;i ++){
      scanf("%d", &nr);
      v[nr] ++;
    }

    for(i = 0; i < 1001; i++){
      while(v[i] > 0){
        printf("%d\n", i);
        v[i] --;
      }
    }
}
