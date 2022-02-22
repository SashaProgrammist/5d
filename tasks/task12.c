#include "../libs/data_structures/matrix/matrix.h"
#include <assert.h>

position getLeftMin(matrix m) {
    int min = **m.values;
    position result = (position) {0, 0};

    for (int j = 0; j < m.nCols; ++j)
        for (int i = 0; i < m.nRows; ++i)
            if (min > m.values[i][j]) {
                min = m.values[i][j];
                result = (position) {i, j};
            }

    return result;
}

void swapPenultimateRow(matrix m, int n) {
    if (!isSquareMatrix(m) ||
        m.nRows < 2)
        return;

    int *colum = getColumn(m, n);
    int *penultimateRow = m.values[m.nRows - 2];

    for (int j = 0; j < m.nCols; ++j)
        penultimateRow[j] = colum[j];

    free((void *) colum);
}

void swapColumLeftMinPenultimateRow(matrix m) {
    int colum = getLeftMin(m).colIndex;

    swapPenultimateRow(m, colum);
}

void test_getLeftMin() {
    int values[] = {1, 1, 1,
                    1, 1, 1,
                    1, 1, 1};
    int r = 3, c = 3;
    matrix m = createMatrixFromArray(values, r, c);

    // Эх, красота-то какая! Лепота!
    for (int i = 0; i < r; ++i)
        for (int j = 0; j < c; ++j) {
            m.values[i][j] = 0;
            for (int k = 0; k < r; ++k)
                for (int w = j + 1; w < c; ++w) {
                    m.values[k][w] = 0;
                    position result = getLeftMin(m);
                    assert(result.colIndex == j);
                    assert(result.rowIndex == i);
                    m.values[k][w] = 1;
                }
            m.values[i][j] = 1;
        }

    freeMemMatrix(m);
}

void test_swapPenultimateRow() {
    int values[] = {1, 2, 3,
                    4, 5, 6,
                    7, 8, 1};
    int r = 3, c = 3;
    matrix m = createMatrixFromArray(values, r, c);

    swapPenultimateRow(m, 0);
    int result1[] = {1, 2, 3,
                    1, 4, 7,
                    7, 8, 1};
    for (int i = 0; i < r; ++i)
        for (int j = 0; j < c; ++j)
            assert(m.values[i][j] == result1[j + i * c]);

    swapPenultimateRow(m, 1);
    int result2[] = {1, 2, 3,
                     2, 4, 8,
                     7, 8, 1};
    for (int i = 0; i < r; ++i)
        for (int j = 0; j < c; ++j)
            assert(m.values[i][j] == result2[j + i * c]);

    swapPenultimateRow(m, 2);
    int result3[] = {1, 2, 3,
                     3, 8, 1,
                     7, 8, 1};
    for (int i = 0; i < r; ++i)
        for (int j = 0; j < c; ++j)
            assert(m.values[i][j] == result3[j + i * c]);

    freeMemMatrix(m);
}

void test_swapColumLeftMinPenultimateRow() {
    int values[] = {1, 2, 3,
                    4, 5, 6,
                    7, 8, 1};
    int result[] = {1, 2, 3,
                    1, 4, 7,
                    7, 8, 1};
    int r = 3, c = 3;
    matrix m = createMatrixFromArray(values, r, c);

    swapColumLeftMinPenultimateRow(m);

    for (int i = 0; i < r; ++i)
        for (int j = 0; j < c; ++j)
            assert(m.values[i][j] == result[j + i * c]);

    freeMemMatrix(m);
}

void test_task12() {
    test_getLeftMin();
    test_swapPenultimateRow();
    test_swapColumLeftMinPenultimateRow();
}

void task12() {
    matrix m = fCons_inputSquareMatrix();

    swapColumLeftMinPenultimateRow(m);

    outputMatrix(m);

    freeMemMatrix(m);
}
