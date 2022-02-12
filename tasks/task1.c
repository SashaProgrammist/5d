#include "..\libs\data_structures\matrix\matrix.h"

void task1(){
    matrix m = fCons_inputSquareMatrix();

    int i_min = getMinValuePos(m).rowIndex;
    int i_max = getMaxValuePos(m).rowIndex;

    swapRows(m, i_min, i_max);

    outputMatrix(m);

    freeMemMatrix(m);
}
