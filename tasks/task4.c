#include "../libs/data_structures/matrix/matrix.h"

void getSquareOfMatrixIfSymmetric(matrix *m) {
    if (isSymmetricMatrix(*m)){
        matrix result = getSquareOfMatrix(*m);
        freeMemMatrix(*m);
        *m = result;
    }
}

void task4() {
    matrix m = fCons_inputSquareMatrix();

    getSquareOfMatrixIfSymmetric(&m);

    outputMatrix(m);

    freeMemMatrix(m);
}
