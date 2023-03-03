#ifndef PRODUITS_H_GUARD
#define PRODUITS_H_GUARD

#define MAX_PRODUITS  100

/*
 * Declare un tableau de noms de MAX_PRODUITS produits appele NOMS_PRODUITS
 */
extern CH50 NOMS_PRODUITS[MAX_PRODUITS];

/*
 * Declare un tableau  de MAX_PRODUITS prix appele PRIX_PRODUITS
 */
extern float PRIX_PRODUITS[MAX_PRODUITS];

/*
 * NB_PRODS indique le nombre de produits disponibles.
 */
extern int  NB_PRODS;

/*
 * Recherche un produit dans le tableau <NOMS_PRODUITS>.
 * Si <nom> a ete trouve, renvoie son indice dans <NOMS_PRODUITS>, et -1 sinon.
 */
int produit_rechercher(CH50 nom);

/*
 * Affiche la liste des produits disponibles dans le magasin.
 */
void produit_afficher_liste();

#endif // PRODUITS_H_GUARD
