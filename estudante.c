#include <stdio.h>
#include <string.h>
#include "estudante.h"
#include "quarto.h"
#include "sistema.h"

struct _estudante{
    char login[OUTROS];                         //vector dinâmico para o login unico de cada estudante
    char nome[NOMES];                           //vector estático para o nome do estudante
    int idade;                                  //idade do estudante
    char localidade[NOMES];                     //vector estático para a localidade onde se encontra a residencia
    char universidade[NOMES];                   //vector estático para a universidade que frequenta
    quarto* candidaturas[CANDIDATURAS];                   //
    int ncandidaturas;                          //numero de candidaturas feitas
};

estudante criaEstudante(char* login, char* nome, int idade, char* localide, char* universidade){
    estudante e = (estudante) malloc(sizeof(struct _estudante));
    if (e == NULL) return NULL;
    strcpy(e->login, login);
    strcpy(e->nome, nome);
    e->idade = idade;
    strcpy(e->localidade, localide);
    strcpy(e->universidade, universidade);

    return e;
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