#include "../libs/data_structures/matrix/matrix.h"
#include "../libs/algorithms/oneDimArray/oneDimArray.h"

void sortRowsByMaxElement(matrix m) {
    insertionSortRowsMatrixByRowCriteria(m, getMax);
}

void task2() {
    matrix m = fCons_inputMatrix();

    sortRowsByMaxElement(m);

    outputMatrix(m);

    freeMemMatrix(m);
}
