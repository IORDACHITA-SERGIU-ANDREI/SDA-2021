#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <time.h>

typedef struct queue_node_t{

	int val;

	struct queue_node_t *next;

    struct queue_node_t *prev;

    unsigned prio;

} queue_node_t;

typedef struct queue_t{

	struct queue_node_t *head;

	struct queue_node_t *tail;

	unsigned int length;

} queue_t;

int random_number(int min_num, int max_num)
{
    int result=0,low=0,high=0;
    if(min_num<max_num)
    {
        low=min_num;
        high=max_num+1;
    }
    else
    {
        low=max_num+1;
        high=min_num;
    }
    result=(rand()%(high-low))+low;

    return result;
}

queue_t *queue_create()
{
	queue_t *queue = NULL;


	queue=(queue_t*)malloc(sizeof(queue_t));
	queue->length=0;
	queue->head=queue->tail=NULL;

	return queue;
}

queue_node_t *queue_node_create(int valx, unsigned priox)
{
	queue_node_t *node = NULL;


	node=(queue_node_t*)malloc(sizeof(queue_node_t));
	if(node==NULL)
	{
		printf("Alocarea dinamica a esuat!");
		return NULL;
	}
	node->next=NULL;
	node->val=valx;
    node->prev=NULL;
    node->prio=priox;

	return node;
}

void queue_push(queue_t *queue, int val, unsigned prio)
{


	queue_node_t *node = queue_node_create(val,prio);
	queue->length += 1;
	if(queue->tail==NULL)
	{
    queue->tail=node;
    queue->head=node;
    return;
	}
	else
	{
	  	if(queue->head->prio <= node->prio)
        {
            queue->head->prev=node;
            node->next=queue->head;
            queue->head=node;

            return;
        }

        if(queue->tail->prio >= node->prio)
        {
            queue->tail->next=node;
            node->prev=queue->tail;
            queue->tail=node;

            return;
        }

        queue_node_t *copiehead=queue->head;

        while(copiehead->prio>=node->prio)
        {
               copiehead=copiehead->next;
        }

        node->next=copiehead;
        node->prev=copiehead;
        copiehead->prev->next=node;
        copiehead->prev=node;
	}

}

void queue_print(queue_t *queue)
{

	queue_node_t *copie =queue->head;
	while(copie!=NULL)
	{
		printf("(%d %d) ",copie->val,copie->prio);
		copie=copie->next;
    }
	printf("\n");

}

int queue_pop(queue_t *queue)
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
        queue->head->prev=NULL;
  		queue->length -= 1;
		free(copie);

	return val;
}

int queue_front(queue_t *queue)
{
	int val = 0;

	if(queue->length==0)
	{
		val=INT_MIN;
	}

	val=queue->head->val;

	return val;
}

int queue_back(queue_t *queue)
{
	int val = 0;

	if(queue->length==0)
	{
		val=INT_MIN;
	}

	val=queue->tail->val;

	return val;
}

int main()
{

    queue_t *queue=queue_create();

    srand(time(NULL));

    queue_push(queue,random_number(-10,10),random_number(0,20));
    queue_push(queue,random_number(-10,10),random_number(0,20));
    queue_push(queue,random_number(-10,10),random_number(0,20));
    queue_push(queue,random_number(-10,10),random_number(0,20));

    queue_print(queue);

    printf ("head = %d\ntail = %d\n", queue_front(queue), queue_back(queue));
    
    queue_node_t *node1=queue_node_create(-11,30);

    queue_push(queue,node1->val,node1->prio);

    node1->prio=0;

    queue_push(queue,node1->val,node1->prio);

    node1->prio=5;

    queue_push(queue,node1->val,node1->prio);

    queue_print(queue);

    return 0;

}
