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
	
	printf("\n\nTesting addDynArr...\n");
	addDynArr(dyn, 3);
	addDynArr(dyn, 4);
	addDynArr(dyn, 10);
	addDynArr(dyn, 6);
	addDynArr(dyn, 5);
	
	printf("The array's content: [3,4,10,6,5]\n");
	assertTrue(EQ(getDynArr(dyn, 0), 3), "Test 1st element == 3");
	assertTrue(EQ(getDynArr(dyn, 1), 4), "Test 2nd element == 4");
	assertTrue(EQ(getDynArr(dyn, 2), 10), "Test 3rd element == 10");
	assertTrue(EQ(getDynArr(dyn, 3), 6), "Test 4th element == 5");
	assertTrue(EQ(getDynArr(dyn, 4), 5), "Test 5th element == 6");
	assertTrue(sizeDynArr(dyn) == 5, "Test size = 5");
	
	printf("\n\nTesting add...\nCalling addDynArr(dyn)\n");
	add(dyn); 
	printf("The array's content: [3,4,7,6,5]\n");
	assertTrue(EQ(getDynArr(dyn, 3), 11), "Test 3rd element == 11");
	assertTrue(sizeDynArr(dyn) == 4, "Test size = 4");
	
	//removing result of add test and restoring array
	removeDynArr(dyn, 3);
	addDynArr(dyn, 6);
	addDynArr(dyn, 5);
	
	printf("\n\nTesting sub...\nCalling addDynArr(dyn)\n");
	subtract(dyn); 
	printf("The array's content: [3,4,7,6,5]\n");
	assertTrue(EQ(getDynArr(dyn, 3), 1), "Test 3rd element == 1");
	assertTrue(sizeDynArr(dyn) == 4, "Test size = 4");	
	//printf("%d \n", sizeDynArr(dyn));
	
		//removing result of add test and restoring array
	removeDynArr(dyn, 3);
	addDynArr(dyn, 20);
	addDynArr(dyn, 5);
	
	printf("\n\nTesting divide...\nCalling addDynArr(dyn)\n");
	divide(dyn); 
	printf("The array's content: [3,4,10,20,5]\n");
	assertTrue(EQ(getDynArr(dyn, 3), 4), "Test 3rd element == 4");
	assertTrue(sizeDynArr(dyn) == 4, "Test size = 4");	
/* 	printf("At 4: %f \n", topDynArr(dyn));
	removeDynArr(dyn,4);
	printf("At 3: %f \n", topDynArr(dyn));
	removeDynArr(dyn,3);
	printf("At 2: %f \n", topDynArr(dyn));	
	removeDynArr(dyn,2);
	printf("At 1: %f \n", topDynArr(dyn));	
	printf("%d \n",sizeDynArr(dyn)); */
	

	
}
 