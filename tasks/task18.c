#include "..\libs\data_structures\matrix\matrix.h"
#include <assert.h>

long long getScalarProductRowAndCol(matrix m, int i, int j) {
    if (!isSquareMatrix(m)) {
        fprintf(stderr, "impossible action");
        exit(1);
    }

    int *col = getColumn(m, j);
    long long result = getScalarProduct(m.values[i], col, m.nRows);
    free((void *) col);

    return result;
}

long long getSpecialScalarProduct(matrix m) {
    int i_max = getMaxValuePos(m).rowIndex;
    int j_min = getMinValuePos(m).colIndex;

    return getScalarProductRowAndCol(m, i_max, j_min);
}

void test_task18(){
    matrix m = createMatrixFromArray(
            (int[]) {
                    6, 8, 5,
                    1, 3, 2,
                    7, 4, 9
            },
            3, 3
    );

    assert(getSpecialScalarProduct(m) == 109);
}

void task18() {
    matrix m = fCons_inputSquareMatrix();

    long long result = getSpecialScalarProduct(m);
    printf("%lld", result);

    freeMemMatrix(m);
}
