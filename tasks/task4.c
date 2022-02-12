#include "../libs/data_structures/matrix/matrix.h"
#include "../libs/algorithms/oneDimArray/oneDimArray.h"

void task4() {
    matrix m = fCons_inputSquareMatrix();

    getSquareOfMatrixIfSymmetric(&m);

    outputMatrix(m);

    freeMemMatrix(m);
}


