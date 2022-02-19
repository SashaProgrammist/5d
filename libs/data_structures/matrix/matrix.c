//
// Created by PC on 06.02.2022.
//

#include "matrix.h"

// memory

matrix getMemMatrix(int nRows, int nCols) {
    if (nRows <= 0 || nCols <= 0) {
        fprintf(stderr, "value error");
        exit(1);
    }

    int **values = (int **) malloc(sizeof(int *) * nRows);
    for (int i = 0; i < nRows; i++)
        values[i] = (int *) malloc(sizeof(int) * nCols);
    return (matrix) {values, nRows, nCols};
}

matrix *getMemArrayOfMatrices(int nMatrices,
                              int nRows, int nCols) {
    if (nMatrices <= 0 || nRows <= 0 || nCols <= 0) {
        fprintf(stderr, "value error");
        exit(1);
    }

    matrix *ms = (matrix *) malloc(nMatrices * sizeof(matrix));
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

    while (!c.isFinished)
        scanf("%d", getLinkC(&c));
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
                             int nRows, int nCols) {
    if (nRows <= 0 || nCols <= 0) {
        fprintf(stderr, "value error");
        exit(1);
    }

    matrix m = getMemMatrix(nRows, nCols);
    counter c = initC(m);

    while (!c.isFinished)
        setValueC(&c, values[c.count]);

    return m;
}

matrix *createArrayOfMatrixFromArray(const int *values,
                                     int nMatrices,
                                     int nRows, int nCols) {
    matrix *ms = getMemArrayOfMatrices(nMatrices, nRows, nCols);
    int currentValueIndex = 0;

    for (int i = 0; i < nMatrices; ++i) {
        counter c = initC(ms[i]);

        while (!c.isFinished)
            setValueC(&c, values[currentValueIndex++]);
    }

    return ms;
}

// swap

void swapRows(matrix m, int i1, int i2) {
    if (i1 < 0 || i1 >= m.nRows ||
        i2 < 0 || i2 >= m.nRows) {
        fprintf(stderr, "value error");
        exit(1);
    }

    if (i1 == i2) return;

    swap(m.values + i1, m.values + i2, sizeof(int *));
}

void swapColumns(matrix m, int j1, int j2) {
    if (j1 < 0 || j1 >= m.nCols ||
        j2 < 0 || j2 >= m.nCols) {
        fprintf(stderr, "value error");
        exit(1);
    }

    if (j1 == j2) return;

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

    for (int i = 1; i < m.nRows; ++i) {
        int currentSwapRow = i - 1;
        int currentCriteria = resultsCriteriaInRows[i];
        int *currentRow = m.values[i];
        int currentIndexRow = i;

        while (currentSwapRow >= 0 &&
               resultsCriteriaInRows[currentSwapRow] > currentCriteria) {
            m.values[currentIndexRow] = m.values[currentSwapRow];
            resultsCriteriaInRows[currentIndexRow] = resultsCriteriaInRows[currentSwapRow];

            currentSwapRow--;
            currentIndexRow--;
        }

        m.values[currentIndexRow] = currentRow;
        resultsCriteriaInRows[currentIndexRow] = currentCriteria;
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

int *getLink(matrix m, position p) {
    return m.values[p.rowIndex] + p.colIndex;
}

position getMinValuePos(matrix m) {
    position result = (position) {0, 0};
    int min = getValue(m, result);

    counter c = initC(m);
    while (!c.isFinished) {
        position currentP = getPositionC(&c);
        int currentV = getValue(m, currentP);

        if (currentV < min) {
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
    while (!c.isFinished) {
        position currentP = getPositionC(&c);
        int currentV = getValue(m, currentP);

        if (currentV > max) {
            result = currentP;
            max = currentV;
        }
    }

    return result;
}

matrix getSquareOfMatrix(matrix m) {
    return getMulMatrices(m, m);
}

matrix getMulMatrices(matrix m1, matrix m2) {
    if (m1.nCols != m2.nRows) {
        fprintf(stderr, "impossible action");
        exit(1);
    }

    int n = m1.nCols;
    matrix result = getMemMatrix(m1.nRows, m2.nCols);
    counter c = initC(result);

    while (!c.isFinished) {
        position currentPosition = getPositionC(&c);

        int *curColum = getColumn(m2, currentPosition.colIndex);
        int currentSum = scalarProduct(m1.values[currentPosition.rowIndex], curColum, n);
        free((void *) curColum);

        setValue(result, currentPosition, currentSum);
    }

    return result;
}


// set

void setValue(matrix m, position p, int value) {
    *getLink(m, p) = value;
}

// bool

bool isSquareMatrix(matrix m) {
    return m.nRows == m.nCols;
}

bool twoMatricesEqual(matrix m1, matrix m2) {
    if (m1.nRows != m2.nRows || m1.nCols != m2.nCols)
        return false;

    int nRows = m1.nRows;
    int nColum = m1.nCols;
    int sizeRow = nColum * sizeof(int);

    for (int i = 0; i < nRows; ++i)
        if (0 != memcmp(m1.values[i],
                        m2.values[i],
                        sizeRow))
            return false;

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

void transposeMatrix(matrix *m) {
    if (isSquareMatrix(*m)) {
        transposeSquareMatrix(*m);
        return;
    }

    matrix result = getMemMatrix(m->nCols, m->nCols);

    for (int i = 0; i < m->nRows; ++i)
        for (int j = 0; j < m->nCols; ++j)
            result.values[j][i] = m->values[i][j];

    freeMemMatrix(*m);

    *m = result;
}

// counter

counter initC(matrix m) {
    return (counter) {m, 0, false};
}

position getPositionC(counter *c) {
    position result = (position) {
            c->count / c->m.nCols,
            c->count % c->m.nCols
    };

    muvC(c);

    return result;
}

position getReversPositionC(counter *c) {
    position p = getPositionC(c);

    return (position) {c->m.nRows - 1 - p.rowIndex,
                       c->m.nCols - 1 - p.colIndex};
}

int getValueC(counter *c) {
    position p = getPositionC(c);

    return getValue(c->m, p);
}

int *getLinkC(counter *c) {
    position p = getPositionC(c);

    return getLink(c->m, p);
}

void setValueC(counter *c, int value) {
    position p = getPositionC(c);

    setValue(c->m, p, value);
}

void muvC(counter *c) {
    (c->count)++;
    if (c->count / c->m.nCols >= c->m.nRows)
        c->isFinished = true;
}

// from console

matrix fCons_inputSquareMatrix() {
    int n;
    scanf("%d", &n);

    matrix m = getMemMatrix(n, n);

    inputMatrix(m);

    return m;
}

matrix fCons_inputMatrix() {
    int n_r, n_c;
    scanf("%d %d", &n_r, &n_c);

    matrix m = getMemMatrix(n_r, n_c);

    inputMatrix(m);

    return m;
}

void fCons_inputMatrices(matrix **ms, int *nM) {// 4 * OK
    int nR, nC;
    scanf("%d %d %d", nM, &nR, &nC);

    *ms = getMemArrayOfMatrices(*nM, nR, nC);

    inputMatrices(*ms, *nM);
}
