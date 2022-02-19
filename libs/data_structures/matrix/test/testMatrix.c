#include "testMatrix.h"

void test_getMemMatrix() {
    int r = 5, c = 10;
    matrix m = getMemMatrix(r, c);

    assert(m.values != NULL);
    assert(m.nRows == r);
    assert(m.nCols == c);
    for (int i = 0; i < r; ++i)
        assert(m.values[i] != NULL);

    freeMemMatrix(m);
}

void test_getMemArrayOfMatrices() {
    int nM = 3, r = 5, c = 10;
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

void test_createMatrixFromArray() {
    int values[] = {1, 2, 3,
                    4, 5, 6,
                    7, 8, 9};
    int r = 3, c = 3;
    matrix m = createMatrixFromArray(values, r, c);

    for (int i = 0; i < r; ++i)
        for (int j = 0; j < c; ++j)
            assert(m.values[i][j] == values[j + i * c]);

    freeMemMatrix(m);
}

void test_createArrayOfMatrixFromArray() {
    int values[] = {1, 2, 3,
                    4, 5, 6,
                    7, 8, 9};
    int nM = 2, r = 2, c = 2;
    matrix *ms = createArrayOfMatrixFromArray(values, nM, r, c);

    for (int i = 0; i < nM; ++i)
        for (int j = 0; j < r; ++j)
            for (int k = 0; k < c; ++k)
                assert(ms[i].values[j][k] == values[k + j * c + i * c * r]);

    freeMemMatrices(ms, nM);
}

void test_swapRows() {
    int values[] = {1, 2, 3,
                    4, 5, 6,
                    7, 8, 9};
    int result[] = {4, 5, 6,
                    1, 2, 3,
                    7, 8, 9};
    int r = 3, c = 3;
    matrix m = createMatrixFromArray(values, r, c);

    swapRows(m, 0, 1);

    for (int i = 0; i < r; ++i)
        for (int j = 0; j < c; ++j)
            assert(m.values[i][j] == result[j + i * c]);

    freeMemMatrix(m);
}

void test_swapColumns() {
    int values[] = {1, 2, 3,
                    4, 5, 6,
                    7, 8, 9};
    int result[] = {1, 3, 2,
                    4, 6, 5,
                    7, 9, 8};
    int r = 3, c = 3;
    matrix m = createMatrixFromArray(values, r, c);

    swapColumns(m, 2, 1);

    for (int i = 0; i < r; ++i)
        for (int j = 0; j < c; ++j)
            assert(m.values[i][j] == result[j + i * c]);

    freeMemMatrix(m);
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

    insertionSortRowsMatrixByRowCriteria(m, getSum);

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

    insertionSortColsMatrixByColCriteria(m, getSum);

    for (int i = 0; i < r; ++i)
        for (int j = 0; j < c; ++j)
            assert(m.values[i][j] == result[j + i * c]);

    freeMemMatrix(m);
}

void test_getColumn() {
    int values[] = {9, 8, 7,
                    6, 5, 4,
                    3, 2, 1};
    int r = 3, c = 3;
    matrix m = createMatrixFromArray(values, r, c);

    for (int j = 0; j < c; ++j) {
        int *current = getColumn(m, j);
        for (int i = 0; i < r; ++i)
            assert(current[i] == values[j + i * c]);
        free((void *) current);
    }

    freeMemMatrix(m);
}

void test_getValue() {
    int values[] = {9, 8, 7,
                    6, 5, 4,
                    3, 2, 1};
    int r = 3, c = 3;
    matrix m = createMatrixFromArray(values, r, c);

    for (int i = 0; i < r; ++i)
        for (int j = 0; j < c; ++j) {
            position p = (position) {i, j};
            assert(getValue(m, p) == values[j + i * c]);
        }

    freeMemMatrix(m);
}

void test_getLink() {
    int values[] = {9, 8, 7,
                    6, 5, 4,
                    3, 2, 1};
    int r = 3, c = 3;
    matrix m = createMatrixFromArray(values, r, c);

    for (int i = 0; i < r; ++i)
        for (int j = 0; j < c; ++j) {
            position p = (position) {i, j};
            assert(getLink(m, p) == m.values[i] + j);
        }

    freeMemMatrix(m);
}

void test_getMinValuePos() {
    int values[] = {1, 1, 1,
                    1, 1, 1,
                    1, 1, 1};
    int r = 3, c = 3;
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
}

void test_getMaxValuePos() {
    int values[] = {1, 1, 1,
                    1, 1, 1,
                    1, 1, 1};
    int r = 3, c = 3;
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
}

void test_getSquareOfMatrix() {
    int values[] = {1, 2, 3,
                    4, 5, 6,
                    7, 8, 9};
    int resultV[] = {30, 36, 42,
                     66, 81, 96,
                     102, 126, 150};
    int r = 3, c = 3;
    matrix m = createMatrixFromArray(values, r, c);

    matrix result = getSquareOfMatrix(m);

    for (int i = 0; i < r; ++i)
        for (int j = 0; j < c; ++j)
            assert(result.values[i][j] == resultV[j + i * c]);

    freeMemMatrix(m);
    freeMemMatrix(result);
}

void test_getMulMatrices() {
    int values1[] = {1, 2, 3,
                     4, 5, 6,
                     7, 8, 9};
    int values2[] = {9, 8, 7,
                     6, 5, 4,
                     3, 2, 1};
    int resultV[] = {30, 24, 18,
                     84, 69, 54,
                     138, 114, 90};
    int r = 3, c = 3;
    matrix m1 = createMatrixFromArray(values1, r, c);
    matrix m2 = createMatrixFromArray(values2, r, c);

    matrix result = getMulMatrices(m1, m2);

    for (int i = 0; i < r; ++i)
        for (int j = 0; j < c; ++j)
            assert(result.values[i][j] == resultV[j + i * c]);

    freeMemMatrix(m1);
    freeMemMatrix(m2);
    freeMemMatrix(result);
}

void test_setValue() {
    int values[] = {1, 2, 3,
                    4, 5, 6,
                    7, 8, 9};
    int r = 3, c = 3;
    int mask = 5;
    matrix m = createMatrixFromArray(values, r, c);

    for (int i = 0; i < r; ++i)
        for (int j = 0; j < c; ++j)
            setValue(m, (position) {i, j}, values[j + i * c] ^ mask);

    for (int i = 0; i < r; ++i)
        for (int j = 0; j < c; ++j)
            assert(m.values[i][j] == (values[j + i * c] ^ mask));

    freeMemMatrix(m);
}

void test_twoMatricesEqual() {
    int values[] = {1, 2, 3,
                    4, 5, 6,
                    7, 8, 9};
    int r = 3, c = 3;
    matrix m1 = createMatrixFromArray(values, r, c);
    matrix m2 = createMatrixFromArray(values, r, c);

    assert(twoMatricesEqual(m1, m2));

    for (int i = 0; i < r; ++i)
        for (int j = 0; j < c; ++j) {
            m1.values[i][j] = -values[j + i * c];
            assert(!twoMatricesEqual(m1, m2));
            m1.values[i][j] = values[j + i * c];
        }

    freeMemMatrix(m1);
    freeMemMatrix(m2);
}

void test_isEMatrix() {
    int values[] = {1, 0, 0,
                    0, 1, 0,
                    0, 0, 1};
    int r = 3, c = 3;
    matrix m = createMatrixFromArray(values, r, c);

    assert(isEMatrix(m));

    for (int i = 0; i < r; ++i)
        for (int j = 0; j < c; ++j) {
            m.values[i][j] = 2;
            assert(!isEMatrix(m));
            m.values[i][j] = values[j + i * c];
        }

    freeMemMatrix(m);
}

void test_isSymmetricMatrix() {
    int values[] = {1, 0, 0,
                    0, 1, 0,
                    0, 0, 1};
    int r = 3, c = 3;
    matrix m = createMatrixFromArray(values, r, c);

    assert(isSymmetricMatrix(m));

    for (int i = 0; i < r; ++i)
        for (int j = 0; j < c; ++j) {
            m.values[i][j] = 2;
            if (i == j)
                assert(isSymmetricMatrix(m));
            else
                assert(!isSymmetricMatrix(m));
            m.values[i][j] = values[j + i * c];
        }

    freeMemMatrix(m);
}

void test_transposeSquareMatrix() {
    int values[] = {9, 8, 7,
                    6, 5, 4,
                    3, 2, 1};
    int result[] = {9, 6, 3,
                    8, 5, 2,
                    7, 4, 1};
    int r = 3, c = 3;
    matrix m = createMatrixFromArray(values, r, c);

    transposeSquareMatrix(m);

    for (int i = 0; i < r; ++i)
        for (int j = 0; j < c; ++j)
            assert(m.values[i][j] == result[j + i * c]);

    freeMemMatrix(m);
}

void test_initC() {
    int values[] = {9, 8, 7,
                    6, 5, 4,
                    3, 2, 1};
    int r = 3, c = 3;
    matrix m = createMatrixFromArray(values, r, c);

    counter cou = initC(m);

    assert(cou.isFinished == false);
    assert(cou.count == 0);

    freeMemMatrix(m);
}

void test_getValueC() {
    int values[] = {9, 8, 7,
                    6, 5, 4,
                    3, 2, 1};
    int r = 3, c = 3;
    matrix m = createMatrixFromArray(values, r, c);
    counter cou = initC(m);

    int i = 0;
    while (!cou.isFinished)
        assert(getValueC(&cou) == values[i++]);

    freeMemMatrix(m);
}

void test_getLinkC() {
    int values[] = {9, 8, 7,
                    6, 5, 4,
                    3, 2, 1};
    int r = 3, c = 3;
    matrix m = createMatrixFromArray(values, r, c);
    counter cou = initC(m);

    int i = 0;
    while (!cou.isFinished) {
        assert(getLinkC(&cou) == m.values[i / c] + i % c);
        i++;
    }

    freeMemMatrix(m);
}

void test_getPositionC() {
    int values[] = {9, 8, 7,
                    6, 5, 4,
                    3, 2, 1};
    int r = 3, c = 3;
    matrix m = createMatrixFromArray(values, r, c);
    counter cou = initC(m);

    int i = 0;
    while (!cou.isFinished) {
        position p = getPositionC(&cou);
        assert(p.rowIndex == i / c);
        assert(p.colIndex == i % c);
        i++;
    }

    freeMemMatrix(m);
}

void test_getReversPositionC() {
    int values[] = {9, 8, 7,
                    6, 5, 4,
                    3, 2, 1};
    int r = 3, c = 3;
    matrix m = createMatrixFromArray(values, r, c);
    counter cou = initC(m);

    int i = r * c - 1;
    while (!cou.isFinished) {
        position p = getReversPositionC(&cou);
        assert(p.rowIndex == i / c);
        assert(p.colIndex == i % c);
        i--;
    }

    freeMemMatrix(m);
}

void test_setValueC() {
    int values[] = {1, 1, 1,
                    1, 1, 1,
                    1, 1, 1};
    int r = 3, c = 3;
    matrix m = createMatrixFromArray(values, r, c);
    counter cou = initC(m);

    int i = 0;
    while (!cou.isFinished) {
        setValueC(&cou, 2);
        position p = (position) {i / c, i % c};
        assert(getValue(m, p) == 2);
        position pm = getMaxValuePos(m);
        assert(pm.rowIndex == p.rowIndex);
        assert(pm.colIndex == p.colIndex);
        setValue(m, p, 1);
        i++;
    }

    freeMemMatrix(m);
}

void test_muvC() {
    int values[] = {1, 1, 1,
                    1, 1, 1,
                    1, 1, 1};
    int r = 3, c = 3;
    matrix m = createMatrixFromArray(values, r, c);
    counter cou = initC(m);

    int i = 0;
    while (!cou.isFinished) {
        assert(cou.count == i);
        muvC(&cou);
        i++;
    }
    assert(cou.count == r * c);
    assert(cou.isFinished);

    freeMemMatrix(m);
}

void test_task13();

void test_task14();

void test_task16();

void test_task17();

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

    test_task13();
    test_task14();
    test_task16();
    test_task17();
}
