/*
Tópico: CADEIA DE CARACTERES

-Ex1) Escreva a função contaCaracteres que:

- recebe uma cadeia (ou seja, um ponteiro para uma cadeia), e o endereço de 

três variáveis onde devem devolvidas as respostas

- devolve nas variáveis, cujos endereços foram recebidos, três valores: o número 

de caracteres especiais * ou $, o número de letras minúsculas e o número de 

letras maiúsculas.

Exemplo de cadeia de caracteres recebida: I*Love*Prog$

Resultado: Caracteres especiais: 3, Maiúsculas: 3, Minúsculas: 6

Ex2) Escreva a função obtemMes que:

- recebe uma cadeia contendo uma data no formato “06 de fevereiro de 2012” e

- retorna uma nova cadeia, alocada dinamicamente do tamanho exato necessário, 

contendo apenas o nome do mês recebido.
 */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void contaCaracteres(char cadeia[], int* nEsp, int* maiu, int* minu)
{
  int i;
  *nEsp = 0;
  *maiu = 0;
  *minu = 0;
  
  for (i=0; i< strlen(cadeia); i++)
    {
      if (cadeia[i] == '*' || cadeia[i] == '$')
	{
	  *nEsp = *nEsp + 1;
	}
      else if ( cadeia[i] >='a' && cadeia[i] <= 'z')
	{
	  *minu = *minu + 1;
	}
      else if( cadeia[i] >= 'A' && cadeia[i] <= 'Z')
	{
	  *maiu = *maiu + 1;
	}
    }
}

int main (void)
{
  char str[30] = {"I*Love*Prog$"};
  int ne, ma, mi;

  printf ("Cadeia de caracteres:= %s\n", str);
  
  contaCaracteres(str, &ne, &ma, &mi);

  printf("Numero de caracteres especiais:= %d\n", ne);
  printf("Numero de caracteres maiusculos:= %d\n", ma);
  printf("Numero de caracteres minusculos:= %d\n", mi);

  strcpy(str, "I$L0v&***T&achinG*G*$*$*");
  
  printf ("Cadeia de caracteres:= %s\n", str);
  
  contaCaracteres(str, &ne, &ma, &mi);
  
  printf("Numero de caracteres especiais:= %d\n", ne);
  printf("Numero de caracteres maiusculos:= %d\n", ma);
  printf("Numero de caracteres minusculos:= %d\n", mi);
  
  return 0;
}
