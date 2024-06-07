#include <assert.h>
#include <stdio.h>
#include "libs/algorithms/array/array.h"
#include "libs/data_structures/matrix/matrix.h"
#include "libs/algorithms/algorithm.h"

void test_getScalarProduct(){
    assert(getScalarProduct((int []){1, 2, 3}, (int []){1, 1, 1}, 3) == 6);
}

void test_getVectorLength(){
    assert(getVectorLength((int []){3, 0, 4}, 3) == 5);
}

void test_getCosine(){
    assert(getCosine((int []){2, 2, 3}, (int []){1, 1, 1}, 3) - 0.98 < 0.001);
}

void test_getVectorIndexWithMaxAngle_oneVector(){
    matrix m = createMatrixFromArray(
            (int[]) {
                    4,0,4
            },
            1, 3
    );

    assert(getVectorIndexWithMaxAngle(m,(int[]){1,1,1}) == 0);

    freeMemMatrix(&m);
}

void test_getVectorIndexWithMaxAngle_equalCoords(){
    matrix m = createMatrixFromArray(
            (int[]) {
                    4,0,4,
                    4,0,4,
                    4,0,4
            },
            3, 3
    );

    assert(getVectorIndexWithMaxAngle(m,(int[]){1,1,1}) == 0);

    freeMemMatrix(&m);
}

void test_getVectorIndexWithMaxAngle_diffCoords(){
    matrix m = createMatrixFromArray(
            (int[]) {
                    3,0,4,
                    4,0,4,
                    10,0,6
            },
            3, 3
    );

    assert(getVectorIndexWithMaxAngle(m,(int[]){1,1,1}) == 2);

    freeMemMatrix(&m);
}

void test_getVectorIndexWithMaxAngle(){
    test_getScalarProduct();
    test_getVectorLength();
    test_getCosine();
    test_getVectorIndexWithMaxAngle_oneVector();
    test_getVectorIndexWithMaxAngle_equalCoords();
    test_getVectorIndexWithMaxAngle_diffCoords();
}

int main(){
    test_getVectorIndexWithMaxAngle();

    return 0;
}