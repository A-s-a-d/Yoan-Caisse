#include "definitions.h"
#include "utils.h"

int NB_PRODS = 11;

/*
 * La base des produits est fixee a la compilation.
 * Rajouter autant qu'on veut a la liste.
 */
CH50 NOMS_PRODUITS[MAX_PRODUITS] = {
    /* 0 */ "CEREALES",
    /* 1 */ "LAIT",
    /* 2 */ "FRUITS",
    /* 3 */ "LEGUMES",
    /* 4 */ "JOUET",
    /* 5 */ "OUTIL",
    /* 6 */ "BOEUF",
    /* 7 */ "POULET",
    /* 8 */ "PIZZA",
    /* 9 */ "QUICHE",
    /* 10 */ "DETERGENT"};

float PRIX_PRODUITS[MAX_PRODUITS] = {
    /* 0 */ 5,
    /* 1 */ 2,
    /* 2 */ 4,
    /* 3 */ 4.5,
    /* 4 */ 10,
    /* 5 */ 12.85,
    /* 6 */ 7,
    /* 7 */ 5,
    /* 8 */ 6.5,
    /* 9 */ 7.5,
    /* 10 */ 13.25};

void produit_afficher_liste()
{
    for (int i = 0, cpt = 0; i < NB_PRODS; ++i, ++cpt)
    {
        printf("[%d] %s\t", i + 1, NOMS_PRODUITS[i]);
        if (cpt == 5)
        {
            cpt = 0;
            puts("");
        }
    }
}

int produit_rechercher(CH50 nom)
{
    for (int i = 0; i < NB_PRODS; ++i)
    {
        if (strcmp(nom, NOMS_PRODUITS[i]) == 0)
            return i;
    }
    return -1;
}

void panier_ajouter(void)
{
    CH50 prod = {0};
    int idx = -1;
    do
    {
        produit_afficher_liste();
        printf("Quel est le nom du produit ? ");
        lire_chaine(prod, sizeof(CH50));
        idx = produit_rechercher(prod);
        printf("############################\n");
        printf("index: %d\n",idx);
        printf("############################\n");
        if (idx == -1)
        {
            printf("Nom de produit invalide.\n");
        }
    } while (idx == -1);
    printf("Quelle est la quantite souhaitee ? ");
    PANIER_PRODS_QTE[idx] = lire_int();
    
    printf("############################\n");
    printf("prix en plus: %f\n",(PANIER_PRODS_QTE[idx] * PRIX_PRODUITS[idx]));
    printf("############################\n");

    PRIX_TOTAL += (PANIER_PRODS_QTE[idx] * PRIX_PRODUITS[idx]);
}

void panier_supprimer(void)
{
    CH50 prod = {0};
    int idx = -1;

    do
    {
        panier_afficher();
        printf("Quel produit voulez-vous supprimer ? ");
        lire_chaine(prod, sizeof(CH50));
        idx = produit_rechercher(prod);
        if (idx == -1)
        {
            printf("Nom de produit invalide.\n");
        }
    } while (idx == -1);

    printf("Quelle est la quantite souhaitee ? ");
    int qte = lire_int();
    if (PANIER_PRODS_QTE[idx] < qte)
        qte = PANIER_PRODS_QTE[idx];

    PRIX_TOTAL -= (qte * PRIX_PRODUITS[idx]);
    PANIER_PRODS_QTE[idx] -= qte;
}
