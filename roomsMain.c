/*
˚ @author 65623 HENRIQUE MARQUES hc.marques@campus.fct.unl.pt
  @author 66178 TOMÁS PATRÍCIO LOPES tp.lopes@campus.fct.unl.pt
*/
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#include "sistema.h"
#include "estudante.h"
#include "quarto.h"
#include "gerente.h"
#include "messages.h"
#include "constants.h"

#include "dicionario.h"
#include "sequencia.h"

#define MAXL 200

/* Funcoes Prototipo*/
void interpertador(sistema s);
void cmdInserirEstudante(sistema s, char *linha);
void cmdDadosEstudante(sistema s, char *linha);
void cmdInserirGerente(sistema s, char *linha);
void cmdDadosGerente(sistema s, char *linha);
void cmdInserirQuarto(sistema s, char *linha);
void cmdDadosQuarto(sistema s, char *linha);
void cmdModificarEstadoQuarto(sistema s, char *linha);
void cmdRemocaoQuarto(sistema s, char *linha);
void cmdInserirCandidatura(sistema s,char *linha);
void cmdAceitarCandidatura(sistema s, char *linha);
void cmdListarCandidaturas(sistema s, char *linha);
int verifyCmd(char *linha);

int main()
{
    sistema s = criaSistema();
   // interpertador(s);
    destroiSistemaEstudantesGerenteQuartos(s);
    return 0;
}

void interpertador(sistema s){

    char linha[MAXL] = "";

    while (strncmp(linha, "XS", MAX_CMD) != 0){

        printf("> ");
        fgets(linha, MAXL, stdin);

        if(linha[0] == '#' ){
            printf("\n");
        }else if(strncmp(linha, "IE", MAX_CMD) == 0){
            cmdInserirEstudante(s, linha);			
        }else if(strncmp(linha, "DE", MAX_CMD) == 0){
            cmdDadosEstudante(s, linha);
        }else if(strncmp(linha, "IG", MAX_CMD) == 0){
            cmdInserirGerente(s, linha);
        }else if(strncmp(linha, "DG", MAX_CMD) == 0){
            cmdDadosGerente(s, linha);
        }else if(strncmp(linha, "IQ", MAX_CMD) == 0 ){
            cmdInserirQuarto(s, linha);
        }else if(strncmp(linha, "DQ", MAX_CMD) == 0){
            cmdDadosQuarto(s, linha);
        }else if(strncmp(linha, "MQ", MAX_CMD) == 0){
            cmdModificarEstadoQuarto(s, linha);
        }else if(strncmp(linha, "RQ", MAX_CMD) == 0){
            cmdRemocaoQuarto(s, linha);
        }else if(strncmp(linha, "IC", MAX_CMD) == 0){
            cmdInserirCandidatura(s, linha);
        }else if(strncmp(linha, "AC", MAX_CMD) == 0){
            cmdAceitarCandidatura(s, linha);
        }else if(strncmp(linha, "LC", MAX_CMD) == 0){
            cmdListarCandidaturas(s, linha);
        }else if(strncmp(linha, "XS", MAX_CMD) == 0){
            printf(MSG_SAIR);
            printf("\n");
            printf("\n");
            break;
        }else{
            printf(MSG_COMANDO_INVALIDO);
            printf("\n");
        }
        printf("\n");
    }
}

void cmdInserirEstudante(sistema s, char *linha){
    char login[OUTROS] = "";
    char nome[NOMES] = "";
    char localidade[NOMES] = ""; 
    char universidade[NOMES] = "";
    int idade = 0;
    
    sscanf(linha, "%*s %s %[^\n]", login, nome);
    fgets(linha, MAXL, stdin);
    sscanf(linha, "%d %[^\n]", &idade, localidade);
    fgets(linha, MAXL, stdin);
    sscanf(linha, " %[^\n]", universidade);
  
    if((verificaLogin(s, login) != 1) && novoEstudanteSistema(s, login, nome, localidade, universidade, idade)){
        printf(MSG_REGISTO_ESTUDANTE_OK);
        printf("\n");
    }else{
        printf(MSG_UTILIZADOR_EXISTENTE);
        printf("\n");
    }
}

void cmdDadosEstudante(sistema s, char *linha){
    char login[OUTROS] = "";

    if(sscanf(linha, "%*s %s", login) == 1){
        if (existeEstudanteSistema(s, login)){
            estudante e = estudanteSistema(s, login);
            printf("%s, %s, %d anos, %s\n%s", daLoginEstudante(e), daNomeEstudante(e), daIdadeEstudante(e), daLocalidadeEstudante(e), daUniversidadeEstudante(e));
            printf("\n");
        }else{
            printf(MSG_ESTUDANTE_INEXISTENTE);
            printf("\n");
        }
    }else{
        printf(MSG_COMANDO_INVALIDO);
        printf("\n");
    }
}

void cmdInserirGerente(sistema s, char *linha){
    char login[OUTROS] = "";
    char nome[NOMES] = "";
    char universidade[NOMES] = "";

    sscanf(linha, "%*s %s %[^\n]", login, nome);
    fgets(linha, MAXL, stdin);
    sscanf(linha, " %[^\n]", universidade);

    if(verificaLogin(s, login) != 1 && novoGerenteSistema(s, login, nome, universidade)){
        printf(MSG_REGISTO_GERENTE_OK);
        printf("\n");
    }else{
        printf(MSG_UTILIZADOR_EXISTENTE);
        printf("\n");
    }
}

void cmdDadosGerente(sistema s, char *linha){
    char login[OUTROS] = "";

    if(sscanf(linha,"%*s %s", login) == 1){
        if(existeGerenteSistema(s, login)){
            gerente g = gerenteSistema(s, login);
            printf("%s, %s\n%s", daLoginGerente(g), daNomeGerente(g), daUniversidadeGerente(g));
            printf("\n");
        }else{
            printf(MSG_GERENTE_INEXISTENTE);
            printf("\n");
        }
    }else{
        printf(MSG_COMANDO_INVALIDO);
        printf("\n");
    }
}
 

void cmdInserirQuarto(sistema s, char *linha){
    char codigo[OUTROS] = "";
    char loginGerente[OUTROS] = "";
    char nomeResi[NOMES] = "";
    char universidade[NOMES] = "";
    char localidade[NOMES] = "";
    char descricao[DESCRICAO] = "";
    int andar = 0;

    sscanf(linha, "%*s %s %s", codigo, loginGerente);
    fgets(linha, MAXL, stdin);
    sscanf(linha, " %[^\n]", nomeResi);
    fgets(linha, MAXL, stdin);
    sscanf(linha, "%[^\n]", universidade);
    fgets(linha, MAXL, stdin);
    sscanf(linha, "%[^\n]", localidade);
    fgets(linha, MAXL, stdin);
    sscanf(linha, "%d", &andar);
    fgets(linha, MAXL, stdin);
    sscanf(linha, "%[^\n]", descricao);

    if(existeQuartoSistema(s, codigo) != 1){
        if(existeGerenteSistema(s, loginGerente)){
            gerente g = gerenteSistema(s, loginGerente);
            if(strcmp(daUniversidadeGerente(g), universidade) == 0){
                novoQuartoSistema(s, codigo, loginGerente, nomeResi, universidade, localidade, andar, descricao);
                printf(MSG_REGISTO_QUARTO_OK);
                printf("\n");
            }else{
                printf(MSG_OP_NAO_AUTORIZADA);
                printf("\n");
            }
        }else{
            printf(MSG_GERENTE_INEXISTENTE);
            printf("\n");
        }
    }else{
        printf(MSG_QUARTO_EXISTENTE);
        printf("\n");
    }
}

void cmdDadosQuarto(sistema s, char *linha){
    char codigo[OUTROS] = "";

    if(sscanf(linha,"%*s %s", codigo) == 1){

        if(existeQuartoSistema(s, codigo)){
            quarto q = quartoSistema(s, codigo);
            printf("%s, %s\n%s\n%s\n%d\n%s\n%s", daCodigoQuarto(q), daNomeResiQuarto(q), daUniversidadeQuarto(q), daLocalidadeQuarto(q), daAndarQuarto(q), daDescricaoQuarto(q), daEstadoQuarto(q));
            printf("\n");
        }else{
            printf(MSG_QUARTO_INEXISTENTE);
            printf("\n");
        }
    }else{
        printf(MSG_COMANDO_INVALIDO);
        printf("\n");
    }
}

void cmdModificarEstadoQuarto(sistema s, char *linha){    
    char codigo[OUTROS] = "";
    char login[OUTROS] = "";
    char estado[OUTROS] = "";

    if(sscanf(linha, "%*s %s %s %s", codigo, login, estado) == 3){

        if(existeQuartoSistema(s, codigo)){
            quarto q = quartoSistema(s, codigo);
            if(strcmp(login, daLoginGerenteQuarto(q)) == 0){
                if(strcmp(estado, MSG_OCUPADO) == 0 && verificaCandidaturaQuarto(q)){
                    modificaEstadoQuarto(q);
                    printf(MSG_QUARTO_ATUALIZADO);
                    printf("\n");
                }else if(strcmp(estado, MSG_LIVRE) == 0){
                    modificaEstadoQuarto(q);
                    printf(MSG_QUARTO_ATUALIZADO);
                    printf("\n");
                }else{
                    printf(MSG_CANDIDATURAS_ACTIVAS);
                    printf("\n");
                }
            }else{
                printf(MSG_OP_NAO_AUTORIZADA);
                printf("\n");
            }
        }else{
            printf(MSG_QUARTO_INEXISTENTE);
            printf("\n");
        }
    }else{
        printf(MSG_COMANDO_INVALIDO);
        printf("\n");
    }
}

void cmdRemocaoQuarto(sistema s, char *linha){
    char codigo[OUTROS] = "";
    char login[OUTROS] = "";

    if(sscanf(linha, "%*s %s %s", codigo, login) == 2){

        if(existeQuartoSistema(s, codigo)){
            quarto q = quartoSistema(s, codigo);
            if(strcmp(login, daLoginGerenteQuarto(q)) == 0){
                if(verificaCandidaturaQuarto(q)){
                    removeQuartoSistema(s, codigo);
                    apagaQuarto(q);
                    printf(MSG_REMOCAO_QUARTO_OK);
                    printf("\n");
                }else{
                    printf(MSG_CANDIDATURAS_ACTIVAS);
                    printf("\n");
                }
            }else{
                printf(MSG_OP_NAO_AUTORIZADA);
                printf("\n");
            }
        }else{
            printf(MSG_QUARTO_INEXISTENTE);
            printf("\n");
        }
    }else{
        printf(MSG_COMANDO_INVALIDO);
        printf("\n");
    }
}

void cmdInserirCandidatura(sistema s,char *linha){
    char codigo[OUTROS] = "";
    char login[OUTROS] = "";

    if(sscanf(linha, "%*s %s %s", login, codigo) == 2){

        if(existeEstudanteSistema(s, login)){
            estudante e = estudanteSistema(s, login);
            if(daNCandidaturasEstudante(e) < 10){
                if(existeQuartoSistema(s, codigo)){
                    quarto q = quartoSistema(s, codigo);
                    if(strcmp(daEstadoQuarto(q), MSG_LIVRE) == 0){
                        if(verificaCandidaturaEstudante(e, daCodigoQuarto(q)) != 1){
                            adicionaQuartoAEstudante(e, daCodigoQuarto(q));
                            adicionaCandidatoAQuarto(e, q);
                            printf(MSG_REGISTO_CANDIDATURA_OK);
                            printf("\n");
                        }else{
                            printf(MSG_CANDIDATURA_EXISTENTE);
                            printf("\n");
                        }
                    }else{
                        printf(MSG_QUARTO_OCUPADO);
                        printf("\n");
                    } 
                }else{
                    printf(MSG_QUARTO_INEXISTENTE);
                    printf("\n");
                }
            }else{
                printf(MSG_OP_NAO_AUTORIZADA);
                printf("\n");
            } 
        }else{
            printf(MSG_ESTUDANTE_INEXISTENTE);
            printf("\n");
        }
    }else{
        printf(MSG_COMANDO_INVALIDO);
        printf("\n");
    }
}

void cmdAceitarCandidatura(sistema s, char *linha){
    char codigo[OUTROS] = "";
    char loginGerente[OUTROS] = "";
    char loginEstudante[OUTROS] = "";

    if(sscanf(linha, "%*s %s %s %s", codigo, loginGerente, loginEstudante) == 3){

        if(existeQuartoSistema(s, codigo)){
            quarto q = quartoSistema(s, codigo);
            if(strcmp(loginGerente, daLoginGerenteQuarto(q)) == 0){
                estudante e = estudanteSistema(s, loginEstudante);
                if(verificaCandidaturaEstudante(e, daCodigoQuarto(q))){ 
                    removeEstudanteDosQuartos(s, e);
                    removerCandidaturasEstudante(e);
                    removerEstudantesDoQuarto(q);
                    modificaEstadoQuarto(q);
                    printf(MSG_ACEITAR_CANDIDATURA);
                    printf("\n");
                }else{
                    printf(MSG_CANDIDATURA_INEXISTENTE);
                    printf("\n");
                }
            }else{
                printf(MSG_OP_NAO_AUTORIZADA);
                printf("\n");
            } 
        }else{
            printf(MSG_QUARTO_INEXISTENTE);
            printf("\n");
        }
    }else{
        printf(MSG_COMANDO_INVALIDO);
        printf("\n");
    }
}

void cmdListarCandidaturas(sistema s, char *linha){
    char codigo[OUTROS] = "";
    char loginGerente[OUTROS] = "";

    if(sscanf(linha, "%*s %s %s", codigo, loginGerente) == 2){

        if(existeQuartoSistema(s, codigo)){
            quarto q = quartoSistema(s, codigo);
            if(strcmp(loginGerente, daLoginGerenteQuarto(q)) == 0){
                if(verificaCandidaturaQuarto(q) != 1){
                    iterador it = iteradorCandidatos(q);
                    while (temSeguinteIterador(it)){
                        estudante e = (estudante) seguinteIterador(it);
                        printf("%s, %s, %s", daLoginEstudante(e), daNomeEstudante(e), daUniversidadeEstudante(e));
                        printf("\n");
                        
                    }
                    destroiIterador(it);
                }else{
                    printf(MSG_INEXISTENCIA_CANDIDATURAS);
                    printf("\n");
                }
            }else{
                printf(MSG_OP_NAO_AUTORIZADA);
                printf("\n");
            } 
        }else{
            printf(MSG_QUARTO_INEXISTENTE);
            printf("\n");
        }
    }else{
        printf(MSG_COMANDO_INVALIDO);
        printf("\n");
    }
}