#include "../libs/data_structures/matrix/matrix.h"

position getLeftMin(matrix m) {
    int min = **m.values;
    position result = (position) {0, 0};

    for (int j = 0; j < m.nCols; ++j)
        for (int i = 0; i < m.nRows; ++i)
            if (min > m.values[i][j]) {
                min = m.values[i][j];
                result = (position) {i, j};
            }

    return result;
}

void swapPenultimateRow(matrix m, int n) {
    if (!isSquareMatrix(m) ||
        m.nRows < 2)
        return;

    int *colum = getColumn(m, n);
    int *penultimateRow = m.values[m.nRows - 2];

    for (int j = 0; j < m.nCols; ++j)
        penultimateRow[j] = colum[j];

    free(colum);
}

void swapColumLeftMinPenultimateRow(matrix m) {
    int colum = getLeftMin(m).colIndex;

    swapPenultimateRow(m, colum);
}

void task12() {
    matrix m = fCons_inputSquareMatrix();

    swapColumLeftMinPenultimateRow(m);

    outputMatrix(m);

    freeMemMatrix(m);
}
