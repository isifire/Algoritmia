#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_TALLAS 12

void RellenaMatriz(double **M, int m, int n)
{
   int i, j;

   for(i=0; i<m; i++)
      for(j=0; j<n; j++)
         M[i][j]=rand();
}


double **CreaMatriz(int m, int n)
{
   double **M=NULL;

   RellenaMatriz(M,NUM_TALLAS,NUM_TALLAS);

   return M;
}


void LiberaMatriz(double **M, int m)
{
   int i, j;

   for(i=0; i<m; i++)
      for(j=0; j<m; j++)
         M[i][j]=0;

}


void Multiplica(double **A, double **B, double **C, int n)
{
   int i, j, k;
   for(i=0; i < n; i++)
      for(j=0; j < n; j++)
         for(k=0; k < n; k++)
            C[i][j] = A[i][k] * B[k][j];
         
}


int main()
{
 int i, j, talla, repite, nflops;
 double **A=NULL, **B=NULL, **C=NULL, tiempo;
 clock_t tiempo_inicial, tiempo_final;

 int Vtallas[NUM_TALLAS] = { 25,   50,  75, 100, 125, 150, 175, 200, 225, 250, 275, 300};
 int Vrepite[NUM_TALLAS] = {1000, 500, 250, 100,  50,  40,  30,  20,  10,   5,   5,   5};

 printf("\n\nPractica 1\n\n");
 printf("Tiempo empleado:\n\n\n");
 printf("\t\tTalla\t\tTiempo\t\tGFLOPs\n");
 printf("\t\t-----\t\t------\t\t------\n");


 for (i=0; i<NUM_TALLAS; i++)
 {
    talla  = Vtallas[i];
    repite = Vrepite[i];
    nflops = talla * talla * talla;

    A=CreaMatriz(talla, talla);
    B=CreaMatriz(talla, talla);
    C=CreaMatriz(talla, talla);

    RellenaMatriz(A, talla, talla);
    RellenaMatriz(B, talla, talla);

    tiempo_inicial=clock();
       for(j=0; j<repite; j++)
          Multiplica(A, B, C, talla);
    tiempo_final=clock();

    LiberaMatriz(A, talla);
    LiberaMatriz(B, talla);
    LiberaMatriz(C, talla);
    A=NULL; B=NULL; C=NULL;

    tiempo = (tiempo_final-tiempo_inicial) / (double)CLOCKS_PER_SEC / repite;
    printf("\t\t%d\t\t%f\t%f\n", talla, tiempo, nflops/(tiempo*1.0E9));
  }
  return 0;
}
