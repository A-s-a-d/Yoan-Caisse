#include "utils.h"
#include <stdio.h>  // pour fgets, ...
#include <stdlib.h> // pour atoi, atof, ...
#include <string.h> // pour strlen, ...

void chomp(char str[])
{
    int l = strlen(str) - 1;
//  Si le dernier caractere avant le '\0' final est un '\n',
//  on ecrase ce dernier avec un '\0' pour terminer la chaine
    if (l > 0 && str[l] == '\n')
        str[l] = '\0';
}

void lire_chaine(char str[], int max_chars)
{

    fgets(str,          // tableau ou stocker la chaine
          max_chars,    // nb max de caracteres a stocker
          stdin);       // lire depuis le clavier
    chomp(str);
}

// atoi() : ASCII-to-int (aussi pour les short)
// atol() : ASCII-to-long (il existe aussi atoll)
// atof() : ASCII-to-float (en vrai, ASCII-to-double)

char  lire_char()
{
    char str[2] = {0};
    lire_chaine((str),2);
    return str[0];
}

short  lire_short()
{
    char str[51] = {0};
    lire_chaine((str),51);
    return atoi((str));
}

int    lire_int()
{
    char str[51] = {0};
    lire_chaine((str),51);
    return atoi((str));
}

long   lire_long()
{
    char str[51] = {0};
    lire_chaine((str),51);
    return atol((str));
    
}

float  lire_float()
{
    char str[51] = {0};
    lire_chaine((str),51);
    return atof((str));
}

double lire_double()
{
    char str[51] = {0};
    lire_chaine((str),51);
    return atof((str));
}

/* Pour information, les fonctions ci-dessus ont 
 * ete obtenues grace a l'utilisation d'une macro 
 * qui m'a permis de creer des fonctions tres proches
 *
 * #define LIRE(type, fonction)            \
 * type lire_##type() {                    \
 *     char str[51] = {0};                 \
 *     lire_chaine((str),51);              \
 *     return fonction((str));             \
 * }                                       \
 * type lire_##type()
 *
 *
 * LIRE(short,  atoi);
 * LIRE(int,    atoi);
 * LIRE(long,   atol);
 * LIRE(float,  atof);
 * LIRE(double, atof);
 */
