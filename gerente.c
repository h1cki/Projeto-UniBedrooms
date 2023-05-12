#include <stdio.h>
#include "gerente.h"
#include "estudante.h"
#include "quarto.h"
#include "sistema.h"

struct _gerente{
    char login[OUTROS];
    char nome[NOMES];
    char universidade[NOMES];
};

gerente criaGerente(char *login, char *nome, char *universidade ){
    gerente g;
    strcpy(g->login, login);
    strcpy(g->nome, nome);
    strcpy(g->universidade, universidade);
    
}

char* daLoginGerente(gerente g){
    return g->login;
}

char* daNomeGerente(gerente g){
    return g->nome;
}

char* daUniversidadeGerente(gerente g){
    return g->universidade;
}