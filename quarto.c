#include <stdio.h>
#include "quarto.h"
#include "sistema.h"

struct _quarto{
    char codigo[OUTROS];
    char loginGerente[OUTROS];
    char nomeResi[NOMES];
    char universidade[NOMES];
    char local[NOMES];
    int andar;
    char descrição[DESCRICAO];
    char estado[OUTROS];
};