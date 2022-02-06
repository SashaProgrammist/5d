#include <stdio.h>

#include "libs/data_structures/matrix/matrix.h"

int main() {
    matrix m = getMemMatrix(3, 3);
    inputMatrix(m);

    printf("isSquareMatrix %d\n", isSquareMatrix(m));

    printf("isEMatrix %d\n", isEMatrix(m));

    printf("twoMatricesEqual %d\n", twoMatricesEqual(m, m));

    printf("isSymmetricMatrix %d\n", isSymmetricMatrix(m));

    return 0;
}
