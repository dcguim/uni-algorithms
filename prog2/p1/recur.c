/**********************************************************************
Tópico: RECURSÃO

Ex1) Escreva a função recursiva contaCaracter que

- recebe uma cadeia (ou seja, um ponteiro para uma cadeia) e um determinado 

caracter

- retorna o número de ocorrências desse caracter na cadeia

Ex2) Escreva a função recursiva transformaEmMaiúsculas que

- recebe uma cadeia (ou seja, um ponteiro para uma cadeia) e 

- substitui toda ocorrência de letra minúscula na cadeia pela equivalente em 

maiúsculo, modificando a palavra original.

Ex3) Escreva uma função recursiva ComparaPalavra que

- recebe duas cadeias de caracteres e

- retorna 1 se elas são iguais ou 0 se são diferentes

Ex4) Escreva uma função recursiva ImprimeMinusculasMaiusculas que

- recebe uma cadeia de caracteres e

- imprime os caracteres minúsculos em maiúsculos e vice-versa

Exemplo: 

Cadeia recebida: fLaMeNgO campeao

Cadeia impressa: FlAmEnGo CAMPEAO

Ex5) Escreva uma função recursiva ImprimeMinusculasMaiusculasInvertida que

- recebe uma cadeia de caracteres e

- imprime de trás para frente a cadeia recebida além de transformar os caracteres 

minúsculos em maiúsculos e vice-versa

Exemplo: 

Cadeia recebida: oaepmac OGNEMALF

Cadeia impressa: flamengo CAMPEAO
**********************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int contaCaracter(char* cad, char car)
{
  if (strlen(cad) == 0)
    return 0;
  else if (cad[0] == car)
    return 1 + contaCaracter(&(cad[1]), car);
  else
    return contaCaracter(&(cad[1]),car);
}

void transformaEmMaiusculas(char* cad)
{// caso base
  if (strlen(cad) == 0)
    return;
  
  // passo indutivo
  if (cad[0] >= 'a' && cad[0] <= 'z')
    // transforma de minuscula pra maiuscula
    cad[0] = cad[0] - ('a'-'A');
  else if  (cad[0] >= 'A' && cad[0] <= 'Z')
    // transforma de maiuscula pra minuscula
    cad[0] = cad[0] + ('a'- 'A');
  
  return transformaEmMaiusculas(&(cad[1]));
}

int comparaPalavras (char* cad1, char* cad2)
{
  // Se as palavras tem tamanhos diferentes entao sao diferentes
  if (strlen(cad1) != strlen(cad2))
    return 1;
  else if (strlen(cad1) == 0 && strlen(cad2) == 0)
    //caso base
    return 0;
  
  if (cad1[0] != cad2[0])
    return 1;
  else// passo indutivo
    return comparaPalavras(&(cad1[1]),&(cad2[1]));
    
}

int main(void)
{
  int num;
  char str1[] = {"L’amore vero vuole il bene dell’amato."};
  char str2[] = {"FunNy StRinG witH mIXed uPPer and LoWeR case"};
  char ch = 'o';
  
  num = contaCaracter(str1, ch);
  printf ("O caracter `%c` repete %d vezes na frase:\n%s\n\n", ch, num, str1);
  
  transformaEmMaiusculas(str2);
  printf ("Frase trasformada:=%s\n", str2);

  printf("%d\n", comparaPalavras("abc", "abcd"));
  printf("%d\n", comparaPalavras("abcd", "abcd"));
  printf("%d\n", comparaPalavras("a", "bcd"));
  printf("%d\n", comparaPalavras("a-vv-v", "a-vv-v-"));
  printf("%d\n", comparaPalavras("a-vv-v", "a-vv-v"));
  
  return 0;
}
