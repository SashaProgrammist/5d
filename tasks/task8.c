#include "../libs/data_structures/matrix/matrix.h"

long long getMinInArea(matrix m) {
    position posMax = getMaxValuePos(m);
    int min = getValue(m, posMax);

    for (int i = posMax.rowIndex - 1; i >= 0; i--) {
        int indent = posMax.rowIndex - i;
        int startArea = posMax.colIndex - indent;
        if (startArea < 0) startArea = 0;
        int endArea = posMax.colIndex + indent;
        if (endArea >= m.nCols) endArea = m.nCols - 1;

        for (int j = startArea; j <= endArea; ++j){
            int currentV = m.values[i][j];
            if (currentV < min)
                min = currentV;
        }
    }

    return min;
}

void task8() {
    matrix m = fCons_inputMatrix();

    long long result = getMinInArea(m);

    printf("%lld", result);

    freeMemMatrix(m);
}
