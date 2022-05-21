#include <stdio.h>
#include <stdlib.h>

typedef struct
{

    int v1,v2,cost;

} Muchie;

typedef struct 
{

    int V,E;
    Muchie *e;

} Graph;

Graph *createGraph()
{
    FILE *f,*h;
    int i=0,k,x,y,w;

    Graph *g=malloc(sizeof(Graph));

    f=fopen("varfuri_muchii.txt","r");

    fscanf(f,"%d %d",&g->V,&g->E);

    fclose(f);

    g->e=(Muchie*)malloc(g->E*sizeof(Muchie));

    h=fopen("start_end_cost.txt","r");

    for(int i=0;i<g->E;i++)
    {
        fscanf(h,"%d %d %d",&(g->e[i].v1),&(g->e[i].v2),&(g->e[i].cost));
    }

    fclose(h);

    return g;
}

void swap(Muchie *m1,Muchie *m2)
{
    Muchie aux;
    aux=*m1;
    *m1=*m2;
    *m2=aux;
}

int partition(Muchie *arr,int low,int high)
{
    int j;
    Muchie aux;
    Muchie pivot=arr[high];
    int i=(low-1);
    for(j=low;j<high-1;j++)
    {
        if(arr[j].cost<=pivot.cost)
        {
            i++;
            swap(&arr[i],&arr[j]);
        }        
    }
    swap(&arr[i+1],&arr[high]);

    return (i+1);
}

void quickSort(Muchie *arr,int low,int high)
{
    if(low<high)
    {
        int pi=partition(arr,low,high);
        quickSort(arr,low,pi-1);
        quickSort(arr,pi+1,high);
    }
}

void Kruskal(Graph *g)
{
    int i,j,min,max,nrMuchiiSelectate=-1;
    int c[g->V];
    
    for(i=0;i<=g->V;i++)
        c[i]=i;

    Muchie a[g->V-1];
    quickSort(g->e,0,(g->E)-1);

    for(i=0;nrMuchiiSelectate<g->V-1;i++)
    {
        if(c[g->e[i].v1]!=c[g->e[i].v2])
        {  
            a[++nrMuchiiSelectate]=g->e[i];
        }
        if(c[g->e[i].v1]<c[g->e[i].v2])
        {
            min=c[g->e[i].v1];
            max=c[g->e[i].v2];
        }
        else
        {
            max=c[g->e[i].v1];
            min=c[g->e[i].v2];
        }
        for(j=0;j<g->V;j++)
            if(c[j]==max)
                c[j]=min;
    }

    for(i=0;i<g->V-1;i++)
    {
        printf("%d%d%d\n",a[i].v1,(a[i].v2),(a[i].cost));
    }

}

int main()
{
    Graph *g=createGraph();
    Kruskal(g);

    return 0;
}