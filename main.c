#include <stdio.h>

#include "libs/data_structures/matrix/matrix.h"

int sum(int *arr, int n){
    int res = 0;
    for (int i = 0; i < n; ++i)
        res += arr[i];
    return res;
}

int main() {
    matrix m = getMemMatrix(3, 2);

    inputMatrix(m);

    printf("\n");
    insertionSortRowsMatrixByRowCriteria(m, sum);
    outputMatrix(m);
    printf("\n");
    insertionSortColsMatrixByColCriteria(m, sum);
    outputMatrix(m);

    return 0;
}
