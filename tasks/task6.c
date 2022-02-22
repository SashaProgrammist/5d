#include "../libs/data_structures/matrix/matrix.h"
#include <assert.h>

bool isMutuallyInverseMatrices(matrix m1, matrix m2) {
    if (m1.nCols != m2.nRows ||
        m1.nRows != m2.nCols ||
        !isSquareMatrix(m1))
        return false;

    matrix mul = getMulMatrices(m1, m2);
    bool result = isEMatrix(mul);
    freeMemMatrix(mul);

    return result;
}

void test_task6_yes() {
    matrix m1 = createMatrixFromArray(
            (int[]) {
                    1, 3, 4,
                    -1, -2, 0,
                    3, 9, 13
            },
            3, 3
    );
    matrix m2 = createMatrixFromArray(
            (int[]) {
                    -26, -3, 8,
                    13,  1,  -4,
                    -3,  0,  1
            },
            3, 3
    );

    assert(isMutuallyInverseMatrices(m1, m2));

    freeMemMatrix(m1);
    freeMemMatrix(m2);
}

void test_task6_no() {
    matrix m1 = createMatrixFromArray(
            (int[]) {
                    1, 3, 4,
                    -1, -2, 0,
                    3, 9, 13
            },
            3, 3
    );
    matrix m2 = createMatrixFromArray(
            (int[]) {
                    -26, -3, 8,
                    13,  1,  -4,
                    -3,  1,  1
            },
            3, 3
    );

    assert(!isMutuallyInverseMatrices(m1, m2));

    freeMemMatrix(m1);
    freeMemMatrix(m2);
}

void test_task6() {
    test_task6_yes();
    test_task6_no();
}

void task6() {
    matrix m1 = fCons_inputSquareMatrix();
    matrix m2 = fCons_inputSquareMatrix();

    if (isMutuallyInverseMatrices(m1, m2))
        printf("YES");
    else
        printf("NO");

    freeMemMatrix(m1);
    freeMemMatrix(m2);
}
