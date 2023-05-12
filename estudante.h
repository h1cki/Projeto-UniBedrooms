#ifndef _H_ESTUDANTE
#define _H_ESTUDANTE
/* Tipo do TAD estudante */
typedef struct _estudante * estudante;

/***********************************************
criaEstudante - Criacao da instancia da estrutura associada a um estudante.
Parametros:
login - codigo unico de identificação do estudante
nome - nome do estudante
idade - idade do estudante
localidade - 
universidade - universidade a qual frequenta
candidaturas - numero de candidaturas a quartos feitas
Retorno: apontador para a instancia criada
Pre-condicoes:
***********************************************/
estudante criaEstudante(char* login, char* nome, int idade, char* localide, char* universidade);

/***********************************************
daLoginEstudante - Consulta o login do estudante.
Parâmetros:
e - estudante
Retorno: login do estudante
Pré-condições: e != NULL
***********************************************/
char* daLoginEstudante(estudante e);

/***********************************************
daNomeEstudante - Consulta o nome do estudante.
Parâmetros:
e - estudante
Retorno: nome do estudante
Pré-condições: e != NULL
***********************************************/
char* daNomeEstudante(estudante e);

/***********************************************
daIdadeEstudante - Consulta a idade do estudante.
Parâmetros:
e - estudante
Retorno: ideade do estudante
Pré-condições: e != NULL
***********************************************/
int daIdadeEstudante(estudante e);

/***********************************************
daLocalidadeEstudante - Consulta a localidade do estudante.
Parâmetros:
e - estudante
Retorno: localidade do estudante
Pré-condições: e != NULL
***********************************************/
char* daLocalidadeEstudante(estudante e);

/***********************************************
daUniversidadeEstudante - Consulta a universidade do estudante.
Parâmetros:
e - estudante
Retorno: universidade do estudante
Pré-condições: e != NULL
***********************************************/
char* daUniversidadeEstudante(estudante e);

#endif
