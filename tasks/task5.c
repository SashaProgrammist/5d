#include "../libs/data_structures/matrix/matrix.h"

void transposeIfMatrixHasEqualSumOfRows(matrix *m) {
    if (m->nRows != m->nCols) return;

    long long *sumOfRows = (long long *) malloc(m->nRows * sizeof(long long ));
    for (int i = 0; i < m->nRows; ++i)
        sumOfRows[i] = getSum(m->values[i], m->nCols);

    if (isUnique(sumOfRows, m->nRows))
        transposeSquareMatrix(*m);

    free((void *)sumOfRows);
}

void task5() {
    matrix m = fCons_inputSquareMatrix();

    transposeIfMatrixHasEqualSumOfRows(&m);

    outputMatrix(m);

    freeMemMatrix(m);
}

