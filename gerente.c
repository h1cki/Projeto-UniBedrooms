/*
˚ @author 65623 HENRIQUE MARQUES hc.marques@campus.fct.unl.pt
  @author 66178 TOMÁS PATRÍCIO LOPES tp.lopes@campus.fct.unl.pt
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "gerente.h"
#include "messages.h"
#include "constants.h"

struct _gerente{
    char login[OUTROS];
    char nome[NOMES];
    char universidade[NOMES];
};

gerente criaGerente(char *login, char *nome, char *universidade ){
    gerente g = (gerente) malloc(sizeof(struct _gerente));
    if (g == NULL) return NULL;
    strcpy(g->login, login);
    strcpy(g->nome, nome);
    strcpy(g->universidade, universidade);

    return g;
}

void apagaGerente(gerente g){
    free(g);
}

void apagaGenGerente(void* g){
    gerente ger = (gerente) g;
    free(ger);
}

char* daNomeGerente(gerente g){
    return g->nome;
}

char* daLoginGerente(gerente g){
    return g->login;
}

char* daUniversidadeGerente(gerente g){
    return g->universidade;
}