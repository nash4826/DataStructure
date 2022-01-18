#include <stdio.h>
#include <stdlib.h>
#include "ArrayStack.h"

void StackInIt(Stack* pstack) {
	pstack->topIdx = -1;
}

int SIsEmpty(Stack* pstack) {
	if (pstack->topIdx == -1)
		return TRUE;
	else
		return FALSE;
}

void SPush(Stack* pstack, Data data) {
	if (pstack->topIdx >= STACK_LEN)
	{
		printf("stack memory over\n");
		return;
	}
	pstack->topIdx += 1;
	pstack->stackArr[pstack->topIdx] = data;
}

Data SPop(Stack* pstack) {
	if (SIsEmpty(pstack))
	{
		printf("Empty Stack\n");
		exit(-1);
	}
	Data rdata = pstack->stackArr[pstack->topIdx];
	pstack->topIdx -= 1;
	
	return rdata;
}

Data SPeek(Stack* pstack) {
	if (SIsEmpty(pstack))
	{
		printf("Empty Stack\n");
		exit(-1);
	}
	return pstack->stackArr[pstack->topIdx];
}