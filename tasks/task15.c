#include <stdio.h>
#include <assert.h>
#include <malloc.h>
#include <math.h>
#include <float.h>

typedef struct f_matrix {
    float **values; // элементы матрицы
    int nRows;      // количество рядов
    int nCols;      // количество столбцов
} f_matrix;

typedef struct position {
    int rowIndex;
    int colIndex;
} position;

f_matrix f_getMemMatrix(int nR, int nC) {
    if (nR <= 0 || nC <= 0) {
        fprintf(stderr, "value error");
        exit(1);
    }

    float **values = (float **) malloc(sizeof(float *) * nR);
    for (int i = 0; i < nR; i++)
        values[i] = (float *) malloc(sizeof(float) * nC);
    return (f_matrix) {values, nR, nC};
}

f_matrix *f_getMemArrayOfMatrices(int nM, int nR, int nC) {
    if (nM <= 0 || nR <= 0 || nC <= 0) {
        fprintf(stderr, "value error");
        exit(1);
    }

    f_matrix *ms = (f_matrix *) malloc(nM * sizeof(f_matrix));
    for (int i = 0; i < nM; i++)
        ms[i] = f_getMemMatrix(nR, nC);
    return ms;
}

void f_inputMatrix(f_matrix m) {
    for (int i = 0; i < m.nRows; ++i)
        for (int j = 0; j < m.nCols; ++j)
            scanf("%f", m.values[i] + j);
}

void f_inputMatrices(f_matrix *ms, int nM) {
    for (int i = 0; i < nM; ++i)
        f_inputMatrix(ms[i]);
}

void f_freeMemMatrix(f_matrix m) {
    for (int i = 0; i < m.nRows; i++)
        free(m.values[i]);

    free(m.values);
}

void f_freeMemMatrices(f_matrix *ms, int nM) {
    for (int i = 0; i < nM; ++i)
        f_freeMemMatrix(ms[i]);

    free(ms);
}

void f_fCons_inputMatrices(f_matrix **ms, int *nM) {
    int nR, nC;
    scanf("%d %d %d", nM, &nR, &nC);

    *ms = f_getMemArrayOfMatrices(*nM, nR, nC);

    f_inputMatrices(*ms, *nM);
}

float f_getMaxValue(f_matrix m) {
    float max = fabs(m.values[0][0]);

    for (int i = 0; i < m.nRows; ++i)
        for (int j = 0; j < m.nCols; ++j){
            float curV = fabs(m.values[i][j]);

            if (curV > max)
                max = curV;
        }

    return max;
}

float f_getMin(float *arr, int size) {
    float min = *arr;

    for (int i = 1; i < size; ++i)
        if (arr[i] < min)
            min = arr[i];

    return min;
}

void f_outputMatrix(f_matrix m) {
    for (int i = 0; i < m.nRows; ++i) {
        for (int j = 0; j < m.nCols; ++j)
            printf("%f ", m.values[i][j]);
        printf("\n");
    }
}

void f_printMinMaxMatrix(f_matrix *ms, int nM) {
    float *max = (float *) malloc(nM * sizeof(float ));

    for (int i = 0; i < nM; ++i)
        max[i] = f_getMaxValue(ms[i]);

    float min = f_getMin(max, nM);

    for (int i = 0; i < nM; ++i)
        if (fabs(max[i] - min) < FLT_EPSILON)
            f_outputMatrix(ms[i]);
}

void task15() {
    f_matrix *ms;
    int nM;
    f_fCons_inputMatrices(&ms, &nM);

    f_printMinMaxMatrix(ms, nM);

    f_freeMemMatrices(ms, nM);
}
