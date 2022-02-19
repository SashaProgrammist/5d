#include "..\libs\data_structures\matrix\matrix.h"
#include <assert.h>

int countValues(const int *a, int n, int value) {
    int result = 0;

    for (int i = 0; i < n; ++i)
        if (a[i] == value)
            result++;

    return result;
}

int countZeroRows(matrix m) {
    int result = 0;

    for (int i = 0; i < m.nRows; ++i) {
        int current = countValues(m.values[i], m.nCols, 0);

        if (current == m.nCols)
            result++;
    }

    return result;
}

void printMatrixWithMaxZeroRows(matrix *ms, int nMatrix) {
    int *countsZeroRows = (int *) malloc(nMatrix * sizeof(int));

    for (int i = 0; i < nMatrix; ++i)
        countsZeroRows[i] = countZeroRows(ms[i]);

    int max = getMax(countsZeroRows, nMatrix);

    for (int i = 0; i < nMatrix; ++i)
        if (countsZeroRows[i] == max)
            outputMatrix(ms[i]);

    free(countsZeroRows);
}

void test_task14() {
    matrix *ms = createArrayOfMatrixFromArray(
            (int[]) {
                    0, 1,
                    1, 0,
                    0, 0,

                    1, 1,
                    2, 1,
                    1, 1,

                    0, 0,
                    0, 0,
                    4, 7,

                    0, 0,
                    0, 1,
                    0, 0,

                    0, 1,
                    0, 2,
                    0, 3,
            },
            5, 3, 2
    );

    int results[] = {1, 0, 2, 2, 0};

    for (int i = 0; i < 5; ++i)
        assert(countZeroRows(ms[i]) == results[i]);

    freeMemMatrices(ms, 5);
}

void task14() {
    matrix *ms;
    int nM;
    fCons_inputMatrices(&ms, &nM);

    printMatrixWithMaxZeroRows(ms, nM);

    freeMemMatrices(ms, nM);
}
