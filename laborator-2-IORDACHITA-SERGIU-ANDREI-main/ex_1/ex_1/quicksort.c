#include "header.h"

int partitie(int number[],int left,int right,int *b)
{

    int pivot=number[right];
    int i=left,aux;
    for(int j=left;j<right;j++)
    {
        if(number[j]<pivot)
        {
            aux=number[j];
            number[j]=number[i];
            number[i]=aux;
            (*b)++;
            i++;
        }

    }
    aux=number[i];
    number[i]=number[right];
    number[right]=aux;
    (*b)++;

    return i;
}

void quickSort(int number[],int left,int right,int *b)
{

   if(left<right){

      int pivot=partitie(number,left,right,b);

      quickSort(number,left,pivot-1,b);
      quickSort(number,pivot+1,right,b);

   }

}
