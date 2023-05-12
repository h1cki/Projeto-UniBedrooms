/*
˚ @author 65623 HENRIQUE MARQUES hc.marques@campus.fct.unl.pt
  @author 66178 TOMÁS PATRÍCIO LOPES tp.lopes@campus.fct.unl.pt
*/

#include <stdio.h>
#include <ctype.h>
#include "estudante.h"
#include "quarto.h"
#include "gerente.h"

#define MAXL 30

/* Funcoes Prototipo*/
void cmdInserirEstudante(char* linha);

void main(){
    interpertador();
}

void iterpertador(){
    char linha[MAXL], cmd[3];
    fgets(linha,MAXL,stdin);
    cmd[0] = toupper(linha[0]);
    cmd[1] = toupper(linha [1]);
    cmd[2] = '\0';

    while (strcmp(cmd, "XC") != 0) {
    /* Tratar comando */    
    if (strcmp(cmd, "IE") == 0) {
        cmdInserirEstudante(linha);
    } else if (strcmp(cmd, "DE") == 0) {
        cmdConsultaDadosEstudante(linha);
    } else if (strcmp(cmd, "IG") == 0) {
        // do nothing
    } else if (strcmp(cmd, "DG") == 0) {
        // do nothing
    } else if (strcmp(cmd, "IQ") == 0) {
        // do nothing
    } else if (strcmp(cmd, "DQ") == 0) {
        // do nothing
    } else if (strcmp(cmd, "MQ") == 0) {
        // do nothing
    } else if (strcmp(cmd, "RQ") == 0) {
        // do nothing
    } else if (strcmp(cmd, "IC") == 0) {
        // do nothing
    } else if (strcmp(cmd, "AC") == 0) {
        // do nothing
    } else if (strcmp(cmd, "LC") == 0) {
        // do nothing
    } else {
        printf("Comando invalido\n");
    }
    fgets(linha, MAXL, stdin);
    cmd[0] = toupper(linha[0]);
    cmd[1] = toupper(linha[1]);
    cmd[2] = '\0'; // add null terminator to the end of the string
}
    printf("Obrigado. Ate a proxima.\n");
}

void cmdInserirEstudante(char* linha){

    
    estudante e;
    char cmd;
    char *login, *nome, *localidade, *universidade;
    int idade;

    if(sscanf(linha,"%c %s %[^\t\n] %d %[^\t\n] %[^\t\n]", &cmd, login, nome, &idade, localidade, universidade)!=6){
        printf("Dados invalidos\n"); return NULL; 
    }
    if(verificaLogin(login) == 1){
        printf("Utilizador ja existente.\n");
        return NULL;
    }
    else{
        e = criaEstudante(login, nome, idade, localidade, universidade);
    }
    printf("Registo do estudante executado.\n");
}

void cmdConsultaDadosEstudante(char* linha){

    char cmd;
    char *login;
    if(sscanf(linha,"%c %s", &cmd, login)!=2){
        printf("Dados invalidos\n"); 
        return NULL;
    }
    else{
        
    }
    
    
}