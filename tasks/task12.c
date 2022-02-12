#include "../libs/data_structures/matrix/matrix.h"
#include "../libs/algorithms/oneDimArray/oneDimArray.h"

position getLeftMin(matrix m){
    int min = **m.values;
    position result = (position) {0, 0};

    for (int j = 0; j < m.nCols; ++j)
        for (int i = 0; i < m.nRows; ++i)
            if (min > m.values[i][j]){
                min = m.values[i][j];
                result = (position) {i, j};
            }

    return result;
}

void swapPenultimateRow(matrix m, int n){
    int *colum = getColumn(m, n);

    for (int i = 0; i < m.nCols; ++i)
        m.values[m.nRows - 2][i] = colum[i];

    free(colum);
}

void swapColumLeftMinPenultimateRow(matrix m){
    int colum = getLeftMin(m).colIndex;

    swapPenultimateRow(m, colum);
}

void task12() {
    matrix m = fCons_inputSquareMatrix();

    swapColumLeftMinPenultimateRow(m);

    outputMatrix(m);

    freeMemMatrix(m);
}


