#include "../libs/data_structures/matrix/matrix.h"

#include <assert.h>
#include <math.h>

float getDistance(int *a, int n) {
    float result = 0;

    for (int i = 0; i < n; ++i) {
        float current = a[i];
        result += current * current;
    }

    return sqrt(result);
}

void insertionSortRowsMatrixByRowCriteriaF(matrix m,
                                           float (*criteria)(int *, int)) {
    float *resultsCriteriaInRows;
    createFloatArray(&resultsCriteriaInRows,
                     m.nRows);
    for (int i = 0; i < m.nRows; ++i)
        resultsCriteriaInRows[i] =
                criteria(m.values[i], m.nCols);

    for (int i = 1; i < m.nRows; ++i) {
        int currentSwapRow = i - 1;
        float currentCriteria = resultsCriteriaInRows[i];
        int *currentRow = m.values[i];
        int currentIndexRow = i;

        while (currentSwapRow >= 0 &&
               resultsCriteriaInRows[currentSwapRow] > currentCriteria) {
            m.values[currentIndexRow] = m.values[currentSwapRow];
            resultsCriteriaInRows[currentIndexRow] =
                    resultsCriteriaInRows[currentSwapRow];

            currentSwapRow--;
            currentIndexRow--;
        }

        m.values[currentIndexRow] = currentRow;
        resultsCriteriaInRows[currentIndexRow] = currentCriteria;
    }

    free((void *) resultsCriteriaInRows);
}

void sortByDistances(matrix m) {
    insertionSortRowsMatrixByRowCriteriaF(m, getDistance);
}


void test_task9() {
    int values[] = {3, 2,    // d^2 = 13
                    3, 4,    // d^2 = 25
                    12, 2,   // d^2 = 148
                    -6, 3,   // d^2 = 45
                    -10, 2,  // d^2 = 104
                    1, 3,};   // d^2 = 10
    int result[] = {1, 3,   // d^2 = 10
                    3, 2,   // d^2 = 13
                    3, 4,   // d^2 = 25
                    -6, 3,  // d^2 = 45
                    -10, 2, // d^2 = 104
                    12, 2};  // d^2 = 148
    int r = 6, c = 2;
    matrix m = createMatrixFromArray(values, r, c);

    sortByDistances(m);

    for (int i = 0; i < r; ++i)
        for (int j = 0; j < c; ++j)
            assert(m.values[i][j] == result[j + i * c]);

    freeMemMatrix(m);
}

void task9() {
    matrix m = fCons_inputMatrix();

    sortByDistances(m);

    outputMatrix(m);

    freeMemMatrix(m);
}

