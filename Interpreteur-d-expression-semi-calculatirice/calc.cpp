#include "calc.h"



int charOperationByRespectOrder(char  *operation){
    float temp1,temp2,temp3;
    temp3 = *operation - '0';
    operation++;
    while (*operation != '\0'){
        /* if (*operation != '-' && *operation != '*' && *operation != '/' && *operation != '+'){
             temp3 = *operation - '0';
         }*/
        // operation++;
        if (*operation == '+'){
            operation++;
            temp3 += (*operation - '0');
            operation++;
        }
        else if (*operation == '*'){
            operation--;
            temp3 -= (*operation - '0');
            operation++;
            operation++;
            operation++;

        }
        else if(*operation == '/')
        {
            operation++;
            temp3 /= (*operation - '0');
            operation++;

        }
        else if(*operation == '-')
        {
            operation++;
            temp3 -= (*operation - '0');
            operation++;

        }
    }
    return temp3;
}
int charOperation(char  *operation){
    float temp1,temp2,temp3;
    temp3 = *operation - '0';
    operation++;
    while (*operation != '\0'){
        /* if (*operation != '-' && *operation != '*' && *operation != '/' && *operation != '+'){
             temp3 = *operation - '0';
         }*/
        // operation++;
        if (*operation == '+'){
            operation++;
            temp3 += (*operation - '0');
            operation++;
        }
        else if (*operation == '*'){
            operation++;
            temp3 *= (*operation - '0');
            operation++;

        }
        else if(*operation == '/')
        {
            operation++;
            temp3 /= (*operation - '0');
            operation++;

        }
        else if(*operation == '-')
        {
            operation++;
            temp3 -= (*operation - '0');
            operation++;

        }
    }
    return temp3;
}

int charOperationMultiplyOrder(char *Operation){
    int temp1;
    int temp2;
    int temp3 = 0;
    int temp4;
    while (*Operation != '\0'){
        if (*Operation == '*'){
            Operation--;
            temp1 = *Operation - '0';
            //*Operation = ' ';
            Operation++;
           // *Operation = ' ';
            Operation++;
            temp2 = *Operation - '0';
           // *Operation = ' ';
            temp4 = temp1 * temp2;
            temp3 += temp4;
            Operation++;
        } else{
            Operation++;
        }

    }
    return temp3;
}
/*int charOperationDivideOrder(char *Operation){
    int temp1;
    int temp2;
    int temp3 = 0;
    int temp4;
    while (*Operation != '\0'){
        if (*Operation == '/'){
            Operation--;
            temp1 = *Operation - '0';
            //*Operation = ' ';
            Operation++;
            // *Operation = ' ';
            Operation++;
            temp2 = *Operation - '0';
            // *Operation = ' ';
            temp4 = temp1 * temp2;
            temp3 += temp4;
            Operation++;
        } else{
            Operation++;
        }

    }
    return temp3;
}
*/