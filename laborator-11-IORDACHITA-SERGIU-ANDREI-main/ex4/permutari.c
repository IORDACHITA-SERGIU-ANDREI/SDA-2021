#include <stdio.h>

int sol[10] ,n;

int verificare(int k)
{
    for(int i=1;i<k;++i)
        if(sol[k]==sol[i])
            return 0;
    return 1;
}

void permutari(int k)
{
    for(int i=1 ; i<=n ; ++i)
    {
        sol[k]=i;
        if( verificare(k) )
            if(k==n)
            {
                for( int j=1;j<=n;j++)
                    printf("%d ",sol[j]);
                printf("\n");
            }
            else
                permutari(k+1);
    }
}
int main()
{
    printf("n= ");
    scanf("%d",&n);
    printf("\nAm generat permutari de %d:\n\n",n);
    permutari(1);

    return 0;

}