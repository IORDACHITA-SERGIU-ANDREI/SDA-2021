#include "list.h"
#include <stdio.h>
#include <stdlib.h>



int main()
{
	printf("Lab 2 - Liste inlantuite.\n");

	/**************************************************************************
	 * Test Task 2.
	 * Creati un nod cu o anumita valoare.
	 * Afisati valoarea la stdout.
	 */

	node_t *node =create(5);

	/* ... your code comes here ... */




	/**************************************************************************
	 * Test Task 3.
	 *
	 * Creati o variabila de tip 'node_t' cu numele 'head'.
	 * Ea va reprezenta cap-ul listei cu care veti lucra mai jos.
	 *
	 * Adaugati 5-6 noduri cu valori diferite la final listei.
	 * Aveti un exemplu.
	 */

	/* ... some cool code... */
	node_t *head =create(0);

	head = append_node(head,10);/* Raspunsul universal :). */
	head = append_node(head,20);
	head = append_node(head,30);/* ... more badass code ... */
	head = append_node(head,40);
	head = append_node(head,50);
	head = append_node(head,60);



	/**************************************************************************
	 * Test Task 4.
	 */

	print_list(head);


	/**************************************************************************
	 * Test Task 5.
	 */

    head=prepend_node(head,55);
    printf("\n");

    /*Test Task 6 */

    node_t *t;
    t=get_node(head,30);
    if(t==NULL)
    {
        printf("Valorea nu exista");
    }
    else{
        printf("%d",t->val);
    }

	/**************************************************************************
	 * Test Task 7.
	 */
     printf("\n");
     t=modify_node(head,30,57);
     print_list(head);

	/**************************************************************************
	 * Test Task 8.
	 */
     printf("\n");
     t=insert_node(head,40,15);
     print_list(head);

	/**************************************************************************
	 * Test Task 9.
	 */
     printf("\n");
     t=remove_node(head,15);
     print_list(head);


	return 0;
}

/**
 * TASK 2.
 *
 * Functia primeste o valoare, creeaza un nou nod cu aceasta
 * valoare si returneaza un pointer catre nodul creat.
 */
node_t *create(int val)
{
	node_t *p;
	p=(node_t *)malloc(sizeof(node_t));
	if(p==NULL)
    {
        printf("Alocarea dinamica a esuat!");
    }
	p->next=NULL;
	p->val=val;

	return p;
}


/**
 * TASK 3.
 *
 * Functia creaza un nou nod cu valoarea 'val'
 * si il adauga la finalul listei.
 *
 * Functia returneaza noul cap al listei (daca e cazul), sau vechiul.
 */
node_t *append_node(node_t *list_head, int val)
{
    node_t *p;
    p=create(val);
    node_t *copie=list_head;
    while(list_head->next!=NULL)
    {
        list_head=list_head->next;
    }
	list_head->next=p;

	return copie;
}

/**
 * TASK 4.
 *
 * Functia afiseaza la stdout continutul listei.
 * Valorile sunt separate prin virgula.
 */
void print_list(node_t *list_head)
{
	while(list_head!=NULL)
    {
        printf("%d, ",list_head->val);
        list_head=list_head->next;
    }
}

/**
 * TASK 5.
 *
 * Functia creaza un nou nod cu valoarea 'val'
 * si il adauga la inceputul liste.
 *
 * Functia returneaza noul cap al listei (daca e cazul), sau vechiul.
 */
node_t *prepend_node(node_t *list_head, int val)
{
	node_t *q;
	q=create(val);
	q->next=list_head;
	return q;
}

/**
 * TASK 6.
 *
 * Functia primeste un numar intreg si cauta in lista acest numar.
 * Daca gaseste numarul in lista, returneaza nodul care il contine.
 * Daca nu il gaseste returneaza NULL.
 * Daca elementul apare de mai multe ori, se returneaza prima aparitie.
 */

node_t *get_node(node_t *list_head, int val)
{
	while(list_head!=NULL)
    {
        if(val==list_head->val)
        {
           return list_head;
        }
        list_head=list_head->next;
    }
	return NULL;
}

/**
 * TASK 7.
 *
 * Functia cauta valoarea 'val' in lista si daca gaseste un element
 * cu aceasta valoare o schimba cu 'new_val'.
 *
 * Functia returneaza un pointer catre acest element, sau
 * NULL daca nodul nu exista.
 */
node_t *modify_node(node_t *list_head, int val, int new_val)
{
	node_t *p=get_node(list_head,val);
	if(p!=NULL)
    {
        p->val=new_val;
    }
	return p;
}

/**
 * TASK 8.
 *
 * Functia creaza un nod nou cu valoarea 'after_val' si il
 * insereaza dupa nodul cu valoarea 'val'.
 * Se returneaza un pointer catre nodul nou creat.
 *
 * Daca nodul cu valoarea 'val' nu exista in lista, lista
 * ramane nemodificata si se returneaza capul listei.
 */
node_t *insert_node(node_t *list_head, int val, int after_val)
{
      node_t *z;
      z=create(after_val);
      node_t *w=get_node(list_head,val);
      if(w==NULL)
      {
          return list_head;
      }
      z->next=w->next;
      w->next=z;


      return z;
}


/**
 * TASK 9.
 *
 * Functia cauta nodul cu valoarea 'val' si il sterge din lista.
 * Functia returneaza noul cap al listei (daca e cazul), sau vechiul.
 *
 * Daca nodul cu valoarea 'val' nu exista in lista, lista
 * ramane nemodificata si se returneaza capul listei.
 */
node_t *remove_node(node_t *list_head, int val)
{
     node_t *t=get_node(list_head,val);
     if(t==NULL)
     {
         return list_head;
     }
     if(t==list_head)
     {
         list_head=t->next;
         free(t);
         return list_head;
     }
     node_t *copie;
     copie=list_head;
     while(list_head->next!=t)
     {
         list_head=list_head->next;
     }
     list_head->next=t->next;
     free(t);
     return copie;

}
