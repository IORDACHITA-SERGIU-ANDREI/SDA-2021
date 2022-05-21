#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct stack_node_arbor
{
	char val;
	struct stack_node_arbor * left;
    struct stack_node_arbor * right;

} stack_node_arbor;


typedef struct stack_arbor
{
	struct stack_node_arbor * root;

} stack_arbor;

stack_arbor * stack_create_arbore ()
{
	stack_arbor * stack = NULL;
	stack = (stack_arbor *) malloc (sizeof (stack_arbor));
	stack->root = NULL;
	return stack;
}

stack_node_arbor * stack_node_create (char val)
{
	stack_node_arbor * node = NULL;

	node = (stack_node_arbor *) malloc (sizeof (stack_node_arbor));
	if (node == NULL)
	{
  	printf("Alocarea dinamica a esuat!");
  	return NULL;
	}
	node->left=node->right = NULL;
	node->val = val;
	return node;
}

void push (stack_arbor * stack,char val)
{
	if(stack==NULL)
	{
		stack = stack_create_arbor ();
	}
	stack_node_arbor * node = NULL;
	node = stack_node_create_operator (val);
	node->left = stack->root;
    node->right= stack->root;
	stack->root = node;
  
}

char stack_pop_operator (stack_arbor * stack)
{
	
}

int main()
{
       char s[30];
       int i;
       stack_arbor *s1=NULL,*s2=NULL;
       printf("Introduceti ecuatia: ");
       gets(s);
       for(i=0;i<strlen(s)-1;i++)
       {
           if( s[i]=='+' || s[i]=='-' || s[i]=='*' || s[i]=='/' )
           {
               push(s2,s[i]);
           }
           else
           {
               push(s1,s[i]);
           }
       }



}
