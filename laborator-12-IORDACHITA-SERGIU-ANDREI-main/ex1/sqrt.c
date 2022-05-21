#include <stdio.h>

float err=1e-6, n;

float radical(int ordin, float stanga, float dreapta)
{
	if (stanga >= dreapta)
		return -1;
	
    float m = (stanga + dreapta) / (float)2;
    float auxm = 1,auxo = ordin;
	
    while(auxo > 0)
    {
        auxm = auxm * m; 
        auxo--;
    }
    if(auxm <= n)
    {
        if(auxm >= n - err * 10)
            return m;
        else
            return radical(ordin, m + err, dreapta);
    }
    else
        return radical(ordin, stanga, m - err);
}

int main()
{
    int ordin=2;
	float stanga=0;
    n = 5;

    printf("sqrt(5)=2.23606797\n");

    float rezultat=radical(ordin, stanga, n);

    printf("Rezultatul este = %f\n", rezultat);

    return 0;
}