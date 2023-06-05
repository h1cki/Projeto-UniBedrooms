/*
˚ @author 65623 HENRIQUE MARQUES hc.marques@campus.fct.unl.pt
  @author 66178 TOMÁS PATRÍCIO LOPES tp.lopes@campus.fct.unl.pt
*/
#ifndef _H_QUARTO
#define _H_QUARTO

#include "estudante.h"
#include "iterador.h"

/* Tipo do TAD quarto */
typedef struct _quarto* quarto;

/***********************************************
criaQuarto - Criacao da instancia da estrutura associada a um quarto.
Parametros:
    codigo - codigo unico de identificação do quarto
    loginGerente - login do gerente associado
    nomeResi - nome da Residencia
    universidade - universidade a qual frequenta
    localidade - localidade do quarto
    andar - andar do quarto
    descricao - descricao sobre o quarto
Retorno: apontador para a instancia criada
Pre-condicoes:
***********************************************/
quarto criaQuarto(char *codigo, char *loginGerente, char *nomeResi, char *universidade, char *localidade, int andar, char *descricao);

/***********************************************
apagaQuarto - Liberta a memória ocupada pela instância da estrutura associada ao quarto.
Parâmetros:
	q - quarto a apagar
Retorno:
Pré-condições: q != NULL
***********************************************/
void apagaQuarto(quarto q);

/***********************************************
apagaGenQuarto - Liberta a memória ocupada pela instância da estrutura associada ao quarto genericamente.
Parametros:
	q - quarto a apagar
Retorno:
Pré-condições: q != NULL
***********************************************/
void apagaGenQuarto(void* q);

/***********************************************
daCodigoQuarto - Consulta o codigo do quarto.
Parâmetros:
    q - quarto
Retorno: codigo do quarto
Pré-condições: q != NULL
***********************************************/
char* daCodigoQuarto(quarto q);

/***********************************************
daLoginGerente - Consulta o login do gerente.
Parâmetros:
    q - quarto
Retorno: login do gerente
Pré-condições: q != NULL
***********************************************/
char* daLoginGerenteQuarto(quarto q);

/***********************************************
daNomeResiQuarto - Consulta o nome da residencia do quarto.
Parâmetros:
    q - quarto
Retorno: nome da residencia
Pré-condições: q != NULL
***********************************************/
char* daNomeResiQuarto(quarto q);

/***********************************************
daUniversidadeQuarto - Consulta a universidade do quarto.
Parâmetros:
    q - quarto
Retorno: nome da universidade do quarto
Pré-condições: q != NULL
***********************************************/
char* daUniversidadeQuarto(quarto q);

/***********************************************
daLocalidadeQuarto - Consulta a localidade do quarto.
Parâmetros:
    q - quarto
Retorno: nome da localidade do quarto
Pré-condições: q != NULL
***********************************************/
char* daLocalidadeQuarto(quarto q);

/***********************************************
daAndarQuarto - Consulta o andar do quarto.
Parâmetros:
    q - quarto
Retorno: andar do quarto
Pré-condições: q != NULL
***********************************************/
int daAndarQuarto(quarto q);

/***********************************************
daDescricaoQuarto - Consulta a descricao do quarto.
Parâmetros:
    q - quarto
Retorno: a descriçao do quarto
Pré-condições: q != NULL
***********************************************/
char* daDescricaoQuarto(quarto q);

/***********************************************
daEstadoQuarto - Consulta o estado do quarto.
Parâmetros:
    q - quarto
Retorno: ocupacao do quarto
Pré-condições: q != NULL
***********************************************/
char* daEstadoQuarto(quarto q);

/***********************************************
modificaEstadoQuarto - Modifica o estado do quarto para o oposto do que esta.
Parâmetros:
    q - quarto
Retorno:
Pré-condições: q != NULL
***********************************************/
void modificaEstadoQuarto(quarto q);

/*********************************************
verificaCandidaturaQuarto - Indica se o quarto tem candidaturas ativas
Parametros:
q - quarto
Retorno: 1- caso quarto não tenha candidaturas ativas; 0 - caso contrario
Pre-condicoes: q != NULL
*********************************************/
int verificaCandidaturaQuarto(quarto q);

/***********************************************
adicionaCandidatoAQuarto - Insere um novo candidato a um determinado quarto
Parametros:
	e - estudante
	q - quarto
Retorno: 
Pré-condições: e != NULL   q != NULL
***********************************************/
void adicionaCandidatoAQuarto(estudante e, quarto q);

/***********************************************
daNCandidatos - Consulta o numero de candidatos ao quarto.
Parâmetros:
    q - quarto
Retorno: numero de candidatos
Pré-condições: q != NULL
***********************************************/
int daNCandidatos(quarto q);

/***********************************************
iteradorCandidatos - Devolve um iterador de candidatos.
Parâmetros:
	q - quarto
Retorno: um iterador de candidatos a um quarto
Pré-condições: q != NULL
***********************************************/
iterador iteradorCandidatos(quarto q);

/***********************************************
removeEstudanteQuarto - Remove o estudante da sequencia de candidatos ao quarto.
Parâmetros:
	q - quarto
Retorno: um iterador de candidatos a um quarto
Pré-condições: q != NULL
***********************************************/
void removeEstudanteQuarto(quarto q, estudante e);

/***********************************************
daPosEstudanteQuarto - Devolve a posição do estudante na sequencia de candidatos ao quartos.
Parâmetros:
	q - quarto
    e - estudante
Retorno: pos do estudante
Pré-condições: q != NULL && e != NULL
***********************************************/
int daPosEstudanteQuarto(quarto q, estudante e);

void removerEstudantesDoQuarto(quarto q);

#endif