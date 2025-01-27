
#ifndef EXERCICE_POINTEUR_EXO_H
#define EXERCICE_POINTEUR_EXO_H

int longueur(const char *chaine);
void copie(char *dest, const char *source);
void concatenate(char *dest, const char *source);
void concatenate2(char *dest, const char *source);
int compare(const char *, const char *);
char *cherche_char(const char *chaine, char caractere);
void inversion_chaine(char *);
void to_upper(char *);
void to_lower(char *);
char *chercher_mot(const char *, const char *);
void sous_chaine(const char *, char *, int, int);
void supprime_charactere(char *chaine, char caractere);
int compte_mot(const char *);
void afficherEtatMot(const char* mot, const bool* lettresDevinees, int longueur);
void jeuDuPendu(const char* mot);
#endif //EXERCICE_POINTEUR_EXO_H
