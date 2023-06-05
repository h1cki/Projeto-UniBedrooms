/*
˚ @author 65623 HENRIQUE MARQUES hc.marques@campus.fct.unl.pt
  @author 66178 TOMÁS PATRÍCIO LOPES tp.lopes@campus.fct.unl.pt
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "estudante.h"
#include "messages.h"
#include "constants.h"

struct _estudante{
    char login[OUTROS];                         //vector estático para o login unico de cada estudante
    char nome[NOMES];                           //vector estático para o nome do estudante
    int idade;                                  //idade do estudante
    char localidade[NOMES];                     //vector estático para a localidade onde se encontra a residencia
    char universidade[NOMES];                   //vector estático para a universidade que frequenta
    int ncandidaturas;                          //numero de candidaturas feitas
    char *candidaturas[CANDIDATURAS];           //vector estático de códigos de quartos
};

estudante criaEstudante(char* login, char* nome, int idade, char* localide, char* universidade){
    estudante e = (estudante) malloc(sizeof(struct _estudante));
    if (e == NULL) return NULL;
    strcpy(e->login, login);
    strcpy(e->nome, nome);
    e->idade = idade;
    strcpy(e->localidade, localide);
    strcpy(e->universidade, universidade);
    e->ncandidaturas = 0;

    return e;
}

void apagaEstudante(estudante e){
    free(e);
}

void apagaGenEstudante(void* e){
    estudante estud = (estudante) e;
    free(estud);
}

char* daLoginEstudante(estudante e){    
    return e->login;
}

char* daNomeEstudante(estudante e){
    return e->nome;
}

int daIdadeEstudante(estudante e){
    return e->idade;
}

char* daLocalidadeEstudante(estudante e){
    return e->localidade;
}

char* daUniversidadeEstudante(estudante e){
    return e->universidade;
}

int daNCandidaturasEstudante(estudante e){
    return e->ncandidaturas;
}

int verificaCandidaturaEstudante(estudante e, char* codigo){
    for(int i = 0; i < (e->ncandidaturas); i++){
        if(strcmp(codigo, e->candidaturas[i]) == 0){
            return 1;
        }
    }
    return 0;
}

void adicionaQuartoAEstudante(estudante e, char* codigo){
    e->candidaturas[e->ncandidaturas] = codigo;
    e->ncandidaturas += 1;
}

char* daCodigoQuartoCandidatura(estudante e, int i){
    return e->candidaturas[i];
}

void removerCandidaturasEstudante(estudante e){
    e->ncandidaturas = 0;    
}
