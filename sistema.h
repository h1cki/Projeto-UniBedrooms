/*
˚ @author 65623 HENRIQUE MARQUES hc.marques@campus.fct.unl.pt
  @author 66178 TOMÁS PATRÍCIO LOPES tp.lopes@campus.fct.unl.pt
*/
#ifndef _H_SISTEMA
#define _H_SISTEMA

#include "quarto.h"
#include "gerente.h"
#include "estudante.h"

typedef struct _sistema * sistema;

/***********************************************
criaSistema - Criação da instância da estrutura associada ao sistema.
Parâmetros:
Retorno: apontador para a instância criada
Pré-condições:
***********************************************/
sistema criaSistema();

/***********************************************
destroiSistemaEstudantesGerenteQuartos - Liberta a memória ocupada pela instância da estrutura associada ao sistema
aos estudantes, aos gerentes e aos quartos.
Parâmetros:
	s - sistema a destruir
Retorno:
Pré-condições: s != NULL
***********************************************/
void destroiSistemaEstudantesGerenteQuartos(sistema s);

/***********************************************
verificaLogin - Indica se existe um estudante ou gerente com o login dado existe
Parâmetros:
	s - sistema
	login - login a verificar
Retorno: 1 - caso exista; 0 - caso não exista
Pré-condições: s != NULL
***********************************************/
int verificaLogin(sistema s, char *login);

/***********************************************
novoEstudanteSistema - Adiciona o estudante com o login dado no sistema dado.
Parâmetros:
    s - sistema
    login - login estudante
    nome - nome estudante
    localidade - nome localidade
    universidade - nome universidade
    idade - idade estudante
Retorno: 1- Estudante inserido com sucesso; 0 - Falha ao inserir o estudante
Pré-condições: s != NULL 
***********************************************/
int novoEstudanteSistema(sistema s, char *login, char *nome, char *localidade, char *universidade, int idade);

/***********************************************
existeEstudanteSistema - Indica se o estudante com o login dado existe no sistema dado.
Parâmetros:
	s - sistema
	login - login a verificar
Retorno: 1 - caso exista o login; 0 - caso não exista o login
Pré-condições: s != NULL
***********************************************/
int existeEstudanteSistema(sistema s, char *login);

/***********************************************
estudanteSistema - Consulta o estudante com o login dado no sistema.
Parâmetros:
	s - sistema
	login - login estudante
Retorno: estudante
Pré-condições: s != NULL
***********************************************/
estudante estudanteSistema(sistema s, char* login);

/***********************************************
novoGerenteSistema - Adiciona o gerente com o login dado no sistema dado.
Parâmetros:
    s - sistema
    login - login gerente
    nome - nome gerente
    universidade - nome universidade
Retorno: 1- Gerente inserido com sucesso; 0 - Falha ao inserir o gerente
Pré-condições: s != NULL 
***********************************************/
int novoGerenteSistema(sistema s, char *login, char *nome, char *universidade);

/***********************************************
existeGerenteSistema - Indica se o gerente com o login dado existe no sistema dado.
Parâmetros:
	s - sistema
	login - login a verificar
Retorno: 1 - caso exista o login; 0 - caso não exista o login
Pré-condições: s != NULL
***********************************************/
int existeGerenteSistema(sistema s, char *login);

/***********************************************
gerenteSistema - Consulta o gerente com o login dado no sistema.
Parâmetros:
	s - sistema
	login - login gerente
Retorno: gerente
Pré-condições: s != NULL
***********************************************/
gerente gerenteSistema(sistema s, char* login);

/***********************************************
novoQuartoSistema - Adiciona o quarto com o codigo dado no sistema dado.
Parâmetros:
    s - sistema
    codigo - codigo unico de identificação do quarto
    loginGerente - login do gerente associado
    nomeResi - nome da Residencia
    universidade - universidade a qual frequenta
    localidade - localidade do quarto
    andar - andar do quarto
    descricao - descricao sobre o quarto
Retorno: 1- Quarto inserido com sucesso; 0 - Falha ao inserir o quarto
Pré-condições: s != NULL 
***********************************************/
int novoQuartoSistema(sistema s, char* codigo, char *loginGerente, char *nomeResi, char *universidade, char *localidade,int andar, char *descricao);

/***********************************************
existeQuartoSistema - Indica se o quarto com o codigo dado existe no sistema dado.
Parâmetros:
	s - sistema
	codigo - codigo a verificar
Retorno: 1 - caso exista o codigo; 0 - caso não exista o codigo
Pré-condições: s != NULL
***********************************************/
int existeQuartoSistema(sistema s, char *codigo);

/***********************************************
quartoSistema - Consulta o quarto com o codigo dado no sistema.
Parâmetros:
	s - sistema
	codigo - codigo do quarto
Retorno: quarto
Pré-condições: s != NULL
***********************************************/
quarto quartoSistema(sistema s, char* codigo);

/***********************************************
removeQuartoDic - Remove o quarto com a chave dada no dicionario, se existir.
Parametros:
	s – sistema	
    codigo – endereco do codigo
Retorno: Retorna o quarto, caso exista ou NULL, caso contrario
Pre-condicoes: s != NULL && codigo != NULL
***********************************************/
quarto removeQuartoSistema(sistema s,char * codigo);

/***********************************************
removeEstudanteDosQuartos - Remove o estudante de todos os quartos aos quais se candidatou.
Parametros:
	s – sistema	
    e – estudante
Retorno: 
Pre-condicoes: s != NULL && e != NULL
***********************************************/
void removeEstudanteDosQuartos(sistema s, estudante e);

#endif