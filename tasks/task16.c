#include "..\libs\data_structures\matrix\matrix.h"
#include <assert.h>

int getCountOfSpecialItem(int *a, int n) {
    int result = 0;
    bool f = true;

    for (int i = 1; i <= n; ++i)
        if (i == n || a[i - 1] < a[i]) {
            if (f) result++;
            f = true;
        } else
            f = false;

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
    assert(getCountOfSpecialItem((int[]) {1}, 1) == 1);
}

void test_getCountOfSpecialItem_SpecialItemOnEnd_notRecurringItem() {
    assert(2 == getCountOfSpecialItem(
            (int[]) {1, 2, 1, 0, -1, 0},
            6
    ));
}

void test_getCountOfSpecialItem_RecurringItem() {
    assert(1 == getCountOfSpecialItem(
            (int[]) {1, 1, 0, 0, 1, 3, -1, -1},
            8
    ));
}

void test_getCountOfSpecialItem() {
    test_getCountOfSpecialItem_NoElement();
    test_getCountOfSpecialItem_OneElement();
    test_getCountOfSpecialItem_SpecialItemOnEnd_notRecurringItem();
    test_getCountOfSpecialItem_RecurringItem();
}

void test_getCountOfSpecialItemInRows() {
    matrix m = createMatrixFromArray(
            (int[]) {
                    2, 2, 5, 5, 4,
                    6, 2, 3, 8, 12,
                    12, 12, 2, 1, 2
            },
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
