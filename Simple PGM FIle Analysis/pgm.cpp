#include "pgm.h"
#include<fstream>
#include <iostream>

int **duplicateMatrixInfo() {
    std::ifstream file("/Users/smoke/CLionProjects/Simple PGM File Analysis/pgm/1.pgm", std::ios::binary);
    if (!file) {
        std::cerr << "Erreur lors de l'ouverture du fichier " << std::endl;
        return 0;
    }
    std::string typePgmfile;
    int hei = 0, wei = 0;
    file >> typePgmfile >> wei >> hei;
    int **matrixVal = new int*[hei];
    if (!matrixVal) {
        std::cerr << "Erreur lors de l'allocation de dynamique " << hei << std::endl;
        return 0;
    }
    for (unsigned int i = 0; i < hei; i++)
        matrixVal[i] = new int[wei];

    unsigned char **matrixBuffer = new unsigned char*[hei];
    if (!matrixBuffer) {
        std::cerr << "Erreur lors de l'allocation dynamique char(*)" << hei << std::endl;
    }
    for (unsigned int i = 0; i < hei; i++)
        matrixBuffer[i] = new unsigned char[wei];

    for (unsigned int i = 0; i < hei; i++) {
        file.read(reinterpret_cast<char *>(matrixBuffer[i]), wei);
    }
    for (unsigned int i = 0; i < hei; i++) {
        for (unsigned int j = 0; j < wei; j++) {
            matrixVal[i][j] = static_cast<int>(matrixBuffer[i][j] );
        }
    }

    for (unsigned int i = 0; i < hei; i++) {
        delete[] matrixBuffer[i];
    }
    delete[] matrixBuffer;
    file.close();
    return matrixVal;
}

std::tuple<int, int, int, std::string> saveInfo() {
    std::ifstream file("/Users/smoke/CLionProjects/Simple PGM File Analysis/pgm/1.pgm", std::ios::binary);
    int hei = 0, wei = 0, maxPixelVals = 0;
    std::string typePgmfile;

    file >> typePgmfile >> wei >> hei >> maxPixelVals;
    file.close();
    return {wei, hei, maxPixelVals, typePgmfile};
}

void inversionPixel(int **t, int wei, int hei, int maxPixelVals) {
    for (unsigned int i = 0; i < hei; i++) {
        for (unsigned int j = 0; j < wei; j++) {
            t[i][j] = maxPixelVals - t[i][j];
        }
    }
}
bool writeOnGpmFile(int **t, int wei, int hei) {
    std::ofstream file("/Users/smoke/CLionProjects/Simple PGM File Analysis/pgm/1.pgm", std::ios::binary);
    if (!file) {
        std::cerr << "Planta lors de l'ouverture ayant pour objectif lecriture";
        return false;
    }
    const int maxVal = 255;
    file << "P5\n" << wei << " " << hei << "\n" << maxVal << "\n";

    for (unsigned int i = 0; i < hei; i++) {
        for (unsigned int j = 0; j < wei; j++) {
            unsigned char pixelVal = static_cast<unsigned char>(std::clamp(t[i][j], 0, maxVal));
            file.write(reinterpret_cast<const char*>(&pixelVal), sizeof(unsigned char));
        }
    }
    for (unsigned int i = 0; i < hei; i++) {
        file.write(reinterpret_cast<char *>(t[i]), wei);
    }
    file.close();
    return true;
}