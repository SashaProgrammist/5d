#include "..\libs\data_structures\matrix\matrix.h"
#include <assert.h>

int getCountOfSpecialItem(const int *array, int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;

    int *minArray;
    createIntArray(&minArray, n);
    minArray[n - 1] = INT_MAX;
    for (int i = n - 2; i >= 0; --i)
        minArray[i] = min2(minArray[i + 1], array[i + 1]);

    int *maxArray;
    createIntArray(&maxArray, n);
    maxArray[0] = -INT_MAX;
    for (int i = 1; i < n; ++i)
        maxArray[i] = max2(maxArray[i - 1], array[i - 1]);

    int result = 0;

    if (array[0] < minArray[0])result++;
    if (array[n - 1] > maxArray[n - 1])result++;

    for (int i = 1; i < n - 1; ++i)
        if (array[i] < minArray[i] &&
            array[i] > maxArray[i])
            result++;

    free((void *) minArray);
    free((void *) maxArray);

    return result;
}

int getCountOfSpecialItemInRows(matrix m) {
    int result = 0;

    for (int i = 0; i < m.nRows; ++i)
        result += getCountOfSpecialItem(m.values[i], m.nCols);

    return result;
}

void test_getCountOfSpecialItem_NoElement() {
    assert(getCountOfSpecialItem((int[]) {}, 0) == 0);
}

void test_getCountOfSpecialItem_OneElement() {
    assert(getCountOfSpecialItem((int[]) {INT_MAX}, 1) == 1);
}

void test_getCountOfSpecialItem_SpecialItemOnEnd_notRecurringItem() {
    assert(0 == getCountOfSpecialItem(
            (int[]) {1, 2, 1, 0, -1, 0},
            6
    ));
}

void test_getCountOfSpecialItem_RecurringItem() {
    assert(0 == getCountOfSpecialItem(
            (int[]) {1, 1, 0, 0, 1, 3, -1, -1},
            8
    ));
}

void test_getCountOfSpecialItem_onSpecialItem() {
    assert(3 == getCountOfSpecialItem(
            (int[]) {1, 1, 3, 4, 5, 4, 7, 8},
            8
    ));
}

void test_getCountOfSpecialItem_ollSpecialItem() {
    assert(8 == getCountOfSpecialItem(
            (int[]) {1, 2, 3, 4, 5, 6, 7, 8},
            8
    ));
}

void test_getCountOfSpecialItem() {
    test_getCountOfSpecialItem_NoElement();
    test_getCountOfSpecialItem_OneElement();
    test_getCountOfSpecialItem_SpecialItemOnEnd_notRecurringItem();
    test_getCountOfSpecialItem_RecurringItem();
    test_getCountOfSpecialItem_onSpecialItem();
    test_getCountOfSpecialItem_ollSpecialItem();
}

void test_getCountOfSpecialItemInRows() {
    matrix m = createMatrixFromArray(
            (int[]) { 2,  3,  5,  5,  4,
                      6,  2,  3,  8, 12,
                      12, 12,  2,  1,  2},
            3, 5
    );

    assert(4 == getCountOfSpecialItemInRows(m));

    freeMemMatrix(m);
}

void test_task16() {
    test_getCountOfSpecialItem();
    test_getCountOfSpecialItemInRows();
}


void task16() {
    matrix m = fCons_inputMatrix();

    int result = getCountOfSpecialItemInRows(m);

    printf("%d", result);

    freeMemMatrix(m);
}
