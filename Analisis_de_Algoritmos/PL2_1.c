#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define NUM_TALLAS 8

void RellenaMatriz(int **M, int n, int p)
{
   int i, j;

   for(i=0; i<n; i++)
      for(j=0; j<n; j++)
         M[i][j]=p;
}


int **CreaMatriz(int n)
{

   int **M=NULL;
   M = (int**)malloc(n*sizeof(int*));

   for(int i = 0; i < n; i++){
      M[i] = (int*)malloc(n*sizeof(int));
   }

   return M;

}


void LiberaMatriz(int **M, int n)
{
   for(int i = 0; i < n; i++){
      free(M[i]);
   }

   free(M);

}


bool Comprueba(int **A, int **B, int n)
{
   bool resultado=true;
   int i = -1;
   while((i < n-1) && resultado){
      int j=-1;
      i++;
         while((j<n-1) && resultado){
            j++;
            if(2*A[i][j] != B[i][j]){
               resultado = false;
            }
         }
   }
   return resultado;
}


int main()
{
 int i, j, talla, repite, nflops;
 int **A=NULL, **B=NULL;
 double tiempo_MC, tiempo_PC;
 clock_t tiempo_inicial_MC, tiempo_final_MC;
 clock_t tiempo_inicial_PC, tiempo_final_PC;


 int Vtallas[NUM_TALLAS] = { 1000, 2000, 3000, 4000, 5000, 6000, 7000, 8000};
 int Vrepite[NUM_TALLAS] = { 10, 10, 10, 10, 10, 10, 10, 10};

 printf("\n\nPractica 1\n\n");
 printf("Tiempo empleado:\n\n\n");
 printf("\t\tTalla\t\tTiempo MC\t\tTiempo PC\n");
 printf("\t\t-----\t\t---------\t\t---------\n");


 for (i=0; i<NUM_TALLAS; i++)
 {
    talla  = Vtallas[i];
    repite = Vrepite[i];
    nflops = talla * talla * talla;

    A=CreaMatriz(talla);
    B=CreaMatriz(talla);

    // MEJOR CASO
    RellenaMatriz(A, talla, 1);
    RellenaMatriz(B, talla, 20);
    tiempo_inicial_MC=clock();
       for(j=0; j<repite; j++)
          Comprueba(A, B, talla);
    tiempo_final_MC=clock();

    // PEOR CASO
    RellenaMatriz(A, talla, 10);
    RellenaMatriz(B, talla, 20);
    tiempo_inicial_PC=clock();
       for(j=0; j<repite; j++)
          Comprueba(A, B, talla);
    tiempo_final_PC=clock();


    tiempo_MC = (tiempo_final_MC-tiempo_inicial_MC) / (double)CLOCKS_PER_SEC / repite;
    tiempo_PC = (tiempo_final_PC-tiempo_inicial_PC) / (double)CLOCKS_PER_SEC / repite;

    printf("\t\t%d\t\t%f\t\t%f\n", talla, tiempo_MC, tiempo_PC);

    LiberaMatriz(A, talla);
    LiberaMatriz(B, talla);

    A=NULL; B=NULL;
  }
  return 0;
}
