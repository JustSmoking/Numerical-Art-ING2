#ifndef PGM_H
#define PGM_H
#include <tuple>

int **duplicateMatrixInfo();
std::tuple<int, int, int, std::string> saveInfo();
void inversionPixel(int **, int, int, int);
bool writeOnGpmFile(int **, int, int);
#endif //PGM_H
