#include "../libs/data_structures/matrix/matrix.h"
#include <assert.h>

int countNUnique(long long *a, int n) {
    long long *workingMem = longlong_copy(a, n);
    long_long_sort(workingMem, n);

    int result = 0;
    for (int i = 0, j = 0; i <= n; ++i)
        if ((i == n) || (workingMem[i] != workingMem[j])) {
            if (i - j != 1) // i - j == 1 => workingMem[j] is unique
                result++;
            j = i;
        }

    free((void *) workingMem);
    return result;
}

int countEqClassesByRowsSum(matrix m) {
    long long *sums;
    createLongLongArray(&sums, m.nRows);
    for (int i = 0; i < m.nRows; ++i)
        sums[i] = getSum(m.values[i], m.nCols);

    int result = countNUnique(sums, m.nRows);

    free((void *) sums);
    return result;
}

void test_countNUnique() {
    assert(0 == countNUnique((long long[]) {
            1, 2, 3, 4, 5
    }, 5));
    assert(0 == countNUnique((long long[]) {
            5, 1, 2, 4, 3
    }, 5));
    assert(1 == countNUnique((long long[]) {
            5, 1, 2, 1, 3
    }, 5));
    assert(1 == countNUnique((long long[]) {
            1, 1, 2, 4, 1
    }, 5));
    assert(2 == countNUnique((long long[]) {
            3, 1, 2, 2, 3
    }, 5));
    assert(1 == countNUnique((long long[]) {
            1, 1, 1, 1, 1
    }, 5));
}

void test_countEqClassesByRowsSum(){
    matrix m = createMatrixFromArray( // nu - 3; u - 1
            (int[]) {
                    3, 2, // 5 nu
                    5, 4, // 9 nu
                    1, 3, // 4 u
                    6, 3, // 9 nu
                    3, 2, // 5 nu
                    1, 2, // 3 nu
                    1, 4, // 5 nu
                    6, 3, // 9 nu
                    3, 2, // 5 nu
                    1, 2  // 3 nu
            },
            10, 2
    );

    assert(3 == countEqClassesByRowsSum(m));

    freeMemMatrix(m);
}

void test_task10() {
    test_countNUnique();
    test_countEqClassesByRowsSum();
}

void task10() {
    matrix m = fCons_inputMatrix();

    int result = countEqClassesByRowsSum(m);

    printf("%d", result);

    freeMemMatrix(m);
}