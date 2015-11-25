#include<stdio.h>
#include<stdlib.h>
#include"lst-pilha.h"

/*Função recebe duas listas encadeadas lst1 e lst2
  a função concatena as duas listas apontando do último
  elemento da lst2 para o primeiro elemento da lst1
  (Caso a lst2 seja NULL a funçao retorna a lst1).*/

Elemento* lst_concatena(Elemento* lst1,Elemento* lst2)
{
  Elemento* e;
  Pilha* p =pilha_cria();

  e = lst2;
  
  if (lst2 == NULL)
    return lst1;
  
  do
    {
      pilha_push(p, lst_acessaInfo(e));
      
      e = lst_acessaProx(e);      
    }while (e != NULL);

    lst_libera(lst2);

  while (!pilha_vazia(p))
    {
      lst1 = lst_insere(lst1, pilha_pop(p));
    }
  return lst1;
}


int main (void)
{
  Elemento* l1 = lst_cria();
  Elemento* l2 = lst_cria();

  l1 = lst_insere(l1,5);
  l1 = lst_insere(l1,4);

  l2 = lst_insere(l2,3);
  l2 = lst_insere(l2,2);
  l2 = lst_insere(l2,1);

  l1 = lst_concatena(l1,l2);

  lst_imprime(l1);
  return 0;
}
