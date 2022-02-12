#include "../libs/data_structures/matrix/matrix.h"


bool isInArea(position pos, position max) {
    return abs(pos.colIndex - max.colIndex) <=
           (max.rowIndex - pos.rowIndex);
}

long long getMinInArea(matrix m) {
    position posMax = (position) {
            m.nRows - 1,
            m.nCols - 1};
    int min = getValue(m, posMax);
    int max = getValue(m, posMax);

    counter c = initC(m);

    while (!c.isFinished){
        position currentP = getReversPositionC(&c);
        int currentV = getValue(m, currentP);

        if (currentV > max) {
            max = currentV;
            posMax = currentP;
            min = currentV;
        } else if (isInArea(currentP, posMax) &&
                   currentV < min)
            min = currentV;
    }

    return min;
}

void task8() {
    matrix m = fCons_inputMatrix();

    long long result = getMinInArea(m);

    printf("%lld", result);

    freeMemMatrix(m);
}
