#ifndef NUMBERS_H
#define NUMBERS_H

#include "types.h"

NumberType NumberAdd(NumberType number_1, NumberType number_2);
NumberType NumberSub(NumberType number_1, NumberType number_2);
NumberType NumberMul(NumberType number_1, NumberType number_2);
NumberType NumberDiv(NumberType number_1, NumberType number_2);
NumberType NumberLess(NumberType number_1, NumberType number_2);
NumberType NumberMore(NumberType number_1, NumberType number_2);
NumberType NumberEqual(NumberType number_1, NumberType number_2);
NumberType NumberAnd(NumberType number_1, NumberType number_2);
NumberType NumberOr(NumberType number_1, NumberType number_2);
NumberType NumberNot(NumberType number);
#endif
