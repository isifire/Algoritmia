// ---------------------------------------------------------------------------------
//
//  ALGORITMIA: IMPLEMENTACION SEGUN BACKTRACKING DE LA SOLUCI�N DEL PROBLEMA DE
//              DESCOMPONER
//              UN NUMERO N EN M SUMANDOS CON N>=M>0 DE TAL MODO QUE LOS M SUMANDOS
//              SUMEN N Y SU PRODUCTO SEA MAXIMO. SE GENERAR�N ADEMAS: TODAS LAS
//              SOLUCIONES FACTIBLES Y LA PRIMERA FACTIBLE.
//
//
//  SESION 3.3 DE PRACTICAS (ESQUEMAS ALGORITMICOS - BACKTRACKING)
//
//  Copyright: Nahuel Costa & Raquel Cortina
//
//  Fechas: del 28 de noviembre al 2 de diciembre de 2022
//
// ----------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include <stdbool.h>

// prototipos de las funciones backtracking
void DESCOMPONER_BACK_TODAS(int , int , int , int *);
void DESCOMPONER_BACK_UNA(int , int , int , int *, bool *);
void DESCOMPONER_BACK_OPTIMA(int , int , int , int *, int *, int *);

// prototipos de las funciones auxiliares que utiliza backtracking: correcto, valor, tratar



// funcion main
int main(){
int N,M;
int *x,*x_mejor,v_mejor;
bool flag;

do{
   printf ("\nIntroduce el numero a descomponer: ");
   scanf("%d",&N);
}while(N<=0);

do{
   printf ("\nIntroduce el numero de sumandos: ");
   scanf("%d",&M);
}while(M>N);

//
// Los vectores x y x_mejor tienen tama�o M+1
//

x=(int*)malloc((M+1)*sizeof(int));
x_mejor=(int *)malloc((M+1)*sizeof(int));

// invocamos a TODAS_LAS_FACTIBLES de BACKTRACKING
printf("\n\nTODAS LAS SOLUCIONES FACTIBLES\n");
DESCOMPONER_BACK_TODAS(N,M,1,x);

// invocamos a UNA_FACTIBLE de BACKTRACKING
printf("\n\nUNA TUPLA FACTIBLE:\n");
flag=true;
DESCOMPONER_BACK_UNA(N,M,1,x,&flag);

// invocamos a OPTIMA de BACKTRACKING
printf("\n\nSOLUCION OPTIMA:\n");
v_mejor=INT_MIN;
DESCOMPONER_BACK_OPTIMA(N,M,1,x,x_mejor,&v_mejor);

// mostrar la solucion (secuencia de decisiones optima y beneficio maximo)
tratar(x_mejor,M);
printf("\t\tEl producto maximo de la descomposicion es: %d\n", v_mejor);

// liberar memoria
free(x);
free(x_mejor);

return 0;
}


//
// BACKTRACKING
//

// definiciones de las funciones auxiliares que utiliza backtracking: correcto, valor y tratar
// TAREA A REALIZAR POR EL ALUMNO

int suma(int *x,int k){
int i, total=0;
for (i=1;i<=k;i++){ // RQL: desde 1, no desde 0, de ahi que no saliera nada
   total=total+x[i];
  }
return total;
}

void tratar(int *x, int M){
    int i;
    printf("\n<");
    for(i=1;i<=M;i++){
        printf("%d ",x[i]);
    }
    printf(">");
}

int valor(int *x,int n){
int i, total=1;
for (i=1;i<=n;i++){
   total=total*x[i];
  }
return total;
}


void DESCOMPONER_BACK_TODAS(int N, int M, int k, int *x){

x[k] = 0;
   while(x[k] < N-M+1){
         x[k]++;
         if(k==M && suma(x,k) == N) tratar(x,M);
         if(k<M && suma(x,k)<N) DESCOMPONER_BACK_TODAS(N,M,k+1,x);
   }

}

void DESCOMPONER_BACK_UNA(int N, int M, int k, int *x, bool *flag){

x[k] = 0;
   while(x[k] < N-M+1 && *flag == true){
         x[k]++;
         if(k==M && suma(x,k) == N){
            *flag=false;
            tratar(x,M);
         }
         if(k<M && suma(x,k)<N) DESCOMPONER_BACK_UNA(N,M,k+1,x,flag);
   }




}


void DESCOMPONER_BACK_OPTIMA(int N, int M, int k, int *x, int *x_mejor, int *v_mejor){
int aux;
x[k] = 0;
   while(x[k] < N-M+1){
         x[k]++;
         if(k==M && suma(x,k) == N){
            aux=valor(x,k);
            if(aux > *v_mejor){
               //*v_mejor = suma(x,k);
               *v_mejor = aux; //RQL: es la razon por la que no daba el producto maximo
               memcpy(x_mejor,x,(M+1)*sizeof(int));
            }
         }
         if(k<M && suma(x,k)<N) DESCOMPONER_BACK_OPTIMA(N,M,k+1,x,x_mejor,v_mejor);
   }



}

