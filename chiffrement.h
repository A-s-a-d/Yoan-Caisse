#ifndef CHIFFREMENT_H_GUARD
#define CHIFFREMENT_H_GUARD

#include "definitions.h"

#define CLE_DEFAUT 26

extern int CLE;

/*
 * crypto_choix_cle
 * fonction :
 * entrées :
 * sortie :
 * variables globales modifiées
 */
void crypto_choix_cle(int);

/*
 * crypto_chiffrer
 * fonction :
 * entrées :
 * sortie :
 * variables globales modifiées
 */
void crypto_chiffrer(CH50);

/*
 * crypto_dechiffrer
 * fonction :
 * entrées :
 * sortie :
 * variables globales modifiées
 */
void crypto_dechiffrer(CH50);

#endif // CHIFFREMENT_H_GUARD
