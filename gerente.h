/*
˚ @author 65623 HENRIQUE MARQUES hc.marques@campus.fct.unl.pt
  @author 66178 TOMÁS PATRÍCIO LOPES tp.lopes@campus.fct.unl.pt
*/
#ifndef _H_GERENTE
#define _H_GERENTE
/* Tipo do TAD gerente */
typedef struct _gerente* gerente;

/***********************************************
criaGerente - Criacao da instancia da estrutura associada a um gerente.
Parametros:
	login - codigo unico de identificação do estudante
	nome - nome do estudante
	universidade - universidade a qual frequenta
Retorno: apontador para a instancia criada
Pre-condicoes:
***********************************************/
gerente criaGerente(char *login, char *nome, char *universidade);

/***********************************************
apagaGerente - Liberta a memória ocupada pela instância da estrutura associada ao gerente.
Parâmetros:
	g - gerente a apagar
Retorno:
Pré-condições: g != NULL
***********************************************/
void apagaGerente(gerente g);

/***********************************************
apagaGenGerente - Liberta a memória ocupada pela instância da estrutura associada ao gerente genericamente.
Parametros:
	g - gerente a apagar
Retorno:
Pré-condições: g != NULL
***********************************************/
void apagaGenGerente(void* g);

/***********************************************
daLoginGerente - Consulta o login do gerente.
Parâmetros:
    g - gerente
Retorno: login do gerente
Pré-condições: g != NULL
***********************************************/
char* daLoginGerente(gerente g);

/***********************************************
daNomeGerente - Consulta o nome do gerente.
Parâmetros:
    g - gerente
Retorno: nome do gerente
Pré-condições: g != NULL
***********************************************/
char* daNomeGerente(gerente g);
/***********************************************
daLoginGerente - Consulta a universidade do gerente.
Parâmetros:
    g - gerente
Retorno: universidade do gerente
Pré-condições: g != NULL
***********************************************/
char* daUniversidadeGerente(gerente g);
#endif