/**********************************************************************
Tópico: ALOCAÇÃO DINÂMICA DE MEMÓRIA

Escreva a função criaVetorDeProdutosZerados, que:

- recebe um vetor de inteiros com os códigos dos produtos vendidos em uma 

loja, um vetor de inteiros com a quantidade em estoque de cada produto (onde 

estoque[i] corresponde a codigo[i]) e o número de produtos. A função também 

recebe o endereço de uma variável onde deve ser devolvido o número de 

produtos com estoque zerado;

- retorna um novo vetor (ou seja, o endereço do primeiro elemento de um novo 

vetor) de inteiros, criado com o tamanho exato necessário, apenas com os 

códigos dos produtos com estoque igual a 0. A função deve também devolver, 

numa variável cujo endereço foi recebido como parâmetro, o número de 

produtos com estoque zerado.
**********************************************************************/

#include<stdio.h>
#include<stdlib.h>

int* criaVetorDeProdutosZerados(int cod[], int qtd[], int nprod, int* nzero)
{
  int i,j;
  // vetor dos códigos dos produtos que tem quantidade zero no estoque
  int* codZero;
  
  // Ainda não possui nenhum produto com estoque zerado
  *nzero = 0;

  // encontrar o numero de produtos que faltam no estoque
  for (i = 0; i < nprod; i++)
    {
      if (qtd[i] == 0)
	*nzero = *nzero + 1;
    }
  codZero = (int*) malloc ((*nzero)*sizeof(int));

  // indice para guardar os produtos com código zero
  j = 0;
  for (i = 0; i < nprod; i++)
    {
      if (qtd[i] == 0)
	{
	  codZero[j] = cod[i];
	  j++;
	}
    }
  return codZero;
}

int main (void)
{
  int c[12] = {11,12,13,14,15,23,28,29,32,33,37,38};
  int q[12] = {2,15,0,5,0,4,15,0,0,0,1,30};
  int* vZeros;
  int num,i;
  
  vZeros = criaVetorDeProdutosZerados(c, q, 12, &num);

  printf("Existem %d produtos em falta no estoque:\n", num);
  for (i=0; i<num; i++)
    {
      printf("codigo produto:= %d\n",vZeros[i] );
    }

  free(vZeros);
  return 0;
}
