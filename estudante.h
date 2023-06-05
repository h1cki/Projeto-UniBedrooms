/*
˚ @author 65623 HENRIQUE MARQUES hc.marques@campus.fct.unl.pt
  @author 66178 TOMÁS PATRÍCIO LOPES tp.lopes@campus.fct.unl.pt
*/
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
	localidade - localidade do estudante
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

/***********************************************
daNCandidaturas - Consulta o numero de candidaturas do estudante.
Parâmetros:
	e - estudante
Retorno: numero de candidaturas
Pré-condições: e != NULL
***********************************************/
int daNCandidaturasEstudante(estudante e);

/***********************************************
apagaEstudante - Liberta a memória ocupada pela instância da estrutura associada ao estudante.
Parametros:
	e - estudante a apagar
Retorno:
Pré-condições: e != NULL
***********************************************/
void apagaEstudante(estudante e);

/***********************************************
apagaGenEstudante - Liberta a memória ocupada pela instância da estrutura associada ao estudante genericamente.
Parametros:
	e - estudante a apagar
Retorno:
Pré-condições: e != NULL
***********************************************/
void apagaGenEstudante(void* e);

/***********************************************
verificaCandidaturaEstudante - verifica se o estudante esta a concorrer a um determinado quarto
Parametros:
	e - estudante
	codigo - codigo quarto
Retorno: 1 - se o estudante tiver candidatura ativa ao quarto; 0 - se não tiver
Pré-condições: e != NULL   q != NULL
***********************************************/
int verificaCandidaturaEstudante(estudante e, char* codigo);

/***********************************************
adicionaQuartoAEstudante - Insere um novo quarto a que o estudante se candidata
Parametros:
	e - estudante
	codigo - codigo quarto
Retorno: 
Pré-condições: e != NULL   q != NULL
***********************************************/
void adicionaQuartoAEstudante(estudante e, char* codigo);

/***********************************************
daCodigoQuartoCandidatura - Consulta um quarto i nas candidaturas
Parametros:
	e - estudante
	i - index da candidatura
Retorno: quarto
Pré-condições: e != NULL && i >= 0 && i < ncandidaturas
***********************************************/
char* daCodigoQuartoCandidatura(estudante e, int i);

/***********************************************
removerCandidaturasEstudante - remove todas as candidaturas do estudante
Parametros:
	e - estudante
Retorno: 
Pré-condições: e != NULL
***********************************************/
void removerCandidaturasEstudante(estudante e);

#endif
