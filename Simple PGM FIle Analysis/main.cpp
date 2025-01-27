#include <iostream>
#include "pgm.h"

int main() {
    int **t = new int*[1280];
    for (unsigned int i = 0; i < 1280; i++) {
        t[i] = new int[1920];
    }
    int k = 0;
    t = duplicateMatrixInfo();
    inversionPixel(t, 1920, 1280, 255);
    std::cout << writeOnGpmFile(t, 1920, 1280) << std::endl;
    /*for (int i = 0; i < 1280; i++) {
        for (int j = 0; j < 1920; j++) {
            if (t[i][j] == 0)
                k++;
        }
    }
    std::cout << k;*/
    delete[] t;
}