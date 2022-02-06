#include <stdio.h>

#include "libs/data_structures/matrix/matrix.h"

int main() {
    matrix m = getMemMatrix(3, 2);

    inputMatrix(m);

    swapColumns(m, 0, 1);
    swapRows(m, 0, 1);

    outputMatrix(m);
    return 0;
}
