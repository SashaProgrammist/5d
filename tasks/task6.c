#include "../libs/data_structures/matrix/matrix.h"

bool isMutuallyInverseMatrices(matrix m1, matrix m2){
    return isEMatrix(getMulMatrices(m1, m2));
}

void task6() {
    matrix m1 = fCons_inputSquareMatrix();
    matrix m2 = fCons_inputSquareMatrix();

    if (isMutuallyInverseMatrices(m1, m2))
        printf("YES");
    else
        printf("NO");

    freeMemMatrix(m1);
    freeMemMatrix(m2);
}

