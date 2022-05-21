#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define BYTE 8
#define COUNT_BYTE 256

// Heap Sort Algoritm

void schimba(int a[],int i,int j) 
{
    int aux;
    aux = a[i];
    a[i] = a[j];
    a[j] = aux;
}
void cerne(int a[],int n,int k)
{
    int fiuStanga = 2 * k + 1, 
        fiuDreapta = 2 * k + 2,
        pozMax = fiuStanga; 
    if(fiuStanga >= n)
        return; 
    if(fiuDreapta < n) {
        if(a[fiuDreapta] > a[fiuStanga] ) {
            pozMax = fiuDreapta;
        }
    }
    if(a[k] < a[pozMax]) 
    {
        schimba(a,k,pozMax); 
        cerne(a,n,pozMax); 
    }
}
void makeHeap(int a[],int n) 
{
    
    for(int i = n / 2;i >= 0;i--) 
    { 
        cerne(a,n,i); 
    }
}
void heapSort(int a[],int n)
{
    makeHeap(a,n); 
    while(n > 1) 
    {
        schimba(a,0,n-1); 
        n--; 
        cerne(a,n,0);         
    }
 
}



// Radix Sort Algoritm

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
    int n=1e6;
    int i,*v,*x;
    v=(int*)malloc(n*sizeof(int));
    x=(int*)malloc(n*sizeof(int));
    for(i=0;i<n;i++)
    {
        v[i]=rand()%1000;
        x[i]=v[i];
    }
  /*  for(i=0;i<n;i++)
    {
        printf("%d ",v[i]);
    } */
    clock_t begin = clock();
    heapSort(v,n);
    clock_t end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("\n");
    printf("Heap Sort: ");
  /*  for(i=0;i<n;i++)
    {
        printf("%d ",v[i]);
    }  */
    printf("\n");
    printf("Timpul de rulare al heap sort este %lf",time_spent);
    printf("\n");
    printf("\n");


  /*  for(i=0;i<n;i++)
    {
        printf("%d ",x[i]);
    }   */
    clock_t begin2 = clock();
    radixSort(x,n);
    clock_t end2 = clock();
    double time_spent2 = (double)(end2 - begin2) / CLOCKS_PER_SEC;
    printf("\n");
    printf("Radix Sort: ");
  /*  for(i=0;i<n;i++)
    {
        printf("%d ",x[i]);
    }   */
    printf("\n");
    printf("Timpul de rulare al radix sort este %lf",time_spent2);
    printf("\n");
    printf("\n");

    return 0;
}