#include "maths.h"
#include <stdbool.h>
#include <math.h>
#include <tgmath.h>
#include <stdlib.h>
#include <time.h>

static bool initialized_prng = false;

NumberType Sin(NumberType number) {
	return sin(number);
}

NumberType Cos(NumberType number) {
	return cos(number);
}

NumberType Tg(NumberType number) {
	return tan(number);
}

NumberType Arcsin(NumberType number) {
	return asin(number);
}

NumberType Arccos(NumberType number) {
	return acos(number);
}

NumberType Arctg(NumberType number) {
	return atan(number);
}

NumberType Arctg2(NumberType y, NumberType x) {
	return atan2(y, x);
}

NumberType Pow(NumberType base, NumberType exponent) {
	return pow(base, exponent);
}

NumberType Exp(NumberType number) {
	return exp(number);
}

NumberType Sqrt(NumberType number) {
	return sqrt(number);
}

NumberType Ln(NumberType number) {
	return log(number);
}

NumberType Lg(NumberType number) {
	return log10(number);
}

NumberType Abs(NumberType number) {
	return fabs(number);
}

NumberType Trunc(NumberType number) {
	return trunc(number);
}

NumberType Rand() {
	if (!initialized_prng) {
		srand(time(NULL));
		initialized_prng = true;
	}

	return (NumberType)rand() / RAND_MAX;
}
