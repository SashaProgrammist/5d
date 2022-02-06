//
// Created by PC on 06.02.2022.
//

#include "matrix.h"

void swap(void *a, void *b, size_t size) {
    char *arg1 = (char *) a;
    char *arg2 = (char *) b;

    for (size_t i = 0; i < size; i++) {
        char t = arg1[i];
        arg1[i] = arg2[i];
        arg2[i] = t;
    }
}

// memory

matrix getMemMatrix(int nRows, int nCols) {
    int **values = (int **) malloc(sizeof(int *) * nRows);
    for (int i = 0; i < nRows; i++)
        values[i] = (int *) malloc(sizeof(int) * nCols);
    return (matrix) {values, nRows, nCols};
}

matrix *getMemArrayOfMatrices(int nMatrices,
                              int nRows, int nCols) {
    matrix *ms = (matrix *) malloc(sizeof(matrix) * nMatrices);
    for (int i = 0; i < nMatrices; i++)
        ms[i] = getMemMatrix(nRows, nCols);
    return ms;
}

void freeMemMatrix(matrix m) {
    for (int i = 0; i < m.nRows; i++)
        free(m.values[i]);

    free(m.values);
}

void freeMemMatrices(matrix *ms, int nMatrices) {
    for (int i = 0; i < nMatrices; ++i)
        freeMemMatrix(ms[i]);

    free(ms);
}

// input / output

void inputMatrix(matrix m) {
    counter c = initC(m);

    while (!c.isFinished){
        int *current = getLinkC(&c);
        scanf("%d", current);
    }
}

void inputMatrices(matrix *ms, int nMatrices) {
    for (int i = 0; i < nMatrices; ++i)
        inputMatrix(ms[i]);
}

void outputMatrix(matrix m) {
    for (int i = 0; i < m.nRows; ++i) {
        for (int j = 0; j < m.nCols; ++j)
            printf("%d ", m.values[i][j]);
        printf("\n");
    }
}

void outputMatrices(matrix *ms, int nMatrices) {
    for (int i = 0; i < nMatrices; ++i) {
        outputMatrix(ms[i]);
        printf("\n");
    }
}

// create

matrix createMatrixFromArray(const int *values,
                             int nRows, int nCols){
    matrix m = getMemMatrix(nRows, nCols);
    counter c = initC(m);
    int i = 0;

    while (!c.isFinished)
        setValueC(&c, values[i++]);

    return m;
}

matrix *createArrayOfMatrixFromArray(const int *values,
                                     int nMatrices,
                                     int nRows, int nCols){
    matrix *ms = getMemArrayOfMatrices(nMatrices, nRows, nCols );
    int j = 0;

    for (int i = 0; i < nMatrices; ++i) {
        counter c = initC(ms[i]);

        while (!c.isFinished)
            setValueC(&c, values[j++]);
    }

    return ms;
}

// swap

void swapRows(matrix m, int i1, int i2) {
    swap(m.values + i1, m.values + i2, sizeof(int *));
}

void swapColumns(matrix m, int j1, int j2) {
    for (int i = 0; i < m.nRows; i++)
        swap(m.values[i] + j1, m.values[i] + j2, sizeof(int));
}

// sort

void insertionSortRowsMatrixByRowCriteria(matrix m,
                                          int (*criteria)(int *, int)) {
    int *resultsCriteriaInRows =
            (int *) malloc(m.nRows * sizeof(int));
    for (int i = 0; i < m.nRows; ++i)
        resultsCriteriaInRows[i] =
                criteria(m.values[i], m.nCols);

    for (int i = 0; i < m.nRows; ++i) {
        int current = i;
        for (int j = i + 1; j < m.nRows; ++j)
            if (resultsCriteriaInRows[current] >
                resultsCriteriaInRows[j])
                current = j;

        if (current != i) {
            swapRows(m, i, current);
            swap(resultsCriteriaInRows + current,
                 resultsCriteriaInRows + i,
                 sizeof(int));
        }
    }

    free(resultsCriteriaInRows);
}

void insertionSortColsMatrixByColCriteria(matrix m,
                                          int (*criteria)(int *, int)) {
    int *resultsCriteriaInCols =
            (int *) malloc(m.nCols * sizeof(int));
    for (int j = 0; j < m.nCols; ++j) {
        int *currentCol = getColumn(m, j);
        resultsCriteriaInCols[j] = criteria(currentCol, m.nRows);
        free(currentCol);
    }

    for (int i = 0; i < m.nCols; ++i) {
        int current = i;
        for (int j = i + 1; j < m.nCols; ++j)
            if (resultsCriteriaInCols[current] >
                resultsCriteriaInCols[j])
                current = j;

        if (current != i) {
            swapColumns(m, i, current);
            swap(resultsCriteriaInCols + current,
                 resultsCriteriaInCols + i,
                 sizeof(int));
        }
    }

    free(resultsCriteriaInCols);
}

// get

int *getColumn(matrix m, int j) {
    int *result = malloc(m.nRows * sizeof(int));

    for (int i = 0; i < m.nRows; ++i)
        result[i] = m.values[i][j];

    return result;
}

int getValue(matrix m, position p) {
    return m.values[p.rowIndex][p.colIndex];
}

int *getLink(matrix m, position p){
    return m.values[p.rowIndex] + p.colIndex;
}

position getMinValuePos(matrix m) {
    position result = (position) {0, 0};
    int min = getValue(m, result);

    counter c = initC(m);
    while (!c.isFinished){
        position currentP = getPositionC(&c);
        int currentV = getValue(m, currentP);

        if (currentV < min){
            result = currentP;
            min = currentV;
        }
    }

    return result;
}

position getMaxValuePos(matrix m) {
    position result = (position) {0, 0};
    int max = getValue(m, result);

    counter c = initC(m);
    while (!c.isFinished){
        position currentP = getPositionC(&c);
        int currentV = getValue(m, currentP);

        if (currentV > max){
            result = currentP;
            max = currentV;
        }
    }

    return result;
}

// set

void setValue(matrix m, position p, int value) {
    m.values[p.rowIndex][p.colIndex] = value;
}

// bool

bool isSquareMatrix(matrix m) {
    return m.nRows == m.nCols;
}

bool twoMatricesEqual(matrix m1, matrix m2) {
    if (m1.nRows != m2.nRows || m1.nCols != m2.nCols)
        return false;

    counter c = initC(m1);
    while (!c.isFinished){
        position p = getPositionC(&c);

        if (getValue(m1, p) != getValue(m2, p))
            return false;
    }

    return true;
}

bool isEMatrix(matrix m) {
    if (!isSquareMatrix(m))
        return false;
    int n = m.nRows;

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            if (m.values[i][j] != (i == j))
                return false;

    return true;
}

bool isSymmetricMatrix(matrix m) {
    if (!isSquareMatrix(m))
        return false;
    int n = m.nRows;

    for (int i = 0; i < n; ++i)
        for (int j = i + 1; j < n; ++j)
            if (m.values[i][j] != m.values[j][i])
                return false;

    return true;
}

// transformations

void transposeSquareMatrix(matrix m) {
    if (!isSquareMatrix(m))
        return;
    int n = m.nRows;

    for (int i = 0; i < n; ++i)
        for (int j = i + 1; j < n; ++j)
            swap(m.values[i] + j, m.values[j] + i, sizeof(int));
}

// counter

counter initC(matrix m) {
    return (counter) {m, 0, false};
}

position getPositionC(counter *c) {
    if (c->isFinished) return (position) {-1, -1};

    position result = (position) {
            c->count / c->m.nCols,
            c->count % c->m.nCols
    };

    muvC(c);

    return result;
}

int getValueC(counter *c) {
    position p = getPositionC(c);

    return getValue(c->m, p);
}

int *getLinkC(counter *c){
    position p = getPositionC(c);

    return getLink(c->m, p);
}

void setValueC(counter *c, int value) {
    position p = getPositionC(c);

    setValue(c->m, p, value);
}

void muvC(counter *c) {
    if (c->isFinished) return;

    (c->count)++;
    if (c->count / c->m.nCols >= c->m.nRows)
        c->isFinished = true;
}
