#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct stack_node_t{

	int val;

	struct stack_node_t *next;

} stack_node_t;

typedef struct stack_t{

	struct stack_node_t *head;

	unsigned int length;

} stack_t;

double generateRandomDouble(double n_min, double n_max)
{
    double nr = (double) rand() / ((double) RAND_MAX + 1);
    return (n_min + nr*(n_max - n_min));
}

stack_t *stack_create()
{
	stack_t *stack =NULL;

	stack=(stack_t*)malloc(sizeof(stack_t));
	stack->length=0;
    stack->head=NULL;

	return stack;
}

stack_node_t *stack_node_create(int val)
{
	stack_node_t *node = NULL;

	node=(stack_node_t*)malloc(sizeof(stack_node_t));
	if(node==NULL)
	{
        printf("Alocarea dinamica a esuat!");
        return NULL;
    }
	node->next=NULL;
	node->val=val;

	return node;
}

void stack_push(stack_t *stack, int val)
{
    if(stack==NULL)
	{
		stack=stack_create();
	}
    stack_node_t *node = NULL;
	node=stack_node_create(val);
	node->next=stack->head;
	stack->head=node;
	stack->length += 1;
}

void stack_print(stack_t *stack)
{
  	stack_node_t *copie =stack->head;
	while(copie!=NULL)
	{
		printf("%d ",copie->val);
		copie=copie->next;
    }
	printf("\n");
}

int main()
{
    int n;
    stack_t *stack = stack_create();
    stack_t *stack1 = stack_create();
    stack_t *stack2 = stack_create();
    
	// Am generat un sir de 7 numere aleatorii.
    
	stack_push(stack,generateRandomDouble(-10, 10));
	stack_push(stack,generateRandomDouble(-10, 10));
	stack_push(stack,generateRandomDouble(-10, 10));
	stack_push(stack,generateRandomDouble(-10, 10));
	stack_push(stack,generateRandomDouble(-10, 10));
	stack_push(stack,generateRandomDouble(-10, 10));
	stack_push(stack,generateRandomDouble(-10, 10));

	stack_print(stack);

	stack_node_t *copie =stack->head;
	while(copie!=NULL)
	{
		if(copie->val<0)
		{
			stack_push(stack1,copie->val);
			copie=copie->next;
		}
		else
		{
			stack_push(stack2,copie->val);
			copie=copie->next;
		}
    }
	printf("\n");
	stack_print(stack);
	printf("\n");
	stack_print(stack1);
	printf("\n");
	stack_print(stack2);  

	return 0;
    
}