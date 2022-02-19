#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "heapFunctions.h"

int mu_abs(int x) {
    return (x >= 0) ? x : -x;
}

int max2(int n1, int n2) {
    return (n1 > n2) ? n1 : n2;
}

int min2(int n1, int n2) {
    return (n1 < n2) ? n1 : n2;
}

int max3(int n1, int n2, int n3) {
    return max2(max2(n1, n2), n3);
}

int min3(int n1, int n2, int n3) {
    return min2(min2(n1, n2), n3);
}

long long getDistanceSquared(long long n1, long long n2) {
    long long distance = n1 - n2;
    return distance * distance;
}

double getDistanse(int x1, int y1, int x2, int y2) {
    long long distanceSquaredByX = getDistanceSquared(x1, x2);
    long long distanceSquaredByY = getDistanceSquared(y1, y2);
    return sqrt(distanceSquaredByX + distanceSquaredByY);
}

double getDiscriminant(double b, double a, double c) {
    return b * b - 4 * a * c;
}

void solveX2(double a, double b, double c) {
    if (a != 0) {
        double d = getDiscriminant(b, a, c);

        if (d > 0) {
            double x1 = (-b + sqrt(d)) / 2 / a;
            double x2 = (-b - sqrt(d)) / 2 / a;

            printf("x1 - %e\nx2 - %e\n", x1, x2);
        } else if (d == 0) {
            double x = -b / 2 / a;

            printf("x - %e\n", x);
        } else
            printf("no valid roots\n");
    } else if (b != 0) {
        double x = -c / b;

        printf("x - %e\n", x);
    } else if (c == 0)
        printf("x any number\n");
    else
        printf("no roots\n");
}

char getLowercaseCharacter(char symbol) {
    return (symbol < 'A' || symbol > 'Z') ? symbol : symbol + 'a' - 'A';
}

bool isSymbolVowel(char symbol) {
    symbol = getLowercaseCharacter(symbol);
    if ((symbol >= 'a') && (symbol <= 'z')) {
        int shift = symbol - 'a';

        return (VOWEL_INDICES >> shift) & 1;
    }
    return 0;
}

bool isSymbolDigit(char symbol) {
    return '0' <= symbol && symbol <= '9';
}

void niceScanf(char const format[], char const name[], void *Variable) {
    printf(name);
    printf(" = ");
    scanf(format, Variable);
}

void swapFloat(float *n1, float *n2) {
    float t = *n1;
    *n1 = *n2;
    *n2 = t;
}

void sort2Float(float *a, float *b) {
    if (*a > *b)
        swapFloat(a, b);
}

void sort3Float(float *a, float *b, float *c) {
    sort2Float(a, b);
    sort2Float(b, c);
    sort2Float(a, b);
}

void swapInt(int *n1, int *n2) {
    int t = *n1;
    *n1 = *n2;
    *n2 = t;
}

void sort2Int(int *a, int *b) {
    if (*a > *b)
        swapInt(a, b);
}

void sort3Int(int *a, int *b, int *c) {
    sort2Int(a, b);
    sort2Int(b, c);
    sort2Int(a, b);
}

bool isItPossibleMakeTriangle(int a, int b, int c) {
    sort3Int(&a, &b, &c);

    return a + b > c;
}

float getCosOfLargerSide(float a, float b, float c) {
    if (!isItPossibleMakeTriangle(a, b, c)) {
        printf("Value Error\n");
        exit(EXIT_FAILURE);
    }

    sort3Float(&a, &b, &c);

    return (a * a + b * b - c * c) / (a * b);
}

int getTriangleTypeLength(int a, int b, int c) {
    if (!isItPossibleMakeTriangle(a, b, c))
        return IS_NOT_TRIANGLE;

    double cosOfLargerSide = getCosOfLargerSide((float) a, (float) b, (float) c);

    if (cosOfLargerSide > LAMBDA)
        return ACUTE_ANGLED_TRIANGLE;
    if (cosOfLargerSide < -LAMBDA)
        return OBTUSE_TRIANGLE;
    return RIGHT_TRIANGLE;
}

int getSammDigit(int number) {
    int result = 0;
    number = mu_abs(number);

    while (number > 0) {
        result += number % 10;
        number /= 10;
    }

    return result;
}

long long ceilFrac(long long a, long long b) {
    return (a % b != 0) ? a / b + 1 : a / b;
}

int nod(int number1, int number2) {
    while (number1 > 0 && number2 > 0)
        if (number1 > number2)
            number1 %= number2;
        else
            number2 %= number1;

    return number1 + number2;
}

int nok(int number1, int number2) {
    return number1 / nod(number1, number2) * number2;
}

void swap(void *a, void *b, size_t size) {
    void *buf = malloc(size);

    memcpy(buf, a, size);
    memcpy(a, b, size);
    memcpy(b, buf, size);

    free((void *) buf);
}

