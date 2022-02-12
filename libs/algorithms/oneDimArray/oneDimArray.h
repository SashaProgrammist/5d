#ifndef ONE_DIM_ARRAY
#define ONE_DIM_ARRAY

#include <stddef.h>
#include <stdbool.h>
#include "../heapFunctions/heapFunctions.h"

/// <summary>
/// производит ввод массива array размера length
/// </summary>
/// <param name="array"></param>
/// <param name="length"></param>
void inputArray(int *array, size_t length);

void setInputArray(int **array, size_t length);

/// <summary>
/// производит вывод в консоль массива array размера length
/// </summary>
/// <param name="array"></param>
/// <param name="length"></param>
void printArray(int *array, size_t length);

/// <param name="array"></param>
/// <param name="length"></param>
/// <param name="condition">логическое вырожение</param>
/// <returns>
/// индикс первого элемента 
/// из массива array размера length
/// удовлетворяющего функции condition
/// </returns>
int getIndexOfElementFirstSatisfiesCondition(int array[], size_t length, int condition(int));

/// <param name="array"></param>
/// <param name="length"></param>
/// <param name="condition">логическое вырожение</param>
/// <returns>
/// индикс последнего элемента 
/// из массива array размера length
/// удовлетворяющего функции condition
/// </returns>
int getIndexOfElementLastSatisfiesCondition(int array[], size_t length, int condition(int));

/// <param name="array"></param>
/// <param name="length"></param>
/// <param name="condition">логическое вырожение</param>
/// <returns>
/// количество элиментов 
/// из массива array размера length
/// удовлетворяющие функции condition
/// </returns>
int getCountElementsSatisfiesCondition(int array[], size_t length, int condition(int));

/// <summary>
/// производит перестоновку элементов
/// из массива array размера length
/// в обратном порядке
/// </summary>
/// <param name="array"></param>
/// <param name="length"></param>
void invertArray(int array[], size_t length);

/// <param name="array"></param>
/// <param name="length"></param>
/// <returns>
/// являетс яли массив array размера length полендромом
/// </returns>
int isArrayPolendrom(int array[], size_t length);

/// <summary>
/// удоляет элименты
/// из массива array размера length
/// индекс которых 
/// удовлетворяющие функции condition
/// </summary>
/// <param name="array"></param>
/// <param name="length"></param>
/// <param name="condition">логическая функция</param>
void removeElementsWithSatisfyingConditionIndex(int array[], size_t *length, int condition(int));

/// <summary>
/// производит сортировку по не убыванию
/// массива array размера length
/// </summary>
/// <param name="array"></param>
/// <param name="length"></param>
void sort(int array[], size_t length);

/// <summary>
/// удоляет элименты
/// из массива array размера length
/// удовлетворяющие функции condition
/// </summary>
/// <param name="array"></param>
/// <param name="length"></param>
/// <param name="condition">логическая функция</param>
void removeElementsSatisfyingCondition(int array[], size_t *length, int condition(int));

/// <summary>
/// встовляет element 
/// в массив array размера length
/// с идексом index
/// с сохранением относительного порядка
/// остальных элиментов массива
/// </summary>
/// <param name="array"></param>
/// <param name="length"></param>
/// <param name="element"></param>
/// <param name="index"></param>
void insertElementIntoArray(int array[], size_t *length, int element, size_t index);

/// <summary>
/// добавляет element в конец
/// массива array размера length
/// </summary>
/// <param name="array"></param>
/// <param name="length"></param>
/// <param name="element"></param>
void append(int array[], size_t *length, int element);

/// <summary>
/// добавляет element в конец
/// массива array размера length
/// </summary>
/// <param name="array"></param>
/// <param name="length"></param>
/// <param name="element"></param>
/// <returns>
/// '0'  когда  получилось выделить  память,
/// '-1' когда неполучилась выделить память
/// </returns>
int appendMalloc(int **array, size_t *length, int element);

/// <summary>
/// удаляет элимент
/// по индексу index
/// из массива array размера length
/// с сохранением относительного порядка 
/// </summary>
/// <param name="array"></param>
/// <param name="length"></param>
/// <param name="index"></param>
/// <returns>
/// элимент стоявший по индексу index
/// </returns>
int pop(int array[], size_t *length, size_t index);

/// <summary> 
/// удаляет элимент
/// по индексу index
/// из массива array размера length
/// не сохраняя относительный порядок 
/// </summary>
/// <param name="array"></param>
/// <param name="length"></param>
/// <param name="index"></param>
/// <returns>
/// элимент стоявший по индексу index
/// </returns>
int removeElementWithoutPreservingOrder(int array[], size_t *length, size_t index);

/// <summary>
/// применяет к элиментам
/// из массива array размера length
/// функцию function
/// </summary>
/// <param name="Array"></param>
/// <param name="length"></param>
/// <param name="function"></param>
void forEach(int Array[], size_t length, int function(int));

int getAbsoluteMin(int array[], size_t length);

/// <param name="array"></param>
/// <param name="length"></param>
/// <returns>
/// копию массива array размера length
/// </returns>
int *copy(int array[], size_t length);

size_t getIndexAbsoluteMin(int array[], size_t length);

/// <param name="array"></param>
/// <param name="length"></param>
/// <returns>
/// индкс первого минимума
/// из массива array размера length
/// </returns>
size_t getFirstIndexMin(int array[], size_t length);

/// <param name="array"></param>
/// <param name="length"></param>
/// <returns>
/// индкс последнего минимума
/// из массива array размера length
/// </returns>
size_t getLastIndexMin(int array[], size_t length);

int getMin(int *array, int size);

/// <param name="array"></param>
/// <param name="length"></param>
/// <returns>
/// индкс первого максимума
/// из массива array размера length
/// </returns>
size_t getFirstIndexMax(int array[], size_t length);

/// <param name="array"></param>
/// <param name="length"></param>
/// <returns>
/// индкс последнего максимума
/// из массива array размера length
/// </returns>
size_t getLastIndexMax(int array[], size_t length);

int getMax(int *array, int size);

/// <param name="array"></param>
/// <param name="length"></param>
/// <returns>
/// состоит ли массив array размера length
/// из уникальных элиментов 
/// </returns>
int isUniqueArray(int array[], size_t length);

/// <param name="array"></param>
/// <param name="length"></param>
/// <param name="element"></param>
/// <returns>
/// индекс element в массиве array длины length
/// если он присутствует в array,
/// иначе -1
/// </returns>
int linearSearchElement(int array[], size_t length, int element);

/// <param name="array"></param>
/// <param name="length"></param>
/// <param name="Condition">логическое выражение</param>
/// <returns>
/// индекс такого элемента что
/// вызвав Condition с любым
/// элементом  следующий за ним
/// то Condition вернёт 'истину'
/// из массива array размера length
/// </returns>
size_t getIndexBestInCondition(int array[], size_t length, int Condition(int, int));

/// <param name="array"></param>
/// <param name="length"></param>
/// <returns>
/// является ли последовательность
/// из массива array размера length
/// упорядочиной по неубыванию или по невозрастанию
/// </returns>
int isOrderedSequence(int array[], size_t length);

/// <param name="array"></param>
/// <param name="length"></param>
/// <returns>
/// является ли последовательность
/// из массива array размера length
/// упорядочиной по неубыванию
/// </returns>
int isNotDecreasingOrdering(int array[], size_t length);

/// <param name="array"></param>
/// <param name="length"></param>
/// <returns>
/// является ли последовательность
/// из массива array размера length
/// упорядочиной по невозрастанию
/// </returns>
int isNotAscendingOrdering(int array[], size_t length);

/// <param name="array"></param>
/// <param name="length"></param>
/// <param name="element"></param>
/// <param name="isFirst">
/// если 'истина' поиск с начала массива,
/// иначе поиск с конца массива
/// </param>
/// <returns>
/// индекс element из массива array размера length
/// если он есть иначе '-1'
/// </returns>
int getIndexELement(int array[], size_t length, int element, int isFirst);

/// <param name="array">отсортированный массив!!!!</param>
/// <param name="length"></param>
/// <param name="condition">логическое выражение</param>
/// <param name="isFirst">
/// если 'истина' поиск первого,
/// иначе поиск последнего
/// </param>
/// <returns>
/// индекс элемента удовлетворяющего condition
/// из массива array размера length
/// если он есть, иначе '-1'
/// </returns>
int getIndexExtremeInSortArray(int array[], size_t length, int condition(int), int isFirst);

int getIndexFirstInArrayLargerNumber(int *array, size_t length, int number);

/// <param name="array"></param>
/// <param name="length"></param>
/// <returns>
/// все ли элименты
/// из массива array размера length
/// равны между собой
/// </returns>
int isAllElementsEqual(int *array, size_t length);

int *getShiftedLeftArray(int *array, size_t length, size_t shift);

int any(int *array, size_t length, int condition(int));

int all(int *array, size_t length, int condition(int));

int summ(int *array, size_t length);

int binSearchElement(int array[], size_t length, int element);

void setRandomElementsToArray(int *array, size_t length);

void createIntArray(int **array, size_t length);

void createLongLongArray(long long **array, size_t length);

void createArray(void **array, size_t length, size_t sizeElement);

/// <summary>
/// удаляет из масива array состоящего 
/// из элементов длины sizeElement
/// и количества элементав sizeArray
/// элкменты не удовлетворяющие condition
/// </summary>
/// <param name="array">
/// указатель на первый элемент масива
/// </param>
/// <param name="sizeElement">
/// размер в байтах элементов
/// </param>
/// <param name="sizeArray">
/// количество элементов
/// </param>
/// <param name="condition">
/// логическое вырожение
/// </param>
void removeNonSatisfyingConditions(void *array,
                                   size_t sizeElement,
                                   size_t *sizeArray,
                                   bool condition(void *));

void simplifyOrderedArray(void *array,
                          const size_t sizeElement,
                          size_t *sizeArray,
                          bool isEqual (void *, void *));

#endif // !ONE_DIM_ARRAY
