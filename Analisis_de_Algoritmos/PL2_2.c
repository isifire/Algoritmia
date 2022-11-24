#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_TALLAS 11


long int Factorial_REC(int n)
{
  if(n == 0){
    return 1;
  }

  else{
    return Factorial_REC(n-1)*n;
  }

}


long int Factorial_ITER(int n)
{
  int p = 1;
  for(int i = 0; i < n; i++){
    p=p*i;
  }
  return p;
}

int main()
{
 int i, j, talla, repite;
 double tiempo_REC, tiempo_ITER;
 clock_t tiempo_inicial_REC, tiempo_final_REC;
 clock_t tiempo_inicial_ITER, tiempo_final_ITER;


//int Vtallas[NUM_TALLAS] = { 1000, 2000, 3000, 4000, 5000, 6000, 7000, 8000};
//int Vrepite[NUM_TALLAS] = { 10, 10, 10, 10, 10, 10, 10, 10};

/////

 int Vtallas[NUM_TALLAS] = { 8000,  8500,  9000,  9500,  10000, 15000, 20000, 25000, 30000, 35000, 40000 };
 int Vrepite[NUM_TALLAS] = { 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000 };

 printf("\n\nPractica 1_2\n\n");
 printf("Tiempo empleado:\n\n\n");
 printf("\t\tTalla\t\tTiempo recursivo\t\tTiempo iterativo\n");
 printf("\t\t-----\t\t----------------\t\t----------------\n");


 for (i=0; i<NUM_TALLAS; i++)
 {
    talla  = Vtallas[i];
    repite = Vrepite[i];

    // RECURSIVO

    tiempo_inicial_REC=clock();
       for(j=0; j<repite; j++)
         Factorial_REC(talla);
    tiempo_final_REC=clock();


    // ITERATIVO


    tiempo_inicial_ITER=clock();
       for(j=0; j<repite; j++)
         Factorial_ITER(talla);
    tiempo_final_ITER=clock();

    tiempo_REC =  (tiempo_final_REC-tiempo_inicial_REC) / (double)CLOCKS_PER_SEC / repite;
    tiempo_ITER = (tiempo_final_ITER-tiempo_inicial_ITER) / (double)CLOCKS_PER_SEC / repite;

    printf("\t\t%d\t\t%f\t\t\t%f\n", talla, tiempo_REC, tiempo_ITER);

  }
  return 0;
}
