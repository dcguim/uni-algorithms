#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "consulta.h"

struct consulta
{
  int dia;
  int mes;
  int ano;
  int hora;
  int min;
  char medico[50];
  char paciente[50];
};

struct data
{
  int dia;
  int mes;
  int ano;
};
typedef struct data Data;

void Cons_libera_consulta (Consulta *p)
{
  free(p);
}

Consulta * Cons_cria_consulta (char *paciente, int d,
			      int m, int a, int hr,
			      int min, char *medico)
{
  Consulta* new = (Consulta*) malloc (sizeof(Consulta));
  
  if (new == NULL)
    {
      perror("Memoria insuficiente!\n");
      fflush(stdout);
      exit(1);	
    }

  new->dia = d;
  new->mes = m;
  new->ano = a;
  new->hora = hr;
  new->min = min;
  
  strcpy(new->medico, medico);
  strcpy(new->paciente, paciente);

  fflush(stdout);
  return new;
}

void Cons_altera_paciente (Consulta *p, char *nome)
{
  strcpy(p->paciente, nome);
}

void Cons_altera_data_consulta (Consulta *p, int d,
				int m, int a)
{
  p->dia = d;
  p->mes = m;
  p->ano = a;
}


void imprime_consulta(Consulta* p)
{
  printf("Consulta:\n   (%d/%d/%d) as %d:%d\n   medico: %s\n   paciente: %s\n\n"
	 , p->dia, p->mes, p->ano, p->hora,
	 p->min, p->medico, p->paciente);
}

void Cons_altera_medico (Consulta *p, char *med)
{
  strcpy(p->medico, med);
}

int Cons_verifica_data_consulta (Consulta *p, int d,
				 int m, int a)
{
  if (p->dia == d && p->mes == m && p->ano == a)
    {
      return 1;
    }
  return 0;
}

int Cons_verifica_medico (Consulta *p, char *med)
{
  if (!strcmp(p->medico, med))
    {
      return 1;
    }
  return 0;
}

Consulta *Cons_copia_consulta (Consulta *p)
{
  Consulta* new = (Consulta*) malloc (sizeof(Consulta));

  new->dia = p->dia;
  new->mes = p->dia;
  new->ano = p->ano;
  new->hora = p->hora;
  new->min = p->min;
  strcpy(new->paciente, p->paciente);
  strcpy(new->medico, p->medico);
  
  return new;
}
/*
int troca_medico(Consulta **vet, int n, Data d,
		 char *med, char *sub)
{
  int i, no = 0;
  Consulta* c;
  for (i = 0; i < n; i++)
    {
      c = vet[i];
      if (d.dia == c->dia &&
	  d.mes == c->mes &&
	  d.ano == c->ano &&
	  !strcmp(med, c->medico))
	{
	  strcpy(c->medico, sub);
	  no++;
	}	
    }
  return no;
  }*/

int troca_medico(Consulta **vet, int n, Data d,
		 char *med, char *sub)
{
  int i, no = 0;
  for (i=0; i< n; i++)
    {
      if ((Cons_verifica_data_consulta (vet[i], d.dia,
				       d.mes, d.ano) == 1)
	  &&
	  (Cons_verifica_medico (vet[i], med) == 1))
	{
	  Cons_altera_medico (vet[i], sub);
	  no++;
	}
    }
  return no;
}

int main (void)
{
  Consulta* p = Cons_cria_consulta("P.D. Ouspensky",
  				   12, 6, 1945, 15, 30,
  				   "Dr. Gurdjieff");
  
  Consulta* n = Cons_copia_consulta(p);

  char pac1[50] = {"Jean Luc Godard"};
  char med1[50] = {"Immanuel Kant"};

  int nc = 10;
  Consulta* consultas[nc];

  Data data1;
  
  // Altera a consulta criada
  Cons_altera_paciente(n, pac1);

  Cons_altera_data_consulta (n, 19, 7, 1945);

  Cons_altera_medico (n, med1);

  // Testa as funcoes de verificação
  printf("%d\n",Cons_verifica_medico (n, med1));

  printf("%d\n",Cons_verifica_data_consulta(n, 19,7,1945));

  // Imprime as consultas
  imprime_consulta(p);

  imprime_consulta(n);

  // Preenche(Popula) o vetor de consultas
  consultas[0] = p;
  consultas[1] = n;
  consultas[2] = Cons_cria_consulta("Arthur Schopenhauer",
  				   1, 12, 1995, 15, 30,
  				   "Pedro Brumz");
  consultas[3] = Cons_cria_consulta("Eric Fromm",
  				   27, 2, 1805, 15, 30,
  				   "Luiz Buscaccio");
  consultas[4] = Cons_cria_consulta("Jeová",
				    27, 2, 1715, 19, 3,
				    "Eduardo Casco");
  consultas[5] = Cons_cria_consulta("Paulo Andre",
				    27, 3, 1915, 1, 20,
				    "Igor");

  imprime_consulta(consultas[2]);
  imprime_consulta(consultas[3]);
  imprime_consulta(consultas[4]);
  imprime_consulta(consultas[5]);

  // Preenche a variavel data1 com a data da consulta a ser trocada
  // e realiza a troca
  printf("Troca consulta:\n");
  data1.dia = 27;
  data1.mes = 3;
  data1.ano = 1915;
  troca_medico(consultas, 6, data1 ,
	       "Igor", "Sandro");

  imprime_consulta(consultas[5]);

  // Desaloca as consultas
  Cons_libera_consulta(p);

  Cons_libera_consulta(n);
  
  Cons_libera_consulta(consultas[3]);
  Cons_libera_consulta(consultas[4]);
  Cons_libera_consulta(consultas[5]);
  
  
  return 0;
}
