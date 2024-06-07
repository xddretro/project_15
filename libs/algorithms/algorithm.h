#ifndef UNTITLED1_ALGORITHM_H
#define UNTITLED1_ALGORITHM_H

#include "../data_structures/matrix/matrix.h"

//Дана квадратная матрица, все элементы которой различны. Поменять местами
//строки, в которых находятся максимальный и минимальный элементы.
//1
void swapMinMaxRows(matrix* m);

//возвращает максимальный элемент в матрице
int getMax(const int a[], const int n);

// сортирует строки матрицы m по не убыванию наибольших элементов строк
void sortRowsByMaxElement(matrix* m);

//возвращает минимальный элемент в матрице
int getMin( const int a[],const int n);

// возвращает минимальный элемент массива a размера
void sortColsByMinElement(matrix* m);

// возвращает матрицу, равную перемножению матрицы m1 на матрицу m2
matrix mulMatrices(matrix m1, matrix m2);

// заменяет исходную матрицу m, если она является симметричной, на её квадрат
void getSquareOfMatrixIfSymmetric(matrix* m);

// возвращает true, если массив a размера n состоит только из уникальных элементов
// иначе false
bool isUnique(long long int a[], int n);

// возвращает сумму элементов массива a размера n
long long int getSum(int a[], int n);

// транспонирует матрицу, если суммы строк различны
void transposeIfMatrixHasNotEqualSumOfRows(matrix* m);

// возвращает true, если матрицы m1 и m2 являются взаимно обратными
//иначе false
bool isMutuallyInverseMatrices(matrix m1, matrix m2);

// возвращает максимальный элемент между a и b
int max(int a, int b);

// возвращает сумму максимальных элементов псевдодиагоналей матрицы m
// только если элементы матрицы положительны, иначе 0
long long int findSumOfMaxesOfPseudoDiagonal(matrix m);

// возвращает true, если элемент по индексу i,j находится в области элемента max
bool valuInArea(position max, int i, int j);

// возвращает минимальный элемент матрицы m, который находится в зоне
int getMinInArea(matrix m);

// возвращает расстояние вектора a размера n, до начала координат
float getDistance(int a[], int n);

// сортирует строки матрицы m по не убыванию, основываясь на критерии criteria
void insertionSortRowsMatrixByRowCriteriaF(matrix* m, float (*criteria)(int*, int));

// сортирует строки матрицы m, относительно их удалённости от начала координат
void sortByDistance(matrix* m);

// возвращает количество уникальных элементов массива a размера n
int countNUnique(long long int a[], int n);

// возвращает количество уникальных сумм строк матрицы m
int countEqClassesByRowsSum(matrix m);

// возвращает количество "особых" элементов матрицы m
// элемент считается особенным, если он больше суммы остальных элементов своего столбца
int getNSpecialElement(matrix m);

// возвращает position минимального левого элемента
position getLeftMin(matrix m);

// меняет местами предпоследнюю строку матрицы m, на n столбец
void swapPenultimateRow(matrix* m, int n);

// возвращает true, если массив a размера n отсортирован по не убыванию
// иначе false
bool isNonDescendingSorted(const int a[], int n);


// возвращает true, если все строки матрицы m отсортированы по не убыванию
// иначе false
bool hasAllNonDescendingRows(matrix m);


// возвращает количество матриц, из массива матриц ms размера n_matrix,
// строки в которых упорядочены по не убыванию
int countNonDescendingRowsMatrices(matrix ms[], int n_matrix);

// возвращает количество элементов value в массиве a размера n
int countValues(const int a[], int n, int value);

// возвращает количество нулевых строк в матрицы m
int countZero_rows(matrix m);

// выводит матрицы, из массива матриц ms размера n_matrix,
// с максимальным числом нулевых строк
void printMatrixWithMaxZeroRows(matrix ms[], int n_matrix);

// возвращает максимальное абсолютное значение в массиве a размера n
int getMaxAbsValue(const int a[], int n);


// возвращает максимальное абсолютное значение в матрице m
int getMaxAbsValueInMatrix(matrix m);


// выводит матрицы, из массива матриц ms размера n_matrix,
// с минимальной нормой
// за норму берут максимум из абсолютных величин матрицы
void printMatrixWithMinStandard(matrix ms[], int n_matrix);

// возвращает true, если элемент по индексу index в массиве a размера n является особенным
// элемент особенный, если в строке слева от него находятся только меньшие элементы,
// иначе false
bool isSpeciaElement(int a[], int n, int index);


// возвращает количество "особых" элементов матрицы m
// элемент считается особенным, если в строке слева от него находятся только меньшие элементы,
// а справа большие

// возвращает скалярное произведение массива a размера n на массив b размера n
double getScalarProduct(int a[], int b[], int n);


// возвращает длину вектора a размера n
double getVectorLength(int a[], int n);

// возвращает косинус между вектором a размера n и вектором b размера n
double getCosine(int a[], int b[], int n);

// возвращает индекс строки матрицы m, которая образует максимальный угол с данным вектором b
int getVectorIndexWithMaxAngle(matrix m, int* b);

#endif //UNTITLED1_ALGORITHM_H
