#include <stdio.h>
#include <stdbool.h>
#include <malloc.h>
#include <stdlib.h>

#include "oneDimArray.h"

void inputArray(int *array, size_t length) {
	for (size_t i = 0; i < length; i++)
		scanf("%d", array + i);
}

void setInputArray(int **array, size_t length) {
	createIntArray(array, length);

	inputArray(*array, length);
}

void createIntArray(int **array, size_t length) {
	void *prototype;
	createArray(&prototype, length, sizeof(int));
	*array = (int *)prototype;
}

void createLongLongArray(long long **array, size_t length) {
	void *prototype;
	createArray(&prototype, length, sizeof(long long));
	*array = (long long *)prototype;
}

void createArray(void **array, size_t length, size_t sizeElement) {
	*array = malloc(length * sizeElement);
}

void printArray(int *array, size_t length) {
	for (size_t i = 0; i < length; i++)
		printf("%d ", array[i]);

	printf("\n");
}

int getIndexOfElementFirstSatisfiesCondition(int array[], size_t length, int condition(int)) {
	for (size_t i = 0; i < length; i++)
		if (condition(array[i]))
			return i;

	return -1;
}

int getIndexOfElementLastSatisfiesCondition(int array[], size_t length, int condition(int)) {
	for (size_t i = length; i > 0; i--)
		if (condition(array[i - 1]))
			return i - 1;

	return -1;
}

int getCountElementsSatisfiesCondition(int array[], size_t length, int condition(int)) {
	int result = 0;

	for (size_t i = length; i > 0; i--)
		if (condition(array[i - 1]))
			result++;

	return result;
}

void invertArray(int array[], size_t length) {
	int *lastELement = array + length - 1;

	for (size_t i = 0; i < length / 2; i++)
		swapInt(array + i, lastELement - i);
}

int isArrayPolendrom(int array[], size_t length) {
	size_t indexLast = length - 1;
	size_t indexMiddle = length / 2;

	for (size_t i = 0; i < indexMiddle; i++)
		if (array[i] != array[indexLast - i])
			return false;

	return true;
}

void removeElementsWithSatisfyingConditionIndex(int array[], size_t *length, int condition(int)) {
	size_t indexReading = 0;
	while (indexReading < *length && !condition(indexReading))
		indexReading++;

	size_t indexWritte = indexReading;
	indexReading++;

	for (; indexReading < *length; indexReading++) {
		if (!condition(indexReading)) {
			array[indexWritte] = array[indexReading];
			indexWritte++;
		}
	}

	*length = indexWritte;
}

void sort(int array[], size_t length) {
	for (size_t i = 0; i < length; i++) {
		size_t iMin = getFirstIndexMin(array + i, length - i) + i;

		swapInt(array + i, array + iMin);
	}
}

void removeElementsSatisfyingCondition(int array[], size_t *length, int condition(int)) {
	size_t indexReading = 0;
	while (indexReading < *length && !condition(array[indexReading]))
		indexReading++;

	size_t indexWritte = indexReading;
	indexReading++;

	for (; indexReading < *length; indexReading++) {
		if (!condition(array[indexReading])) {
			array[indexWritte] = array[indexReading];
			indexWritte++;
		}
	}

	*length = indexWritte;
}

void insertElementIntoArray(int array[], size_t *length, int element, size_t index) {
	int slidingElement = element;

	for (size_t i = index; i <= *length; i++)
		swapInt(array + i, &slidingElement);

	++*length;
}

void append(int array[], size_t *length, int element) {
	array[*length] = element;

	++*length;
}

int appendMalloc(int **array, size_t *length, int element) {
	int *copyArray = (int *)realloc(*array, sizeof(int) * (*length + 1));

	if (copyArray != NULL) {
		*array = copyArray;
		*array[*length] = element;

		++*length;
		return 0;
	} else
		return -1;
}

int pop(int array[], size_t *length, size_t index) {
	int popElement = array[index];

	for (size_t i = index + 1; i < *length; i++)
		array[i - 1] = array[i];

	(*length)--;

	return popElement;
}

int removeElementWithoutPreservingOrder(int array[], size_t *length, size_t index) {
	int removeElement = array[index];

	array[index] = array[*length - 1];

	--*length;
	
	return removeElement;
}

void forEach(int array[], size_t length, int function(int)) {
	for (size_t i = 0; i < length; i++) {
		array[i] = function(array[i]);
	}
}

int getAbsoluteMin(int array[], size_t length) {
	int min = mu_abs(array[0]);

	for (size_t i = 1; i < length; i++) {
		min = min2(min, mu_abs(array[i]));
	}
}

int *copy(int array[], size_t length) {
	int *copyArray = (int *)malloc(length * sizeof(int));

	for (size_t i = 0; i < length; i++)
		copyArray[i] = array[i];

	return copyArray;
}

size_t getIndexAbsoluteMin(int array[], size_t length) {
	int min = mu_abs(array[0]);
	size_t iMin = 0;

	for (size_t i = 1; i < length; i++) {
		int curent = mu_abs(array[i]);
		if (curent < min) {
			min = curent;
			iMin = i;
		}
	}

	return iMin;
}

static int _isFirstIndexMin(int a, int b) {
	return a > b;
}

size_t getFirstIndexMin(int array[], size_t length) {
	return getIndexBestInCondition(array, length, _isFirstIndexMin);
}

static int _isLastIndexMin(int a, int b) {
	return a >= b;
}

size_t getLastIndexMin(int array[], size_t length) {
	return getIndexBestInCondition(array, length, _isLastIndexMin);
}

int getMin(int *array, int size){
    int iMin = getFirstIndexMin(array, size);

    return array[iMin];
}

static int _isFirstIndexMax(int a, int b) {
	return a < b;
}

size_t getFirstIndexMax(int array[], size_t length) {
	return getIndexBestInCondition(array, length, _isFirstIndexMax);
}

static int _isLastIndexMax(int a, int b) {
	return a <= b;
}

size_t getLastIndexMax(int array[], size_t length) {
	return getIndexBestInCondition(array, length, _isLastIndexMax);
}

int getMax(int *array, int size){
    int iMin = getFirstIndexMax(array, size);

    return array[iMin];
}

size_t getIndexBestInCondition(int array[], size_t length, int condition(int, int)) {
	size_t iBest = 0;
	for (size_t j = 1; j < length; j++)
		if (condition(array[iBest], array[j]))
			iBest = j;

	return iBest;
}

int linearSearchElement(int array[], size_t length, int element) {
	for (size_t i = 0; i < length; i++) {
		if (array[i] == element)
			return i;
	}

	return -1;
}

int binSearchElement(int array[], size_t length, int element) {
	int rightBorder = 0;
	int leftBorder = length - 1;

	while (leftBorder >= rightBorder) {
		int medle = rightBorder + (leftBorder - rightBorder) / 2;

		int curentElement = array[medle];

		if (curentElement == element)
			return medle;

		if (curentElement > element)
			leftBorder = medle - 1;
		else
			rightBorder = medle + 1;
	}

	return -1;
}

int isUniqueArray(int array[], size_t length) {
	for (size_t i = 0; i < length; i++) {
		if (linearSearchElement(array + i + 1, length - i - 1, array[i]) == -1)
			return false;
	}

	return true;
}

int isOrderedSequence(int array[], size_t length) {
	return isNotDecreasingOrdering(array, length) ||
		   isNotAscendingOrdering(array, length);
}

int isNotDecreasingOrdering(int array[], size_t length){
	for (size_t i = 1; i < length; i++) 
		if (array[i - 1] > array[i])
			return false;
	
	return true;
}

int isNotAscendingOrdering(int array[], size_t length) {
	for (size_t i = 1; i < length; i++)
		if (array[i - 1] < array[i])
			return false;

	return true;
}

int getIndexELement(int array[], size_t length, int element, int isFirst) {
	int i;
	int change;
	
	if (isFirst) { i = 0;          change = 1; }
	else		 { i = length - 1; change = -1; }

	while (i >= 0 && i < length) {
		if (array[i] == element)
			return i;

		i += change;
	}

	return -1;
}

int getIndexExtremeInSortArray(int array[], size_t length, int condition(int), int isFirst) {
	int rightBorder = -1;
	int leftBorder = length;

	while (leftBorder - rightBorder > 1) {
		int medle = rightBorder + (leftBorder - rightBorder) / 2;

		if (condition(array[medle]) ^ isFirst)
			rightBorder = medle;
		else
			leftBorder = medle;
	}

	if (isFirst)
		return leftBorder != length ? leftBorder : -1;
	else
		return rightBorder;
}

int getIndexFirstInArrayLargerNumber(int *array, size_t length, int number) {
	int rightBorder = -1;
	int leftBorder = length;

	while (leftBorder - rightBorder > 1) {
		int medle = rightBorder + (leftBorder - rightBorder) / 2;

		if (array[medle] <= number)
			rightBorder = medle;
		else
			leftBorder = medle;
	}

	return leftBorder;
}

int isAllElementsEqual(int *array, size_t length) {
	if (length == 0)
		return true;

	int first = array[0];

	for (size_t i = 1; i < length; i++)
		if (first != array[i])
			return false;

	return true;
}

int *getShiftedLeftArray(int *array, size_t length, size_t shift) {
	int *resultArray = (int *)malloc(length * sizeof(int));

	if (resultArray == NULL)
		return NULL;

	for (size_t i = 0; i < length; i++) {
		resultArray[(i + shift) % length] = array[i];
	}

	return resultArray;
}

int any(int *array, size_t length, int condition(int)) {
	for (size_t i = 0; i < length; i++)
		if (condition(array[i]))
			return true;

	return false;
}

int all(int *array, size_t length, int condition(int)) {
	for (size_t i = 0; i < length; i++)
		if (!condition(array[i]))
			return false;

	return true;
}

int arraySplit(int *array, size_t length, int condition(int),
				int **a, size_t *lengthA,
				int **b, size_t *lengthB) {

	*a = (int *)malloc(0);
	*lengthA = 0;
	*b = (int *)malloc(0);
	*lengthB = 0;

	for (size_t i = 0; i < length; i++) {
		int result;
		if (condition(array[i]))
			result = appendMalloc(a, lengthA, array[i]);
		else
			result = appendMalloc(b, lengthB, array[i]);

		if (result == -1)
			return -1;
	}

	return 0;
}

int summ(int *array, size_t length) {
	int result = 0;

	for (size_t i = 0; i < length; i++)
		result += array[i];

	return result;
}

void setRandomElementsToArray(int *array, size_t length) {
	for (size_t i = 0; i < length; i++)
		array[i] = rand();
}

void removeNonSatisfyingConditions(void *array,
                                   const size_t sizeElement,
                                   size_t *sizeArray,
                                   bool condition(void *)) {
    const char *first = (char *)array;
    size_t iRead = 0;
    const size_t coumtAllBete = *sizeArray * sizeElement;

    while (iRead < coumtAllBete &&
        condition(first + iRead)) {
        iRead += sizeElement;
    }

    size_t iWrite = iRead;
    iRead += sizeElement;

    while (iRead < coumtAllBete) {
        if (condition(first + iRead)) {
            swap(first + iRead,
                first + iWrite,
                sizeElement);

            iWrite += sizeElement;
        }

        iRead += sizeElement;
    }

    *sizeArray = iWrite / sizeElement;
}

void simplifyOrderedArray(void *array,
						  const size_t sizeElement,
	                      size_t *sizeArray,
					      bool isEqual (void *, void *)) {
	const char *first = (char *)array;
    size_t iread = sizeElement;
	const size_t coumtAllBete = *sizeArray * sizeElement;

    while (iread < coumtAllBete &&
        !isEqual(first + iread - sizeElement,
		     	 first + iread)) {
        iread += sizeElement;
    }

    size_t iwrite = iread;
    iread += sizeElement;

    while (iread < *sizeArray) {
        if (!isEqual(first + iread - sizeElement,
			         first + iread)) {
            swap(first + iread - sizeElement, first + iread,
				 sizeElement);
            iwrite += sizeElement;
        }
        iread += sizeElement;
    }

	*sizeArray = iwrite / sizeElement;
}
