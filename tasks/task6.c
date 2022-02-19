#include "../libs/data_structures/matrix/matrix.h"

bool isMutuallyInverseMatrices(matrix m1, matrix m2) {
    if (m1.nCols != m2.nRows ||
        m1.nRows != m2.nCols ||
        !isSquareMatrix(m1))
        return false;

    matrix mul = getMulMatrices(m1, m2);
    bool result = isEMatrix(mul);
    freeMemMatrix(mul);

    return result;
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
