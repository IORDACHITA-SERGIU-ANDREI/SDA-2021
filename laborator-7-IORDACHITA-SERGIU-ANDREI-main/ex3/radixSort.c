#include <stdio.h>
#include <stdlib.h>
#define BYTE 8
#define COUNT_BYTE 256

int obtineOctetul(int n,int byteNr)
{   
    int bitsNr =  BYTE * byteNr;
    int mask = COUNT_BYTE - 1;
    return (n >> bitsNr) & mask;
}
void rad(int *a,int *b, int byteNr,int n)
{   
    int i,
        count[COUNT_BYTE] = {0}, 
        index[COUNT_BYTE] = {0}; 
    for(i = 0; i < n;i++) 
    {
        int car = obtineOctetul(a[i],byteNr);
        count[car]++;
    }
    for(i = 1;i < COUNT_BYTE;i++) 
        index[i] = index[i-1] + count[i-1];
    for(i = 0; i < n; i++) 
    { 
        int car = obtineOctetul(a[i],byteNr);
        b[index[car]++] = a[i];
    }
}
void radixSort(int *a,int n)
{
    int *b = malloc(n*sizeof(int)), byteNr, k = sizeof(a[0]); 
    for(byteNr = 0; byteNr < k; byteNr += 2) 
    {
        rad(a, b, byteNr, n); 
        rad(b, a, byteNr + 1, n); 
    }
    
    free(b);
}

int main()
{

    int v[]={-15,8,-33,9,2,6,-11,-44,0,100};
    for(int i=0;i<10;i++)
    {
        printf("%d ",v[i]);
    }
    int min=v[0];
    printf("\n");
    for(int i=1;i<10;i++)
    {
        if(v[i]<min)
            min=v[i];
    }
    if(min<0)
    {
        for(int i=0;i<10;i++)
        {
            v[i]=v[i]-min;
        }
    }
    radixSort(v,10);
    if(min<0)
    {
        for(int i=0;i<10;i++)
        {
            v[i]=v[i]+min;
        }
    }
    for(int i=0;i<10;i++)
    {
        printf("%d ",v[i]);
    }
    printf("\n");

}