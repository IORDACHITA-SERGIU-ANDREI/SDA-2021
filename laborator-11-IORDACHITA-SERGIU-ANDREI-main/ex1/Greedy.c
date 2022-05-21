#include <stdio.h>

void gasire_minim(int n)
{
    int coins[5]={1,5,10,50,100};
    int coinList[20]={0};
    int i,k=0;

    for(i=4;i>=0;i--)
    {
        while(n>=coins[i])
        {
            n-=coins[i];
            coinList[k++]=coins[i];
        }
    }

    for(i=0;i<k;i++)
    {
        printf("%d ",coinList[i]);
    }

    printf("\nNumarul de bancnote necesare este %d\n",k);

}

int main()
{
    int n;

    printf("Introduceti suma de bani: ");
    scanf("%d",&n);

    gasire_minim(n);

    return 0;
}