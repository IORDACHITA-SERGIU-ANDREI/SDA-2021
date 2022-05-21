#include<stdio.h> 

int x1[19],x2[19];

void combinari(int k,int len,int max)
{
     if(k-1 == max) 
     {
         for(int i = 1; i <= max;i++)
           printf("%d ",x1[i]);
         printf("\n");
     }     
     else
     {
         for(int  i = 1; i <= len; i++)
            if(!x2[i] && x1[k-1] < i)  
            {
                 x1[k] = i;
                 x2[i] = 1; 
                 combinari(k+1,len,max); 
                 x2[i] = 0;   
            }
     }
}

int main()  
{   
    int n,k;
    printf("Combinari de ");
    scanf("%d",&n);
    printf("luate cate ");
    scanf("%d",&k);
    combinari(1,n,k);  

    return 0;
}  