#include <stdio.h>

int n, sol[100], num;

void produscartezian (int v[], int k)
{
	int i;
	if (k == n + 1)
    {
		for (i = 1; i <= n; i++)
			printf("%d",sol[i]);
        printf("\n");
	}
	else 
    {
		int counter = 0;
		sol[k] = v[counter];
		while (counter < num)
        {
			sol[k] = v[counter];	
			counter ++;
			produscartezian (v, k + 1); 
		}
		
	}

}

int main ()
{  
    n = 3;
    int v[3] = {1,5,3};
    num = 3;
    produscartezian (v, 1);

    return 0;
}


