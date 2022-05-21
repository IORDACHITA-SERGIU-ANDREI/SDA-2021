#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct
{
    char * nume;
    char * prenume;
    char id[6];
    double note[5];

} student;


double generateRandomDouble(double n_min, double n_max)
{
    double nr = (double) rand() / ((double) RAND_MAX + 1);
    return (n_min + nr*(n_max - n_min));
}

void afisare(student *s, int nr_s)
{
    for (int i = 0; i < nr_s; i++)
    {
        printf("n : %s, \tp : %s, \tid : %s, \tnote : ", s[i].nume, s[i].prenume, s[i].id);
        for (int j = 0; j < 5; j ++)
            printf("%.2lf\t",s[i].note[j]);
        printf("\n");
    }
}

void restantieri(student * s, int nr_s)
{
    FILE *f = fopen ("restantieri.txt", "wt");
    if(f==NULL)
        printf("Fisierul nu se poate deschide");
    int nr_t_r = 0;
    for(int i = 0; i < nr_s; i++)
    {
        int nr_r = 0;
        for(int j = 0; j < 5; j ++)
            if (s[i].note[j] < 5)
                nr_r ++;
        nr_t_r += nr_r;
        if(nr_r >= 1)
            fprintf(f, "id: %s \tn: %s \tp: %s \tnr: %d\n", s[i].id, s[i].nume, s[i].prenume, nr_r);
    }
    fprintf(f, "Nr. Total de restante: %d", nr_t_r);
    fclose(f);
}


int v_stergere(student * s, int nr_s)
{
    int s_r = 0, z, i = 0;
    while( i < nr_s - s_r)
    {
        int restantier = 0;
        for(int j = 0; j < 5; j++)
            if (s[i].note[j] < 5)
            {
                restantier = 1;
                break;
            }
        s_r += restantier;
        for(z = i; restantier == 1 && z < nr_s - 1; z++)
        {
            strcpy(s[z].nume, s[z + 1].nume);
            strcpy(s[z].prenume, s[z + 1].prenume);
            strcpy(s[z].id, s[z + 1].id);
            for (int k = 0; k < 5; k++)
                s[z].note[k] = s[z + 1].note[k];
        }
        if(!restantier)
            i++;
    }
    if (nr_s - s_r == 0)
    {
        printf("Toti studentii sunt restantieri\n");
        for(i = 0; i < nr_s; i++)
        {
            free(s[i].nume);
            free(s[i].prenume);
        }
        nr_s = 0;
        free(s);
        s = NULL;
    }
    else
    {
        s = (student *) realloc (s, (nr_s - s_r) * sizeof(student));
        nr_s -= s_r;
        afisare(s, nr_s);
    }
    return nr_s;
}


void v_adaugare(student * s, int nr_s, int poz, student st)
{
    if (nr_s == 0)
    {
        s = (student * ) malloc (sizeof(student));
        if (poz != 0 )
            poz = 0;
    }
    else
        s = (student *) realloc(s, (nr_s + 1) * sizeof(student));
    s[nr_s].nume = (char *)malloc(sizeof(char) * 20);
    s[nr_s].prenume = (char *)malloc(sizeof(char) * 20);
    nr_s ++;
    for (int i = nr_s - 1; i > poz; i--)
    {
        strcpy(s[i].nume, s[i - 1].nume);
        strcpy(s[i].prenume, s[i - 1].prenume);
        strcpy(s[i].id, s[i - 1].id);
        for (int k = 0; k < 5; k++)
            s[i].note[k] = s[i - 1].note[k];
    }
    strcpy(s[poz].nume, st.nume);
    strcpy(s[poz].prenume, st.prenume);
    strcpy(s[poz].id, st.id);
    for (int k = 0; k < 5; k++)
        s[poz].note[k] = st.note[k];
    afisare(s, nr_s);
}

int main()
{
    student * s;
    int nr_s, i, poz;
    student st;
    st.nume = (char *) malloc (sizeof(char) * 20);
    st.prenume = (char *) malloc (sizeof(char) * 20);

    printf ("Cati studenti?:\n");
    scanf ("%d", &nr_s);
    printf ("Nr de studenti citit este %d \n", nr_s);


    char v_nume[4][12] = {"Dinu", "Popescu", "Ionescu", "Georgescu"};
    char v_prenume[4][12] = {"Diana", "Maria", "Darius", "Catalin"};
    char v_id[8][6] = {"id001", "id002", "id003", "id004", "id005", "id006", "id007", "id008"};
    int * viz = (int * )calloc(nr_s, sizeof(int));

    s = (student * ) malloc (nr_s * sizeof(student));
    for (i = 0; i < nr_s; i++ )
    {
        s[i].nume = (char * ) malloc (20);
        s[i].prenume = (char *) malloc (20);

        int i_nume = rand() % 4;
        int i_prenume = rand() % 4;
        int verif = 0;
        int no = rand() % nr_s;
        while(viz[no] == 1)
        {
            no = rand() % nr_s;
        }
        strcpy(s[i].id, v_id[no]);
        viz[no] = 1;

        for(int j = 0; j < i && verif == 0; j++ )
        {
            if (strcmp(s[j].nume, v_nume[i_nume]) == 0 && strcmp (s[j].prenume,v_prenume[i_prenume]) == 0)
            {
                verif = 1;
            }
        }
        while (verif == 1)
        {
            if(verif == 1)
            {
                i_nume = rand() % 4;
                i_prenume = rand() % 4;
            }
            verif = 0;
            for(int j = 0; j < i && verif == 0; j++ )
            {
                if (strcmp(s[j].nume, v_nume[i_nume]) == 0 && strcmp (s[j].prenume,v_prenume[i_prenume]) == 0)
                {
                    verif = 1;
                }
            }
        }
        strcpy (s[i].nume, v_nume[i_nume]);
        strcpy (s[i].prenume, v_prenume[i_prenume]);

        for (int j = 0; j < 5; j++)
            s[i].note[j] = generateRandomDouble(1, 10);
    }
    afisare(s, nr_s);

    restantieri(s, nr_s);

    printf("\n");
    // prin generarea notelor random, toti studentii sunt restantieri
    // asa ca am initializat manual unul integralist
    for (int j = 0; j < 5; j ++)
        s[0].note[j] = 10;
    nr_s = v_stergere(s, nr_s);

    strcpy(st.nume, "Marinescu");
    strcpy(st.prenume, "Alexandru");
    strcpy(st.id, "id009");
    for (int i = 0; i < 5; i++)
    {
        st.note[i] = generateRandomDouble(1, 10);
    }
    printf ("\nPe ce pozitie adaug?\n");
    scanf ("%d", &poz);
    if(poz > nr_s)
        poz = nr_s;
    printf("\n");
    v_adaugare(s, nr_s, poz, st);

    nr_s ++;

    for(i = 0; i < nr_s; i++)
    {
        free(s[i].nume);
        free(s[i].prenume);
    }
    free(s);

    return 0;
}
