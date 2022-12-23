//
// ALGORITMIA: PRACTICA DE DIVIDE Y VENCERAS
//
// MAXIMO_VECTOR - PRODUCTO_VECTOR - EXAMEN RECURSION NOVIEMBRE 2020
//
// Copyright: Nahuel Costa & Raquel Cortina
//
// Fecha: 11 de noviembre de 2022
//
// -----------------------------------------------------------------------------------------------------------------------------------------------------
//
// TAREAS.-
//
// Programa en el que se pide el tamanio del vector (n>=1), se reserva dinamicamente memoria,
// se leen sus elementos. Los elementos se muestran por pantalla y seguidamente, a traves de las funciones
// MAXIMO_VECTOR y PRODUCTO_VECTOR, que deben seguir el esquema de divide y venceras, se buscará el elemento de mayor
// valor en el vector y se calculará el producto de los elementos del vector respectivamente.
//
// Programa en el que se pide el numero de filas y de columnas de la matriz (n,m>=1), se reserva dinamicamente memoria,
// se leen sus elementos. Los elementos se muestran por pantalla y seguidamente, a traves de la funcion
// EXAMEN_RECURSION_NOVIEMBRE_2020, que debe seguir el esquema de divide y venceras, se resolverá el problema 1 del examen del tema 2 (curso 2020/2021):
//
// "Dada una matriz de enteros A[1..n][1..m] siendo n≥1 y m≥1, diseñar una función recursiva que retorne cierto si se cumple que
//  todo elemento de la matriz es el doble del elemento situado a su izquierda, y falso en caso contrario"
//
//--------------------------------------------------------------------------------------------------------------------------------------------------------


#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// prototipos de funciones maximo y producto
int lee_vector(int *, int);
int escribe_vector(int *, int);
int maximo_vector_DyV(int *,int,int);
int producto_vector_DyV(int *,int,int);

// prototipos de la funcion EXAMEN RECURSION NOVIEMBRE 2020 y funciones auxiliares
void lee_matriz (int **, int, int);
void escribe_matriz (int **, int, int);
bool EXAMEN_RECURSION_NOVIEMBRE_2020 (int **, int, int, int);
bool interseccion_columnas(int **M, int mitad, int m);

// programa principal
int main() {

    int n,m,x;
    int *V;

    do{
       printf("\nIntroduce el numero de elementos del vector para obtener el maximo y el producto (>=1): ");
       scanf("%d",&n);} while (n<1);

    // reservar dinamicamente memoria
    V = (int*) malloc(n*sizeof(int));


    lee_vector(V,n);
    escribe_vector (V,n);

    printf("\nEl maximo de los elementos del vector es %d\n\n",maximo_vector_DyV(V,0,n-1));
    printf("\nEl producto de los elementos del vector es %d\n\n",producto_vector_DyV(V,0,n-1));

    //liberar memoria
    free(V);

    // EXAMEN RECURSION NOVIEMBRE 2020

    printf("Dame el numero de filas: ");
    scanf("%d",&n);
    printf("Dame el numero de columnas: ");
    scanf("%d",&m);

    // definimos una variable de tipo puntero a puntero a int y reservamos memoria para n filas
    int **M = (int**) malloc(n*sizeof(int*));

    //reservamos espacio para las columnas
    for(int i=0;i<n;i++)
            M[i] = (int*) malloc(m*sizeof(int));

    // Leemos la matriz
    lee_matriz (M,n,m);


    printf("\n\nLa matriz introducida es:\n\n");

    // Mostramos el contenido de la matriz
    escribe_matriz (M,n,m);

    //Invocamos a la funcion que comprueba
      if (EXAMEN_RECURSION_NOVIEMBRE_2020(M,n,0,m-1)) printf("Si se cumple que todo elemento de la matriz es el doble del elemento situado a su izquierda\n\n");
      else printf("No se cumple que todo elemento de la matriz es el doble del elemento situado a su izquierda\n\n");

    // Liberamos el espacio reservado para las columnas
    for (int i=0;i<n;i++) free(M[i]);

    // Liberamos el espacio reservado para las filas
    free(M);

    return 0;
}

//
// Definiciones de funciones
//

// Funcion para leer las componentes del vector
int lee_vector(int *V, int n){
    for (int i=0;i<n;i++) {
        printf("\nDame el valor de la componente %d: ",i+1);
    scanf("%d",V+i);
    }
    return 0;
}

// Funcion para escribir las componentes del vector
int escribe_vector(int *V, int n){
    printf("\nEl vector introducido es: [ ");
    for (int i=0;i<n;i++) {
        printf("%d ",*(V+i));
    }
    printf("]\n");
    return 0;
}


void lee_matriz (int **M, int n, int m){
    int i,j;
    for (i=0;i<n;i++)
        for (j=0;j<m;j++){
            printf("Dame el elemento [%d,%d] :  ",i+1,j+1);
            scanf("%d",&M[i][j]);
            // otra opcion
            //scanf("%d",M[i]+j);
            // y otra opcion
            //scanf("%d",*(M+i)+j);
        }
    }

void escribe_matriz (int **M, int n, int m){
    int i,j,aux;
    for (i=0;i<n;i++)
    {
        for (j=0;j<m;j++){
            printf("%d\t",M[i][j]);
            // otra opcion
            //printf("%d\t",*(M[i]+j));
            // y otra opcion
            //printf("%d\t",*(*(M+i)+j));
        };
    printf("\n\n");
    }
}


// Funcion que proporciona el maximo del vector siguiendo el esquema de Divide y Venceras

int maximo_vector_DyV(int *V, int inicio, int fin){
int m, max1, max2, max;

if (inicio == fin ) return V[inicio];
else {
      // dividir
      m=(inicio+fin)/2;

      // resolver
      max1=maximo_vector_DyV(V,inicio,m);
      max2=maximo_vector_DyV(V,m+1,fin);


      // combinar
    if(max1 > max2){
        max = max1;
    }

    else{
        max = max2;
    }

    return max;

    }
}


// Funcion que proporciona el producto de los elementos del vector siguiendo el esquema de Divide y Venceras
int producto_vector_DyV(int *V, int inicio, int fin){

int m, p1, p2, p;

if (inicio == fin ) return V[inicio];
else {
      // dividir
      m=(inicio+fin)/2;

      // resolver
      p1=producto_vector_DyV(V,inicio,m);
      p2=producto_vector_DyV(V,m+1,fin);


      // combinar
      p = p1 * p2;


    return p;

    }


}

bool exaAux(int **M, int n, int inicio_columnas, int fin_columnas){
    if(2*M[n][inicio_columnas] == M[n][inicio_columnas+1]){
        return true;
    }
    else{
        return false;
    }
}



// Funcion que soluciona el problema 1 del examen del tema 2, siguiendo el esquema de Divide y Venceras
bool EXAMEN_RECURSION_NOVIEMBRE_2020(int **M, int n, int inicio_columnas, int fin_columnas){
    int d,d1,d2;
    bool b = false;
    if(inicio_columnas == fin_columnas){
        return true;
    }

 

    d = (fin_columnas+inicio_columnas)/2;

    d1 = EXAMEN_RECURSION_NOVIEMBRE_2020(M,n,inicio_columnas,d);
    d2 = EXAMEN_RECURSION_NOVIEMBRE_2020(M,n,d+1,fin_columnas);
  

    return d1 && d2 && interseccion_columnas(M,n,d);
    
}



bool interseccion_columnas(int **M,int n, int mitad){
    int i;
    bool resultado = true;
    i = -1;
    while(i < n-1 && resultado){
        i++;
        if(2*M[i][mitad] != M[i][mitad+1]){
            resultado = false;
        }
    }
    return resultado;
}
