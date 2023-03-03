#include "definitions.h"
#include "fichiers.h"
#include "chiffrement.h"

Personne PERSONNES[MAX_PERSONNES];
int NB_PERS;

void personnes_remplir_liste()
{
    if (NB_PERS == 0 && !fichier_ouvert())
    {
        printf("La base de donnee n'est pas ouverte !");
        return;
    }
    char ligne[51];
    Personne p;

    while (!fin_de_fichier())
    {
        lire_ligne(ligne);


        p = personne_creer(ligne);

        printf("########\n");
        personne_afficher(p);
        printf("########\n");

        if (personne_rechercher(p) == -1)
        {
            personne_ajouter(p);
            NB_PERS++;
        }
    }
}

int personne_cmp(Personne p1, Personne p2)
{
    int cmp;

    cmp = strcmp(p1.nom, p2.nom);
    if (cmp != 0)
        return cmp;

    cmp = strcmp(p1.pnom, p2.pnom);
    if (cmp != 0)
        return cmp;

    if (p1.tel > p2.tel)
        cmp = 1;
    else if (p1.tel < p2.tel)
        cmp = -1;
    else
        cmp = 0;

    return cmp;
}

int personne_rechercher(Personne p)
{
    for (int i = 0; i < NB_PERS; ++i)
        if (personne_cmp(p, PERSONNES[i]) == 0)
            return i;

    return -1;
}

int personne_ajouter(Personne p)
{
    if (NB_PERS >= MAX_PERSONNES)
        return MAX_PERSONNES;

    int idx = personne_rechercher(p);

    if (idx != -1)
        return idx;

    PERSONNES[NB_PERS++] = p;

    return 0;
}

/* une meilleure solution est d'utiliser isspace()  (voir la doc de ctype.h) */
bool est_un_espace(char c)
{
    return c == ' ' || c == '\t';
}

/* Fonction utilitaire.
 * Elle ne sert que dans ce fichier, c'est pourquoi elle n'est pas exposée dans
 * personnes.h.
 *
 * XXX Note : peut-être que vous n'aurez pas besoin de la fonction
 * copier_prochain_champ, mais le fait qu'elle existe devrait vous donner un
 * indice sur une façon de réaliser personne_creer…
 */
int copier_prochain_champ(char dst[], int taille, CH50 ligne, int decalage)
{

    int i;
    printf("dans la fonction copie prochaine ligne = %s\n", ligne);
    for (i = decalage; i < decalage + taille; ++i)
    {
        /* code */

        if (est_un_espace(ligne[i]))
        {
            break;
        }
        printf("ligne[i] = %c\n", ligne[i]);

        dst[i] = ligne[i];
    }

    dst[i] = '\0';

    return i; // indice du prochain caractère à traiter
}

Personne personne_creer(CH50 ligne)
{
    /* indice : utiliser la fonction strtoul() pour convertir une chaîne de
     * caractères en nombre entier non-signé.
     * Exemple d'utilisation :
     * unsigned nb;
     * // ...
     * nb = strtoul(chaine_a_convertir,NULL,10);
     *
     *  => chaine_a_convertir est la chaîne de caractère qui contient le nombre
     *     sous forme caractères
     *  => NULL indique une adresse « vide » (laisser tel quel)
     *  => 10 indique qu'on veut lire un nombre en base 10.
     *     NOTE: On pourrait écrire 0 à la place de 10, ce qui signifie «
     *     détermine la base tout seul ». Voir la doc de strotoul pour savoir
     *     comment s'en servir.
     */

    Personne p;
    

    // lire le nom
    int prochain_decalage = copier_prochain_champ(p.nom, 30, ligne, 0) + 1;


    // lire le prenom
    printf("prochain decalage pour le prenom = %d\n", prochain_decalage);
    printf("sizeof(p.pnom) = %d\n", sizeof(p.pnom));

    prochain_decalage = copier_prochain_champ(p.pnom, 20, ligne, prochain_decalage) + 1;

    // lire le téléphone
    printf("prochain decalage pour le tel = %d\n", prochain_decalage);
    p.tel = strtoul(&(ligne[prochain_decalage]), NULL, 10);

    return p;
}

void personne_afficher(Personne p)
{
    printf("@personne\t .nom = %s \t .pnom = %s \t .tel = %u\n", p.nom, p.pnom, p.tel);
}
