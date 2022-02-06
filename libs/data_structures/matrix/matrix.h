//
// Created by PC on 06.02.2022.
//

#ifndef INC_5D_MATRIX_H
#define INC_5D_MATRIX_H

#include <malloc.h>

typedef struct matrix {
    int **values; // элементы матрицы
    int nRows;    // количество рядов
    int nCols;    // количество столбцов
} matrix;

typedef struct position {
    int rowIndex;
    int colIndex;
} position;

matrix getMemMatrix(int nRows, int nCols);

matrix *getMemArrayOfMatrices(int nMatrices,
                              int nRows, int nCols);

void freeMemMatrix(matrix m);

void freeMemMatrices(matrix *ms, int nMatrices);

#endif //INC_5D_MATRIX_H
