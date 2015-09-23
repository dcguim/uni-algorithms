/**********************************************************************
Tópico: PONTEIRO

1. Implemente a função calc_circulo, que calcula a área e a circunferência de um círculo de 

raio r. Essa função deve obedecer o seguinte protótipo:

void	calc_circulo(float	r,	float	*	circunferencia,	float	*	area);

Fórmulas e constantes:

Área = πr

Circunferência = 2πr

π =3.14159265

Implemente um programa que teste essa função.

2. Escreva a função obtemMaiorMenor que 

- recebe um vetor de inteiros com números aleatórios e a quantidade de números 

- retorna o maior e o menor número encontrados neste vetor.

Implemente um programa que teste essa função. Considere que não existem 2 números 

iguais.
**********************************************************************/

#include<stdio.h>

#define pi 3.14159

void calc_circulo(float r, float* circunferencia, float* area)
{
  *circunferencia = 2*pi*r;
  *area = pi*r*r;
}

void obtemMaiorMenor(int vet[], int tam, int* maior, int* menor)
{
  int i;
  if (tam > 0)
    {
      *maior = vet[0];
      *menor = vet[0];

      for (i = 0; i < tam; i++)
	{
	  if (vet[i] > *maior)
	    *maior = vet[i];
	  
	  if (vet[i] < *menor)
	    *menor = vet[i];
	}
    }
}

int main (void)
{
  int maior, menor, raio = 8;
  float circ, area;
  int v[8] = {15,13,-5,89,13,-30,7,3};
  
  calc_circulo(raio, &circ, &area);
  printf("circunferencia: %f area %f\n", circ, area);

  obtemMaiorMenor(v, 8, &maior, &menor);
  printf("maior:%d menor:%d\n", maior, menor);
  
  return 0;
}
