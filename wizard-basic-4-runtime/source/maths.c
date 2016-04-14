#include "maths.h"
#include <math.h>
#include <stdlib.h>
#include <time.h>

static Boolean initialize_prmg = FALSE;

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

NumberType Sh(NumberType number) {
	return sinh(number);
}

NumberType Ch(NumberType number) {
	return cosh(number);
}

NumberType Th(NumberType number) {
	return tanh(number);
}

NumberType Exponent(NumberType number) {
	return exp(number);
}

NumberType Ln(NumberType number) {
	return log(number);
}

NumberType Lg(NumberType number) {
	return log10(number);
}

NumberType Modulus(NumberType number) {
	return fabs(number);
}

NumberType Power(NumberType base, NumberType exponent) {
	return pow(base, exponent);
}

NumberType Integer(NumberType number) {
	return floor(number);
}

NumberType Random(NumberType minimum, NumberType maximum) {
	if (initialize_prmg == FALSE) {
		srand(time(NULL));
		initialize_prmg = TRUE;
	}

	return (NumberType)rand() / RAND_MAX * (maximum - minimum) + minimum;
}

NumberType SquareRoot(NumberType number) {
	return sqrt(number);
}

NumberType Angle(NumberType x, NumberType y) {
	return atan2(y, x);
}
