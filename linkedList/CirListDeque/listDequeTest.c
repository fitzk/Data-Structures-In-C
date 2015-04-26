#include "cirListDeque.h"
#include <stdio.h>

int main(){
//	printf("creating struct\n");
	struct cirListDeque* q = createCirListDeque();
//	printf("\nstruct q created in listDequeTest.c\n");
	addBackCirListDeque(q, (TYPE)1);
//	printf("%g", backCirListDeque(q));
	addBackCirListDeque(q, (TYPE)2);
//	printf("%g", backCirListDeque(q));
	addBackCirListDeque(q, (TYPE)3);
//	printf("%g", backCirListDeque(q));
	addFrontCirListDeque(q, (TYPE)4);
//	printf("%g", frontCirListDeque(q));
	addFrontCirListDeque(q, (TYPE)5);
//	printf("%g", frontCirListDeque(q));
	addFrontCirListDeque(q, (TYPE)6);
//	printf("%g", frontCirListDeque(q));
	//printf("\n%s", "1-6 added");
	printCirListDeque(q);
	printf("\n%g\n", frontCirListDeque(q));
	printf("\n%g\n", backCirListDeque(q));
	removeFrontCirListDeque(q);
	removeBackCirListDeque(q);
	printCirListDeque(q);
	reverseCirListDeque(q);
	printCirListDeque(q);
	return 0;
}
