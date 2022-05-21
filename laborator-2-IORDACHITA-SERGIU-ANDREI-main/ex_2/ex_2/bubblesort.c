#include "header.h"
#include <string.h>
#include <stdio.h>

void bubblesort(char x[][5],int n)
{
    int i,schimbat;
    do {
        schimbat = 0;
        // parcurgem vectorul
        for(i = 0; i < n-1; i++) {
        // daca valoarea i din vectorul a este mai mica decat cea de pe pozitia i+1
            if (strcmp(x[i],x[i+1]) > 0) {
                char aux[5];
                // interschimbare
                strcpy(aux,x[i]);
                strcpy(x[i],x[i+1]);
                strcpy(x[i+1],aux);
                schimbat = 1;
                }
        }
    } while(schimbat);

}

