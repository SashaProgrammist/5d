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
    for (int i = 0; i < m.nRows; ++i)
        for (int j = 0; j < m.nCols; ++j)
            scanf("%d", m.values[i] + j);
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

// bool

bool isSquareMatrix(matrix m){
    return m.nRows == m.nCols;
}

bool twoMatricesEqual(matrix m1, matrix m2){
    if (m1.nRows != m2.nRows || m1.nCols != m2.nCols)
        return false;

    for (int i = 0; i < m1.nRows; ++i)
        for (int j = 0; j < m1.nCols; ++j)
            if (m1.values[i][j] != m2.values[i][j])
                return false;

    return true;
}

bool isEMatrix(matrix m){
    if (!isSquareMatrix(m))
        return false;
    int n = m.nRows;

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            if (m.values[i][j] != (i == j))
                return false;

    return true;
}

bool isSymmetricMatrix(matrix m){
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

void transposeSquareMatrix(matrix m){
    if (!isSquareMatrix(m))
        return;
    int n = m.nRows;

    for (int i = 0; i < n; ++i)
        for (int j = i + 1; j < n; ++j)
            swap(m.values[i] + j, m.values[j] + i, sizeof(int));
}
