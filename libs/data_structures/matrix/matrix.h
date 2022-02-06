//
// Created by PC on 06.02.2022.
//

#ifndef INC_5D_MATRIX_H
#define INC_5D_MATRIX_H

#include <malloc.h>
#include <stdio.h>
#include <memory.h>
#include <stdbool.h>

typedef struct matrix {
    int **values; // элементы матрицы
    int nRows;    // количество рядов
    int nCols;    // количество столбцов
} matrix;

typedef struct position {
    int rowIndex;
    int colIndex;
} position;

// memory

matrix getMemMatrix(int nRows, int nCols);

matrix *getMemArrayOfMatrices(int nMatrices,
                              int nRows, int nCols);

void freeMemMatrix(matrix m);

void freeMemMatrices(matrix *ms, int nMatrices);

#endif //INC_5D_MATRIX_H

// input / output

void inputMatrix(matrix m);

void inputMatrices(matrix *ms, int nMatrices);

void outputMatrix(matrix m);

void outputMatrices(matrix *ms, int nMatrices);

// swap

void swapRows(matrix m, int i1, int i2);

void swapColumns(matrix m, int j1, int j2);

// sort

void insertionSortRowsMatrixByRowCriteria(matrix m,
                                          int (*criteria)(int *, int));

void insertionSortColsMatrixByColCriteria(matrix m,
                                          int (*criteria)(int *, int));

// get

int *getColumn(matrix m, int j);

// bool

bool isSquareMatrix(matrix m);

bool twoMatricesEqual(matrix m1, matrix m2);

bool isEMatrix(matrix m);

bool isSymmetricMatrix(matrix m);

// transformations

void transposeSquareMatrix(matrix m);
