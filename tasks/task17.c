#include "..\libs\data_structures\matrix\matrix.h"

#include <math.h>
#include <assert.h>

double d_getScalarProduct(double *a, double *b, size_t size) {
    double result = 0;

    for (int i = 0; i < size; ++i)
        result += a[i] * b[i];

    return result;
}

double getVectorLength(int *a, int n) {
    double result = 0;

    for (int i = 0; i < n; ++i) {
        double current = a[i];
        result += current * current;
    }

    return sqrt(result);
}

double *getNormal(int *a, int n) {
    double length = getVectorLength(a, n);
    double *result = (double *) malloc(n * sizeof(double));

    for (int i = 0; i < n; ++i)
        result[i] = a[i] / length;

    return result;
}

int getVectorIndexWithMaxAngle(matrix m, int *b) {
    double *bNormal = getNormal(b, m.nCols);
    double minCos = 2;
    int result = -1;

    for (int i = 0; i < m.nRows; ++i) {
        double *currentNormal = getNormal(m.values[i], m.nCols);
        double currentCos = d_getScalarProduct(currentNormal, bNormal, m.nCols);

        if (currentCos < minCos) {
            minCos = currentCos;
            result = i;
        }

        free((void *) currentNormal);
    }

    free((void *) bNormal);

    return result;
}

void test_task17() {
    matrix m = createMatrixFromArray(
            (int[]) {
                    1, 0, 0,
                    0, 1, 0,
                    0, 0, 1
            },
            3, 3
    );

    assert(0 == getVectorIndexWithMaxAngle(m, (int []) {1, 2, 2}));
    assert(1 == getVectorIndexWithMaxAngle(m, (int []) {2, 1, 2}));
    assert(2 == getVectorIndexWithMaxAngle(m, (int []) {2, 2, 1}));

    freeMemMatrix(m);
}

void task17() {
    matrix m = fCons_inputMatrix();
    int *b;
    setInputArray(&b, m.nCols);

    int result = getVectorIndexWithMaxAngle(m, b);

    printf("%d", result);

    free((void *) b);
    freeMemMatrix(m);
}


