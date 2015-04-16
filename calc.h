#ifndef CALC
#define CALC

#include"dynamicArray.h"

	int isNumber(char *s, double *num);
	void add(DynArr *stack);
	void subtract(DynArr *stack);
	void divide(DynArr *stack);
	double calculate(int numInputTokens, char **inputString);

#endif