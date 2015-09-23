/**********************************************************************
Tópico: VETOR E PONTEIRO

Escreva a função obtemInicioDosAcimaDeX que 

- recebe um vetor de inteiros com as matrículas dos alunos, ordenado 

crescentemente, o número de alunos e um inteiro X

- retorna um ponteiro, ou seja, o endereço, do primeiro aluno com matrícula 

maior do que o inteiro recebido X. Caso não existam matrículas maiores que X, 

retorne NULL.
**********************************************************************/

#include<stdio.h>
#include<stdlib.h>

int* obtemInicioDosAcimaDeX (int vet[], int num, int x)
{
  int i, maior = -1;
  for (i=0; i<num; i++)
    {
      if (vet[i] > x)
	{
	  maior = i;
	  break;
	}
    }
  
  if (maior == -1)
    return NULL;
  
  return &(vet[i]);
}

//Somente necessário para ordenar
int cmpfunc (const void * a, const void * b)
{
   return ( *(int*)a - *(int*)b );
}

int main (void)
{
  int i=0;
  int *pont;
  // aluno com matrícula maior do que 2013, ou seja que ingressou depois do
  // ano de 2013  
  int x = 1300000;
  int vet[10] = {1021361, 1017288,1214288, 1516217, 928299, 1316211, 1412180,
		 1119201, 1229288, 1012214};

  printf ("busca aluno com matricula maior que %d\n", x);
  qsort(vet, 10, sizeof(int), cmpfunc);
  do
    {
      printf("mat aluno %d:= %d\n", i, vet[i]);
      i++;
    }
  while(i<10);
      
  pont = obtemInicioDosAcimaDeX (vet, 10, x);
  if (pont == NULL)
    printf("não foi encontrado nenhum aluno\n");
  else
    printf("foi retornado o endereço do aluno %d\n",*pont);
  
  return 0;
}

