#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

// typedef struct node
// {
//     char s[10000];
//     int nr;

//     struct node *next;

// } node;

int nrorase;

typedef struct node_t{

	char statie[50];
	struct node_t *next;

}node_t;

typedef struct list
{

    node_t *head;

} list;

typedef struct queue_node_t{
	
	int val;

	struct queue_node_t *next;
} queue_node_t;

typedef struct queue_t{
	
	struct queue_node_t *head;
	
	struct queue_node_t *tail;

	unsigned int length;
} queue_t;

queue_t *queue_create()
{
	queue_t *queue = NULL;

	queue=(queue_t*)malloc(sizeof(queue_t));
	queue->length=0;
	queue->head=queue->tail=NULL;

	return queue;
}

queue_node_t *queue_node_create(int val)
{
	queue_node_t *node = NULL;

	node=(queue_node_t*)malloc(sizeof(queue_node_t));
	if(node==NULL)
	{
		printf("Alocarea dinamica a esuat!");
		return NULL;
	}
	node->next=NULL;
	node->val=val;

	return node;
}

void enqueue(queue_t *queue, int val)
{

	queue_node_t *node = queue_node_create(val);
	queue->length += 1;
	if(queue->tail==NULL)
	{
		queue->tail=node;
	}
	else
	{
		queue->tail->next=node;
		queue->tail=node;
	}
	if(queue->head==NULL)
	{
		queue->head=queue->tail;
	}
	
}

int dequeue(queue_t *queue)
{
	int val = 0;

	if(queue->length==0)
   	{
	   	return 0;
   	}
  	if(queue->length==1)
  	{
		val=queue->head->val;
    	free(queue->head);
    	queue->head = NULL;
    	queue->length = 0;
    	return val;
  	}
		queue_node_t *copie=queue->head;
		val=copie->val;
		queue->head=queue->head->next;
  		queue->length -= 1;
		free(copie);

	return val;
}


node_t *create(char statie[])
{
	node_t *p;
	p=(node_t *)malloc(sizeof(node_t));
	if(p==NULL)
    {
        printf("Alocarea dinamica a esuat!");
    }
	p->next=NULL;
	strcpy(p->statie,statie);

	return p;
}

void append_node(node_t *list_head,char statie[])
{
    node_t *p;
    p=create(statie);
    node_t *copie=list_head;
    while(list_head->next!=NULL)
    {
        list_head=list_head->next;
    }
	list_head->next=p;

	//return copie;
}

node_t *get_node(node_t *list_head,char statie[])
{
	while(list_head!=NULL)
    {
        if(strstr(list_head->statie,statie)!=NULL)
        {
           return list_head;
        }
        list_head=list_head->next;
    }
	return NULL;
}

void print_list(node_t *list_head)
{
	while(list_head!=NULL)
    {
        printf("%s, ",list_head->statie);
        list_head=list_head->next;
    }
}

int d[1000];
int mn[550][550];
int viz[550];

void BFS(node_t *h)
{
    queue_t *q=queue_create();
    FILE *r;

    r=fopen("parcurgere_bfs.txt","w");

    fprintf(r,"%s",h->statie);
    int u=0;
    viz[0]=1;
    d[u] = INT_MAX;    

    enqueue(q,u);     
 
    while(q->length!=0)
    {
     int v=dequeue(q);   
     for(int i=0;i<nrorase;i++)
          if (mn[v][i] == 1 && viz[i]==0)
          {
                node_t *copie4=h;
                int counter4=0;
                while(counter4<i)
                {
                    counter4++;
                    copie4=copie4->next;
                }
                fprintf(r,"%s",copie4->statie);
                d[u] = d[v] + 1;
                enqueue(q,i);
                viz[i]=1;   
          }
    }

    fclose(r);
    
}

FILE *p;

void DFS(node_t *c,node_t *head)
{
    fprintf(p,"%s",c->statie);
    int counter5=0;
    node_t *copie5=head;
    while(copie5!=NULL)
    {
        if(strcmp(copie5->statie,c->statie)==0)
            break;
        counter5++;
        copie5=copie5->next;
    }
    viz[counter5]=1;
	for(int i=0;i<nrorase;i++)
    {   
            
        if( mn[counter5][i]==1 && viz[i]==0)
            {
                copie5=head;
                int counter6=0;
                while(copie5!=NULL)
                {
                    if(counter6==i)
                        break;
                    counter6++;
                    copie5=copie5->next;
                }
                DFS(copie5,head);   
            }
    }

}

int main()
{
    FILE *f,*g;
    f=fopen("trains/_all_files.txt","r");
    char s1[10000];
    char s2[10000];
    char x[30];
    list LUnic,LTotal;
    LUnic.head=NULL;
    LTotal.head=NULL;
    int nrmuchiio=0,nrmuchiin=0;
    
    while(fgets(s1,100,f)!=NULL)
    {
        strcpy(x,"trains/");
        strcat(x,s1);
        strcpy(x+strlen(x)-1,x+strlen(x));
        g=fopen(x,"r");
            while(fgets(s2,100,g)!=NULL)
            {
                if(LTotal.head==NULL)
                    LTotal.head=create(s2);
                else append_node(LTotal.head,s2); 
                if(LUnic.head==NULL)
                    {
                        LUnic.head=create(s2);
                        nrorase++;
                    }
                else
                {
                    int flag=1;
                    node_t *copie=LUnic.head;
                    while(copie!=NULL)
                    {
                        if(strcmp(copie->statie,s2)==0)
                            {
                                flag=0;
                                break;
                            }
                        copie=copie->next;
                    }
                    if(flag==1)
                    {
                        append_node(LUnic.head,s2);
                        nrorase++;
                    }
                }              
            }
            append_node(LTotal.head,"NULL");
        fclose(g);
    }
    
    fclose(f);

    int mo[nrorase+1][nrorase+1];

    for(int i=0;i<nrorase;i++)
        for(int j=0;j<nrorase;j++)
            {
                mo[i][j]=0;
            }

    int a=-1,b=-1;
        
    while(LTotal.head!=NULL)
    {
        if(a==-1)
        {
            int counter=0;
            node_t *copie=LUnic.head;
            while(copie!=NULL)
            {
                if(strcmp(LTotal.head->statie,copie->statie)==0)
                    break;
                counter++;
                copie=copie->next;
            }
            a=counter;     
        }
        else
        {
            if(strcmp(LTotal.head->statie,"NULL")==0)
            {
                a=-1;
                LTotal.head=LTotal.head->next;
                continue;
            }
            int counter=0;
            node_t *copie=LUnic.head;
            while(copie!=NULL)
            {
                if(strcmp(LTotal.head->statie,copie->statie)==0)
                    break;
                counter++;
                copie=copie->next;
            }
            b=counter;
            if(a!=b && mo[a][b]==0)
            {
                mo[a][b]=1;
                mn[a][b]=mn[b][a]=1;
                nrmuchiio++;
                nrmuchiin+=2;               
            }
            a=b;
        }
        LTotal.head=LTotal.head->next;
    }

    // FILE *r;

    // r=fopen("MatriceN.txt","w");

    // for(int i=0;i<nrorase;i++)
    // {
    //     for(int j=0;j<nrorase;j++)
    //     {
    //         fprintf(r,"%d ",mn[i][j]);
    //     }
    //     fprintf(r,"\n");  
    // }
    
    // fclose(r);

    FILE *r;

    r=fopen("noduri.txt","w");

    fprintf(r,"%d",nrorase);

    fclose(r);

    r=fopen("muchii.txt","w");

    fprintf(r,"%d %d",nrmuchiio,nrmuchiin);

    fclose(r);

    int max1=-1,max2=0;
    char smax1[50],smax2[50];

    for(int i=0;i<nrorase;i++)
    {
        int grad=0;
        for(int j=0;j<nrorase;j++)
        {
            grad+=mn[i][j];
        }
        if(max1<=grad)
        {
            if(max1!=-1)
            {
                strcpy(smax2,smax1);
            }
            max2=max1;
            max1=grad;
            int nr=0;
            node_t *copie=LUnic.head;
            while(nr<i)
            {
                copie=copie->next;
                nr++;
            }
            strcpy(smax1,copie->statie);
        }
        else if(max2<=grad)
        {
            max2=grad;
            int nr=0;
            node_t *copie=LUnic.head;
            while(nr<i)
            {
                copie=copie->next;
                nr++;
            }
            strcpy(smax2,copie->statie);   
        }
    }

    r=fopen("primul.txt","w");

    fprintf(r,"%s",smax1);

    fclose(r);

    r=fopen("doilea.txt","w");

    fprintf(r,"%s",smax2);

    fclose(r);

    char oras[]="Rosiori Nord";

    node_t *copie2=LUnic.head;
    int counter2=0;

    while(copie2!=NULL)
    {
        if(strstr(copie2->statie,oras)!=NULL)
            break;
        counter2++;
        copie2=copie2->next;       
    }

    int grad=0;

    for(int i=0;i<nrorase;i++)
    {
        grad=grad+mn[counter2][i];
    }

    r=fopen("orasul_meu.txt","w");

    fprintf(r,"%d",grad);

    fclose(r);

    BFS(get_node(LUnic.head,"Bucuresti"));

    p=fopen("parcurgere_dfs.txt","w");

    for(int i=0;i<nrorase;i++)
        viz[i]=0;

    for(int i=0;i<nrorase;i++)
    {
        if(viz[i]==0)
        {
            node_t *copie7=LUnic.head;
            int counter7=0;
            while(counter7<i)
            {
                copie7=copie7->next;
                counter7++;
            }
            DFS(copie7,LUnic.head);
        }
    }

    fclose(p);    

    return 0;


}