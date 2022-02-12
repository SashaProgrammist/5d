#include "../libs/data_structures/matrix/matrix.h"
#include "../libs/algorithms/oneDimArray/oneDimArray.h"

void sortColsByMinElement(matrix m) {
    insertionSortColsMatrixByColCriteria(m, getMin);
}

void task3() {
    matrix m = fCons_inputMatrix();

    sortColsByMinElement(m);

    outputMatrix(m);

    freeMemMatrix(m);
}

