#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include "calc.h"



/* param: s the string
   param: num a pointer to double
   returns: true (1) if s is a number else 0 or false.
   postcondition: if it is a number, num will hold
   the value of the number
*/
int isNumber(char *s, double *num)
{
	char *end;
	double returnNum;

	if(strcmp(s, "0") == 0)
	{
		*num = 0;
		return 1;
	}
	else 
	{
		returnNum = strtod(s, &end);
		/* If there's anything in end, it's bad */
		if((returnNum != 0.0) && (strcmp(end, "") == 0))
		{
			*num = returnNum;
			return 1;
		}
	}
	return 0;  //if got here, it was not a number
}

/*	param: stack the stack being manipulated
	pre: the stack contains at least two elements
	post: the top two elements are popped and 
	their sum is pushed back onto the stack.
*/
void add (struct DynArr *stack)
{
	if(sizeDynArr(stack) > 1){
		
		TYPE firstOff = topDynArr(stack);
		popDynArr(stack);
		TYPE secondOff = topDynArr(stack);
		popDynArr(stack);
		TYPE putBack = firstOff + secondOff;
		pushDynArr(stack, putBack);
		
	}
}

/*	param: stack the stack being manipulated
	pre: the stack contains at least two elements
	post: the top two elements are popped and 
	their difference is pushed back onto the stack.
*/
void subtract(struct DynArr *stack)
{
	if(sizeDynArr(stack) > 1){
		
		TYPE firstOff = topDynArr(stack);
		popDynArr(stack);
		TYPE secondOff = topDynArr(stack);
		popDynArr(stack);
		TYPE putBack = secondOff-firstOff;
		pushDynArr(stack, putBack);
	}
	
}

/*	param: stack the stack being manipulated
	pre: the stack contains at least two elements
	post: the top two elements are popped and 
	their quotient is pushed back onto the stack.
*/
void divide(struct DynArr *stack)
{
	if(sizeDynArr(stack) > 1){	
		TYPE firstOff = topDynArr(stack);
		popDynArr(stack);
		TYPE secondOff = topDynArr(stack);
		popDynArr(stack);
		printf("%f/%f = ", secondOff, firstOff);
		TYPE putBack = secondOff/firstOff;
		printf("%f \n",putBack);
		pushDynArr(stack, putBack);
		printf("%d", sizeDynArr(stack));
	}
}
/*
 * Name         : multiply
 *
 * Arguments    : stack the stack being manipulated
 *
 * Description  : 	
 *	pre: the stack contains at least two elements
 *	post: the top two elements are popped and 
 *	the result of the multiplication is pushed back onto the stack. 
 */

void multiply(struct DynArr *stack)
{
	if(sizeDynArr(stack) > 1){	
		TYPE firstOff = topDynArr(stack);
		popDynArr(stack);
		TYPE secondOff = topDynArr(stack);
		popDynArr(stack);
		printf("%f*%f = ", secondOff, firstOff);
		TYPE putBack = secondOff*firstOff;
		printf("%f \n",putBack);
		printf("%d", sizeDynArr(stack));
	}
}
/*
 * Name         : powerOf
 *
 * Arguments    : stack the stack being manipulated
 *
 * Description  : 	
 *	pre: the stack contains at least two elements
 *	post: the top two elements are popped and 
 *	the result of the first to the power of the 
 *  second is pushed back onto the stack. 
 */
void powerOf(struct DynArr *stack)
{
	if(sizeDynArr(stack) > 1){	
		TYPE firstOff = topDynArr(stack);
		popDynArr(stack);
		TYPE secondOff = topDynArr(stack);
		popDynArr(stack);
		printf("%f^%f = ", secondOff, firstOff);
		TYPE putBack = pow(secondOff,firstOff);
		printf("%f \n",putBack);
		pushDynArr(stack, putBack);
		printf("%d", sizeDynArr(stack));
	}
}

void squaring(struct DynArr *stack)
{
	if(sizeDynArr(stack) > 1){	
		TYPE firstOff = topDynArr(stack);
		popDynArr(stack);
		TYPE secondOff = topDynArr(stack);
		popDynArr(stack);
		printf("%f^%f = ", secondOff, firstOff);
		TYPE putBack = pow(secondOff,firstOff);
		printf("%f \n",putBack);
		pushDynArr(stack, putBack);
		printf("%d", sizeDynArr(stack));
	}
}

// stack greater than 0
void squareRoot(struct DynArr *stack)
{
	if(sizeDynArr(stack) > 0){	
		TYPE firstOff = topDynArr(stack);
		popDynArr(stack);
		TYPE putBack = sqrt(firstOff);
		printf("%f \n",putBack);
		pushDynArr(stack, putBack);
		printf("%d", sizeDynArr(stack));
	}
}

// stack greater than 0
void expontential(struct DynArr *stack)
{
	if(sizeDynArr(stack) > 0){	
		TYPE firstOff = topDynArr(stack);
		popDynArr(stack);
		TYPE putBack = exp(firstOff);
		printf("%f \n",putBack);
		pushDynArr(stack, putBack);
		printf("%d", sizeDynArr(stack));
	}
}
// stack greater than 0
void naturalLog(struct DynArr *stack)
{
	if(sizeDynArr(stack) > 0){	
		TYPE firstOff = topDynArr(stack);
		popDynArr(stack);
		TYPE putBack = log(firstOff);
		printf("%f \n",putBack);
		pushDynArr(stack, putBack);
		printf("%d", sizeDynArr(stack));
	}
}
// stack greater than 0
void commonLog(struct DynArr *stack)
{
	if(sizeDynArr(stack) > 0){	
		TYPE firstOff = topDynArr(stack);
		popDynArr(stack);
		TYPE putBack = log10(firstOff);
		printf("%f \n",putBack);
		pushDynArr(stack, putBack);
		printf("%d", sizeDynArr(stack));
	}
}

double calculate(int numInputTokens, char **inputString)
{
	int i;
	double result = 0.0;
	char *s;
	struct DynArr *stack;

	//set up the stack
	stack = createDynArr(20);

	// start at 1 to skip the name of the calculator calc
	for(i=1;i < numInputTokens;i++) 
	{
		s = inputString[i];

		// Hint: General algorithm:
		// (1) Check if the string s is in the list of operators.
		//   (1a) If it is, perform corresponding operations.
		//   (1b) Otherwise, check if s is a number.
		//     (1b - I) If s is not a number, produce an error.
		//     (1b - II) If s is a number, push it onto the stack

		if(strcmp(s, "+") == 0)
			add(stack);
		else if(strcmp(s,"-") == 0)
			subtract(stack);
		else if(strcmp(s, "/") == 0)
			divide(stack);
		else if(strcmp(s, "x") == 0)
			multiply(stack);
		else if(strcmp(s, "^") == 0)
			powerOf(stack);
		else if(strcmp(s, "^2") == 0)
			squaring(stack);
		else if(strcmp(s, "^3") == 0)
			//cubing(stack);
		else if(strcmp(s, "abs") == 0)
			//absoluteVal(stack);
			printf("Absolute value\n");
		else if(strcmp(s, "sqrt") == 0)
			squareRoot(stack);
		else if(strcmp(s, "exp") == 0)
			expontential(stack);
		else if(strcmp(s, "ln") == 0)
			naturalLog(stack);
		else if(strcmp(s, "log") == 0)
			commonLog(stack);
		else 
		{
			// FIXME: You need to develop the code here (when s is not an operator)
			// Remember to deal with special values ("pi" and "e")
			
		}
	}	//end for 

	/* FIXME: You will write this part of the function (2 steps below) 
	 * (1) Check if everything looks OK and produce an error if needed.
	 * (2) Store the final value in result and print it out.
	 */
	
	return result;
}

/* int main(int argc , char** argv)
{
	// assume each argument is contained in the argv array
	// argc-1 determines the number of operands + operators
	if (argc == 1)
		return 0;

	calculate(argc,argv);
	return 0;
} */
