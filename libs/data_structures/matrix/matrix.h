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

typedef struct counter{
    matrix m;
    int count;
    bool isFinished;
} counter;

// memory

matrix getMemMatrix(int nRows, int nCols);

matrix *getMemArrayOfMatrices(int nMatrices,
                              int nRows, int nCols);

void freeMemMatrix(matrix m);

void freeMemMatrices(matrix *ms, int nMatrices);

// input / output

void inputMatrix(matrix m);

void inputMatrices(matrix *ms, int nMatrices);

void outputMatrix(matrix m);

void outputMatrices(matrix *ms, int nMatrices);

// create

matrix createMatrixFromArray(const int *values,
                             int nRows, int nCols);

matrix *createArrayOfMatrixFromArray(const int *values,
                                     int nMatrices,
                                     int nRows, int nCols);

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

int getValue(matrix m, position p);

int *getLink(matrix m, position p);

position getMinValuePos(matrix m);

position getMaxValuePos(matrix m);

matrix getSquareOfMatrix(matrix m);

matrix getMulMatrices(matrix m1, matrix m2);

// set

void setValue(matrix m, position p, int value) ;

// bool

bool isSquareMatrix(matrix m);

bool twoMatricesEqual(matrix m1, matrix m2);

bool isEMatrix(matrix m);

bool isSymmetricMatrix(matrix m);

// transformations

void transposeSquareMatrix(matrix m);

void getSquareOfMatrixIfSymmetric(matrix *m);

// counter

counter initC(matrix m);

int getValueC(counter *c);

int *getLinkC(counter *c);

position getPositionC(counter *c);

void setValueC(counter *c, int value);

void muvC(counter *c);

// from console

matrix fCons_inputSquareMatrix();

matrix fCons_inputMatrix();

#endif //INC_5D_MATRIX_H
