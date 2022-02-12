#include "../libs/data_structures/matrix/matrix.h"
#include "../libs/algorithms/oneDimArray/oneDimArray.h"

void transposeIfMatrixHasEqualSumOfRows(matrix *m) {
    long long *sumOfRows = (long long *) malloc(m->nRows * sizeof(long long ));
    for (int i = 0; i < m->nRows; ++i)
        sumOfRows[i] = getSum(m->values[i], m->nCols);

    if (isUnique(sumOfRows, m->nCols))
        transposeSquareMatrix(*m);

    free(sumOfRows);
}

void task5() {
    matrix m = fCons_inputSquareMatrix();

    transposeIfMatrixHasEqualSumOfRows(&m);

    outputMatrix(m);

    freeMemMatrix(m);
}

