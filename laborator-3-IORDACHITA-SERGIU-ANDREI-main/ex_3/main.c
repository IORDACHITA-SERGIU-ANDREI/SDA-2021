#include <stdio.h>
#include <string.h>
#include <stdlib.h>


typedef struct Node_s
{

    int val;
    struct Node_s * next;

} Node_s;

void show_s_pare (Node_s * s)
{
    printf("\n");
    if (s == NULL)
    {
        printf("Lista este vida\n");
        return;
    }
    while (s->next != NULL)
    {
        if (s->val % 2 == 0)
            printf ("%d\n", s->val);
        s = s->next;
    }
}


void delete_pare (Node_s ** s)
{
    Node_s * p = (Node_s *) * s;
    Node_s * q = NULL;
    if (p == NULL)
        return;
    if (p->next == NULL)
    {
        if (p->val % 2 == 0)
        {
            p = NULL;
            (*s) = p;
        }
        return;
    }
    while (p->val % 2 == 0)
    {
        Node_s * q = p;
        p = p->next;
        q = NULL;
    }
    if (p == NULL)
        return;
    while (p->next != NULL)
    {
        q = p;
        p = p->next;
        if (p->val % 2 == 0)
        {
            q->next = p->next;
            p = q;
        }
    }
}

void read_from_file (Node_s ** s, char * file_name){
  FILE * pf = fopen (file_name, "r");
  int nr;
  Node_s * p = (Node_s * ) * s;
  do {
    fscanf (pf, "%d", &nr);
    if (p == NULL){
      p = (Node_s *) malloc (sizeof(Node_s));
      p->next = NULL;
      p->val = nr;
      (*s) = p;
    }
    else{
      Node_s * q = (Node_s *) malloc (sizeof(Node_s));
      q->next = NULL;
      q->val = nr;
      p->next = q;
      p = p->next;
    }
  }while (! feof(pf));
  fclose (pf);
}

void show_s (Node_s * s){
  printf("\n");
  if (s == NULL){
    printf("Lista este vida\n");
    return;
  }
  while (s->next != NULL){
    printf ("%d\n", s->val);
    s = s->next;
  }
}

int main (int argc, char * argv[])
{

    Node_s * start_s = NULL;

    if (argc == 1)
        printf ("\nNu a fost dat niciun argument\n");
    else
    {
        printf ("\nFisierul este %s\n", argv[1]);
        read_from_file (&start_s, argv[1]);
        show_s_pare (start_s);

        delete_pare (&start_s);
        show_s (start_s);
    }

    return 0;
}
