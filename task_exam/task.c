#include <stdio.h>
#include <math.h>
# include <assert.h>
#include "../libs/data_structures/matrix/matrix.h"

# define COS_OUT_OF_RANGE 2

double getScalarProduct(int *a, int *b, int n){
    double scalar_product = 0;

    for (int i = 0; i < n; i++)
        scalar_product += a[i] * b[i];

    return scalar_product;
}

double getVectorLength(int *a, int n){
    double vector_length = 0;

    for (int i = 0; i < n; i++)
        vector_length += a[i] * a[i];

    return sqrt(vector_length);
}

double getCosine(int *a, int *b, int n){
    double length_product = (getVectorLength(a, n) * getVectorLength(b, n));

    assert(length_product != 0);

    return getScalarProduct(a, b, n) / length_product;
}

double absDouble(double a){
    return a < 0 ? -a : a;
}

int getVectorIndexWithMaxAngle(matrix m, int *b) {
    int index_of_vector_max_angle;
    double min_cos = COS_OUT_OF_RANGE;

    for (int i = 0; i < m.n_rows; i++) {
        double abs_cos = absDouble(getCosine(m.values[i], b, m.n_cols));
        if (abs_cos < min_cos) {
            index_of_vector_max_angle = i;
            min_cos = abs_cos;
        }
    }

    return index_of_vector_max_angle;
}