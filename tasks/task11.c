#include "../libs/data_structures/matrix/matrix.h"
#include <assert.h>

int getCountSpecialNumber(int *a, int n) {
    long long sum = getSum(a, n);
    int result = 0;

    for (int i = 0; i < n; ++i)
        if (sum < 2 * a[i])
            result++;

    return result;
}

int getNSpecialElement(matrix m) {
    int result = 0;

    for (int j = 0; j < m.nCols; ++j) {
        int *currentColum = getColumn(m, j);
        result += getCountSpecialNumber(currentColum, m.nRows);
        free((void *) currentColum);
    }

    return result;
}

void test_getCountSpecialNumber() {
    assert(0 == getCountSpecialNumber((int[]) {
        1, 1, 1, 1, 1
    }, 5));
    assert(1 == getCountSpecialNumber((int[]) {
            6, 1, 1, 1, 1
    }, 5));
    assert(1 == getCountSpecialNumber((int[]) {
            1, 1, 1, 1, 6
    }, 5));
    assert(4 == getCountSpecialNumber((int[]) {
            1, 1, -100, 1, 1
    }, 5));
}

void test_getNSpecialElement() {
    matrix m = createMatrixFromArray(
            (int[]) {
                    3, 5, 5, 4,
                    2, 3, 6, 7,
                    12, 2, 1, 2
            },
            3, 4
    );

    assert(2 == getNSpecialElement(m));

    freeMemMatrix(m);
}

void test_task11() {
    test_getCountSpecialNumber();
    test_getNSpecialElement();
}

void task11() {
    matrix m = fCons_inputMatrix();

    int result = getNSpecialElement(m);

    printf("%d", result);

    freeMemMatrix(m);
}
