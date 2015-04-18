#ifndef CALC
#define CALC

#include"dynamicArray.h"

	int isNumber(char *s, double *num);
	void add(DynArr *stack);
	void subtract(DynArr *stack);
	void divide(DynArr *stack);
	void multiply(DynArr *stack);
	void powerOf(DynArr *stack);
	void squaring(DynArr *stack);
	void squareRoot(DynArr *stack);
	void exponential(DynArr *stack);	
	void naturalLog(DynArr *stack);	
	void commonLog(DynArr *stack);	
	double calculate(int numInputTokens, char **inputString);

#endif