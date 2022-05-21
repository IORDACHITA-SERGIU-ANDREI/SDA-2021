#include <stdio.h>
#include <string.h>
#include <stdlib.h>



typedef struct Node{

  char nr_telefon[10];
  char * nume;
  char * post;
  struct Node * next;
  struct Node * prev;

}Node;

void add_last (Node ** p, char * nume, char nr_telefon[10], char * post){
  // creez un nod nou
  Node * q = (Node *) malloc (sizeof (Node));
  q->nume = (char *) malloc (strlen(nume));
  q->post = (char *) malloc (strlen(post));
  q->next = NULL;
  q->prev = NULL;
  strcpy (q->nume, nume);
  strcpy (q->nr_telefon, nr_telefon);
  strcpy (q->post, post);
  // daca primul element e NULL
  if ((*p) == NULL){
    (*p) = q;
    return;
  }
  // Copie unde pastrez primul element din Lista
  Node * ss = (Node *) * p;
  while (ss->next != (*p) && ss->next != NULL)
    ss = ss->next;
  ss->next = q;
  q->prev = ss;
  q->next = (*p);
  (*p)->prev = q;
}

void show (Node * s){
  // copie a inceputului listei
  Node * head = s;
  // parcutg lista pana la final
  do{
    printf("Nume: %s\nNr. telefon: %s\nPost: %s\n\n", s->nume, s->nr_telefon, s->post);
    s = s->next;
  }while (s != head);
}

int add_after_third (Node ** pp, char * n, char * t, char * ps){
  // creeaza nod
  Node * q = (Node *) malloc (sizeof (Node));
  q->nume = (char *) malloc (strlen(n));
  q->post = (char *) malloc (strlen(ps));
  q->next = NULL;
  q->prev = NULL;
  strcpy (q->nume, n);
  strcpy (q->nr_telefon, t);
  strcpy (q->post, ps);
  // in cazul in care lista e nula
  if ((*pp) == NULL){
    (*pp) = q;
    return -1;
  }
  // in ss pastrez capul listei
  Node * ss = (Node *) * pp;
  int nr = 0;
  while (ss->next != (*pp) && ss->next != NULL){
    ss = ss->next;
    nr ++;
    if (nr == 2)
      break;
  }
  // daca sunt mai putin de 3 elemente returnez -1
  if (nr < 2)
    return -1;
  // daca sunt doar 3 elemente in lista,trebuie sa adaug q ca ultim element

  if (ss->next == (*pp)){
    q->next = (*pp);
    q->prev = ss;
    ss->next = q;
    (*pp)->prev = q;
    return 1;
  }
  // adaug dupa al treilea element
  q->next = ss->next;
  q->prev = ss;
  ss->next = q;
  (ss->next)->prev = q;
  return 1;
}

int add_before_mecanic (Node ** pp, char * n, char * t, char * ps){
  // initializez postul pe care il caut in lista, ca sa adaug un nod nou inaintea lui

  char cst[] = "mecanic";
  // creez nod nou
  Node * q = (Node *) malloc (sizeof (Node));
  q->nume = (char *) malloc (strlen(n));
  q->post = (char *) malloc (strlen(ps));
  q->next = NULL;
  q->prev = NULL;
  strcpy (q->nume, n);
  strcpy (q->nr_telefon, t);
  strcpy (q->post, ps);
  // daca lista e vida
  if ((*pp) == NULL){
    return -1;
  }
  // initializez variabila cu care sa parcurg lista
  Node * ss = (Node *) * pp;
  int nr = 0;
  // daca primul nod este cel care contine postul de mecanic

  if (strcmp (ss->post, cst) == 0){
    Node * end = (Node *) * pp;
    while (end->next != (*pp)){
        end = end->next;
    }
    end->next = q;
    q->prev = end;
    ss->prev = q;
    q->next = ss;
    (*pp) = q;
    return 1;
  }
  // parcurg lista pana la final, si daca intalnesc un mecanic,adaug inaintea lui

  while (ss->next != (*pp)){
    if (strcmp ((ss->next)->post, cst) == 0){
      nr = 1;
      break;
    }
    ss = ss->next;
  }
  if (!nr)
    return -1;
  q->next = ss->next;
  q->prev = ss;
  ss->next = q;
  (ss->next)->prev = ss;
  return 1;
}

void delete_number (Node ** s, char nr_telefon[10]){
  Node * p = (Node *) * s;
  if (p == NULL)
    return;
  if (p->next == NULL){
    if (strcmp (p->nr_telefon, nr_telefon) == 0){
      free ((*s)->nume);
      free ((*s)->post);
      free (*s);
      (*s) = NULL;
    }
    return;
  }
  do{
    if (strcmp (p->nr_telefon, nr_telefon) == 0){
      if (p->next == (*s)){
        (p->prev)->next = (*s);
        (*s)->prev = p->prev;
        free (p->nume);
        free (p->post);
        free (p);
      }
      else {
        (p->prev)->next = p->next;
        (p->next)->prev = p->prev;
        free (p->nume);
        free (p->post);
        free (p);
      }
    }
    p = p->next;
  }while (p != NULL && p != (*s));
}

void read (Node ** s){
  int rasp;
  printf ("Citesti un element?Daca da,introdu un numar diferit de 0:\n");
  scanf("%d", &rasp);
  while (rasp){
    char * nume, * post, nr_telefon[10];

    printf ("Nume : ");
    nume = (char *) malloc (100 * sizeof(char));
    scanf("%s", nume);

    printf ("Nr. Telefon :");
    scanf("%s", nr_telefon);

    printf ("Post : ");
    post = (char *) malloc (100 * sizeof(char));
    scanf("%s", post);

    add_last (s, nume, nr_telefon, post);
    printf ("Citesti un element?Daca da,introdu un numar diferit de 0:\n");
    scanf ("%d", &rasp);
  }
}

int main ()
{
  Node * start = NULL;

  // citesc lista
  read (&start);

  char n[15] = "Ionut";
  char nt[15] = "0733333333";
  char ps[15] = "profesor";

  // // test pt a.
   int rez = add_after_third (&start, n, nt, ps);
  // // test pt b.
  if (rez == -1)
     printf ("\nNu exista\n");
   else
     printf ("\nAdd corect in lista\n");
    rez = add_before_mecanic (&start, n, nt, ps);
   if (rez == -1)
     printf ("\nNu exista\n");
   else
     printf ("\nAdd corect in lista\n");
  // test pt c.
   delete_number (&start, "0");
   show (start);

  return 0;

}



