#include "../libs/data_structures/matrix/matrix.h"
#include <assert.h>

void transposeIfMatrixHasEqualSumOfRows(matrix *m) {
    long long *sumOfRows;
    createLongLongArray(&sumOfRows, m->nRows);
    for (int i = 0; i < m->nRows; ++i)
        sumOfRows[i] = getSum(m->values[i], m->nCols);

    if (isUnique(sumOfRows, m->nRows))
        transposeMatrix(m);

    free((void *) sumOfRows);
}

void test_task5_yes() {
    int values[] = {1, 2, 3,   // 6
                    4, 1, 0,   // 5
                    1, 1, 2};  // 4
    int result[] = {1, 4, 1,
                    2, 1, 1,
                    3, 0, 2};
    int r = 3, c = 3;
    matrix m = createMatrixFromArray(values, r, c);

    transposeIfMatrixHasEqualSumOfRows(&m);

    for (int i = 0; i < r; ++i)
        for (int j = 0; j < c; ++j)
            assert(m.values[i][j] == result[j + i * c]);

    freeMemMatrix(m);
}

void test_task5_no() {
    int values[] = {1, 2, 3,   // 6
                    4, 1, 0,   // 5
                    1, 2, 2};  // 5
    int *result = values;
    int r = 3, c = 3;
    matrix m = createMatrixFromArray(values, r, c);

    transposeIfMatrixHasEqualSumOfRows(&m);

    for (int i = 0; i < r; ++i)
        for (int j = 0; j < c; ++j)
            assert(m.values[i][j] == result[j + i * c]);

    freeMemMatrix(m);
}

void test_task5() {
    test_task5_yes();
    test_task5_no();
}

void task5() {
    matrix m = fCons_inputSquareMatrix();

    transposeIfMatrixHasEqualSumOfRows(&m);

    outputMatrix(m);

    freeMemMatrix(m);
}

