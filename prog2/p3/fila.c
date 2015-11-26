#include<stdio.h>
#include"fila.h"
#include<stdlib.h>

/* nó da lista para armazenar valores reais
   suponha que info seja equivalente a idade
   da pessoa representada como um nó da lista
   encadeada */
struct lista {
 float info;
 struct lista* prox;
};

typedef struct lista Lista;
/* estrutura da fila */
struct fila {
 Lista* ini;
 Lista* fim;
};

int fila_vazia (Fila* f)
{
  if (f->ini == f->fim)
      return 1;

  return 0;
}

void fila_libera (Fila* f)
{
  Lista* l;
  Lista* t;

  l = f->ini;
  while(l != f->fim)
    {
      t = l->prox;      
      free(l);
      l = t;     
    }
  
  free(l);

  f->ini = NULL;
  f->fim = NULL;
}

Fila* fila_cria (void)
{
 Fila* f = (Fila*) malloc(sizeof(Fila));
 f->ini = f->fim = NULL;
 return f;
}

void fila_insere (Fila* f, float v)
{
 Lista* n = (Lista*) malloc(sizeof(Lista));
 
 n->info = v; /* armazena informação */
 n->prox = NULL; /* novo nó passa a ser o último */
 
 if (f->fim != NULL)
   {
     if(f->ini == f->fim)
       {
	 f->ini->prox = n;
       }
     f->fim = n;    
   }
 else 
   {
     f->ini = n;
     f->fim = n; /* fila aponta para novo elemento */
   }
}

float fila_retira (Fila* f)
{
  Lista* t;
  float v;
  if (fila_vazia(f)) {
    printf("Fila vazia.\n");
    exit(1); } /* aborta programa */
  
  t = f->ini;
  v = t->info;
  f->ini = t->prox;
  if (f->ini == NULL) /* verifica se fila ficou vazia */
    f->fim = NULL;
  free(t);
 return v;
}

void separa_filas (Fila* f, Fila* f_prioridade, Fila* f_convencional)
{
  Lista* l = f->ini;
  
  if (!fila_vazia(f))
    {
      while (l != NULL)
	{	  
	  if ((2015 - l->info) >= 65)
	    {
	      fila_insere(f_prioridade, l->info);
	    }
	  else
	    {	  
	      fila_insere(f_convencional, l->info);
	    }
	  l = l->prox;
	}
    }
}

int main (void)
{
  Fila* f = fila_cria();
  Fila* f_p = fila_cria();
  Fila* f_c = fila_cria();
  
  fila_insere(f, 2004); 
  fila_insere(f,1905);
 
  separa_filas(f, f_p, f_c);
  printf("prioridade:%f\n", f_p->ini->info);
  printf("convencional:%f\n", f_c->ini->info);
  fila_libera(f);
  
  free(f->ini);
  free(f->fim);
  free(f);
  
  return 0;
}

