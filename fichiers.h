#ifndef FICHIERS_H_GUARD
#define FICHIERS_H_GUARD
#include "definitions.h"

#define NOM_BDD       "clients.bdd"

/* Descripteur du fichier NOM_BDD dans le programme */
extern FILE* CLIENTS;

/*
 *  Essaie d'ouvrir le fichier "clients.bdd". Si le fichier n'existe pas, il le crée.
 *  Renvoie une valeur négative s'il y a eu un problème d'entrée-sortie, et 0 sinon.
 */
int ouvrir_fichier();


/*
 *  Essaie d'ouvrir le fichier "clients.bdd". Si le fichier n'existe pas, il le crée.
 *  Si le fichier existe, il efface son contenu. 
 *  Cette fonction est utile pour créer un fichier NOM_BDD vide.
 *  Renvoie une valeur négative s'il y a eu un problème d'entree-sortie, et 0 sinon.
 */
int recreer_fichier();

/*
 * Ferme le fichier NOM_BDD
 */
void fermer_fichier();


/*
 * Indique si le fichier de base de données est ouvert (true) ou pas (false).
 */
bool fichier_ouvert();

/*
 * Lit une ligne dans le fichier, et la stocke dans la chaîne donnée en paramètre.
 * Retire le '\n' final.
 */
void lire_ligne(CH50 ligne);


/*
 * Écrit le contenu de la chaîne ligne dans le fichier NOM_BDD s'il est ouvert.  
 * Ajoute un '\n' en fin de ligne.
 */
void ecrire_ligne(CH50 ligne);

/*
 * Renvoie true si on est arrive en fin de fichier NOM_BDD, et false sinon.
 */
bool fin_de_fichier();

#endif // FICHIERS_H_GUARD
