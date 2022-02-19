#include "../libs/data_structures/matrix/matrix.h"

int getCountSpecialNumber(int *a, int n){
    long long sum = getSum(a, n);
    int result = 0;

    for (int i = 0; i < n; ++i)
        if (sum < 2 * a[i])
            result++;

    return result;
}

int getNSpecialElement(matrix m){
    int result = 0;

    for (int j = 0; j < m.nCols; ++j) {
        int *currentColum = getColumn(m, j);
        result += getCountSpecialNumber(currentColum, m.nRows);
        free((void *)currentColum);
    }

    return result;
}

void task11() {
    matrix m = fCons_inputMatrix();

    int result = getNSpecialElement(m);

    printf("%d", result);

    freeMemMatrix(m);
}
