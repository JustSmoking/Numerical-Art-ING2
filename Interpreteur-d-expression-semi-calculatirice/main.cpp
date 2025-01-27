#include <iostream>
#include "calc.h"


int main() {
    char *chaine = "4+2";
    char *chaine1 = "4*3";
    char *chaine2 = "4+3-2+6-7";
    char *chaine3 = "4+3*3+2*1+3*1+5"; // Ne prends pas en compte les negations
    std::cout << charOperation(chaine) << std::endl;
    std::cout << charOperationMultiplyOrder(chaine1) << std::endl;
    std::cout << charOperation(chaine2) << std::endl;
    std::cout << charOperationMultiplyOrder(chaine3) + charOperationByRespectOrder(chaine3) << std::endl;

}



