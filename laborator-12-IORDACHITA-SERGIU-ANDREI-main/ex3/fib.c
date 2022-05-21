#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int fib(int n)
{
    if(n==0) return 0;
    if(n==1) return 1;
    return fib(n-1)+fib(n-2);
}

int fibmemo(int n,int memo[])
{
    if((n==0) || (n==1)) return n;
    if(memo[n]==0) 
        memo[n]=fibmemo(n-1,memo)+fibmemo(n-2,memo);
    return memo[n];
}

int main()
{
    int n=20;
    int *v=(int*)calloc(n+1,sizeof(int));

    clock_t begin=clock();
    int m=fibmemo(n,v);
    clock_t end=clock();
    double t1=(double)(end-begin)/CLOCKS_PER_SEC;
    printf("Cu memorizare: %d            %f",m,t1);

    clock_t begin2=clock();
    int x=fib(n);
    clock_t end2=clock();
    double t2=(double)(end2-begin2)/CLOCKS_PER_SEC;
    printf("\nFara memorizare: %d          %f\n",x,t2);


    return 0;
}