#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
    char s[10000];
    int nr;

    struct node *next;

} node;

typedef struct list
{

    node *head;

} list;

int main()
{
    FILE *f,*g;
    f=fopen("trains/_all_files.txt","r");
    char s1[10000];
    char s2[10000];
    char x[30];
    
    while(fgets(s1,100,f)!=NULL)
    {
        strcpy(x,"trains/");
        strcat(x,s1);
        strcpy(x+strlen(x)-1,x+strlen(x));
        g=fopen(x,"r");
            while(fgets(s2,100,g)!=NULL)
            {
                //printf("%s",s2);
                
            }
        fclose(g);
    }
    
    fclose(f);
    

    return 0;



}