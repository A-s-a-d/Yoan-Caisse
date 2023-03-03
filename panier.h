#ifndef PANIER_H_GUARD
#define PANIER_H_GUARD

#include "definitions.h"
#include "produits.h"
#include "utils.h"


/*
 * PANIER_PRODS_QTE contient la quantite de chaque produit du meme indice que
 * dans le tableau PRODUITS.
 * Par exemple, si PANIER_PRODS_QTE[3] == 2, alors c'est que le client a demande
 * d'acheter 2 lots de "LEGUMES" (voir produits.c).
 */
extern int     PANIER_PRODS_QTE[MAX_PRODUITS];

/*
 * PRIX_TOTAL stock la valeur du prix d'achat du panier avant les remises.
 * 
 */
extern float   PRIX_TOTAL                    ;

/*
 *  CLIENT_FIDELE, ceci nous permet de savoir si le client est un de nos clients fidèles
 * 
 */
extern bool    CLIENT_FIDELE                 ;

/* 
 * panier_remise_client
 * fonction : elle permet de voir si le client peux avoir une remise
 * entrees :  aucun paramètre est passé, mais elle accedera à la variable globale PRIX_TOTAL
 * sortie :   un boolean
 * variables globales modifiées : aucune
 */
bool panier_remise_client(void);

/* 
 * panier_initialiser
 * fonction : cette procedure permet d'initialiser l'etat du panier pour chaque client
 * entrees :  aucun paramètre passé, mais elle accédera aux variable globale, PRIX_TOTAL, CLIENT_FIDELE, PANIER_PRODS_QTE
 * sortie :   elle a pas de type de retour, ( c'est une procedure )
 * variables globales modifiées : PANIER_PRODS_QTE, CLIENT_FIDELE, PRIX_TOTAL
 */
void panier_initialiser(void);

/* 
 * panier_afficher
 * fonction : cette procèdure va itérer sur le panier du client pour afficher les achats.
 * entrees :  aucun paramètre est passé, mais elle aura accès aux variables globales
 * sortie :   elle à pas de type de retour, 
 * variables globales modifiées : aucune.
 */
void panier_afficher(void);

/* 
 * panier_payer
 * fonction : cette procédure va nous permettre de voir si l'utilisateur est un client fidèle, puis de lui informer sur le prix
 * entrees :  aucun paramètre est passé, mais elle aura accès aux variables globales
 * sortie :   elle à pas de type de retour, 
 * variables globales modifiées : aucune
 */
void panier_payer(void);

/* 
 * panier_ajouter
 * fonction : cette procédure va nous permettre de donner la main à l'utilisateur, qui va saisir le produit à ajouter et aussi la quantité d'ajôut
 * entrees : aucun paramètre est passé, mais elle aura accès aux variables globales et aussi à la saisie de l'utilisateur / client
 * sortie :  elle à pas de type de retour, 
 * variables globales modifiées : PANIER_PRODS_QTE, PRIX_TOTAL
 */
void panier_ajouter(void);

/* 
 * panier_supprimer
 * fonction : cette procédure va nous permettre de donner la main à l'utilisateur, qui va saisir le produit à supprimer et aussi la quantité de suppression
 * entrees : aucun paramètre est passé, mais elle aura accès aux variables globales et aussi à la saisie de l'utilisateur / client 
 * sortie : elle à pas de type de retour, 
 * variables globales modifiées : PANIER_PRODS_QTE, PRIX_TOTAL
 */
void panier_supprimer(void);

#endif // PANIER_H_GUARD
