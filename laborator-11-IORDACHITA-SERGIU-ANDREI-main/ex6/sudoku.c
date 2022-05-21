#include <stdio.h>
 
void rezultat(int m[9][9])
{
     for (int i = 0; i < 9; i++)
     {
        for (int j = 0; j < 9; j++)
            printf("%d ",m[i][j]);
         printf("\n");
     }
}
 
int verificare(int m[9][9], int linie, int coloana, int num)
{
    for (int x = 0; x <= 8; x++)
        if (m[linie][x] == num)
            return 0;
 
    for (int x = 0; x <= 8; x++)
        if (m[x][coloana] == num)
            return 0;

    int startLinie = linie - linie % 3, startColoana = coloana - coloana % 3;
   
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (m[i + startLinie][j + startColoana] == num)
                return 0;
 
    return 1;
}
 
int rezolvareSuduko(int m[9][9], int linie, int coloana)
{
    if (linie == 9 - 1 && coloana == 9)
        return 1;
 
    if (coloana == 9)
    {
        linie++;
        coloana = 0;
    }
   
    if (m[linie][coloana] > 0)
        return rezolvareSuduko(m, linie, coloana + 1);
 
    for (int num = 1; num <= 9; num++)
    {
        if (verificare(m, linie, coloana, num)==1)
        {
            m[linie][coloana] = num;
           
            if (rezolvareSuduko(m, linie, coloana + 1)==1)
                return 1;
        }
       
        m[linie][coloana] = 0;
    }

    return 0;
}
 
int main()
{
    
    int m[9][9] = { { 5, 3, 0, 0, 7, 0, 0, 0, 0 },
                    { 6, 0, 0, 1, 9, 5, 0, 0, 0 },
                    { 0, 9, 8, 0, 0, 0, 0, 6, 0 },
                    { 8, 0, 0, 0, 6, 0, 0, 0, 3 },
                    { 4, 0, 0, 8, 0, 3, 0, 0, 1 },
                    { 7, 0, 0, 0, 2, 0, 0, 0, 6 },
                    { 0, 6, 0, 0, 0, 0, 2, 8, 0 },
                    { 0, 0, 0, 4, 1, 9, 0, 0, 5 },
                    { 0, 0, 0, 0, 8, 0, 0, 7, 9 } };
 
    if (rezolvareSuduko(m, 0, 0)==1)
        rezultat(m);
    else
        printf("Niciun rezultat - sfarsitul jocului!");
 
    return 0;

}