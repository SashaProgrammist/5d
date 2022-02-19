#include "..\libs\data_structures\matrix\matrix.h"
#include <assert.h>

bool hasAllNonDescendingRows(matrix m) {
    for (int i = 0; i < m.nRows; ++i) {
        bool isCurrentRowNotDecreasing =
                isNotDecreasingOrdering(m.values[i],
                                        m.nCols);

        if (!isCurrentRowNotDecreasing)
            return false;
    }

    return true;
}

int countNonDescendingRowsMatrices(matrix *ms, int nMatrix) {
    int result = 0;

    for (int i = 0; i < nMatrix; ++i) {
        bool isCurrentHasAllNonDescendingRows =
                hasAllNonDescendingRows(ms[i]);

        if (!isCurrentHasAllNonDescendingRows)
            result++;
    }

    return result;
}

void test_task13() {
    matrix *ms = createArrayOfMatrixFromArray(
            (int []) {
                    7, 1,
                    1, 1,

                    1, 6,
                    2, 2,

                    5, 4,
                    2, 3,

                    1, 3,
                    7, 9
            },
            4, 2, 2
    );

    bool results[] = {false, true, false, true};

    for (int i = 0; i < 4; ++i)
        assert(results[i] == hasAllNonDescendingRows(ms[i]));

    int result = countNonDescendingRowsMatrices(ms, 4);

    assert(result == 2);
}

void task13() {
    matrix *ms;
    int nM;
    fCons_inputMatrices(&ms, &nM);

    int result = countNonDescendingRowsMatrices(ms, nM);

    printf("%d\n", result);

    freeMemMatrices(ms, nM);
}
