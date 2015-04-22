#include <stdio.h>
#include <stdlib.h>
#include "calc.h"

void assertTrue(int predicate, char *message) 
{
	printf("%s: ", message);
	if (predicate)
		printf("PASSED\n");
	else
		printf("FAILED\n");
}
 
int main(int argc, char* argv[]){
	
	DynArr *dyn;
	dyn = createDynArr(2);
	double a,b,c,d,e,f,g,h;
	a = 3;
	b = 4;
	c = 10;
	d = 6;
	e = 5; 
	f = 20;
	printf("\n\nTesting addDynArr...\n");
	addDynArr(dyn, a);
	addDynArr(dyn, b);
	addDynArr(dyn, c);
	addDynArr(dyn, d);
	addDynArr(dyn, e);
	
	printf("The array's content: [3,4,10,6,5]\n");
	assertTrue(EQ(getDynArr(dyn, 0), a), "Test 1st element == 3");
	assertTrue(EQ(getDynArr(dyn, 1), b), "Test 2nd element == 4");
	assertTrue(EQ(getDynArr(dyn, 2), c), "Test 3rd element == 10");
	assertTrue(EQ(getDynArr(dyn, 3), d), "Test 4th element == 5");
	assertTrue(EQ(getDynArr(dyn, 4), e), "Test 5th element == 6");
	assertTrue(sizeDynArr(dyn) == 5, "Test size = 5");
	
	printf("\n\nTesting add...\nCalling addDynArr(dyn)\n");
	add(dyn); 
	printf("The array's content: [3,4,7,6,5]\n");
	assertTrue(EQ(getDynArr(dyn, 3), (double)11), "Test 3rd element == 11");
	assertTrue(sizeDynArr(dyn) == 4, "Test size = 4");
	
	//removing result of add test and restoring array
	removeDynArr(dyn, 3);
	addDynArr(dyn, d);
	addDynArr(dyn, e);
	
	printf("\n\nTesting sub...");
	subtract(dyn); 
	printf("The array's content: [3,4,7,6,5]\n");
	assertTrue(EQ(getDynArr(dyn, 3), (double)1), "Test 3rd element == 1");
	assertTrue(sizeDynArr(dyn) == 4, "Test size = 4");	
	//printf("%d \n", sizeDynArr(dyn));
	printf("Top: %f \n", topDynArr(dyn));	
		//removing result of add test and restoring array
	popDynArr(dyn);
	printf("Top: %f \n", topDynArr(dyn));
	pushDynArr(dyn, f);
	pushDynArr(dyn, e);
	printf("Top: %f \n", topDynArr(dyn));
	
	printf("\n\nTesting divide...");
	divide(dyn); 
	//printf("The array's content: [3,4,10,20,5]\n");
	//assertTrue(EQ(getDynArr(dyn, 3),(double)4), "Test 3rd element == 4");
	//assertTrue(sizeDynArr(dyn) == 4, "Test size = 4");	
/* 	printf("At 4: %f \n", topDynArr(dyn));
	removeDynArr(dyn,4);
	printf("At 3: %f \n", topDynArr(dyn));
	removeDynArr(dyn,3);
	printf("At 2: %f \n", topDynArr(dyn));	
	removeDynArr(dyn,2);
	printf("At 1: %f \n", topDynArr(dyn));	
	printf("%d \n",sizeDynArr(dyn)); */
	
			//removing result of add test and restoring array
	printf("\nTop: %f \n", topDynArr(dyn));
	popDynArr(dyn);
	printf("Top: %f \n", topDynArr(dyn));
	pushDynArr(dyn, f);
	pushDynArr(dyn, e);
	printf("Top: %f \n", topDynArr(dyn));
	
	printf("\n\nTesting multiply...\nCalling addDynArr(dyn)\n");
	multiply(dyn); 
	//printf("The array's content: [3,4,10,6,5]\n");
	//assertTrue(EQ(getDynArr(dyn, 3),(float)30), "Test 3rd element == 30");
	//assertTrue(sizeDynArr(dyn) == (float)4, "Test size = 4");
	
	
	printf("Before pop Top: %f \n", topDynArr(dyn));			//removing result of add test and restoring array
	popDynArr(dyn);
	printf("After pop Top: %f \n", topDynArr(dyn));
	pushDynArr(dyn,(double) 2);
	pushDynArr(dyn,(double) 1);
	printf("After 2 push Top: %f \n", topDynArr(dyn));	
	printf("\n\nTesting power of...n");
	powerOf(dyn); 
	//printf("The array's content: [3,4,10,6,5]\n");
	//assertTrue(EQ(getDynArr(dyn, 3),(float)2), "Test 3rd element == 2");
	//assertTrue(sizeDynArr(dyn) == (float)4, "Test size = 4");
	


	
}
 