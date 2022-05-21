#include "header.h"

int bubblesort(int x[],int n,int a)
{
    int i,schimbat,aux;
    do {
        schimbat = 0;
        // parcurgem vectorul
        for(i = 0; i < n-1; i++) {
	    // daca valoarea i din vectorul a este mai mica decat cea de pe pozitia i+1
            if (x[i] < x[i+1]) {
                // interschimbare
	        aux = x[i];
		x[i] = x[i+1];
		x[i+1] = aux;
		schimbat = 1;
		a++;
	    }
        }
    } while(schimbat);

    return a;
}
