// ---------------------------------------------------------------------------------
//
// ALGORITMIA: PRACTICA DE DISENIO DE ALGORITMOS RECURSIVOS
//
// Se recoge la implementacion en C del algoritmo recursivo que calcula la
// potencia n-esima de a donde a>=0 y n>=0
//
// Copyright: Nahuel Costa & Raquel Cortina
//
// Fecha: 17 de octubre de 2022
//
// ---------------------------------------------------------------------------------
//
// Completar con las tareas indicadas para el alumno en la sesion 2.1 de practicas
//
//----------------------------------------------------------------------------------


#include <stdio.h>

//
// Definiciones de funciones
//

// Potencia
int   POTENCIA(int a, int n){
  if (n==0) return 1;
  else return POTENCIA(a,n-1)*a;
}

// Potencia_detalles
int POTENCIA_entresijos(int a, int n){
int p;
if (n==0){
        printf("\tpotencia(%d,%d)\n\n",a,n);
        p=1;
        printf("\n\n CASO BASE y su resultado\n\n");
        printf("\tpotencia(%d,%d) ---> resultado = %d\n\n",a,n,p);
        printf("\n\n ASCENSO en la cadena de llamadas ... (se aplica la FUNCION de COMBINACION hasta alcanzar la llamada inicial)\n\n");
        return p;
        }
else{
    printf("\tpotencia(%d,%d)\n",a,n);
    p=POTENCIA_entresijos(a,n-1)*a;
    printf("\tpotencia(%d,%d) ---> resultado = %d\n",a,n,p);
    return p;
    }
}




//
// Definicion de las funciones a realizar por el alumno
//

// Potencia_3
// Completar por el alumno
// ...
int Potencia3(int n){
  if(n==0) return 1;
  if(n==1) return 3;
  else return 2*Potencia3(n-1) + 3*Potencia3(n-2);
}

// Potencia_3_entresijos
// Completar por el alumno
// ...
int Potencia3_entresijos(int n){
  int p;
  if(n == 0){
    printf("\tpotencia3(%d)\n\n",n);
    p = 1;
    printf("\tpotencia3(%d) ---> resultado = %d\n\n",n,p);
    printf("\n\n ASCENSO en la cadena de llamadas ... (se aplica la FUNCION de COMBINACION hasta alcanzar la llamada inicial)\n\n");
    return p;
  }
  if(n == 1){
    printf("\tpotencia3(%d)\n\n",n);
    p = 3;
    printf("\tpotencia3(%d) ---> resultado = %d\n\n",n,p);
    printf("\n\n ASCENSO en la cadena de llamadas ... (se aplica la FUNCION de COMBINACION hasta alcanzar la llamada inicial)\n\n");
    return p;
  }
  else{
    printf("\tpotencia3(%d)\n\n",n);
    p=2*Potencia3_entresijos(n-1) + 3*Potencia3_entresijos(n-2);
    printf("\tpotencia3(%d) ---> resultado = %d\n",n,p);
    return p;
  }
}
// MCD
// Completar por el alumno
// ...
int MCD(int a, int b){
  if(a==b) return a;
  if(a>b) return MCD(a-b,b);
  if(b>a) return MCD(a,b-a);
}

// MCD_entresijos
// Completar por el alumno
// ...
int MCD_entresijos(int a, int b){
int p;
if (a==b){
        printf("\tMCD_entresijos(%d,%d)\n\n",a,b);
        p=a;
        printf("\n\n CASO BASE y su resultado\n\n");
        printf("\tMCD(%d,%d) ---> resultado = %d\n\n",a,b,p);
        printf("\n\n ASCENSO en la cadena de llamadas ... (se aplica la FUNCION de COMBINACION hasta alcanzar la llamada inicial)\n\n");
        return p;
        }
if (a>b){
    printf("\tMCD_entresijos(%d,%d)\n",a,b);
    p=MCD_entresijos(a-b,b);
    printf("\tMCD(%d,%d) ---> resultado = %d\n",a,b,p);
    return p;
    }
else{
    printf("\tMCD_entresijos(%d,%d)\n",a,b);
    p=MCD_entresijos(a,b-a);
    printf("\tMCD(%d,%d) ---> resultado = %d\n",a,b,p);
    return p;
    }
}

// factorial
// Completar por el alumno
// ...
int factorial(int n){
  if (n==0) return 1;
  else return factorial(n-1)*n;
}

// numero_cifras
// Completar por el alumno
// ...
int numero_cifras(int n){
  if (n<10) return 1;
  else return numero_cifras(n/10)+1;
}

// suma_cifras
// Completar por el alumno
// ...
int suma_cifras(int n){
  if (n<10) return n;
  else return suma_cifras(n/10)+n%10;
}

// semifactorial
// Completar por el alumno
// ...
int semifactorial(int n){
  if (n==0) return 1;
  else return semifactorial(n-2)*n;
}

// fibonacci
// Completar por el alumno
// ...
int fibonacci(int n){
  if (n==0) return 0;
  if (n==1) return 1;
  else return fibonacci(n-1)+fibonacci(n-2);
}

// contar_pares_vector
// Completar por el alumno
// ...
int contar_pares_vector(int v[], int n){
  if (n==0) return 0;
  else if (v[n-1]%2==0) return contar_pares_vector(v,n-1)+1;
  else return contar_pares_vector(v,n-1);
}

// contar_coincidencias_matriz
// Completar por el alumno
// ...

int contar_coincidencias_matriz(int M[4][4], int n){
  if (n==0) return 1;
  else if (M[n-1][n-1]==M[4-n][4-n]){
    return simetria_matriz(M,n-1)+1;
  }

}

// [OPCIONAL] suma_vector
// Completar por el alumno
// ...
int suma_vector(int v[], int n){
  if (n==0) return 0;
  else return suma_vector(v,n-1)+v[n-1];
}

// [OPCIONAL] simetria_matriz
// Completar por el alumno
// ...

int simetria_matriz(int M[4][4], int n){
  if (n==0) return 1;
  else if (M[n-1][n-1]!=M[4-n][4-n]) return 0;
  else return simetria_matriz(M,n-1);
}


//
// Programa principal
//
int main() {
 int n,a;

  printf("\t\t CALCULO LA POTENCIA n-ESIMA DE UN NUMERO\n\n");

 // leer la base
 do{
 printf(" Introduce la base a (a>=0): ");
 scanf("%d",&a);
 } while(a<0);

 // leer el exponente
 do{
 printf(" Introduce el exponente n (n>=0): ");
 scanf("%d",&n);
 } while(n<0);

 printf("\n\n");
 printf(" --------\n");
 printf(" POTENCIA\n");
 printf(" --------\n");

 printf(" La potencia %d-esima de %d es: %d \n\n\n", n, a, POTENCIA(a,n));

 printf(" ---------------------------------------------\n");
 printf(" POTENCIA mostrando el funcionamiento interno \n");
 printf(" ---------------------------------------------\n");

 printf(" \n Se muestra el proceso interno: sucesivas llamadas a la funcion, resultado en el caso base y \n");
 printf(" resultados parciales hasta alcanzar el resultado final");

 printf("\n\n\n DESCENSO en la cadena de llamadas ... (se aplica la FUNCION SUCESOR hasta alcanzar caso base)\n\n");

 printf("\n\nLa potencia %d-esima de %d es: %d \n\n", n, a, POTENCIA_entresijos(a,n));


 // Invocacion de las funciones a realizar por el alumno

 // Invocaciones de las funciones potencia_3 y potencia_3_entresijos
 // Completar por el alumno
 // ...
printf("La potencia 3 de 3 es: %d\n",Potencia3(3));
Potencia3_entresijos(3);

 // Invocaciones de las funciones MCD y MCD_entresijos
 // Completar por el alumno
 // ...
printf("el mcd de 10 y 14 es: %d\n",MCD(10,14));
MCD_entresijos(10,14);

 // Invocaciones de las funciones: factorial, numero_cifras, suma_cifras, semifactorial y fibonacci
 // Completar por el alumno
 // ...
printf("El factorial de 4 es: %d\n",factorial(4));
printf("El n de cifras de 198 es: %d\n",numero_cifras(198));
printf("La suma de cifras de 123 es: %d\n",suma_cifras(123));
printf("El semifactorial de 4 es: %d\n",semifactorial(4));
printf("El fibonacci de 5 es: %d\n",fibonacci(5));

 // Invocaciones de las funciones: contar_pares_vector y contar_coincidencias_matriz
 // Completar por el alumno
 // ...
 int vector[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20};
 printf("El n de pares del vector es de: %d\n",contar_pares_vector(vector,20));
 printf("La suma del vector es: %d\n",suma_vector(vector,16));

 int matrix[4][4] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
 printf("n veces matriz: %d\n",contar_coincidencias_matriz(matrix,4));
 printf("La matriz es simetrica 1/si 0/no: %d",simetria_matriz(matrix,4));

 printf("\n\n UO285039 - ISIDRO BENITEZ ZAPICO");


 return 0;
}
