#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Node_s
{

    int val;
    struct Node_s * next;

} Node_s;

void read_from_file (Node_s ** s, char * file_name)
{
    FILE * pf = fopen (file_name, "r");
    int nr;
    Node_s * p = (Node_s * ) * s;
    do
    {
        fscanf (pf, "%d", &nr);
        if (p == NULL)
        {
            p = (Node_s *) malloc (sizeof(Node_s));
            p->next = NULL;
            p->val = nr;
            (*s) = p;
        }
        else
        {
            Node_s * q = (Node_s *) malloc (sizeof(Node_s));
            q->next = NULL;
            q->val = nr;
            p->next = q;
            p = p->next;
        }
    }
    while (! feof(pf));
    fclose (pf);
}


void show_s (Node_s * s)
{
    printf("\n");
    if (s == NULL)
    {
        printf("Lista este vida\n");
        return;
    }
    while (s->next != NULL)
    {
        printf ("%d\n", s->val);
        s = s->next;
    }
}

void delete_x (Node_s ** start, int x)
{
    Node_s * head = (Node_s *) * start;
    Node_s * prev = NULL;
    if (head->val == x)
    {
        (*start) = (*start)->next;
        free(head);
        return;
    }
    int nr = 0;
    while (head != NULL)
    {
        prev = head;
        head = head->next;
        if (head->val == x)
        {
            nr = 1;
            break;
        }
    }
    if (nr )
    {
        prev->next = head->next;
        free(head);
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
        show_s (start_s);
        int x;
        printf("\nVal x = ");
        scanf("%d", &x);
        delete_x (&start_s, x);
        show_s (start_s);
    }

    return 0;
}

