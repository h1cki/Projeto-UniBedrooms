/*
˚ @author 65623 HENRIQUE MARQUES hc.marques@campus.fct.unl.pt
  @author 66178 TOMÁS PATRÍCIO LOPES tp.lopes@campus.fct.unl.pt
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "quarto.h"
#include "estudante.h"
#include "messages.h"
#include "constants.h"

#include "iterador.h"
#include "sequencia.h"

struct _quarto{
    char codigo[OUTROS];                //codigo unico do quarto
    char loginGerente[OUTROS];          //login unico do gerente do quarto
    char nomeResi[NOMES];               //nome da residencia onde se encontra o quarto
    char universidade[NOMES];           //nome da universidade
    char localidade[NOMES];             //localidade onde se localiza
    int andar;                          //andar do quarto
    char descricao[DESCRICAO];          //descrição a cerca do quarto
    char estado[OUTROS];                //estado de ocupação do quarto
    sequencia candidatos;               //sequencia em lista de estudantes que se candidataram ao quarto
};

quarto criaQuarto(char *codigo, char *loginGerente, char *nomeResi, char *universidade, char *localidade, int andar, char *descricao){
    quarto q = (quarto) malloc (sizeof(struct _quarto));
    if(q == NULL) return NULL;
    strcpy(q->codigo, codigo);
    strcpy(q->loginGerente, loginGerente);
    strcpy(q->nomeResi, nomeResi);
    strcpy(q->universidade, universidade);
    strcpy(q->localidade, localidade);
    q->andar = andar;
    strcpy(q->descricao, descricao);
    strcpy(q->estado, MSG_LIVRE);
    q->candidatos = criaSequencia(CAP_ESTUNDATES);

    return q;
}

void apagaQuarto(quarto q){
    destroiSeqElems(q->candidatos, apagaGenEstudante);
    free(q);
}

void apagaGenQuarto(void* q){
    quarto quar = (quarto) q;
    destroiSequencia(quar->candidatos);
    free(quar);
    
}

char* daCodigoQuarto(quarto q){
    return q->codigo;
}

char* daLoginGerenteQuarto(quarto q){
    return q->loginGerente;
}

char* daNomeResiQuarto(quarto q){
    return q->nomeResi;
}

char* daUniversidadeQuarto(quarto q){
    return q->universidade;
}

char* daLocalidadeQuarto(quarto q){
    return q->localidade;
}

int daAndarQuarto(quarto q){
    return q->andar;
}

char* daDescricaoQuarto(quarto q){
    return q->descricao;
}

char* daEstadoQuarto(quarto q){
    return q->estado;
}

void modificaEstadoQuarto(quarto q){
    if(strcmp(q->estado, MSG_LIVRE) == 0){
        strcpy(q->estado, MSG_OCUPADO);
    }else if(strcmp(q->estado, MSG_OCUPADO) == 0){
        strcpy(q->estado, MSG_LIVRE);
    }
}

int verificaCandidaturaQuarto(quarto q){
    if (q->candidatos == NULL) {
        return 1;
    } else { 
        return vaziaSequencia(q->candidatos); 
    }
}

void adicionaCandidatoAQuarto(estudante e, quarto q){
    adicionaPosSequencia(q->candidatos, e, tamanhoSequencia(q->candidatos) + 1);
}

int daNCandidatos(quarto q){
    return tamanhoSequencia(q->candidatos);
}

estudante daEstudanteCandidato(quarto q, int i){
    return elementoPosSequencia(q->candidatos, i);
}

iterador iteradorCandidatos(quarto q){
    return iteradorSequencia(q->candidatos);
}


void removeEstudanteQuarto(quarto q, estudante e){
    int pos = daPosEstudanteQuarto(q, e);
    if ( pos > 0)
        removePosSequencia(q->candidatos, pos);
}

int daPosEstudanteQuarto(quarto q, estudante e){

    for (int i = 0; i < tamanhoSequencia(q->candidatos); i++){
        int pos = strcmp(daLoginEstudante(e), daLoginEstudante(elementoPosSequencia(q->candidatos, i+1)));
        if(pos == 0){
            return i;
        }
    }
    return -1; 
}

void removerEstudantesDoQuarto(quarto q){
    destroiSeqElems(q->candidatos, apagaGenEstudante);
}