#include "testMatrix.h"

#define DEPTH_BRUTE_FORCE 4

void bruteForceTest_getMemMatrix(int r, int c) {
    matrix m = getMemMatrix(r, c);

    assert(m.values != NULL);
    assert(m.nRows == r);
    assert(m.nCols == c);
    for (int i = 0; i < r; ++i)
        assert(m.values[i] != NULL);

    freeMemMatrix(m);
}

void test_getMemMatrix() {
    for (int r = 1; r < DEPTH_BRUTE_FORCE; ++r)
        for (int c = 1; c < DEPTH_BRUTE_FORCE; ++c)
            bruteForceTest_getMemMatrix(r, c);
}

void bruteForceTest_getMemArrayOfMatrices(int nM, int r, int c) {
    matrix *ms = getMemArrayOfMatrices(nM, r, c);

    assert(ms != NULL);
    for (int j = 0; j < nM; ++j) {
        assert(ms[j].values != NULL);
        assert(ms[j].nRows == r);
        assert(ms[j].nCols == c);
        for (int i = 0; i < r; ++i)
            assert(ms[j].values[i] != NULL);
    }

    freeMemMatrices(ms, nM);
}

void test_getMemArrayOfMatrices() {
    for (int nM = 1; nM < DEPTH_BRUTE_FORCE; ++nM)
        for (int r = 1; r < DEPTH_BRUTE_FORCE; ++r)
            for (int c = 1; c < DEPTH_BRUTE_FORCE; ++c)
                bruteForceTest_getMemArrayOfMatrices(nM, r, c);
}

void bruteForceTest_createMatrixFromArray(int r, int c) {
    int count = r * c;
    int *values;
    createIntArray(&values, count);
    setRandom(values, count);

    matrix m = createMatrixFromArray(values, r, c);

    for (int i = 0; i < r; ++i)
        for (int j = 0; j < c; ++j)
            assert(m.values[i][j] == values[j + i * c]);

    freeMemMatrix(m);
    free((void *) values);
}

void test_createMatrixFromArray() {
    for (int r = 1; r < DEPTH_BRUTE_FORCE; ++r)
        for (int c = 1; c < DEPTH_BRUTE_FORCE; ++c)
            bruteForceTest_createMatrixFromArray(r, c);
}

void bruteForceTest_createArrayOfMatrixFromArray(int nM, int r, int c) {
    int count = nM * r * c;
    int *values;
    createIntArray(&values, count);
    setRandom(values, count);

    matrix *ms = createArrayOfMatrixFromArray(values, nM, r, c);

    for (int i = 0; i < nM; ++i)
        for (int j = 0; j < r; ++j)
            for (int k = 0; k < c; ++k)
                assert(ms[i].values[j][k] == values[k + j * c + i * c * r]);

    freeMemMatrices(ms, nM);
    free((void *) values);
}

void test_createArrayOfMatrixFromArray() {
    for (int nM = 1; nM < DEPTH_BRUTE_FORCE; ++nM)
        for (int r = 1; r < DEPTH_BRUTE_FORCE; ++r)
            for (int c = 1; c < DEPTH_BRUTE_FORCE; ++c)
                bruteForceTest_createArrayOfMatrixFromArray(nM, r, c);
}

void bruteForceTest_swapRows(int r, int c) {
    int count = r * c;
    int *values;
    createIntArray(&values, count);
    setRandom(values, count);

    matrix m = createMatrixFromArray(values, r, c);

    for (int i1 = 0; i1 < r; ++i1)
        for (int i2 = i1; i2 < r; ++i2) {
            swapRows(m, i1, i2);

            for (int i = 0; i < r; ++i)
                for (int j = 0; j < c; ++j)
                    if (i == i1 || i == i2)
                        assert(m.values[i][j] ==
                               values[j + (i1 + i2 - i) * c]);
                    else
                        assert(m.values[i][j] ==
                               values[j + i * c]);

            swapRows(m, i1, i2);
        }

    freeMemMatrix(m);
    free((void *) values);
}

void test_swapRows() {
    for (int r = 1; r < DEPTH_BRUTE_FORCE; ++r)
        for (int c = 1; c < DEPTH_BRUTE_FORCE; ++c)
            bruteForceTest_swapRows(r, c);
}

void bruteForceTest_swapColumns(int r, int c) {
    int count = r * c;
    int *values;
    createIntArray(&values, count);
    setRandom(values, count);

    matrix m = createMatrixFromArray(values, r, c);

    for (int j1 = 0; j1 < c; ++j1)
        for (int j2 = j1; j2 < c; ++j2) {
            swapColumns(m, j1, j2);

            for (int i = 0; i < r; ++i)
                for (int j = 0; j < c; ++j)
                    if (j == j1 || j == j2)
                        assert(m.values[i][j] ==
                               values[j1 + j2 - j + i * c]);
                    else
                        assert(m.values[i][j] ==
                               values[j + i * c]);

            swapColumns(m, j1, j2);
        }

    freeMemMatrix(m);
    free((void *) values);
}

void test_swapColumns() {
    for (int r = 1; r < DEPTH_BRUTE_FORCE; ++r)
        for (int c = 1; c < DEPTH_BRUTE_FORCE; ++c)
            bruteForceTest_swapColumns(r, c);
}

void test_insertionSortRowsMatrixByRowCriteria() {
    int values[] = {9, 8, 7,
                    6, 5, 4,
                    3, 2, 1};
    int result[] = {3, 2, 1,
                    6, 5, 4,
                    9, 8, 7};
    int r = 3, c = 3;
    matrix m = createMatrixFromArray(values, r, c);

    insertionSortRowsMatrixByRowCriteria(
            m, (int (*)(int *, int)) getSum);

    for (int i = 0; i < r; ++i)
        for (int j = 0; j < c; ++j)
            assert(m.values[i][j] == result[j + i * c]);

    freeMemMatrix(m);
}

void test_insertionSortColsMatrixByColCriteria() {
    int values[] = {9, 8, 7,
                    6, 5, 4,
                    3, 2, 1};
    int result[] = {7, 8, 9,
                    4, 5, 6,
                    1, 2, 3};
    int r = 3, c = 3;
    matrix m = createMatrixFromArray(values, r, c);

    insertionSortColsMatrixByColCriteria(
            m, (int (*)(int *, int)) getSum);

    for (int i = 0; i < r; ++i)
        for (int j = 0; j < c; ++j)
            assert(m.values[i][j] == result[j + i * c]);

    freeMemMatrix(m);
}

void bruteForceTest_getColumn(int r, int c) {
    int count = r * c;
    int *values;
    createIntArray(&values, count);
    setRandom(values, count);

    matrix m = createMatrixFromArray(values, r, c);

    for (int j = 0; j < c; ++j) {
        int *current = getColumn(m, j);
        for (int i = 0; i < r; ++i)
            assert(current[i] == values[j + i * c]);
        free((void *) current);
    }

    freeMemMatrix(m);
    free((void *) values);
}

void test_getColumn() {
    for (int r = 1; r < DEPTH_BRUTE_FORCE; ++r)
        for (int c = 1; c < DEPTH_BRUTE_FORCE; ++c)
            bruteForceTest_getColumn(r, c);
}

void bruteForceTest_getValue(int r, int c) {
    int count = r * c;
    int *values;
    createIntArray(&values, count);
    setRandom(values, count);

    matrix m = createMatrixFromArray(values, r, c);

    for (int i = 0; i < r; ++i)
        for (int j = 0; j < c; ++j) {
            position p = (position) {i, j};
            assert(getValue(m, p) == values[j + i * c]);
        }

    freeMemMatrix(m);
    free((void *) values);
}

void test_getValue() {
    for (int r = 1; r < DEPTH_BRUTE_FORCE; ++r)
        for (int c = 1; c < DEPTH_BRUTE_FORCE; ++c)
            bruteForceTest_getValue(r, c);
}

void bruteForceTest_getLink(int r, int c) {
    matrix m = getMemMatrix(r, c);

    for (int i = 0; i < r; ++i)
        for (int j = 0; j < c; ++j) {
            position p = (position) {i, j};
            assert(getLink(m, p) == m.values[i] + j);
        }

    freeMemMatrix(m);
}

void test_getLink() {
    for (int r = 1; r < DEPTH_BRUTE_FORCE; ++r)
        for (int c = 1; c < DEPTH_BRUTE_FORCE; ++c)
            bruteForceTest_getLink(r, c);
}

void bruteForceTest_getMinValuePos(int r, int c) {
    size_t count = r * c;
    int *values;
    createIntArray(&values, count);
    setArrayValue(values, count, 1);

    matrix m = createMatrixFromArray(values, r, c);

    for (int i = 0; i < r; ++i)
        for (int j = 0; j < c; ++j) {
            m.values[i][j] = 0;
            position result = getMinValuePos(m);
            assert(result.rowIndex == i);
            assert(result.colIndex == j);
            m.values[i][j] = 1;
        }

    freeMemMatrix(m);
    free((void *) values);
}

void test_getMinValuePos() {
    for (int r = 1; r < DEPTH_BRUTE_FORCE; ++r)
        for (int c = 1; c < DEPTH_BRUTE_FORCE; ++c)
            bruteForceTest_getMinValuePos(r, c);
}

void bruteForceTest_getMaxValuePos(int r, int c) {
    size_t count = r * c;
    int *values;
    createIntArray(&values, count);
    setArrayValue(values, count, 1);

    matrix m = createMatrixFromArray(values, r, c);

    for (int i = 0; i < r; ++i)
        for (int j = 0; j < c; ++j) {
            m.values[i][j] = 2;
            position result = getMaxValuePos(m);
            assert(result.rowIndex == i);
            assert(result.colIndex == j);
            m.values[i][j] = 1;
        }

    freeMemMatrix(m);
    free((void *) values);
}

void test_getMaxValuePos() {
    for (int r = 1; r < DEPTH_BRUTE_FORCE; ++r)
        for (int c = 1; c < DEPTH_BRUTE_FORCE; ++c)
            bruteForceTest_getMaxValuePos(r, c);
}

void enterExitTest_getSquareOfMatrix(int *enter, int *exit, int n) {
    matrix m = createMatrixFromArray(enter, n, n);

    matrix result = getSquareOfMatrix(m);

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            assert(result.values[i][j] == exit[j + i * n]);

    freeMemMatrix(m);
    freeMemMatrix(result);
}

void test_getSquareOfMatrix() {
    enterExitTest_getSquareOfMatrix(
            (int[]) {1},
            (int[]) {1},
            1
    );

    enterExitTest_getSquareOfMatrix(
            (int[]) {2},
            (int[]) {4},
            1
    );

    enterExitTest_getSquareOfMatrix(
            (int[]) {1, 2,
                     4, 5},
            (int[]) {9, 12,
                     24, 33},
            2
    );

    enterExitTest_getSquareOfMatrix(
            (int[]) {1, 2, 3,
                     4, 5, 6,
                     7, 8, 9},
            (int[]) {30, 36, 42,
                     66, 81, 96,
                     102, 126, 150},
            3
    );
}

void enterExitTest_getMulMatrices(int *enter1, int *enter2,
                                  int *exit,
                                  int a, int b, int c) {
    matrix m1 = createMatrixFromArray(enter1, a, b);
    matrix m2 = createMatrixFromArray(enter2, b, c);

    matrix result = getMulMatrices(m1, m2);

    assert(result.nRows == a);
    assert(result.nCols == c);

    for (int i = 0; i < a; ++i)
        for (int j = 0; j < c; ++j)
            assert(result.values[i][j] == exit[j + i * c]);

    freeMemMatrix(m1);
    freeMemMatrix(m2);
    freeMemMatrix(result);
}

void test_getMulMatrices() {
    enterExitTest_getMulMatrices(
            (int[]) {1, 2, 3},
            (int[]) {9, 8, 7},
            (int[]) {46},
            1, 3, 1
    );

    enterExitTest_getMulMatrices(
            (int[]) {1, 2, 3,
                     4, 5, 6,
                     7, 8, 9},
            (int[]) {9, 8, 7},
            (int[]) {46, 118, 190},
            3, 3, 1
    );

    enterExitTest_getMulMatrices(
            (int[]) {1, 2, 3,
                     4, 5, 6,
                     7, 8, 9},
            (int[]) {9, 8, 7,
                     6, 5, 4,
                     3, 2, 1},
            (int[]) {30, 24, 18,
                     84, 69, 54,
                     138, 114, 90},
            3, 3, 3
    );
}

void bruteForceTest_setValue(int r, int c) {
    int count = r * c;
    int *values;
    createIntArray(&values, count);
    setRandom(values, count);

    matrix m = getMemMatrix(r, c);

    for (int i = 0; i < r; ++i)
        for (int j = 0; j < c; ++j)
            setValue(m, (position) {i, j}, values[j + i * c]);

    for (int i = 0; i < r; ++i)
        for (int j = 0; j < c; ++j)
            assert(m.values[i][j] == (values[j + i * c]));

    freeMemMatrix(m);
    free((void *) values);
}

void test_setValue() {
    for (int r = 1; r < DEPTH_BRUTE_FORCE; ++r)
        for (int c = 1; c < DEPTH_BRUTE_FORCE; ++c)
            bruteForceTest_setValue(r, c);
}

void bruteForceTest_twoMatricesEqual(int r, int c) {
    int count = r * c;
    int *values;
    createIntArray(&values, count);
    setRandom(values, count);

    matrix m1 = createMatrixFromArray(values, r, c);
    matrix m2 = createMatrixFromArray(values, r, c);

    assert(twoMatricesEqual(m1, m2));

    for (int i = 0; i < r; ++i)
        for (int j = 0; j < c; ++j) {
            m1.values[i][j] = -values[j + i * c] + 1;
            assert(!twoMatricesEqual(m1, m2));
            m1.values[i][j] = values[j + i * c];
        }

    for (int i = 0; i < r; ++i)
        for (int j = 0; j < c; ++j) {
            m2.values[i][j] = -values[j + i * c] + 1;
            assert(!twoMatricesEqual(m1, m2));
            m2.values[i][j] = values[j + i * c];
        }

    freeMemMatrix(m1);
    freeMemMatrix(m2);
    free((void *) values);
}

void test_twoMatricesEqual() {
    for (int r = 1; r < DEPTH_BRUTE_FORCE; ++r)
        for (int c = 1; c < DEPTH_BRUTE_FORCE; ++c)
            bruteForceTest_twoMatricesEqual(r, c);
}

void bruteForceTest_isEMatrix(int n) {
    int count = n * n;
    int *values;
    createIntArray(&values, count);
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            values[j + i * n] = i == j;

    matrix m = createMatrixFromArray(values, n, n);

    assert(isEMatrix(m));

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j) {
            m.values[i][j] = 2;
            assert(!isEMatrix(m));
            m.values[i][j] = values[j + i * n];
        }

    freeMemMatrix(m);
    free((void *) values);
}

void bruteForceTest_isEMatrix_notSquareMatrix() {
    for (int i = 0; i < DEPTH_BRUTE_FORCE; ++i)
        for (int j = 0; j < DEPTH_BRUTE_FORCE; ++j)
            if (i != j){
                matrix m;
                m.nRows = i;
                m.nCols = j;

                assert(!isEMatrix(m));
            }
}

void test_isEMatrix() {
    for (int n = 1; n < DEPTH_BRUTE_FORCE; ++n)
        bruteForceTest_isEMatrix(n);

    bruteForceTest_isEMatrix_notSquareMatrix();
}

void bruteForceTest_isSymmetricMatrix(int n) {
    int count = n * n;
    int *values;
    createIntArray(&values, count);
    for (int i = 0; i < n; ++i)
        for (int j = i; j < n; ++j) {
            int current = rand();
            values[j + i * n] = current;
            values[i + j * n] = current;
        }

    matrix m = createMatrixFromArray(values, n, n);

    assert(isSymmetricMatrix(m));

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j) {
            m.values[i][j] = -values[j + i * n] + 1;
            if (i != j)
                assert(!isSymmetricMatrix(m));
            else
                assert(isSymmetricMatrix(m));
            m.values[i][j] = values[j + i * n];
        }

    freeMemMatrix(m);
    free((void *) values);
}

void bruteForceTest_isSymmetricMatrix_notSquareMatrix() {
    for (int i = 0; i < DEPTH_BRUTE_FORCE; ++i)
        for (int j = 0; j < DEPTH_BRUTE_FORCE; ++j)
            if (i != j){
                matrix m;
                m.nRows = i;
                m.nCols = j;

                assert(!isSymmetricMatrix(m));
            }
}

void test_isSymmetricMatrix() {
    for (int n = 1; n < DEPTH_BRUTE_FORCE; ++n)
        bruteForceTest_isSymmetricMatrix(n);

    bruteForceTest_isSymmetricMatrix_notSquareMatrix();
}

void bruteForceTest_transposeSquareMatrix(int n) {
    size_t count = n * n;
    int *values;
    createIntArray(&values, count);
    setRandom(values, count);

    matrix m = createMatrixFromArray(values, n, n);

    transposeSquareMatrix(m);

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            assert(m.values[i][j] == values[i + j * n]);

    freeMemMatrix(m);
    free((void *) values);
}

void test_transposeSquareMatrix() {
    for (int n = 1; n < DEPTH_BRUTE_FORCE; ++n)
        bruteForceTest_transposeSquareMatrix(n);
}

void bruteForceTest_initC(int r, int c) {
    matrix m;
    m.nRows = r;
    m.nCols = c;

    counter cou = initC(m);

    assert(cou.isFinished == false);
    assert(cou.count == 0);
}

void test_initC() {
    for (int r = 1; r < DEPTH_BRUTE_FORCE; ++r)
        for (int c = 1; c < DEPTH_BRUTE_FORCE; ++c)
            bruteForceTest_initC(r, c);
}

void bruteForceTest_getValueC(int r, int c) {
    size_t count = r * c;
    int *values;
    createIntArray(&values, count);
    setRandom(values, count);

    matrix m = createMatrixFromArray(values, r, c);
    counter cou = initC(m);

    int i = 0;
    while (!cou.isFinished) {
        int currentV = values[i];
        assert(getValueC(&cou) == currentV);
        i++;
    }
    assert(i == r * c);

    freeMemMatrix(m);
    free((void *) values);
}

void test_getValueC() {
    for (int r = 1; r < DEPTH_BRUTE_FORCE; ++r)
        for (int c = 1; c < DEPTH_BRUTE_FORCE; ++c)
            bruteForceTest_getValueC(r, c);
}

void bruteForceTest_getLinkC(int r, int c) {
    matrix m;
    m.nRows = r;
    m.nCols = c;

    counter cou = initC(m);

    int i = 0;
    while (!cou.isFinished) {
        int *currentLink = m.values[i / c] + i % c;
        assert(getLinkC(&cou) == currentLink);
        i++;
    }
    assert(i == r * c);
}

void test_getLinkC() {
    for (int r = 1; r < DEPTH_BRUTE_FORCE; ++r)
        for (int c = 1; c < DEPTH_BRUTE_FORCE; ++c)
            bruteForceTest_getLinkC(r, c);
}

void bruteForceTest_getPositionC(int r, int c) {
    matrix m;
    m.nRows = r;
    m.nCols = c;

    counter cou = initC(m);

    int i = 0;
    while (!cou.isFinished) {
        position p = getPositionC(&cou);
        assert(p.rowIndex == i / c);
        assert(p.colIndex == i % c);
        i++;
    }
    assert(i == r * c);
}

void test_getPositionC() {
    for (int r = 1; r < DEPTH_BRUTE_FORCE; ++r)
        for (int c = 1; c < DEPTH_BRUTE_FORCE; ++c)
            bruteForceTest_getPositionC(r, c);
}

void bruteForceTest_getReversPositionC(int r, int c) {
    matrix m;
    m.nRows = r;
    m.nCols = c;

    counter cou = initC(m);

    int i = r * c - 1;
    while (!cou.isFinished) {
        position p = getReversPositionC(&cou);
        assert(p.rowIndex == i / c);
        assert(p.colIndex == i % c);
        i--;
    }
    assert(i == -1);
}

void test_getReversPositionC() {
    for (int r = 1; r < DEPTH_BRUTE_FORCE; ++r)
        for (int c = 1; c < DEPTH_BRUTE_FORCE; ++c)
            bruteForceTest_getReversPositionC(r, c);
}

void bruteForceTest_setValueC(int r, int c) {
    size_t count = r * c;
    int *values;
    createIntArray(&values, count);
    setArrayValue(values, count, 1);

    matrix m = createMatrixFromArray(values, r, c);
    counter cou = initC(m);

    int i = 0;
    while (!cou.isFinished) {
        setValueC(&cou, 2);
        position p = (position) {i / c, i % c};

        for (int j = 0; j < r; ++j)
            for (int k = 0; k < c; ++k)
                if (j != p.rowIndex || k != p.colIndex)
                    assert(m.values[j][k] == 1);
                else
                    assert(m.values[j][k] == 2);

        setValue(m, p, 1);
        i++;
    }

    freeMemMatrix(m);
    free((void *) values);
}

void test_setValueC() {
    for (int r = 1; r < DEPTH_BRUTE_FORCE; ++r)
        for (int c = 1; c < DEPTH_BRUTE_FORCE; ++c)
            bruteForceTest_setValueC(r, c);
}

void bruteForceTest_muvC(int r, int c) {
    matrix m;
    m.nRows = r;
    m.nCols = c;

    counter cou = initC(m);

    int i = 0;
    while (!cou.isFinished) {
        assert(cou.count == i);
        muvC(&cou);
        i++;
    }
    assert(cou.count == r * c);
    assert(cou.isFinished);
    assert(i == r * c);
}

void test_muvC() {
    for (int r = 1; r < DEPTH_BRUTE_FORCE; ++r)
        for (int c = 1; c < DEPTH_BRUTE_FORCE; ++c)
            bruteForceTest_muvC(r, c);
}

void test_task5();

void test_task6();

void test_task7();

void test_task8();

void test_task9();

void test_task10();

void test_task11();

void test_task12();

void test_task13();

void test_task14();

void test_task16();

void test_task17();

void test_task18();

void test() {
    test_getMemMatrix();
    test_getMemArrayOfMatrices();
    test_createMatrixFromArray();
    test_createArrayOfMatrixFromArray();
    test_swapRows();
    test_swapColumns();
    test_insertionSortRowsMatrixByRowCriteria();
    test_insertionSortColsMatrixByColCriteria();
    test_getColumn();
    test_getValue();
    test_getLink();
    test_getMinValuePos();
    test_getMaxValuePos();
    test_getSquareOfMatrix();
    test_getMulMatrices();
    test_setValue();
    test_twoMatricesEqual();
    test_isEMatrix();
    test_isSymmetricMatrix();
    test_transposeSquareMatrix();
    test_initC();
    test_getValueC();
    test_getLinkC();
    test_getPositionC();
    test_getReversPositionC();
    test_setValueC();
    test_muvC();

    test_task5();
    test_task6();
    test_task7();
    test_task8();
    test_task9();
    test_task10();
    test_task11();
    test_task12();
    test_task13();
    test_task14();
    test_task16();
    test_task17();
    test_task18();
}
