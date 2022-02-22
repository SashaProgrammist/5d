#include "compares.h"

ComparisonResults int_compare(const void *a, const void *b) {
	int arg1 = *(const int *)a;
	int arg2 = *(const int *)b;

	if (arg1 < arg2) return smaller;
	if (arg1 > arg2) return larger;
	return equal;
}


ComparisonResults int_compareInvert(const void *a, const void *b) {
	int arg1 = *(const int *)a;
	int arg2 = *(const int *)b;

	if (arg1 > arg2) return smaller;
	if (arg1 < arg2) return larger;
	return equal;
}

ComparisonResults long_long_compare(const void *pa, const void *pb) {
    long long a = *((long long *) pa);
    long long b = *((long long *) pb);

    if (a > b) return larger;
    if (b < a) return smaller;
    return equal;
}

bool int_isEqual(const void *a, const void *b) {
	int arg1 = *(const int *)a;
	int arg2 = *(const int *)b;

	return arg1 == arg2;
}
