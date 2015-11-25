#include<stdio.h>
#include<stdlib.h>
#include"lst-pilha.h"

struct elemento{
  int info;
  struct elemento *prox;
};

struct pilha {
 Elemento* prim; 
};


Pilha* pilha_cria (void)
{
 Pilha* p = (Pilha*) malloc(sizeof(Pilha));
 
 if (p==NULL)
   exit(1);
 
 p->prim = NULL;
 return p;
}

void pilha_push (Pilha* p, float v)
{
 Elemento* n = (Elemento*) malloc(sizeof(Elemento));
 if (n==NULL)
   exit(1);
 
 n->info = v;
 n->prox = p->prim;
 p->prim = n;
}

float pilha_pop (Pilha* p)
{
 Elemento* t;
 float v;

 if (pilha_vazia(p))
   exit(1); /* aborta programa */
 
 t = p->prim;
 v = t->info;
 p->prim = t->prox;

 free(t);
 return v;
}

void pilha_libera (Pilha* p)
{
  Elemento *t, *q = p->prim;
  while (q!=NULL)
   {
     t = q->prox;
     free(q);
     q = t;
 }
 free(p);
}

int pilha_vazia (Pilha* p)
{
  if(p->prim == NULL)
    return 1;
  return 0;
}

Elemento* lst_cria (void)
{
 return NULL;
}

Elemento* lst_insere (Elemento* lst, int val)
{
 Elemento* novo = (Elemento*) malloc(sizeof(Elemento));
 if (novo == NULL)
   {
     exit(1);
   }
 novo->info = val;
 novo->prox = lst;
 return novo;
}

void lst_imprime (Elemento* lst)
{
 Elemento* p;
 for (p = lst; p != NULL; p = p->prox)
 printf("info = %d\n", p->info);
}

int lst_vazia (Elemento* lst)
{
 return (lst == NULL);
}

void lst_libera (Elemento* lst)
{
  Elemento* p = lst;
  while (p != NULL) {
    Elemento* t = p->prox; /* guarda referência p/ próx. elemento */
    free(p); /* libera a memória apontada por p */
    p = t; /* faz p apontar para o próximo */
  }
}

Elemento* lst_acessaProx(Elemento *e)
{
  e = e->prox;
  return e;
}

int lst_acessaInfo(Elemento *e)
{
  return e->info;
}
