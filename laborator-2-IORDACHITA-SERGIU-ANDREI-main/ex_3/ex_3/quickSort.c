#include "header.h"

int partitie(moment number[],int left,int right)
{

    moment pivot=number[right];
    int i=left;
    moment aux;
    for(int j=left;j<right;j++)
    {
        if(number[j].ora < pivot.ora || (number[j].ora == pivot.ora && number[j].minut < pivot.minut) || (number[j].ora == pivot.ora && number[j].minut == pivot.minut && number[j].secunda < pivot.secunda))
        {
            aux=number[j];
            number[j]=number[i];
            number[i]=aux;
            i++;
        }

    }
    aux=number[i];
    number[i]=number[right];
    number[right]=aux;

    return i;
}

void quickSort(moment number[],int left,int right)
{

   if(left<right){

      int pivot=partitie(number,left,right);

      quickSort(number,left,pivot-1);
      quickSort(number,pivot+1,right);

   }

}
