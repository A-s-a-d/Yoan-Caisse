#include <stdio.h>
#include <stdlib.h>

#include "fichiers.h"
#include "utils.h"

FILE* CLIENTS;
bool FICHIER_OUVERT = false;

bool fichier_ouvert()
{
    return FICHIER_OUVERT;
}

int ouvrir_fichier()
{
    CLIENTS = fopen(NOM_BDD, "a+");
    FICHIER_OUVERT = CLIENTS != NULL;

    return -( CLIENTS == NULL );
}

int recreer_fichier()
{
    CLIENTS = fopen(NOM_BDD, "w+");
    FICHIER_OUVERT = CLIENTS != NULL;

    return -( CLIENTS == NULL );
}

void fermer_fichier()
{
    fclose(CLIENTS);
    FICHIER_OUVERT = false;
}

void lire_ligne(CH50 ligne)
{
    fgets(ligne, sizeof(CH50), CLIENTS);
    chomp(ligne);
}

void ecrire_ligne(CH50 ligne)
{
    if (FICHIER_OUVERT)
        fprintf(CLIENTS, "%s\n", ligne);
    else
        printf("Erreur: %s n'est pas ouvert\n", NOM_BDD);
}

bool fin_de_fichier()
{
    return feof(CLIENTS) != 0;
}
