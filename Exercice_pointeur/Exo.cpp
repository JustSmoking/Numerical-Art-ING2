#include "Exo.h"
#include <iostream>
#include <stdio.h>
#include <cstring>

int longueur(const char *chaine){
    int i = 0;
    while (*chaine != '\0'){
        chaine++;
        i++;
    }
    return i;
}
void copie(char *dest, const char *source){
    while (*source != '\0'){
        *dest = *source;
        source++;
        dest++;
    }
    *dest = '\0';
}
void concatenate(char *dest, const char *source){
    while (*source != '\0'){
        dest++;
        if (*dest == '\0'){
            *dest = *source;
            source++;
        }

    }
    *dest = '\0';
}

int compare(const char *chaine1, const char *chaine2){
    int i = longueur(chaine1);
    int j = longueur(chaine2);

    while (*chaine1 != '\0' || *chaine2 != '\0' ){
        if(*chaine1 == *chaine2){
            chaine1++;
            chaine2++;
            if (*chaine1 == '\0' || *chaine2 == '\0'){
                if (i < j){
                    return -1;
                } else if (i > j){
                    return 1;
                } else if (i == j){
                    return 0;
                }
            }
        }else if (*chaine1 < *chaine2){
            return -1;
        } else if (*chaine1 > *chaine2){
            return 1;
        }
    }

}
char *cherche_char(const char *chaine, char caractere){
    while (*chaine !='\0')
    {
        if(*chaine == caractere)
        {
            return (char*)caractere;
        }
        chaine++;
    }
    return NULL;
}

void inversion_chaine(char *chaine){
    int Var = longueur(chaine);
    char chaineTampon[longueur(chaine)];
    while (*chaine != '\0'){
        for (int i = Var - 1; i >= 0 ; i--) {
            chaineTampon[i] = *chaine;
            chaine++;
        }
    }
    for (int i = 0; i < Var; ++i) {
        std::cout<<chaineTampon[i];

    }

}

void to_upper(char *chaine){
    while (*chaine != '\0'){
        if (*chaine < 97){
            chaine++;
        } else{
            *chaine -= 32;
            chaine++;
        }
    }
}

void to_lower(char *chaine){
    while (*chaine != '\0'){
        if (*chaine > 97){
            chaine++;
        } else{
            *chaine += 32;
            chaine++;
        }
    }
}

char *chercher_mot(const char *phrase, const char *mot){
    char *j = new char[longueur(mot) + 1];
    char *j_D = j;
    const char* mot_d = mot;

    while (*phrase != '\0'){
        if (*phrase == *mot){
            *j = *phrase;
            mot++;
            j++;
        } else{
            mot = mot_d;
            j = j_D;
        }
        phrase++;

        if (*mot == '\0'){
            *j = '\0';
            return j_D;
        }

    }
    delete[]j_D;
    return nullptr;
}
// Exercice Avancé

void sous_chaine(const char *source,char *dest, int debut, int longueur){
    int i = 0;
    int j = 0;
    while (i <= debut){
        source++;
        i++;
    }
    while (*source != '\0' && j <= longueur){
        *dest = *source;
        source++;
        dest++;
        j++;
    }
    *dest = '\0';
    std::cout<< dest - j << std::endl;
}

void supprime_charactere(char *chaine, char caractere){
    char* src = chaine;
    char* dest = chaine;
    while (*src != '\0') {
        if (*src != caractere) {
            *dest = *src;
            dest++;
        }
        src++;
    }
    *dest = '\0';
}
int compte_mot(const char *phrase){
    bool inWord = false;
    int count = 0;
    while (*phrase != '\0') {
        if (isspace(*phrase)) {
            inWord = false;
        } else if (!inWord) {
            inWord = true;
            count++;
        }
        phrase++;
    }
    return count;
}
void afficherEtatMot(const char* mot, const bool* lettresDevinees, int longueur) {
    for (int i = 0; i < longueur; ++i) {
        if (lettresDevinees[i]) {
            std::cout << mot[i] << " ";
        } else { std::cout << "_ "; }
    }
    std::cout << std::endl;
}
void jeuDuPendu(const char* mot){
    int longueur = strlen(mot);
    int essaisRestants = 6;
    bool* lettresDevinees = new bool[longueur]();
    char* lettresEssayees = new char[26];
    int essais = 0;
    while (essaisRestants > 0) {
        afficherEtatMot(mot, lettresDevinees, longueur);
        std::cout << "Essais restants : " << essaisRestants << std::endl;
        std::cout << "Lettres essayées : ";
        for (int i = 0; i < essais; ++i){
            std::cout << lettresEssayees[i] << " ";
        }
        std::cout << std::endl;
        std::cout << "Entrez une lettre : ";
        char lettre; std::cin >> lettre;
        bool dejaEssayee = false;
        for (int i = 0; i < essais; ++i) {
            if (lettresEssayees[i] == lettre) {
                dejaEssayee = true;
                break;
            }
        } if (dejaEssayee) {
            std::cout << "Vous avez déjà essayé cette lettre." << std::endl;
            continue;
        }
        lettresEssayees[essais++] = lettre;
        bool lettreTrouvee = false;
        for (int i = 0; i < longueur; ++i) {
            if (mot[i] == lettre) {
                lettresDevinees[i] = true;
                lettreTrouvee = true;
            }
        } if (!lettreTrouvee)
        {
            essaisRestants--;
        }
        bool toutDevine = true;
        for (int i = 0; i < longueur; ++i) {
            if (!lettresDevinees[i]) {
                toutDevine = false;
                break;
            }
            if (toutDevine) {
                std::cout << "Félicitations ! Vous avez deviné le mot : " << mot << std::endl;
                delete[] lettresDevinees;
                delete[] lettresEssayees;
                return;
            }
        }
    }
    std::cout << "Dommage ! Vous avez perdu. Le mot était : " << mot << std::endl;
    delete[] lettresDevinees;
    delete[] lettresEssayees;
}