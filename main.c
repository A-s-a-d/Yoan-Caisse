#include "definitions.h"
void mettre_en_majuscules(char ch[])
{
        for (int i = 0; ch[i] != '\0'; ++i)
                ch[i] = toupper(ch[i]);
}

void afficher_menu()
{
        printf("Entrez votre choix :\n"
               "[0] Quitter\n"
               "[1] Afficher la liste des produits\n"
               "[2] Ajouter un produit au panier\n"
               "[3] Retirer un produit du panier\n"
               "[4] Afficher le contenu du panier\n"
               "[5] Appliquer remise client\n"
               "[6] Payer\n");
}

int main(void)
{
        int reponse = -1;
        /* lit le fichier de base de donnees des clients, et le charge en memoire */
        printf("Chargement fichier clients...\n");
        ouvrir_fichier();
        personnes_remplir_liste();
        fermer_fichier();


        for (int i = 0; i < NB_PERS; i++)
        {
                /* code */
                personne_afficher(PERSONNES[i]);
        }
        


        return 0;


        /* Menu client */
        do
        {
                afficher_menu();
                reponse = lire_int();

                switch (reponse)
                {
                case 0:
                        puts("A bientot.");
                        break;
                case 1:
                        produit_afficher_liste();
                        break;
                case 2:
                        panier_ajouter();
                        break;
                case 3:
                        panier_supprimer();
                        break;
                case 4:
                        panier_afficher();
                        break;
                case 5:
                        CLIENT_FIDELE = panier_remise_client();
                        break;
                case 6:
                        panier_payer();
                        break;
                default:
                        printf("Reponse incorrecte.\n");
                }
        } while (reponse != 0);
}
