#ifndef MATHS_H
#define MATHS_H

#include "types.h"

NumberType Sin(NumberType number);
NumberType Cos(NumberType number);
NumberType Tg(NumberType number);
NumberType Arcsin(NumberType number);
NumberType Arccos(NumberType number);
NumberType Arctg(NumberType number);
// a reverse order of arguments
NumberType Arctg2(NumberType x, NumberType y);
// a reverse order of arguments
NumberType Pow(NumberType exponent, NumberType base);
NumberType Exp(NumberType number);
NumberType Sqrt(NumberType number);
NumberType Ln(NumberType number);
NumberType Lg(NumberType number);
NumberType Abs(NumberType number);
NumberType Trunc(NumberType number);
NumberType Rand(void);
#endif
