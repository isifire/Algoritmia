import numpy             as np
import matplotlib.pyplot as plt

from random import random     
from time   import time

def CreaListaAlea(m, n):
   C = []
   for i in range(m):
      a = [0.0]*n
      for j in range(n):
         a[j] = random()
      C.append(a)
   return C

def CreaListaZeros(m, n):
   C = []
   for i in range(m):
      a = [0.0]*n
      C.append(a)
   return C

def NaiveListas(n, A, B):
  C = CreaListaZeros(n, n)

  for i in range(n):
    for j in range(n):
      for p in range(n):
        C[i][j] = C[i][j]+A[i][p]*B[p][j]
  return C


def NaiveNumpy(n, A, B):
  C = np.zeros((n, n), order='C', dtype=np.float64)

  for i in range(n):
    for j in range(n):
      for p in range(n):
        C[i,j] = C[i,j]+A[i,p]*B[p,j]
  return C


talla=[ 25,  50, 75, 100, 125, 150, 175, 200, 225, 250, 275, 300]
rept =[200, 100, 50,  20,  10,   8,   6,   4,   2,   1,   1,   1]

Eje_YTeori = np.zeros(len(talla), dtype=np.float64)
Eje_YLista = np.zeros(len(talla), dtype=np.float64)
Eje_YNumpy = np.zeros(len(talla), dtype=np.float64)

for i in range(0,len(talla)):
   n=talla[i]
   nflops=n*n*n

   AListas = CreaListaAlea(n, n)
   BListas = CreaListaAlea(n, n)

   ANumpy = np.random.rand(n, n).astype(np.float64)
   BNumpy = np.random.rand(n, n).astype(np.float64)

   secs = time()
   for j in range(rept[i]):
     C=NaiveListas(n, AListas, BListas) 
   Eje_YLista[i] = (time()- secs)/rept[i]

   gflops = nflops/(Eje_YLista[i]*1.0E+09);
   print(f"NaiveListas {n}x{n}x{n} Segundos={Eje_YLista[i]:1.5E}, GFlops={gflops:1.5E}")

   secs = time()
   for j in range(rept[i]):
     C=NaiveNumpy(n, ANumpy, BNumpy)
   Eje_YNumpy[i] = (time()- secs)/rept[i]

   gflops = nflops/(Eje_YNumpy[i]*1.0E+09);
   print(f"NaiveNumpy  {n}x{n}x{n} Segundos={Eje_YNumpy[i]:1.5E}, GFlops={gflops:1.5E}")

   Eje_YTeori[i] = nflops

Promedio_Listas_vs_Numpy=np.mean(Eje_YNumpy / Eje_YLista)
Promedio_Listas_vs_Teori=np.mean(Eje_YTeori / Eje_YLista)

Ajuste_Numpy =Eje_YLista * Promedio_Listas_vs_Numpy
Ajuste_Teori =Eje_YLista * Promedio_Listas_vs_Teori

print(f"Numpy   es Listas multiplicado por {Promedio_Listas_vs_Numpy:1.5E}")
print(f"Teorico es Listas multiplicado por {Promedio_Listas_vs_Teori:1.5E}")

plt.plot(talla, Eje_YNumpy,         color='xkcd:green')
plt.plot(talla, Ajuste_Numpy, 'o-', color='xkcd:red')
plt.title('Numpy vs Listas*cte')
plt.show()

plt.plot(talla, Eje_YTeori,         color='xkcd:green')
plt.plot(talla, Ajuste_Teori, 'o-', color='xkcd:red')
plt.title('Teorico vs Listas*cte')
plt.show()
