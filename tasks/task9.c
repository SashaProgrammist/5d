#include "../libs/data_structures/matrix/matrix.h"

#include <math.h>

float getDistance(int *a, int n){
    float result = 0;

    for (int i = 0; i < n; ++i) {
        float current = a[i];
        result += current * current;
    }

    return sqrt(result);
}

void insertionSortRowsMatrixByRowCriteriaF(matrix m,
                                           float (*criteria)(int *, int)){
    float *resultsCriteriaInRows =
            (float *) malloc(m.nRows * sizeof(float));
    for (int i = 0; i < m.nRows; ++i)
        resultsCriteriaInRows[i] =
                criteria(m.values[i], m.nCols);

    for (int i = 0; i < m.nRows; ++i) {
        int current = i;
        for (int j = i + 1; j < m.nRows; ++j)
            if (resultsCriteriaInRows[current] >
                resultsCriteriaInRows[j])
                current = j;

        if (current != i) {
            swapRows(m, i, current);
            swap(resultsCriteriaInRows + current,
                 resultsCriteriaInRows + i,
                 sizeof(float));
        }
    }

    free(resultsCriteriaInRows);
}

void sortByDistances(matrix m){
    insertionSortRowsMatrixByRowCriteriaF(m, getDistance);
}


void task9() {
    matrix m = fCons_inputMatrix();

    sortByDistances(m);

    outputMatrix(m);

    freeMemMatrix(m);
}

