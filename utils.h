#ifndef UTILS_H_GUARD
#define UTILS_H_GUARD


/*
 * chomp : "mange" (supprime) le '\n' final de la chaine passee en parametre
 *         s'il existe.
 *
 * Entrees :
 *      str: la chaine a examiner
 * Sortie :
 *      rien.
 */
void chomp(char str[]);

/*
 * lire_chaine : lit une chaine de caracteres depuis l'entree standard (c-a-d :
 *               le clavier dans notre cas). On ne peut pas lire plus de
 *               <max_chars> caracteres (la fonction rajoute automatiquement un
 *               '\0' en fin de chaine). Le '\n' final est aussi supprime s'il
 *               y en a un.
 * Entrees :
 *      str : le tableau ou stocker la chaine de caractere lue sur le clavier.
 *      max_char : le nombre maximum de caracteres qu'on a le droit de lire et
 *                 stocker dans <str>
 *
 */
void lire_chaine(char str[], int max_chars);

/*
 * lire_short, lire_int, lire_long, lire_float, lire_double :
 * fonctions qui lisent une valeur entree au clavier et la convertissent dans
 * le type demande. Permet de se passer de la fonction scanf et des problemes
 * de '\n' residuels lorsqu'on "melange" des lectures de nombres (scanf("%d",
 * &v);) et des lectures de chaine (fgets(tab,maxc,stdin), ou simplement
 * lire_chaine).
 *
 * Entrees :
 *      rien
 * Sortie :
 *      la valeur convertie dans le type demande, ou 0 s'il y a eu un probleme.
 *
 */
char   lire_char();
short  lire_short();
int    lire_int();
long   lire_long();
float  lire_float();
double lire_double();


#endif // UTILS_H_GUARD


