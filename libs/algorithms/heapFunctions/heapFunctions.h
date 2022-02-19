#ifndef heapFunctions
#define heapFunctions

#include <stddef.h>
#include <stdbool.h>
#include <memory.h>

#define VOWEL_INDICES 17842449 // 1 0001 0000 0100 0001 0001 0001 bin

#define LAMBDA 0.00000001

#define ACUTE_ANGLED_TRIANGLE 0 // ������������� �����������
#define RIGHT_TRIANGLE  1 //       ������������� �����������
#define OBTUSE_TRIANGLE 2 //       ������������  �����������
#define IS_NOT_TRIANGLE -1 //      �� �������� �������������


/// <param name="x"></param>
/// <returns>������ x</returns>
int mu_abs(int x);

/// <param name="n1"></param>
/// <param name="n2"></param>
/// <returns>�������� �� n1, n2</returns>
int max2(int n1, int n2);

int min2(int n1, int n2);

/// <param name="n1"></param>
/// <param name="n2"></param>
/// <param name="n3"></param>
/// <returns>�������� �� n1, n2, n3</returns>
int max3(int n1, int n2, int n3);

int min3(int n1, int n2, int n3);

/// <param name="n1"></param>
/// <param name="n2"></param>
/// <returns>�������� ��������� ����� n1, n2</returns>
long long getDistanceSquared(long long n1, long long n2);

/// <param name="x1"></param>
/// <param name="y1"></param>
/// <param name="x2"></param>
/// <param name="y2"></param>
/// <returns>��������� ����� (x1, y1) � (x2, y2)</returns>
double getDistanse(int x1, int y1, int x2, int y2);

/// <summary>�������� ������� ����������� ���������</summary>
/// <param name="a"></param>
/// <param name="b"></param>
/// <param name="c"></param>
void solveX2(double a, double b, double c);

/// <param name="b"></param>
/// <param name="a"></param>
/// <param name="c"></param>
/// <returns>������������</returns>
double getDiscriminant(double b, double a, double c);

/// <param name="symbol"></param>
/// <returns>symbol � ������ ��������</returns>
char getLowercaseCharacter(char symbol);

/// <param name="symbol"></param>
/// <returns>�������� �� symbol ��������</returns>
bool isSymbolVowel(char symbol);

/// <summary>���������� ����������� ���� {name} = {���� ������������}</summary>
/// <param name="format">������������ ����������</param>
/// <param name="name">��� ����������</param>
/// <param name="Variable">��������� �� ����������</param>
void niceScanf(char const format[], char const name[], void *Variable);

/// <param name="symbol"></param>
/// <returns>�������� �� symbol ������</returns>
bool isSymbolDigit(char symbol);

/// <summary>���������� ����� ����� n1, n2 � ����� float</summary>
/// <param name="n1"></param>
/// <param name="n2"></param>
void swapFloat(float *n1, float *n2);

/// <summary>���������� ���������� �� ���������� � ������ float</summary>
/// <param name="a"></param>
/// <param name="b"></param>
void sort2Float(float *a, float *b);

/// <summary>���������� ���������� �� ���������� � ������ float</summary>
/// <param name="a"></param>
/// <param name="b"></param>
/// <param name="c"></param>
void sort3Float(float *a, float *b, float *c);

/// <summary>���������� ����� ����� n1, n2 � ����� int</summary>
/// <param name="n1"></param>
/// <param name="n2"></param>
void swapInt(int *n1, int *n2);

/// <summary>���������� ���������� �� ���������� � ������ int</summary>
/// <param name="a"></param>
/// <param name="b"></param>
void sort2Int(int *a, int *b);

/// <summary>���������� ���������� �� ���������� � ������ int</summary>
/// <param name="a"></param>
/// <param name="b"></param>
/// <param name="c"></param>
void sort3Int(int *a, int *b, int *c);

/// <param name="a"></param>
/// <param name="b"></param>
/// <param name="c"></param>
/// <returns>�������� �� ������� ����������� � ��������� a, b, c</returns>
bool isItPossibleMakeTriangle(int a, int b, int c);

/// <param name="a"></param>
/// <param name="b"></param>
/// <param name="c"></param>
/// <returns>���������� ��� ������������ �� ��������� a, b, c</returns>
int getTriangleTypeLength(int a, int b, int c);

/// <param name="a"></param>
/// <param name="b"></param>
/// <param name="c"></param>
/// <returns>������� �������� ����</returns>
float getCosOfLargerSide(float a, float b, float c);

/// <param name="number"></param>
/// <returns>����� ���� ����� number</returns>
int getSammDigit(int number);

long long ceilFrac(long long a, long long b);

int nod(int number1, int number2);

int nok(int number1, int number2);

/// <summary>
/// ���������� ����� size ���� �� ������� a � b 
/// </summary>
/// <param name="a"></param>
/// <param name="b"></param>
/// <param name="size">���������� ���� ������</param>
void swap(void *a, void *b, size_t size);

#endif // !heapFunctions
