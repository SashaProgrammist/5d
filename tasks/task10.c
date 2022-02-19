#include "../libs/data_structures/matrix/matrix.h"

int cmp_long_long(const void *pa, const void *pb) {
    long long a = *((long long *) pa);
    long long b = *((long long *) pb);

    if (a > b) return 1;
    if (b < a) return -1;
    return 0;
}

int countNUnique(long long *a, int n) {
    long long *workingMem = (long long *) malloc(n * sizeof(long long));
    memcpy(workingMem, a, n * sizeof(long long));
    qsort(workingMem, n, sizeof(long long),
          cmp_long_long);

    int result = 0;
    for (int i = 0, j = 0; i <= n; ++i)
        if ((i == n) || (workingMem[i] != workingMem[j])) {
            if (i - j != 1) // i - j == 1 => workingMem[j] is unique
                result++;
            j = i;
        }

    free(workingMem);
    return result;
}

int countEqClassesByRowsSum(matrix m) {
    long long *sums = (long long *) malloc(m.nRows * sizeof(long long));

    for (int i = 0; i < m.nRows; ++i)
        sums[i] = getSum(m.values[i], m.nCols);

    int result = countNUnique(sums, m.nRows);

    free(sums);
    return result;
}

void task10() {
    matrix m = fCons_inputMatrix();

    int result = countEqClassesByRowsSum(m);

    printf("%d", result);

    freeMemMatrix(m);
}