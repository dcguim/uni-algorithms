typedef struct consulta Consulta;

/*Copia uma consulta, ou seja, aloca uma nova área
  dinamicamente, inicializa essa área com valores
  idênticos ao da consulta recebida como parâmetro e
  retorna o ponteiro para a nova área (ou NULL se
  não foi possível alocá-la).*/

Consulta *Cons_copia_consulta (Consulta *p);



/*Aloca dinamicamente área para o tipo Consulta,
  inicializa essa área com os valores recebidos
  como parâmetros e retorna o ponteiro para essa
  área (ou NULL se não foi possível alocá-la).*/

Consulta *Cons_cria_consulta (char *paciente, int d,
			      int m, int a, int hr,
			      int min, char *medico);



/*Altera o paciente a ser atendido em uma consulta.
  O ponteiro para a consulta e nome do novo paciente
  são recebidos como parâmetros.*/

void Cons_altera_paciente (Consulta *p, char *nome);



/*Altera a data de uma consulta. O ponteiro para a
  consulta e os novos valores de dia, mês e ano são
  recebidos como parâmetros.*/

void Cons_altera_data_consulta (Consulta *p, int d,
				int m, int a);



/*Altera o médico responsável por uma consulta. O
  ponteiro para a consulta e o nome do médico
  substituto são recebidos como parâmetros.*/

void Cons_altera_medico (Consulta *p, char *med);



/*Compara uma data, fornecida como parâmetro, com a
  data de uma consulta. O ponteiro para a consulta e
  o dia, mês e ano a serem comparados são recebidos
  como parâmetros. Retorna 1, se as datas são
  iguais, ou 0, em caso contrário.*/

int Cons_verifica_data_consulta (Consulta *p, int d,
				 int m, int a);



/*Compara um médico, recebido como parâmetro, com o
  médico responsável por uma consulta. O ponteiro
  para a consulta e o nome do médico a ser comparado
  são recebidos como parâmetros. Retorna 1, se os
  nomes dos médicos são iguais, ou 0, em caso
  contrário.*/

//int Cons_verifica_medico (Consulta *p, char *med);



/*Libera a área de uma consulta cujo endereço é
  recebido como parâmetro.*/

void Cons_libera_consulta (Consulta *p);

