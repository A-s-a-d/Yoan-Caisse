#include "panier.h"
#include "personnes.h"
#include "produits.h"
#include "fichiers.h"

int PANIER_PRODS_QTE[MAX_PRODUITS] = {0};
float PRIX_TOTAL = 0.0;
bool CLIENT_FIDELE = false;

bool panier_remise_client(void)
{

    printf("Faites-vous partie du programme fidelite ? (o/n) ");
    // char reponse = lire_char();
    // bool clientValid = false;
    // Personne client;
    // char ligne[51];

    // if (reponse == 'o')
    // {
    //     // demander au client les informations
    //     // lire le nom
    //     lire_chaine(ligne, 30);
    //     strncpy(client.nom, ligne, 30);

    //     // lire le prenom
    //     lire_chaine(ligne, 20);
    //     strncpy(client.pnom, ligne, 20);

    //     // lire le telephone
    //     client.tel = lire_long();

    //     // chercher dans la liste des personnes
    //     int res = personne_rechercher(client);

    //     if (res != -1)
    //         clientValid = true;
    // }

    // return clientValid;
    return false;
}

void panier_initialiser(void)
{
    for (int i = 0; i < MAX_PRODUITS; ++i)
        PANIER_PRODS_QTE[i] = 0;

    PRIX_TOTAL = 0.0;
}

void panier_afficher(void)
{
    /* TODO
     * Lit la quantite de chaque produit dans le tableau des quantites. Si la
     * quantite d'un produit est positive, alors on affiche le produit, sa
     * quantite, et le prix total par produit.
     * On affiche un produit/quantite/total par ligne.
     * On affiche le prix total à la fin sur une ligne à part, et on retourne à
     * la ligne.
     */
    for (int i = 0; i < MAX_PRODUITS; ++i)
    {

        if (PANIER_PRODS_QTE[i] > 0)
        {
            printf("@produit: %s/ @qty: %i/ @prix: %f\n", NOMS_PRODUITS[i], PANIER_PRODS_QTE[i], PANIER_PRODS_QTE[i] * PRIX_PRODUITS[i]);
        }
    }
    printf("PRIX_TOTAL = %f\n", PRIX_TOTAL);
}

void panier_payer(void)
{
    float prix = PRIX_TOTAL;
    panier_afficher();
    if (!CLIENT_FIDELE)
    {
        printf("Faites-vous partie du programme fidelite ? (o/n) ");
        char reponse = lire_char();
        if (reponse == 'o')
        {
            CLIENT_FIDELE = true;
        }
    }

    if (CLIENT_FIDELE)
    {
        float remise = 0.0;
        if (prix >= 80)
        {
            prix *= .90;
            remise = 10;
        }
        else if (prix >= 15)
        {
            prix *= .95;
            remise = 5;
        }
        printf("Total apres remise : %.2f (%.0f%% de remise)\n", prix, remise);
    }
}
