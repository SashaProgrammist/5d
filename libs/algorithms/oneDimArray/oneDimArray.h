#ifndef ONE_DIM_ARRAY
#define ONE_DIM_ARRAY

#include <stddef.h>
#include <stdbool.h>
#include "../heapFunctions/heapFunctions.h"

/// <summary>
/// ���������� ���� ������� array ������� length
/// </summary>
/// <param name="array"></param>
/// <param name="length"></param>
void inputArray(int *array, size_t length);

void setInputArray(int **array, size_t length);

/// <summary>
/// ���������� ����� � ������� ������� array ������� length
/// </summary>
/// <param name="array"></param>
/// <param name="length"></param>
void printArray(int *array, size_t length);

/// <param name="array"></param>
/// <param name="length"></param>
/// <param name="condition">���������� ���������</param>
/// <returns>
/// ������ ������� �������� 
/// �� ������� array ������� length
/// ���������������� ������� condition
/// </returns>
int getIndexOfElementFirstSatisfiesCondition(int array[], size_t length, int condition(int));

/// <param name="array"></param>
/// <param name="length"></param>
/// <param name="condition">���������� ���������</param>
/// <returns>
/// ������ ���������� �������� 
/// �� ������� array ������� length
/// ���������������� ������� condition
/// </returns>
int getIndexOfElementLastSatisfiesCondition(int array[], size_t length, int condition(int));

/// <param name="array"></param>
/// <param name="length"></param>
/// <param name="condition">���������� ���������</param>
/// <returns>
/// ���������� ��������� 
/// �� ������� array ������� length
/// ��������������� ������� condition
/// </returns>
int getCountElementsSatisfiesCondition(int array[], size_t length, int condition(int));

/// <summary>
/// ���������� ������������ ���������
/// �� ������� array ������� length
/// � �������� �������
/// </summary>
/// <param name="array"></param>
/// <param name="length"></param>
void invertArray(int array[], size_t length);

/// <param name="array"></param>
/// <param name="length"></param>
/// <returns>
/// ������� ��� ������ array ������� length �����������
/// </returns>
int isArrayPolendrom(int array[], size_t length);

/// <summary>
/// ������� ��������
/// �� ������� array ������� length
/// ������ ������� 
/// ��������������� ������� condition
/// </summary>
/// <param name="array"></param>
/// <param name="length"></param>
/// <param name="condition">���������� �������</param>
void removeElementsWithSatisfyingConditionIndex(int array[], size_t *length, int condition(int));

/// <summary>
/// ���������� ���������� �� �� ��������
/// ������� array ������� length
/// </summary>
/// <param name="array"></param>
/// <param name="length"></param>
void sort(int array[], size_t length);

/// <summary>
/// ������� ��������
/// �� ������� array ������� length
/// ��������������� ������� condition
/// </summary>
/// <param name="array"></param>
/// <param name="length"></param>
/// <param name="condition">���������� �������</param>
void removeElementsSatisfyingCondition(int array[], size_t *length, int condition(int));

/// <summary>
/// ��������� element 
/// � ������ array ������� length
/// � ������� index
/// � ����������� �������������� �������
/// ��������� ��������� �������
/// </summary>
/// <param name="array"></param>
/// <param name="length"></param>
/// <param name="element"></param>
/// <param name="index"></param>
void insertElementIntoArray(int array[], size_t *length, int element, size_t index);

/// <summary>
/// ��������� element � �����
/// ������� array ������� length
/// </summary>
/// <param name="array"></param>
/// <param name="length"></param>
/// <param name="element"></param>
void append(int array[], size_t *length, int element);

/// <summary>
/// ��������� element � �����
/// ������� array ������� length
/// </summary>
/// <param name="array"></param>
/// <param name="length"></param>
/// <param name="element"></param>
/// <returns>
/// '0'  �����  ���������� ��������  ������,
/// '-1' ����� ������������ �������� ������
/// </returns>
int appendMalloc(int **array, size_t *length, int element);

/// <summary>
/// ������� �������
/// �� ������� index
/// �� ������� array ������� length
/// � ����������� �������������� ������� 
/// </summary>
/// <param name="array"></param>
/// <param name="length"></param>
/// <param name="index"></param>
/// <returns>
/// ������� �������� �� ������� index
/// </returns>
int pop(int array[], size_t *length, size_t index);

/// <summary> 
/// ������� �������
/// �� ������� index
/// �� ������� array ������� length
/// �� �������� ������������� ������� 
/// </summary>
/// <param name="array"></param>
/// <param name="length"></param>
/// <param name="index"></param>
/// <returns>
/// ������� �������� �� ������� index
/// </returns>
int removeElementWithoutPreservingOrder(int array[], size_t *length, size_t index);

/// <summary>
/// ��������� � ���������
/// �� ������� array ������� length
/// ������� function
/// </summary>
/// <param name="Array"></param>
/// <param name="length"></param>
/// <param name="function"></param>
void forEach(int Array[], size_t length, int function(int));

int getAbsoluteMin(int array[], size_t length);

/// <param name="array"></param>
/// <param name="length"></param>
/// <returns>
/// ����� ������� array ������� length
/// </returns>
int *copy(int array[], size_t length);

size_t getIndexAbsoluteMin(int array[], size_t length);

/// <param name="array"></param>
/// <param name="length"></param>
/// <returns>
/// ����� ������� ��������
/// �� ������� array ������� length
/// </returns>
size_t getFirstIndexMin(int array[], size_t length);

/// <param name="array"></param>
/// <param name="length"></param>
/// <returns>
/// ����� ���������� ��������
/// �� ������� array ������� length
/// </returns>
size_t getLastIndexMin(int array[], size_t length);

int getMin(int *array, int size);

/// <param name="array"></param>
/// <param name="length"></param>
/// <returns>
/// ����� ������� ���������
/// �� ������� array ������� length
/// </returns>
size_t getFirstIndexMax(int array[], size_t length);

/// <param name="array"></param>
/// <param name="length"></param>
/// <returns>
/// ����� ���������� ���������
/// �� ������� array ������� length
/// </returns>
size_t getLastIndexMax(int array[], size_t length);

int getMax(int *array, int size);

/// <param name="array"></param>
/// <param name="length"></param>
/// <returns>
/// ������� �� ������ array ������� length
/// �� ���������� ��������� 
/// </returns>
int isUniqueArray(int array[], size_t length);

/// <param name="array"></param>
/// <param name="length"></param>
/// <param name="element"></param>
/// <returns>
/// ������ element � ������� array ����� length
/// ���� �� ������������ � array,
/// ����� -1
/// </returns>
int linearSearchElement(int array[], size_t length, int element);

/// <param name="array"></param>
/// <param name="length"></param>
/// <param name="Condition">���������� ���������</param>
/// <returns>
/// ������ ������ �������� ���
/// ������ Condition � �����
/// ���������  ��������� �� ���
/// �� Condition ����� '������'
/// �� ������� array ������� length
/// </returns>
size_t getIndexBestInCondition(int array[], size_t length, int Condition(int, int));

/// <param name="array"></param>
/// <param name="length"></param>
/// <returns>
/// �������� �� ������������������
/// �� ������� array ������� length
/// ������������ �� ���������� ��� �� �������������
/// </returns>
int isOrderedSequence(int array[], size_t length);

/// <param name="array"></param>
/// <param name="length"></param>
/// <returns>
/// �������� �� ������������������
/// �� ������� array ������� length
/// ������������ �� ����������
/// </returns>
int isNotDecreasingOrdering(int array[], size_t length);

/// <param name="array"></param>
/// <param name="length"></param>
/// <returns>
/// �������� �� ������������������
/// �� ������� array ������� length
/// ������������ �� �������������
/// </returns>
int isNotAscendingOrdering(int array[], size_t length);

/// <param name="array"></param>
/// <param name="length"></param>
/// <param name="element"></param>
/// <param name="isFirst">
/// ���� '������' ����� � ������ �������,
/// ����� ����� � ����� �������
/// </param>
/// <returns>
/// ������ element �� ������� array ������� length
/// ���� �� ���� ����� '-1'
/// </returns>
int getIndexELement(int array[], size_t length, int element, int isFirst);

/// <param name="array">��������������� ������!!!!</param>
/// <param name="length"></param>
/// <param name="condition">���������� ���������</param>
/// <param name="isFirst">
/// ���� '������' ����� �������,
/// ����� ����� ����������
/// </param>
/// <returns>
/// ������ �������� ���������������� condition
/// �� ������� array ������� length
/// ���� �� ����, ����� '-1'
/// </returns>
int getIndexExtremeInSortArray(int array[], size_t length, int condition(int), int isFirst);

int getIndexFirstInArrayLargerNumber(int *array, size_t length, int number);

/// <param name="array"></param>
/// <param name="length"></param>
/// <returns>
/// ��� �� ��������
/// �� ������� array ������� length
/// ����� ����� �����
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
/// ������� �� ������ array ���������� 
/// �� ��������� ����� sizeElement
/// � ���������� ��������� sizeArray
/// �������� �� ��������������� condition
/// </summary>
/// <param name="array">
/// ��������� �� ������ ������� ������
/// </param>
/// <param name="sizeElement">
/// ������ � ������ ���������
/// </param>
/// <param name="sizeArray">
/// ���������� ���������
/// </param>
/// <param name="condition">
/// ���������� ���������
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
