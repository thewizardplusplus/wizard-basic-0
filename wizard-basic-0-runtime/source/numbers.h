#ifndef NUMBERS_H
#define NUMBERS_H

#include "types.h"

// a reverse order of arguments
NumberType NumberAdd(NumberType number_2, NumberType number_1);
// a reverse order of arguments
NumberType NumberSub(NumberType number_2, NumberType number_1);
// a reverse order of arguments
NumberType NumberMul(NumberType number_2, NumberType number_1);
// a reverse order of arguments
NumberType NumberDiv(NumberType number_2, NumberType number_1);
// a reverse order of arguments
NumberType NumberLess(NumberType number_2, NumberType number_1);
// a reverse order of arguments
NumberType NumberMore(NumberType number_2, NumberType number_1);
// a reverse order of arguments
NumberType NumberEqual(NumberType number_2, NumberType number_1);
// a reverse order of arguments
NumberType NumberAnd(NumberType number_2, NumberType number_1);
// a reverse order of arguments
NumberType NumberOr(NumberType number_2, NumberType number_1);
NumberType NumberNot(NumberType number);
#endif
