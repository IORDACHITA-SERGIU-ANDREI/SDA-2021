#include <stdio.h>

void gasire_minim(int n)
{
    int coins[7]={1,3,5,15,30,50,150};
    int coinList[50]={0};
    int i,k=0;

    for(i=6;i>=0;i--)
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
    int n=60;                          // Am gasit un exemplu pentru n=60,se vor folosi 3 bancnote,comparativ cu ex1 cand se foloseau doar 2 bancnote pentru acelasi n.

    gasire_minim(n);                   // Observatie: Deoarece sunt mai multe bancnote si mai diversificate,se pot realiza mai multe combinatii pentru a se plati restul.

    return 0;
}