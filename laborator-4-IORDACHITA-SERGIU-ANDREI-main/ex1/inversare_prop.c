#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct stack_node_t{

      char *str;

      struct stack_node_t *next;

} stack_node_t;


typedef struct stack_t{

       struct stack_node_t *head;

} stack_t;

stack_t *stack_create()
{
	stack_t *stack =NULL;

	stack=(stack_t*)malloc(sizeof(stack_t));
    stack->head=NULL;

	return stack;
}

stack_node_t *stack_node_create(char val[])
{
	stack_node_t *node = NULL;

	node=(stack_node_t*)malloc(sizeof(stack_node_t));
	if(node==NULL)
	{
        printf("Alocarea dinamica a esuat!");
        return NULL;
    }
    node->str=malloc(strlen(val)*sizeof(char));
	node->next=NULL;
	strcpy(node->str,val);

	return node;
}

void stack_push(stack_t *stack, char val[])
{
    if(stack==NULL)
	{
		stack=stack_create();
	}
    stack_node_t *node = NULL;
	node=stack_node_create(val);
	node->next=stack->head;
	stack->head=node;

}

char *stack_pop(stack_t *stack)
{

	if(stack==NULL || stack->head==NULL)
   	{
	   	return 0;
   	}
	stack_node_t *copie=stack->head;
	char *val=(char*)malloc(strlen(copie->str)+1);
	strcpy(val,copie->str);
	if(stack->head->next==NULL)
	{
		stack->head=NULL;
		stack=NULL;
	}
	else
	{
		stack->head=stack->head->next;
	}	
	free(copie);


	return val;
}


int main()
{
   FILE *f;
   stack_t *stack=stack_create();
   char str[20];
   
   f=fopen("input.txt","rt");

    while (fscanf(f,"%s",str)!=EOF)

    {
        stack_push(stack,str);
    }


   fclose(f);

   f=fopen("output.txt","wt");

   while(stack->head!=NULL)
   {
       fprintf(f,"%s ",stack_pop(stack));
   }

   fclose(f);

   return 0;

}