#ifndef UNTITLED3_STRING_H
#define UNTITLED3_STRING_H

# include <assert.h>
# include <ctype.h>
# include <memory.h>a
# include <stdio.h>
#include <stdlib.h>

//нахождение длины строки
int findLength(const char *str);

//количество символов в строке
size_t strlen_(const char *begin);

//возвращает указатель на первый элемент с кодом ch, расположенным на ленте памяти между
//адресами begin и end не включая end. Если символ не найден, возвращается значение end.
char* find(char *begin, char *end, int ch);

//возвращает указатель на первый
//символ, отличный от пробельных, расположенный на ленте памяти, начиная с begin и заканчивая ноль-символом.
// Если символ не найден, возвращается адрес первого ноль-символа
char* findNonSpace(char *begin);

//возвращает указатель на первый пробельный
//символ, расположенный на ленте памяти, начиная с begin и заканчивая ноль-символом.
// Если символ не найден, возвращается адрес первого ноль-символа
char* findSpace(char *begin);

//возвращает указатель на первый справа символ, отличный от пробельных,
//расположенный на ленте памяти, начиная с rbegin (последний символ
//строки, за которым следует ноль-символ) и заканчивая rend (адрес символа перед началом строки). Если символ не найден, возвращается адрес rend.
char* findNonSpaceReverse(char *rbegin, const char *rend);

//возвращает указатель на первый пробельный символ справа, расположенный на ленте памяти, начиная с rbegin и заканчивая rend. Если символ не найден,
//возвращается адрес rend.
char* findSpaceReverse(char *rbegin, const char *rend);

//сравнение строк, если строки раны - возвращает 0, или если lhs распологается до rhs - отрицательное значение, иначе положительное значение
int strcmp_(const char *lhs, const char *rhs);

//записывает по адресу beginDestination фрагмент памяти, начиная с адреса beginSource до endSource.
//Возвращает указатель на следующий свободный фрагмент памяти в destination
char* copy(const char *beginSource, const char *endSource, char *beginDestination);

//записывает по адресу beginDestination элементы из фрагмента памяти начиная с beginSource заканчивая endSource, удовлетворяющие функции-предикату f.
//Функция возвращает указатель на следующий свободный для записи фрагмент в памяти
char* copyIf(char *beginSource, const char *endSource, char *beginDestination, int (*f)(int));

//записывает по адресу beginDestination элементы из фрагмента памяти начиная с rbeginSource заканчивая rendSource,
//удовлетворяющие функции-предикату f. Функция возвращает значение beginDestination по окончанию работы функции.
char* copyIfReverse(char *rbeginSource, const char *rendSource, char *beginDestination, int (*f)(int));

//хранит позиции начала и конца слова
typedef struct WordDescriptor {
    char *begin; // позиция начала слова
    char *end; // позиция первого символа, после последнего символа
} WordDescriptor;

//считывание слова с начала строки
int getWord(char *beginSearch, WordDescriptor *word);

//считывание слова с конца строки
bool getWordReverse(char *rbegin, char *rend, WordDescriptor *word);

//структура, которая хранит начало
//и конец каждого слова исходной строки
typedef struct BagOfWords {
    WordDescriptor words[MAX_N_WORDS_IN_STRING];
    size_t size;
} BagOfWords;

bool getWordWithoutSpace(char* begin_search, WordDescriptor * word);

void getBagOfWords(BagOfWords *bag, char *s);

void freeBagOfWords(BagOfWords * bag);

typedef enum WordBeforeFirstWordWithAReturnCode {
    FIRST_WORD_WITH_A,
    NOT_FOUND_A_WORD_WITH_A,
    WORD_FOUND,
    EMPTY_STRING
} WordBeforeFirstWordWithAReturnCode;

//тестирует функции, написанные выше
void test();

#endif //UNTITLED3_STRING_H