#ifndef _H_GERENTE
#define _H_GERENTE
/* Tipo do TAD gerente */
typedef struct _gerente* gerente;

#define NOMES 50
#define OUTROS 20
#define DESCRICAO 200

/***********************************************
daLoginGerente - Consulta o login do gerente.
Parâmetros:
g - gerente
Retorno: login do gerente
Pré-condições: e != NULL
***********************************************/
char* daLoginGerente(gerente g);

/***********************************************
daNomeGerente - Consulta o nome do gerente.
Parâmetros:
g - gerente
Retorno: nome do gerente
Pré-condições: e != NULL
***********************************************/
char* daNomeGerente(gerente g);
/***********************************************
daLoginGerente - Consulta a universidade do gerente.
Parâmetros:
g - gerente
Retorno: universidade do gerente
Pré-condições: e != NULL
***********************************************/
char* daUniversidadeGerente(gerente g);
#endif