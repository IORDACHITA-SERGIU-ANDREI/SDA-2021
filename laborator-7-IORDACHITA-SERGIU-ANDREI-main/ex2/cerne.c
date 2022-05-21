#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int counter;

void schimba(int a[],int i,int j) 
{
    int aux;
    aux = a[i];
    a[i] = a[j];
    a[j] = aux;
}
void cerne(int a[],int n,int k)
{
    counter++;
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
    printf("\nFunctia cerne s-a apelat de %d ori in makeHeap\n",counter);
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
    printf("\nFunctia cerne s-a apelat de %d ori in heapSort\n",counter);
 
}

int main()
{

    int i,n=16,*v;
    v=(int*)malloc(n*sizeof(int));
    for(i=0;i<n;i++)
    {
        v[i]=rand()%50;
    }
    for(i=0;i<n;i++)
    {
        printf("%d ",v[i]);
    }
    heapSort(v,n);
    printf("\n");
    printf("Heap Sort: ");
    for(i=0;i<n;i++)
    {
        printf("%d ",v[i]);
    }
    printf("\n");



    return 0;
}