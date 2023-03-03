#ifndef PERSONNES_H_GUARD
#define PERSONNES_H_GUARD

#define MAX_PERSONNES 100

struct personne {
    char nom[31];           // declare une chaine de 30 caracteres
    char pnom[21];          // declare une chaine de 20 caracteres
    unsigned tel;       // numero de telephone
};

/* Maintenant on peut utiliser "Personne" a la place de "struct personne" */
typedef struct personne Personne;

/* Declare qu'il existe un tableau global de MAX_PERSONNES personnes appele PERSONNES */
extern Personne PERSONNES[MAX_PERSONNES];

/*
 * Declare qu'il existe une variable globale appelee NB_PERS qui indique
 * combien de valeurs de type Personne sont stockees dans le tableau PERSONNES.
 */
extern int NB_PERS;

/*
 * Pour chaque ligne lue dans le fichier "clients.bdd", cree une nouvelle valeur
 * de type Personne. Cette personne est cherchee dans la base, et si elle
 * n'existe pas deja, elle est rajoutee.
 */
void personnes_remplir_liste(void);

/*
 * Affiche le contenu d'une struct personne / Personne à l'écran.
 */
void personne_afficher(Personne p);

/*
 * Compare 2 personnes. Ordre de comparaison :
 *      1. Nom de famille
 *      2. Prenom
 *      3. Numero de telephone
 *
 * Renvoie une valeur
 *      - positive si <p1> > p2 (dans l'ordre lexicographique/du dictionnaire),
 *      - negative si <p1> < p2 (dans l'ordre lexicographique/du dictionnaire),
 *      - nulle si <p1> == <p2>
 */
int personne_cmp(Personne p1, Personne p2);

/*
 * Cherche une personne <p> dans le tableau <PERSONNES>.
 * Si <p> a ete trouve, renvoie son indice dans <PERSONNES>, et -1 sinon.
 */
int personne_rechercher(Personne p);

/*
 * Ajoute <p> a la fin du tableau <PERSONNES> si <p> n'existe pas deja dedans.
 * Met a jour NB_PERS si necessaire, et verifie qu'il y a la place de rajouter
 * une personne.
 * Retourne 0 si l'ajout a ete fait, MAX_PERSONNES si le tableau est plein, ou
 * -1 <p> existait deja.
 */
int personne_ajouter(Personne p);

/*
 * Cree une valeur de type Personne a partir d'une ligne lue dans le fichier
 * "clients.bdd"
 * Retourne une valeur de type Personne une fois la ligne traitee.
 */
Personne personne_creer(CH50 ligne);

/*
 * Ouvre le fichier des clients, et remplit le tableau de personnes avec.
 */
void personnes_remplir_liste();


#endif // PERSONNES_H_GUARD
