#include "output.h"
#include <stdio.h>

static const char* STRING_SHOW_FORMAT = "%s";
static const char* NUMBER_SHOW_FORMAT = "%f";

void ShowString(const char* string) {
	printf(STRING_SHOW_FORMAT, string);
}

void ShowNumber(NumberType number) {
	printf(NUMBER_SHOW_FORMAT, number);
}
