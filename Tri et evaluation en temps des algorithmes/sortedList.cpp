#include "sortedList.h"
#include <iostream>
#include<chrono>
#include<fstream>

/*  Pour chaque fonction de tri
 *  On fait une copie du tableau T dans K
 *  On lance le timer
 *  On effectue le trie
 *  On calcule la difference de temps
 *  Et on libere la memoire en supprimant le tableau de Copie
 *  fileStream permet de lire les 10 premiers entiers d'un fichier
 */

void bubbleSort(int *t, int m) {
    int temp = 0;
    int *k = new int[10];
    std::cout << "Tableau non trie " << std::endl;
    for (unsigned int i = 0; i < m; i++) {
        std::cout << t[i] << " ";
        k[i] = t[i];
    }
    std::cout << std::endl;
    auto begin = std::chrono::high_resolution_clock::now();
    for (unsigned int i = 0; i < m - 1; i++) {
        for (unsigned j = 0; j < m - i - 1; j++) {
            if (k[j] > k[j + 1]) {
                temp = k[j];
                k[j] = k[j + 1];
                k[j + 1] = temp;
            }
            int o = 0;
            std::cout << " en cour de triage" << std::endl;
            while (o < m) {
                std::cout << k[o] << " ";
                o++;
            }
        }
    }
    auto end = std::chrono::high_resolution_clock::now();
    std::cout << std::endl;
    std::chrono::duration<double> time = end - begin;
    std:: cout << "Duree d'execution = " << time.count() << "s";
    delete[] k;
}

void selectionSort(int t[], int m) {
    int temp = 0;
    int *k = new int[10];
    std::cout << "Tableau non trie " << std::endl;
    for (unsigned int i = 0; i < m; i++) {
        std::cout << t[i] << " ";
        k[i] = t[i];
    }
    auto begin = std::chrono::high_resolution_clock::now();
    for (unsigned int i = 0; i < m - 1; i++) {
        int indexMin = i;
        for (unsigned int j = i + 1; j < m; j++) {
            if (k[j] < k[indexMin])
                indexMin = j;
        }
        temp = k[i];
        k[i] = k[indexMin];
        k[indexMin] = temp;
        int o = 0;
        std::cout << " en cour de triage" << std::endl;
        while (o < m) {
            std::cout << k[o] << " ";
            o++;
        }
    }
    auto end = std::chrono::high_resolution_clock::now();
    std::cout << std::endl;
    std::chrono::duration<double> time = end - begin;
    std:: cout << "Duree d'execution = " << time.count() << "s";
    delete[] k;
}
void insertionSort(int *t, int m) {
    int temp = 0;
    int a = 0;
    int j = 0;
    int *k = new int[10];
    std::cout << "Tableau non trie " << std::endl;
    for (unsigned int i = 0; i < m; i++) {
        std::cout << t[i] << " ";
        k[i] = t[i];
    }
    auto begin = std::chrono::high_resolution_clock::now();
    for (unsigned int i = 0; i < m - 1; i++) {
         a = k[i];
         j = i - 1;
        while (j >= 0 && k[j] > a) {
            k[j + 1] = k[j];
            j = j - 1;
        }
        k[j + 1] = a;
        int o = 0;
        std::cout << " en cour de triage" << std::endl;
        while (o < m) {
            std::cout << k[o] << " ";
            o++;
        }
    }
    auto end = std::chrono::high_resolution_clock::now();
    std::cout << std::endl;
    std::chrono::duration<double> time = end - begin;
    std:: cout << "Duree d'execution = " << time.count() << "s";
    delete[] k;
}

bool fileStream(int *t) {
    int count = 0, i = 0, j;
    //Chemin d'acces au fichier txt!
    std::ifstream fic("Chemin d'acces au fichier ");
    if (!fic) {
        std::cerr << " Erreur lors de l'ouverture du fichier!" << std::endl;
        return false;
    }
    while (fic >> j && count <= 10) {
        t[i++] = j;
    }
    fic.close();
    return true;
}
