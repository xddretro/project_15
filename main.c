#include <assert.h>
#include <stdio.h>
#include "libs/algorithms/array/array.h"
#include "libs/data_structures/bitset/bitset.h"
#include "libs/data_structures/unordered_array_set/unordered_set.h"
#include "libs/data_structures/ordered_array_set/ordered_set.h"

#include "libs/data_structures/matrix/matrix.h"

void test_is_equal_matrix_1_is_equal() {
    matrix m1 = createMatrixFromArray((int[]){1, 2, 3, 4}, 2, 2);
    matrix m2 = getMemMatrix(2, 2);
    m2.values[0][0] = 1;
    m2.values[0][1] = 2;
    m2.values[1][0] = 3;
    m2.values[1][1] = 4;

    bool res = areTwoMatricesEqual(&m1, &m2);

    assert(res == 1);

    freeMemMatrices(&m1, 1);
    freeMemMatrices(&m2, 1);
}


void test_is_equal_matrix_2_is_not_equal() {
    matrix m1 = createMatrixFromArray((int[]){7, 12, 3, 4},2, 2);
    matrix m2 = getMemMatrix(2, 2);
    m2.values[0][0] = 1;
    m2.values[0][1] = 2;
    m2.values[1][0] = 3;
    m2.values[1][1] = 4;


    bool res = areTwoMatricesEqual(&m1, &m2);

    assert(res == 0);

    freeMemMatrix(&m1);
    freeMemMatrix(&m2);
}


void test_is_equal_matrix() {
    test_is_equal_matrix_1_is_equal();
    test_is_equal_matrix_2_is_not_equal();
}




void test_swap_rows_1_different_lines() {
    matrix m1 = createMatrixFromArray((int[]){1, 2, 3, 4}, 2, 2);
    matrix m2 = createMatrixFromArray((int[]){3, 4, 1, 2}, 2, 2);

    swapRows(&m1, 0, 1);

    assert(areTwoMatricesEqual(&m1, &m2));

    freeMemMatrix(&m1);
    freeMemMatrix(&m2);
}


void test_swap_rows_2_herself_to_herself() {
    matrix m1 = createMatrixFromArray((int[]){1, 2, 3, 4}, 2, 2);
    matrix m2 = createMatrixFromArray((int[]){1, 2, 3, 4}, 2, 2);

    swapRows(&m1, 1, 1);

    assert(areTwoMatricesEqual(&m1, &m2));

    freeMemMatrix(&m1);
    freeMemMatrix(&m2);
}


void test_swap_columns_1_different_columns() {
    matrix m1 = createMatrixFromArray((int[]){1, 2, 3,
                                              4, 5, 6}, 2, 3);
    matrix m2 = createMatrixFromArray((int[]){1, 3, 2,
                                              4, 6, 5}, 2, 3);

    swapColumns(&m1, 1, 2);

    assert(areTwoMatricesEqual(&m1, &m2));

    freeMemMatrix(&m1);
    freeMemMatrix(&m2);
}


void test_swap_columns_2_herself_to_herself() {
    matrix m1 = createMatrixFromArray((int[]){1, 2, 3,
                                              4, 5, 6}, 2, 3);
    matrix m2 = createMatrixFromArray((int[]){1, 2, 3,
                                              4, 5, 6}, 2, 3);

    swapColumns(&m1, 1, 1);

    assert(areTwoMatricesEqual(&m1, &m2));

    freeMemMatrix(&m1);
    freeMemMatrix(&m2);
}


void test_swap() {
    test_swap_rows_1_different_lines();
    test_swap_rows_2_herself_to_herself();
    test_swap_columns_1_different_columns();
    test_swap_columns_2_herself_to_herself();
}




// возвращает сумму элементов массива a размера n
int get_sum(int a[], int n) {
    int res = 0;
    for (size_t i = 0; i < n; i++)
        res += a[i];
    return res;
}


void test_sort_insertion_sort_rows_1_different_values() {
    matrix m1 = createMatrixFromArray((int[]){3, 12, 2,
                                              4, 5, 6,
                                              14, 8, 1}
            , 3, 3);

    matrix m2 = createMatrixFromArray((int[]) {4, 5, 6,
                                               3, 12, 2,
                                               14, 8, 1}
            , 3, 3);

    insertionSortRowsMatrixByRowCriteria(&m1, get_sum);

    assert(areTwoMatricesEqual(&m1, &m2));

    freeMemMatrix(&m1);
    freeMemMatrix(&m2);
}


void test_sort_insertion_sort_rows_2_equal_values() {
    matrix m1 = createMatrixFromArray((int[]){1, 2, 3,
                                              1, 5, 0,
                                              1, 4, 1}
            , 3, 3);

    matrix m2 = createMatrixFromArray((int[]) {1, 2, 3,
                                               1, 5, 0,
                                               1, 4, 1}
            , 3, 3);

    insertionSortRowsMatrixByRowCriteria(&m1, get_sum);

    assert(areTwoMatricesEqual(&m1, &m2));

    freeMemMatrix(&m1);
    freeMemMatrix(&m2);
}


void test_sort_selection_sort_cols_1_different_values() {
    matrix m1 = createMatrixFromArray((int[]){3, 12, 2, // 21 25 9
                                              4, 5, 6,
                                              14, 8, 1}
            , 3, 3);

    matrix m2 = createMatrixFromArray((int[]) {2, 3, 12,
                                               6, 4, 5,
                                               1, 14, 8}
            , 3, 3);

    selectionSortColsMatrixByColCriteria(&m1, get_sum);

    assert(areTwoMatricesEqual(&m1, &m2));

    freeMemMatrix(&m1);
    freeMemMatrix(&m2);
}


void test_sort_selection_sort_cols_2_equal_values() {
    matrix m1 = createMatrixFromArray((int[]){3, 1, 9, // 21 25 9
                                              4, 3, 0,
                                              2, 5, 0}
            , 3, 3);

    matrix m2 = createMatrixFromArray((int[]) {3, 1, 9,
                                               4, 3, 0,
                                               2, 5, 0}
            , 3, 3);

    selectionSortColsMatrixByColCriteria(&m1, get_sum);

    assert(areTwoMatricesEqual(&m1, &m2));

    freeMemMatrix(&m1);
    freeMemMatrix(&m2);
}


void test_sort() {
    test_sort_insertion_sort_rows_1_different_values();
    test_sort_insertion_sort_rows_2_equal_values();
    test_sort_selection_sort_cols_1_different_values();
    test_sort_selection_sort_cols_2_equal_values();
}




void test_square_matrix_1_is_square() {
    matrix m = createMatrixFromArray((int[]) {1, 2,
                                              3, 4}
            , 2, 2);

    assert(isSquareMatrix(&m));

    freeMemMatrix(&m);
}


void test_square_matrix_2_is_not_square() {
    matrix m = createMatrixFromArray((int[]) {1, 2, 3,
                                              4, 5, 6}
            , 2, 3);

    assert(!isSquareMatrix(&m));

    freeMemMatrix(&m);
}


void test_square_matrix() {
    test_square_matrix_1_is_square();
    test_square_matrix_2_is_not_square();
}




void test_e_matrix_1_is_e_matrix() {
    matrix e = createMatrixFromArray((int[]){1, 0, 0,
                                             0, 1, 0,
                                             0, 0, 1}
            , 3, 3);

    assert(isEMatrix(&e));

    freeMemMatrix(&e);
}


void test_e_matrix_2_is_not_e_matrix() {
    matrix e = createMatrixFromArray((int[]){1, 2, 0,
                                             0, 1, 0,
                                             3, 0, 1}
            , 3, 3);

    assert(!isEMatrix(&e));

    freeMemMatrix(&e);
}


void test_e_matrix() {
    test_e_matrix_1_is_e_matrix();
    test_e_matrix_2_is_not_e_matrix();
}




void test_symmetric_matrix_1_is_symmetric() {
    matrix s = createMatrixFromArray((int[]) {1, 2, 3,
                                              2, 1, 5,
                                              3, 5, 1}
            , 3, 3);
    assert(isSymmetricMatrix(&s));

    freeMemMatrix(&s);
}


void test_symmetric_matrix_2_is_not_symmetric() {
    matrix s = createMatrixFromArray((int[]) {1, 2, 3,
                                              4, 5, 6,
                                              7, 8, 9}
            , 3, 3);
    assert(!isSymmetricMatrix(&s));

    freeMemMatrix(&s);
}


void test_symmetric_matrix() {
    test_symmetric_matrix_1_is_symmetric();
    test_symmetric_matrix_2_is_not_symmetric();
}




void test_transpose_matrix_1_transpose_square_matrix() {
    matrix m = createMatrixFromArray((int[]) {1, 2, 3,
                                              4, 5, 6,
                                              7, 8, 9},
                                     3, 3);

    matrix check = createMatrixFromArray((int[]) {1, 4, 7,
                                                  2, 5, 8,
                                                  3, 6, 9},
                                         3, 3);

    transposeSquareMatrix(&m);

    assert(areTwoMatricesEqual(&m, &check));

    freeMemMatrix(&m);
    freeMemMatrix(&check);
}


void test_transpose_matrix_2_transpose_symmetric_matrix() {
    matrix m = createMatrixFromArray((int[]) {1, 2, 3,
                                              2, 4, 5,
                                              3, 5, 6},
                                     3, 3);

    matrix check = createMatrixFromArray((int[]) {1, 2, 3,
                                                  2, 4, 5,
                                                  3, 5, 6},
                                         3, 3);

    transposeSquareMatrix(&m);

    assert(areTwoMatricesEqual(&m, &check));

    freeMemMatrix(&m);
    freeMemMatrix(&check);
}


void test_transpose_matrix_3_transpose_uni_matrix() {
    matrix m = createMatrixFromArray((int[]) {1},1, 1);
    matrix check = createMatrixFromArray((int[]) {1},1, 1);

    transposeSquareMatrix(&m);

    assert(areTwoMatricesEqual(&m, &check));

    freeMemMatrix(&m);
    freeMemMatrix(&check);
}


void test_transpose_matrix_1_transpose_matrix() {
    matrix m = createMatrixFromArray((int[]) {1, 2, 3,
                                              2, 4, 5},
                                     2, 3);

    matrix check = createMatrixFromArray((int[]) {1, 2,
                                                  2, 4,
                                                  3, 5},
                                         3, 2);

    transposeMatrix(&m);

    assert(areTwoMatricesEqual(&m, &check));

    freeMemMatrix(&m);
    freeMemMatrix(&check);
}


void test_transpose_matrix_2_transpose_uni_matrix() {
    matrix m = createMatrixFromArray((int[]) {7}, 1, 1);

    matrix check = createMatrixFromArray((int[]) {7}, 1, 1);

    transposeMatrix(&m);

    assert(areTwoMatricesEqual(&m, &check));

    freeMemMatrix(&m);
    freeMemMatrix(&check);
}


void test_transpose_matrix() {
    test_transpose_matrix_1_transpose_square_matrix();
    test_transpose_matrix_2_transpose_symmetric_matrix();
    test_transpose_matrix_3_transpose_uni_matrix();
    test_transpose_matrix_1_transpose_matrix();
    test_transpose_matrix_2_transpose_uni_matrix();
}




void test_get_value_1_get_min_value() {
    matrix m = createMatrixFromArray((int[]) {2, 1, 9, 0}, 2, 2);
    position res = getMinValuePos(m);

    assert(res.row_index == 1 && res.col_index == 1);

    freeMemMatrix(&m);
}


void test_get_value_2_equal_value() {
    matrix m = createMatrixFromArray((int[]) {1, 1, 1, 1}, 2, 2);
    position res = getMinValuePos(m);

    assert(res.row_index == 0 && res.col_index == 0);

    freeMemMatrix(&m);
}


void test_get_value_3_get_max_value() {
    matrix m = createMatrixFromArray((int[]) {2, 1, 9, 0}, 2, 2);
    position res = getMaxValuePos(m);

    assert(res.row_index == 1 && res.col_index == 0);

    freeMemMatrix(&m);
}


void test_get_value_4_equal_value() {
    matrix m = createMatrixFromArray((int[]) {7, 7, 7, 7}, 2, 2);
    position res = getMinValuePos(m);

    assert(res.row_index == 0 && res.col_index == 0);

    freeMemMatrix(&m);
}


void test_get_value() {
    test_get_value_1_get_min_value();
    test_get_value_2_equal_value();
    test_get_value_3_get_max_value();
    test_get_value_4_equal_value();
}




void test() {
    test_is_equal_matrix();
    test_swap();
    test_sort();
    test_square_matrix();
    test_e_matrix();
    test_symmetric_matrix();
    test_transpose_matrix();
    test_get_value();
}


int main() {
    int amount_blocks;
    scanf("%d", &amount_blocks);

    unordered_array_set set = unordered_array_set_create(1000);
    for (int j = 0; j < 1000; j++){
        set.data[j] = 0;
        set.size++;
    }
    for (int i_block; i_block < amount_blocks; i_block++){
        int block;
        scanf("%d", &block);

        set.data[block - 1]++;
    }

    int max_height = 0;
    int amount_towers = 0;
    for (int i = 0; i < 1000; i++){
        if (set.data[i] > max_height)
            max_height = set.data[i];

        if (set.data[i] > 0)
            amount_towers++;
    }

    printf("%d %d", max_height, amount_towers);
return 0;
}
