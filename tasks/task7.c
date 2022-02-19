#include "../libs/data_structures/matrix/matrix.h"

long long findSumOfMaxesOfPseudoDiagonal(matrix m) {
    int n = m.nRows + m.nCols - 1;
    int *maxes = (int *) malloc(n * sizeof(int));

    for (int i = 0; i < n; ++i)
        maxes[i] = -INT_MAX;

    for (int i = 0; i < m.nRows; ++i)
        for (int j = 0; j < m.nCols; ++j){
            int curIndex = m.nRows - 1 - i + j;
            if (m.values[i][j] > maxes[curIndex])
                maxes[curIndex] = m.values[i][j];
        }

    long long result = getSum(maxes, n);
    result -= maxes[m.nRows - 1];
    free(maxes);
    return result;
}

void task7() {
    matrix m = fCons_inputMatrix();

    long long result = findSumOfMaxesOfPseudoDiagonal(m);

    printf("%lld", result);

    freeMemMatrix(m);
}