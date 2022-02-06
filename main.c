#include <stdio.h>

#include "libs/data_structures/matrix/matrix.h"

int main() {
    matrix m = getMemMatrix(3, 3);
    inputMatrix(m);

    transposeSquareMatrix(m);

    outputMatrix(m);

    return 0;
}
