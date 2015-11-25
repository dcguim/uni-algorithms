typedef struct elemento Elemento;
typedef struct pilha Pilha;

/*Função recebe duas listas encadeadas lst1 e lst2
  a função concatena as duas listas apontando do último
  elemento da lst2 para o primeiro elemento da lst1
  (Caso a lst2 seja NULL a funçao retorna a lst1).*/

Elemento* lst_concatena(Elemento* lst1,Elemento* lst2);


Pilha* pilha_cria (void);

void pilha_push (Pilha* p, float v);

float pilha_pop (Pilha* p);

void pilha_libera (Pilha* p);

int pilha_vazia(Pilha* p);


Elemento* lst_cria(void);

Elemento* lst_insere(Elemento* lst, int i);

int lst_vazia(Elemento* lst);

void lst_libera(Elemento* lst);

Elemento* lst_acessaProx(Elemento *e);

int lst_acessaInfo(Elemento *e);

void lst_imprime (Elemento* lst);

Elemento* lst_acessaProx(Elemento *e);

