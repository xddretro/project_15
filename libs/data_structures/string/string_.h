#ifndef UNTITLED3_STRING__H
#define UNTITLED3_STRING__H

#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>
#include <ctype.h>

#define ASSERT_STRING(expected, got) assert_string(expected, got, __FILE__, __FUNCTION__, __LINE__)

#define MAX_STRING_SIZE 100
#define MAX_N_WORDS_IN_STRING 100
#define MAX_WORD_SIZE 20

//хранит позиции начала и конца слова
typedef struct WordDescriptor {
    char* begin; // позиция начала слова
    char* end; // позиция первого символа, после последнего символа
} WordDescriptor;

//структура, которая хранит начало
//и конец каждого слова исходной строки
typedef struct BagOfWords {
    WordDescriptor words[MAX_N_WORDS_IN_STRING];
    size_t size;
} BagOfWords;

extern BagOfWords _bag;
extern BagOfWords _bag2;

extern char _string_buffer[MAX_STRING_SIZE + 1];

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
//строки, за которым следует ноль-символ) и заканчивая rend (адрес символа перед началом строки).
//Если символ не найден, возвращается адрес rend.
char* findNonSpaceReverse(char *rbegin, const char *rend);

//сравнение строк, если строки раны - возвращает 0,
//или если lhs распологается до rhs - отрицательное значение, иначе положительное значение
int strcmp(const char *lhs, const char *rhs);

//записывает по адресу beginDestination фрагмент памяти, начиная с адреса beginSource до endSource.
//Возвращает указатель на следующий свободный фрагмент памяти в destination
char* copy(const char *beginSource, const char *endSource, char *beginDestination);

//записывает по адресу beginDestination элементы из фрагмента памяти начиная с beginSource заканчивая endSource, удовлетворяющие функции-предикату f.
//Функция возвращает указатель на следующий свободный для записи фрагмент в памяти
char* copyIf(char *beginSource, const char *endSource, char *beginDestination, int (*f)(int));

//записывает по адресу beginDestination элементы из фрагмента памяти начиная с rbeginSource заканчивая rendSource,
//удовлетворяющие функции-предикату f. Функция возвращает значение beginDestination по окончанию работы функции.
char* copyIfReverse(char *rbeginSource, const char *rendSource, char *beginDestination, int (*f)(int));

char* getEndOfString(char* s);

void assert_string(const char* expected, char* got,
                   char const* file_name, char const* func_name,
                   int line);

//считывание слова с начала строки
int getWord(char *beginSearch, WordDescriptor *word);

void freeString(char* string);

void free_bag(BagOfWords* bag);

bool isPalindromeWord(WordDescriptor * word);

bool getWordReverse(char* r_begin, char* r_end, WordDescriptor * word);

bool getWordWithoutSpace(char* begin_search, WordDescriptor * word);

void wordDescriptorToString(WordDescriptor word, char* dest);

bool isWordEqual(const WordDescriptor word1, const WordDescriptor word2);

bool get_word_without_space(char* begin_search, WordDescriptor * word);

#endif