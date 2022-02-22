#include "../libs/data_structures/matrix/matrix.h"
#include <assert.h>

#define getCurIndex(shift, p) shift - p.rowIndex + p.colIndex

long long findSumOfMaxesOfPseudoDiagonal(matrix m) {
    int shift = m.nRows - 1;
    int n = shift + m.nCols;
    int *maxes;
    createIntArray(&maxes, n);
    for (int i = 0; i < n; ++i)
        maxes[i] = -INT_MAX;
    counter c = initC(m);

    while (!c.isFinished) {
        position currentP = getPositionC(&c);
        int currentV = getValue(m, currentP);

        int curIndex = getCurIndex(shift, currentP);
        if (currentV > maxes[curIndex])
            maxes[curIndex] = currentV;
    }

    long long result = getSum(maxes, n);
    result -= maxes[shift];
    free((void *) maxes);
    return result;
}

void test_task7() {
    matrix m = createMatrixFromArray(
            (int[]) {
                    3, 2, 5, 4,
                    1, 3, 6, 3,
                    3, 2, 1, 2
            },
            3, 4
    );

    assert(20 == findSumOfMaxesOfPseudoDiagonal(m));

    freeMemMatrix(m);
}

void task7() {
    matrix m = fCons_inputMatrix();

    long long result = findSumOfMaxesOfPseudoDiagonal(m);

    printf("%lld", result);

    freeMemMatrix(m);
}