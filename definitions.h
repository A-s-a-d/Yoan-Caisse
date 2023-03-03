#ifndef DEFINITIONS_H_GUARD
#define DEFINITIONS_H_GUARD

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>
#include <ctype.h>

/*
 * Cree les type "CHXY", qui sont des chaines de XY caracteres
 * (+ 1 caractere de fin de chaine)
 */
typedef char CH50[51];
typedef char CH30[31];
typedef char CH20[21];
typedef char CH10[11];

#include "fichiers.h"
#include "utils.h"
#include "panier.h"
#include "personnes.h"
#include "produits.h"

#define A_FAIRE() do {                      \
    assert(0 && "PAS ENCORE IMPLEMENTE"); \
} while(0)


void mettre_en_majuscules(char[]); 



#endif // DEFINITIONS_H_GUARD
