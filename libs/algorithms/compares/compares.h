#ifndef compares
#define compares

#include <stdbool.h>

typedef enum ComparisonResults {
	larger = 1,
	equal = 0,
	smaller = -1
}ComparisonResults;

ComparisonResults int_compare(const void *a, const void *b);

ComparisonResults int_compareInvert(const void *a, const void *b);

ComparisonResults long_long_compare(const void *pa, const void *pb) ;

bool int_isEqual(const void *a, const void *b);

#endif // !compares
