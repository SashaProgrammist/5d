#include "../libs/data_structures/matrix/matrix.h"
#include <assert.h>

long long getMinInArea(matrix m) {
    position posMax = getMaxValuePos(m);
    int min = getValue(m, posMax);

    for (int i = posMax.rowIndex - 1; i >= 0; i--) {
        int indent = posMax.rowIndex - i;
        int startArea = posMax.colIndex - indent;
        if (startArea < 0) startArea = 0;
        int endArea = posMax.colIndex + indent;
        if (endArea >= m.nCols) endArea = m.nCols - 1;

        for (int j = startArea; j <= endArea; ++j) {
            int currentV = m.values[i][j];
            if (currentV < min)
                min = currentV;
        }
    }

    return min;
}

void test_task8_1() {
    matrix m = createMatrixFromArray(
            (int[]) {
                    3, 2, 5, 4,
                    1, 3, 6, 3,
                    3, 2, 12, 2
            },
            3, 4
    );

    assert(2 == getMinInArea(m));

    freeMemMatrix(m);
}

void test_task8_2() {
    matrix m = createMatrixFromArray(
            (int[]) {
                    3, 2, 5, 1,
                    1, 3, 6, 3,
                    -10, 2, 12, 2
            },
            3, 4
    );

    assert(1 == getMinInArea(m));

    freeMemMatrix(m);
}

void test_task8_3() {
    matrix m = createMatrixFromArray(
            (int[]) {
                    -2, 2, 5, 1,
                    1, 3, 6, 3,
                    -10, 13, 12, 2
            },
            3, 4
    );

    assert(-2 == getMinInArea(m));

    freeMemMatrix(m);
}

void test_task8_4() {
    matrix m = createMatrixFromArray(
            (int[]) {
                    3, 2, 30, 1,
                    1, 3, 6, 3,
                    -10, 2, 12, 2
            },
            3, 4
    );

    assert(30 == getMinInArea(m));

    freeMemMatrix(m);
}

void test_task8_5() {
    matrix m = createMatrixFromArray(
            (int[]) {
                    3, 2, 3, 1,
                    1, 3, -6, 3,
                    -10, 2, 12, 2
            },
            3, 4
    );

    assert(-6 == getMinInArea(m));

    freeMemMatrix(m);
}

void test_task8() {
    test_task8_1();
    test_task8_2();
    test_task8_3();
    test_task8_4();
    test_task8_5();
}

void task8() {
    matrix m = fCons_inputMatrix();

    long long result = getMinInArea(m);

    printf("%lld", result);

    freeMemMatrix(m);
}
