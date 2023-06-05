/*
˚ @author 65623 HENRIQUE MARQUES hc.marques@campus.fct.unl.pt
  @author 66178 TOMÁS PATRÍCIO LOPES tp.lopes@campus.fct.unl.pt
*/
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

#include "estudante.h"
#include "quarto.h"
#include "gerente.h"
#include "dicionario.h"
#include "messages.h"
#include "sistema.h"
#include "sequencia.h"
#include "constants.h"


struct _sistema{
    dicionario estudantes;
    dicionario quartos;
    dicionario gerentes;
};

sistema criaSistema(){
	sistema s = (sistema) malloc (sizeof(struct _sistema));
	//if (s == NULL) return NULL;

	s->estudantes = criaDicionario(CAP_ESTUNDATES,1);
/*	if (s->estudantes == NULL){
		free(s);
		return NULL;
	}
*/
    s->quartos = criaDicionario(CAP_QUARTOS, 1);
 /*   if (s->quartos == NULL){
		free(s->estudantes);
        free(s);
		return NULL;
	}
*/
    s->gerentes = criaDicionario(CAP_GERENTES, 1);
/*    if (s->gerentes == NULL){
        free(s->quartos);
        free(s->estudantes);
		free(s);
		return NULL;
	}
*/
	return s;
}

void destroiSistemaEstudantesGerenteQuartos(sistema s){
    destroiDicEElems(s->estudantes, apagaGenEstudante);
    destroiDicEElems(s->gerentes, apagaGenGerente);
    destroiDicEElems(s->quartos, apagaGenQuarto);
    free(s);
}

int verificaLogin(sistema s, char* login){
    if(existeEstudanteSistema(s, login) || existeGerenteSistema(s, login)){
        return 1;
    }else{
        return 0;
    }
}

int novoEstudanteSistema(sistema s, char *login, char *nome, char *localidade, char *universidade, int idade){
    estudante e = criaEstudante(login, nome, idade, localidade, universidade);
    int ad = adicionaElemDicionario(s->estudantes, (void *)login , (void *)e);
    if (ad != 1){
        apagaEstudante(e);
        printf("Erro na introdução na dicionário");
    }
    return ad;
}

int existeEstudanteSistema(sistema s, char *login){
    return (existeElemDicionario(s->estudantes, (void *)login));
}

estudante estudanteSistema(sistema s, char* login){
    return (estudante) elementoDicionario(s->estudantes, (void *)login);
}

int novoGerenteSistema(sistema s, char *login, char *nome, char *universidade){
    gerente g = criaGerente(login, nome, universidade);
    int ad = adicionaElemDicionario(s->gerentes, (void *)login , (void *)g);
    if (ad != 1){
        apagaGerente(g);
    }
    return ad;
}

int existeGerenteSistema(sistema s, char *login){
    return existeElemDicionario(s->gerentes, (void *)login);
}


gerente gerenteSistema(sistema s, char *login){
    return (gerente) elementoDicionario(s->gerentes, (void *)login);
}

int novoQuartoSistema(sistema s, char* codigo, char *loginGerente, char *nomeResi, char *universidade, char *localidade, int andar, char *descricao){
    quarto q = criaQuarto(codigo, loginGerente, nomeResi, universidade, localidade, andar, descricao);
    int ad = adicionaElemDicionario(s->quartos, (void *)codigo , (void *)q);
    if (ad != 1){
        apagaQuarto(q);
        printf("Erro na Introdução no dicionário.\n");
    }
    return ad;  
}

int existeQuartoSistema(sistema s, char *codigo){
    return existeElemDicionario(s->quartos, (void *) codigo);
}

quarto quartoSistema(sistema s, char* codigo){
    return (quarto) elementoDicionario(s->quartos, (void *) codigo);
}

quarto removeQuartoSistema(sistema s,char * codigo){
    return (quarto) removeElemDicionario(s->quartos, codigo);
}

void removeEstudanteDosQuartos(sistema s, estudante e){
    char codigo[OUTROS] = "";

    for (int i = 0; i < daNCandidaturasEstudante(e); i++){
        strcpy(codigo, daCodigoQuartoCandidatura(e, i));
        quarto q = quartoSistema(s, codigo);
        if (q != NULL) 
            removeEstudanteQuarto(q, e);
    }
}

